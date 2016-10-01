#include "include/implementation/ExpanderTop.hpp"

#include "include/BlendSplitter.hpp"
#include "include/implementation/Overlay.hpp"
#include "include/implementation/WidgetDecorator.hpp"

ExpanderTop::ExpanderTop(WidgetDecorator* parent) : Expander(parent)
{
    QPolygon mask;
    mask << QPoint{0, 0} << QPoint{0, BlendSplitter::expanderSize/10} << QPoint{BlendSplitter::expanderSize * 9 / 10, BlendSplitter::expanderSize} << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize} << QPoint{BlendSplitter::expanderSize, 0};
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
            qCritical("A BlendSplitter library error occurred. Error code: 4");
            return;
        }
        BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(parentDecorator->parentWidget())};
        if(parentSplitter == 0)
        {
            qCritical("A BlendSplitter library error occurred. Error code: 5");
            return;
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 0 and event->y() > 0 and (BlendSplitter::expanderSize - event->x()) > event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes.insert(index + 1, BlendSplitter::expanderSize);
            sizes[index] -= BlendSplitter::expanderSize + 1;
            parentSplitter->insertWidget(index + 1);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < BlendSplitter::expanderSize and event->y() > BlendSplitter::expanderSize and (BlendSplitter::expanderSize - event->x()) < event->y())
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes[index] -= BlendSplitter::expanderSize + 1;
            sizes.insert(index, BlendSplitter::expanderSize);
            parentSplitter->insertWidget(index);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < BlendSplitter::expanderSize and event->y() > BlendSplitter::expanderSize and (BlendSplitter::expanderSize - event->x()) < event->y())
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Vertical}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addWidget();
            newSplitter->addDecoratedWidget(parentDecorator);
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (BlendSplitter::expanderSize - event->x()) > event->y())
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Horizontal}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addDecoratedWidget(parentDecorator);
            newSplitter->addWidget();
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        if(parentSplitter->orientation() == Qt::Horizontal and event->x() > BlendSplitter::expanderSize and event->y() > 0 and event->y() < parentDecorator->height())
        {
            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) + 1 < parentSplitter->count())
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) + 1)};
                overlay->show();
            }
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < BlendSplitter::expanderSize and event->y() < 0 and (BlendSplitter::expanderSize - event->x()) < parentDecorator->width())
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
