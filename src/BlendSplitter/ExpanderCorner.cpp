#include "include/implementation/ExpanderCorner.hpp"

#include "include/BlendSplitter.hpp"
#include "include/implementation/Overlay.hpp"
#include "include/implementation/WidgetDecorator.hpp"

#include <QDebug>

ExpanderCorner::ExpanderCorner(WidgetDecorator* parent,Qt::Corner location) : Expander{parent} ,
    corner{location},unitX{1},unitY{1},hotspotX{0},hotspotY{0},dragaction{undecidedDrag},
    dragorientation(Qt::Horizontal)
{
    //now do some masking and pixmap rotating depending on location
    //also set out unit steps
    QPolygon mask;
    switch (location) {
    case Qt::TopLeftCorner: {
        QTransform rot;
        *pixmap = pixmap->transformed(rot.rotate(-90), Qt::FastTransformation);
        setPixmap(*pixmap);
        mask << QPoint{BlendSplitter::expanderSize, 0}
             << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize/10}
             << QPoint{BlendSplitter::expanderSize / 10, BlendSplitter::expanderSize}
             << QPoint{0, BlendSplitter::expanderSize}
             << QPoint{0, 0};
//        unitX=1;
//        unitY=1;
            };
        break;
    case Qt::TopRightCorner: {
        QTransform rot;
        *pixmap = pixmap->transformed(rot.rotate(0), Qt::FastTransformation);
        setPixmap(*pixmap);
        mask << QPoint{0, 0}
             << QPoint{0, BlendSplitter::expanderSize/10}
             << QPoint{BlendSplitter::expanderSize * 9 / 10, BlendSplitter::expanderSize}
             << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize}
             << QPoint{BlendSplitter::expanderSize, 0};
        unitX=-1;
//        unitY=1;
        hotspotX=BlendSplitter::expanderSize-1;
        };
        break;
    case Qt::BottomLeftCorner: {
        QTransform rot;
        *pixmap = pixmap->transformed(rot.rotate(180), Qt::FastTransformation);
        setPixmap(*pixmap);
        mask << QPoint{0, 0}
             << QPoint{BlendSplitter::expanderSize/10, 0}
             << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize * 9 / 10}
             << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize}
             << QPoint{0, BlendSplitter::expanderSize};
//        unitX=1;
        unitY=-1;
        hotspotY=BlendSplitter::expanderSize-1;
        };
        break;
    case Qt::BottomRightCorner: {
        QTransform rot;
        *pixmap = pixmap->transformed(rot.rotate(90), Qt::FastTransformation);
        setPixmap(*pixmap);
        mask << QPoint{BlendSplitter::expanderSize, 0}
             << QPoint{BlendSplitter::expanderSize * 9 /10, 0}
             << QPoint{0, BlendSplitter::expanderSize * 9 / 10}
             << QPoint{0, BlendSplitter::expanderSize}
             << QPoint{BlendSplitter::expanderSize, BlendSplitter::expanderSize};
        };
        unitX=-1;
        unitY=-1;
        hotspotX=BlendSplitter::expanderSize-1;
        hotspotY=BlendSplitter::expanderSize-1;
    default:
        break;

    }
    setMask(QRegion{mask});
}

void ExpanderCorner::reposition()
{
    switch (corner) {
    case Qt::TopLeftCorner:
        move(0, 0);
        break;
    case Qt::TopRightCorner:
        move(parentWidget()->width() - width(), 0);
        break;
    case Qt::BottomLeftCorner:
        move(parentWidget()->width() - width(), parentWidget()->height()-height());
        break;
    case Qt::BottomRightCorner:
        move(parentWidget()->width() - width(), parentWidget()->height()-height());
        break;
    default:
        break;
    }
    raise();
}

/**
 * @brief ExpanderCorner::performInnerSplit
 * @param parentDecorator
 * @param parentSplitter
 * @param splitorientation
 *
 * This will split the widget.
 * If the orientation of the split corresponds to the splitter we simply add an item
 * If the orietation is orthogonal we replace the widget with a new splitter and have the widget added to the new splitter
 */
void ExpanderCorner::performInnerSplit(WidgetDecorator* parentDecorator, BlendSplitter* parentSplitter, Qt::Orientation splitorientation)
{
    if (parentSplitter->orientation() == splitorientation){
        // add a widget in current splitter
        bool after;
        if (parentSplitter->orientation()==Qt::Horizontal){
            after=unitX>0;
        } else {
            after=unitY>0;
        }

        QList<int> sizes{parentSplitter->sizes()};
        int index{parentSplitter->indexOf(parentDecorator)};
        if (after){
            sizes.insert(index, BlendSplitter::expanderSize);
            sizes[index + 1] -= BlendSplitter::expanderSize + 1;
            parentSplitter->insertWidget(index);
        } else {
            sizes.insert(index +1, BlendSplitter::expanderSize);
            sizes[index] -= BlendSplitter::expanderSize + 1;
            parentSplitter->insertWidget(index+1);
        }
        parentSplitter->setSizes(sizes);
        parentSplitter->handle(index + 1)->grabMouse();
    } else {
        //add a new splitter orthogonal to the current one
        Qt::Orientation newOrientation{parentSplitter->orientation()==Qt::Horizontal?Qt::Vertical:Qt::Horizontal};
        BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, newOrientation}};
        QList<int> sizes{parentSplitter->sizes()};
        parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
        // add a widget in current splitter but on the right side
        bool after;
        if (newOrientation==Qt::Horizontal){
            after=unitX>0;
        } else {
            after=unitY>0;
        };
        if (after){
            newSplitter->addWidget();
            newSplitter->addDecoratedWidget(parentDecorator);
        } else {
            newSplitter->addDecoratedWidget(parentDecorator);
            newSplitter->addWidget();
        }
        parentSplitter->setSizes(sizes);
        newSplitter->handle(1)->grabMouse();
   }
}

void ExpanderCorner::setupJoiners(WidgetDecorator *parentDecorator, BlendSplitter *parentSplitter, int x, int y, Qt::Orientation /*splitorientation*/)
{
    bool after;
    if (parentSplitter->orientation()==Qt::Horizontal){
        after=unitX>0;
    } else {
        after=unitY>0;
    }


    if(overlay == nullptr && (
                (   parentSplitter->orientation() == Qt::Horizontal and
                    pos().y()+y > 0 and
                    pos().y()+y < parentDecorator->height()
                    )
                or
                (   parentSplitter->orientation() == Qt::Vertical and
                    pos().x()+x > 0 and
                    pos().x()+x < parentDecorator->width()
                    )
                )
            )
    {
        if( !after and
                parentSplitter->indexOf(parentDecorator) + 1 < parentSplitter->count())
        {
            overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) + 1),
                    (parentSplitter->orientation()==Qt::Horizontal?Qt::RightArrow:Qt::DownArrow)};
            overlay->show();
            dragaction=joinDrag;
        }
        else if (after and
                 parentSplitter->indexOf(parentDecorator) > 0)
        {
            overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) - 1),
            (parentSplitter->orientation()==Qt::Horizontal?Qt::LeftArrow:Qt::UpArrow)};
            overlay->show();
            dragaction=joinDrag;
        }

    }
}

/**
 * @brief ExpanderCorner::decideDragAction
 * @param event
 *
 *If a drag is just started this function helps determine if we drag inwards
 *our outward and if it is a horizontal or vertical drag.
 */
void ExpanderCorner::decideDragAction(QMouseEvent *event, WidgetDecorator* parentDecorator, BlendSplitter* parentSplitter)
{
    int x=event->x()-hotspotX;
    int y=event->y()-hotspotY;

    if (abs(x) < BlendSplitter::expanderSize and abs(y) < BlendSplitter::expanderSize ){
        return;
    };

    // we dragged far enough
    dragorientation= (abs(x) > abs(y)) ? Qt::Horizontal : Qt::Vertical ;

    // but did we drag inwards?
    // (and als prefent splitting if widget already too small!)
    if ( x*unitX >0 and y*unitY>0 and (
             (dragorientation==Qt::Horizontal and parentDecorator->width()>2*BlendSplitter::expanderSize) or
             (dragorientation==Qt::Vertical and parentDecorator->height()>2*BlendSplitter::expanderSize))
         )
        {
            dragaction=splitDrag; // we dragged inwards
            performInnerSplit(parentDecorator,parentSplitter,dragorientation);
    }
    // do we join widgets together?
    else if (dragorientation == parentSplitter->orientation()){
        setupJoiners(parentDecorator,parentSplitter,x,y,dragorientation);
    } else {
        //here we could start a relocationdrag....
    }
}

void ExpanderCorner::mouseMoveEvent(QMouseEvent *event)
{
    if( !(event->buttons() & Qt::LeftButton)){
        return;
    }

    //get our parentdecorator and our immediate blendSplitter
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

    switch (dragaction) {
    case undecidedDrag:
        decideDragAction(event,parentDecorator,parentSplitter);
        break;
    case joinDrag:
    {
        int x=event->x()-hotspotX;
        int y=event->y()-hotspotY;
        setupJoiners(parentDecorator,parentSplitter,x,y,(abs(x) > abs(y)) ? Qt::Horizontal : Qt::Vertical);
    };
        break;
    case splitDrag:
    default:
        break;
    }
//        if(parentSplitter->orientation() == Qt::Horizontal
//                and event->x() < 0 and event->y() > 0
//                and (BlendSplitter::expanderSize - event->x()) > event->y())
//        {
//            QList<int> sizes{parentSplitter->sizes()};
//            int index{parentSplitter->indexOf(parentDecorator)};
//            sizes.insert(index + 1, BlendSplitter::expanderSize);
//            sizes[index] -= BlendSplitter::expanderSize + 1;
//            parentSplitter->insertWidget(index + 1);
//            parentSplitter->setSizes(sizes);
//            parentSplitter->handle(index + 1)->grabMouse();
//        }
//        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < BlendSplitter::expanderSize and event->y() > BlendSplitter::expanderSize and (BlendSplitter::expanderSize - event->x()) < event->y())
//        {
//            QList<int> sizes{parentSplitter->sizes()};
//            int index{parentSplitter->indexOf(parentDecorator)};
//            sizes[index] -= BlendSplitter::expanderSize + 1;
//            sizes.insert(index, BlendSplitter::expanderSize);
//            parentSplitter->insertWidget(index);
//            parentSplitter->setSizes(sizes);
//            parentSplitter->handle(index + 1)->grabMouse();
//        }
//        else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < BlendSplitter::expanderSize and event->y() > BlendSplitter::expanderSize and (BlendSplitter::expanderSize - event->x()) < event->y())
//        {
//            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Vertical}};
//            QList<int> sizes{parentSplitter->sizes()};
//            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
//            newSplitter->addWidget();
//            newSplitter->addDecoratedWidget(parentDecorator);
//            parentSplitter->setSizes(sizes);
//            newSplitter->handle(1)->grabMouse();
//        }
//        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (BlendSplitter::expanderSize - event->x()) > event->y())
//        {
//            BlendSplitter* newSplitter{new BlendSplitter{parentSplitter->defaultWidget, Qt::Horizontal}};
//            QList<int> sizes{parentSplitter->sizes()};
//            parentSplitter->insertSplitter(parentSplitter->indexOf(parentDecorator), newSplitter);
//            newSplitter->addDecoratedWidget(parentDecorator);
//            newSplitter->addWidget();
//            parentSplitter->setSizes(sizes);
//            newSplitter->handle(1)->grabMouse();
//        }
//        if(parentSplitter->orientation() == Qt::Horizontal and event->x() > BlendSplitter::expanderSize and event->y() > 0 and event->y() < parentDecorator->height())
//        {
//            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) + 1 < parentSplitter->count())
//            {
//                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) + 1),Qt::RightArrow};
//                overlay->show();
//            }
//        }
//        else if(parentSplitter->orientation() == Qt::Vertical and event->x() < BlendSplitter::expanderSize and event->y() < 0 and (BlendSplitter::expanderSize - event->x()) < parentDecorator->width())
//        {
//            if(overlay == nullptr and parentSplitter->indexOf(parentDecorator) > 0)
//            {
//                overlay = new Overlay{parentSplitter->widget(parentSplitter->indexOf(parentDecorator) - 1),Qt::UpArrow};
//                overlay->show();
//            }
//        }
//        else if(overlay != nullptr)
//        {
//            delete overlay;
//            overlay = nullptr;
//        }
}

void ExpanderCorner::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragaction=undecidedDrag; //start of drag
        event->accept();    // No-op
    }
    else
    {
        releaseMouse();
        event->ignore();    // Propagate event
    }
}

void ExpanderCorner::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton or overlay == nullptr){
        return;
    };
    //correct button and we have an overlay, so continue...

    //first get our decorator and the parent blendSplitter
    WidgetDecorator* parentDecorator{qobject_cast<WidgetDecorator*>(parentWidget())};
    if(parentDecorator == 0)
    {
        qCritical("A BlendSplitter library error occurred. Error code: 1");
        return;
    }
    BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(overlay->parentWidget()->parentWidget())};
    if(parentSplitter == 0)
    {
        qCritical("A BlendSplitter library error occurred. Error code: 2");
        return;
    }


    //now delete the item with the overlay from the splitter
    QList<int> sizes{parentSplitter->sizes()};
    int parentIndex{parentSplitter->indexOf(parentDecorator)};
    int overlayIndex{parentSplitter->indexOf(overlay->parentWidget())};
    sizes[parentIndex] += sizes[overlayIndex] + 1;
    sizes.removeAt(overlayIndex);
    delete parentSplitter->widget(overlayIndex);
    overlay = nullptr;


    //if we now have a blendSplitter with a single item, which is inside another blendSplitter then we remove this singular-item splitter
    if(parentSplitter->count() == 1 and parentSplitter->parentWidget()->inherits("SplitterDecorator"))
    {
        BlendSplitter* newParent{qobject_cast<BlendSplitter*>(parentSplitter->parentWidget()->parentWidget())};
        if(newParent == nullptr)
        {
            qCritical("A BlendSplitter library error occurred. Error code: 3");
            return;
        }
        QList<int> sizes2{newParent->sizes()};
        newParent->insertDecoratedWidget(newParent->indexOf(parentSplitter->parentWidget()), parentDecorator);
        delete parentSplitter->parentWidget();
        newParent->setSizes(sizes2);
    }
    else
    {
        parentSplitter->setSizes(sizes);
    }

}
