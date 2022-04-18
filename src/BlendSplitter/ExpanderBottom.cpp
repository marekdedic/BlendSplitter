#include "include/implementation/ExpanderBottom.hpp"

#include "include/BlendSplitter.hpp"
#include "include/implementation/Overlay.hpp"
#include "include/implementation/WidgetDecorator.hpp"

ExpanderBottom::ExpanderBottom(WidgetDecorator* parent) : Expander(parent)
{
    QTransform rot;
    *pixmap = pixmap->transformed(rot.rotate(180), Qt::FastTransformation);
    setPixmap(*pixmap);
    QPolygon mask;
    mask << QPoint{0, 0} << QPoint{BlendSplitter::expanderSize/10, 0} << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize * 9 / 10} << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize} << QPoint{0, BlendSplitter::expanderSize};
    setMask(QRegion{mask});
}

void ExpanderBottom::reposition()
{
    move(0, parentWidget()->height() - height());
    Expander::reposition();
}

void ExpanderBottom::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        WidgetDecorator* parentDecorator{qobject_cast<WidgetDecorator*>(parentWidget())};
        if(parentDecorator == nullptr)
        {
            qCritical("A BlendSplitter library error occurred. Error code: 6");
            return;
        }
        BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(parentDecorator->parentWidget())};
        if(parentSplitter == nullptr)
        {
            qCritical("A BlendSplitter library error occurred. Error code: 7");
            return;
        }
        if(parentSplitter->orientation() == Qt::Horizontal and
                event->x() > BlendSplitter::expanderSize and
                event->y() < BlendSplitter::expanderSize and
                event->x() > (BlendSplitter::expanderSize - event->y()))
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes.insert(index, BlendSplitter::expanderSize);
            sizes[index + 1] -= BlendSplitter::expanderSize + 1;
            parentSplitter->insertWidget(index);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and
                event->x() > 0 and event->y() < 0 and
                event->x() < (BlendSplitter::expanderSize - event->y()))
        {
            QList<int> sizes{parentSplitter->sizes()};
            int index{parentSplitter->indexOf(parentDecorator)};
            sizes[index] -= BlendSplitter::expanderSize + 1;
            sizes.insert(index + 1, BlendSplitter::expanderSize);
            parentSplitter->insertWidget(index + 1);
            parentSplitter->setSizes(sizes);
            parentSplitter->handle(index + 1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Horizontal and event->x() > 0 and event->y() < 0 and event->x() < (BlendSplitter::expanderSize - event->y()))
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Vertical}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addDecoratedWidget(parentDecorator);
            newSplitter->addWidget();
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }
        else if(parentSplitter->orientation() == Qt::Vertical and event->x() > BlendSplitter::expanderSize and event->y() < BlendSplitter::expanderSize and event->x() > (BlendSplitter::expanderSize - event->y()))
        {
            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Horizontal}};
            QList<int> sizes{parentSplitter->sizes()};
            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
            newSplitter->addWidget();
            newSplitter->addDecoratedWidget(parentDecorator);
            parentSplitter->setSizes(sizes);
            newSplitter->handle(1)->grabMouse();
        }




        if(parentSplitter->orientation() == Qt::Horizontal and
                event->x() < 0 and
                event->y() < BlendSplitter::expanderSize and
                (BlendSplitter::expanderSize - event->y()) < parentDecorator->height())
        {
            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) > 0)
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) - 1),Qt::LeftArrow};
                overlay->show();
            }
        }
        else if(parentSplitter->orientation() == Qt::Vertical and
                event->x() > 0 and
                event->y() > BlendSplitter::expanderSize and
                event->x() < parentDecorator->width())
        {
            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) + 1 < parentSplitter->count())
            {
                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) + 1),Qt::DownArrow};
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
