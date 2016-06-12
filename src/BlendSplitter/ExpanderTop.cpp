#include "include/implementation/ExpanderTop.hpp"

#include "include/BlendSplitter.hpp"
#include "include/implementation/Overlay.hpp"
#include "include/implementation/WidgetDecorator.hpp"

ExpanderTop::ExpanderTop(WidgetDecorator* parent) : Expander(parent)
{
    QPolygon mask;
    mask << QPoint{0, 0} << QPoint{0, size/10} << QPoint{size * 9 / 10, size} << QPoint{size, size} << QPoint{size, 0};
    setMask(QRegion{mask});
}

void ExpanderTop::reposition()
{
    move(parentWidget()->width() - width(), 0);
    Expander::reposition();
}

void ExpanderTop::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        WidgetDecorator* parentDecorator{qobject_cast<WidgetDecorator*>(parentWidget())};
        if(parentDecorator == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(parentDecorator->parentWidget())};
        if(parentSplitter == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 0 and event->y() > 0 and (size - event->x()) > event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes.insert(index + 1, size);
            sizes[index] -= size + 1;
            parentSplitter->insertWidget(index + 1);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < size and event->y() > size and (size - event->x()) < event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes[index] -= size + 1;
            sizes.insert(index, size);
            parentSplitter->insertWidget(index);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < size and event->y() > size and (size - event->x()) < event->y())
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Vertical}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addWidget();
            newSplitter->addDecoratedWidget(parentDecorator);
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (size - event->x()) > event->y())
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Horizontal}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addDecoratedWidget(parentDecorator);
            newSplitter->addWidget();
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() > size and event->y() > 0 and event->y() < parentDecorator->height())
        {
            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) + 1 < parentSplitter->count())
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) + 1)};
                overlay->show();
            }
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < size and event->y() < 0 and (size - event->x()) < parentDecorator->width())
        {
            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) > 0)
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) - 1)};
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
