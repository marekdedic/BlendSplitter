#include "include/Expander.hpp"

#include "include/Splitter.hpp"

int Expander::size = 32;

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pixmap{new QPixmap{filename}}
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
}

bool Expander::eventFilter(QObject*, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if(mask().contains(mouseEvent->pos() - geometry().topLeft()))
        {
            grabMouse();
            mousePressEvent(mouseEvent);
            return true;
        }
    }
    return false;
}

void Expander::mousePressEvent(QMouseEvent* event)
{
    event->accept();    // No-op
}

void Expander::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        try
        {
            SplitWidget* parentSplitWidget{dynamic_cast<SplitWidget*>(parentWidget())};
            Splitter* parentSplitter{dynamic_cast<Splitter*>(parentSplitWidget->parentWidget())};
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
            }
            else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < size and event->y() > size and (size - event->x()) < event->y())
            {
                Splitter* newSplitter{new Splitter{parentSplitter->defaultWidget, Qt::Vertical}};
                QList<int> sizes1{parentSplitter->sizes()};
                QList<int> sizes2{};
                if(event->y() + size < parentSplitWidget->height())
                {
                    sizes2.append(event->y());
                    sizes2.append(parentSplitWidget->height() - event->y() - 1);
                }
                else
                {
                    sizes2.append(parentSplitWidget->height() - size - 1);
                    sizes2.append(size);
                }
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addWidget();
                newSplitter->addSplitWidget(parentSplitWidget);
                parentSplitter->setSizes(sizes1);
                newSplitter->setSizes(sizes2);
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (size - event->x()) > event->y())
            {
                Splitter* newSplitter{new Splitter{parentSplitter->defaultWidget, Qt::Horizontal}};
                QList<int> sizes1{parentSplitter->sizes()};
                QList<int> sizes2{};
                if(-(event->x()) + (2 * size) < parentSplitWidget->width())
                {
                    sizes2.append(parentSplitWidget->width() + event->x() - size - 1);
                    sizes2.append(-(event->x()) + size);
                }
                else
                {
                    sizes2.append(size);
                    sizes2.append(parentSplitWidget->width() - size - 1);
                }
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addSplitWidget(parentSplitWidget);
                newSplitter->addWidget();
                parentSplitter->setSizes(sizes1);
                newSplitter->setSizes(sizes2);
            }
            else if(parentSplitter->orientation() == Qt::Horizontal and event->x() > size and event->y() > 0 and event->y() < parentSplitWidget->height())
            {
                delete parentSplitter->widget(parentSplitter->indexOf(parentSplitWidget) + 1);
                if(parentSplitter->count() == 1 and parentSplitter != SPLITTER)
                {
                    Splitter* newParent{dynamic_cast<Splitter*>(parentSplitter->parentWidget())};
                    newParent->insertSplitWidget(newParent->indexOf(parentSplitter), parentSplitWidget);
                    delete parentSplitter;
                }
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->y() < 0 and event->x() < size and -(event->x()) < parentSplitWidget->width() - size)
            {
                delete parentSplitter->widget(parentSplitter->indexOf(parentSplitWidget) - 1);
                if(parentSplitter->count() == 1 and parentSplitter != SPLITTER)
                {
                    Splitter* newParent{dynamic_cast<Splitter*>(parentSplitter->parentWidget())};
                    newParent->insertSplitWidget(newParent->indexOf(parentSplitter), parentSplitWidget);
                    delete parentSplitter;
                }
            }
            releaseMouse();
        }
        catch(std::bad_cast& exception)
        {
            std::cerr << exception.what() << " caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
    }
}
