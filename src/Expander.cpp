#include "include/Expander.hpp"

#include "include/Splitter.hpp"

int Expander::size = 32;

Expander::Expander(QString filename, SplitterWidgetDecorator* parent) : QLabel(parent), pixmap{new QPixmap{filename}}, overlay{nullptr}
{
    *pixmap = pixmap->scaledToHeight(size, Qt::FastTransformation);
    setPixmap(*pixmap);
    resize(size, size);
    reposition();
    QPolygon mask;
    mask << QPoint{0, 0} << QPoint{0, size/10} << QPoint{size * 9 / 10, size} << QPoint{size, size} << QPoint{size, 0};
    setMask(QRegion{mask});
}

void Expander::reposition()
{
    move(parentWidget()->width() - width(), 0);
    raise();
}

void Expander::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        event->accept();    // No-op
    }
    else
    {
        releaseMouse();
        event->ignore();    // Propagate event
    }
}

void Expander::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        SplitterWidgetDecorator* parentSplitWidget{qobject_cast<SplitterWidgetDecorator*>(parentWidget())};
        if(parentSplitWidget == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
        Splitter* parentSplitter{qobject_cast<Splitter*>(parentSplitWidget->parentWidget())};
        if(parentSplitter == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 0 and event->y() > 0 and (size - event->x()) > event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentSplitWidget)};
            int newSize;
            if(-(event->x()) + (2 * size) < sizes[index])
            {
                newSize = -(event->x()) + size;
            }
            else
            {
                newSize = sizes[index] - size;
            }
            sizes[index] -= newSize;
            sizes.insert(index + 1, newSize - 1);
            parentSplitter->insertWidget(index + 1);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < size and event->y() > size and (size - event->x()) < event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentSplitWidget)};
            int newSize;
            if(event->y() + size < sizes[index])
            {
                newSize = event->y();
            }
            else
            {
                newSize = sizes[index] - size;
            }
            sizes[index] -= newSize;
            sizes.insert(index, newSize - 1);
            parentSplitter->insertWidget(index);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < size and event->y() > size and (size - event->x()) < event->y())
        {
            Splitter* newSplitter{new Splitter{parentSplitter->defaultWidget, Qt::Vertical}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
            newSplitter->addWidget();
            newSplitter->addSplitWidget(parentSplitWidget);
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (size - event->x()) > event->y())
        {
            Splitter* newSplitter{new Splitter{parentSplitter->defaultWidget, Qt::Horizontal}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
            newSplitter->addSplitWidget(parentSplitWidget);
            newSplitter->addWidget();
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() > size and event->y() > 0 and event->y() < parentSplitWidget->height())
        {
            if(overlay == nullptr)
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentSplitWidget) + 1)};
                overlay->show();
            }
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->y() < 0 and event->x() < size and -(event->x()) < parentSplitWidget->width() - size)
        {
            if(overlay == nullptr)
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentSplitWidget) - 1)};
                overlay->show();
            }
        }
        else if(overlay != nullptr)
        {
            delete overlay;
            overlay = nullptr;
        }
    }
}

void Expander::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        SplitterWidgetDecorator* parentSplitWidget{qobject_cast<SplitterWidgetDecorator*>(parentWidget())};
        if(parentSplitWidget == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
        Splitter* parentSplitter{qobject_cast<Splitter*>(parentSplitWidget->parentWidget())};
        if(parentSplitter == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() > size and event->y() > 0 and event->y() < parentSplitWidget->height())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentSplitWidget)};
            sizes[index] += sizes[index + 1] + 1;
            sizes.removeAt(index + 1);
            delete parentSplitter->widget(index + 1);
            if(parentSplitter->count() == 1 and parentSplitter->parentWidget()->inherits("SplitterDecorator"))
            {
                Splitter* newParent{qobject_cast<Splitter*>(parentSplitter->parentWidget()->parentWidget())};
                if(newParent == 0)
                {
                    std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
                    APPLICATION->exit(-1);
                }
                newParent->insertDecoratedWidget(newParent->indexOf(parentSplitter->parentWidget()), parentSplitWidget);
                delete parentSplitter->parentWidget();
            }
            else
            {
                parentSplitter->setSizes(sizes);
            }
            overlay = nullptr;
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->y() < 0 and event->x() < size and -(event->x()) < parentSplitWidget->width() - size)
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentSplitWidget)};
            sizes[index] += sizes[index - 1] + 1;
            sizes.removeAt(index - 1);
            delete parentSplitter->widget(index - 1);
            if(parentSplitter->count() == 1 and parentSplitter->parentWidget()->inherits("SplitterDecorator"))
            {
                Splitter* newParent{qobject_cast<Splitter*>(parentSplitter->parentWidget()->parentWidget())};
                if(newParent == 0)
                {
                    std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
                    APPLICATION->exit(-1);
                }
                newParent->insertDecoratedWidget(newParent->indexOf(parentSplitter->parentWidget()), parentSplitWidget);
                delete parentSplitter->parentWidget();
            }
            else
            {
                parentSplitter->setSizes(sizes);
             }
            overlay = nullptr;
        }
        releaseMouse();
    }
}
