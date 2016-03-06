#include "include/Expander.hpp"

#include "include/Splitter.hpp"

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pixmap{new QPixmap{filename}}
{
    *pixmap = pixmap->scaledToHeight(32, Qt::FastTransformation);
    setPixmap(*pixmap);
    resize(32, 32);
    reposition();
    QPolygon mask;
    mask << QPoint{0, 0} << QPoint{0, 3} << QPoint{29, 32} << QPoint{32, 32} << QPoint{32, 0};
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
        QLabel* inserted{new QLabel{"Inserted"}};
        try
        {
            SplitWidget* parentSplitWidget{dynamic_cast<SplitWidget*>(parentWidget())};
            Splitter* parentSplitter{dynamic_cast<Splitter*>(parentSplitWidget->parentWidget())};

            if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 0 and event->y() > 0 and (32 - event->x()) > event->y())
            {
                QList<int> sizes{parentSplitter->sizes()};
                int index{parentSplitter->indexOf(parentSplitWidget)};
                int newSize;
                if(-(event->x()) + 64 < sizes[index])
                {
                    newSize = -(event->x()) + 32;
                }
                else
                {
                    newSize = sizes[index] - 32;
                }
                sizes[index] -= newSize;
                sizes.insert(index + 1, newSize - 1);
                parentSplitter->insertWidget(index + 1, inserted);
                parentSplitter->setSizes(sizes);
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 32 and event->y() > 32 and (32 - event->x()) < event->y())
            {
                QList<int> sizes{parentSplitter->sizes()};
                int index{parentSplitter->indexOf(parentSplitWidget)};
                int newSize;
                if(event->y() + 32 < sizes[index])
                {
                    newSize = event->y();
                }
                else
                {
                    newSize = sizes[index] - 32;
                }
                sizes[index] -= newSize;
                sizes.insert(index, newSize - 1);
                parentSplitter->insertWidget(index, inserted);
                parentSplitter->setSizes(sizes);
            }
            else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 32 and event->y() > 32 and (32 - event->x()) < event->y())
            {
                Splitter* newSplitter{new Splitter{Qt::Vertical}};
                QList<int> sizes1{parentSplitter->sizes()};
                QList<int> sizes2{};
                if(event->y() + 32 < parentSplitWidget->height())
                {
                    sizes2.append(event->y());
                    sizes2.append(parentSplitWidget->height() - event->y() - 1);
                }
                else
                {
                    sizes2.append(parentSplitWidget->height() - 33);
                    sizes2.append(32);
                }
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addWidget(inserted);
                newSplitter->addSplitWidget(parentSplitWidget);
                parentSplitter->setSizes(sizes1);
                newSplitter->setSizes(sizes2);
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (32 - event->x()) > event->y())
            {
                Splitter* newSplitter{new Splitter{Qt::Horizontal}};
                QList<int> sizes1{parentSplitter->sizes()};
                QList<int> sizes2{};
                if(-(event->x()) + 64 < parentSplitWidget->width())
                {
                    sizes2.append(parentSplitWidget->width() + event->x() - 33);
                    sizes2.append(-(event->x()) + 32);
                }
                else
                {
                    sizes2.append(32);
                    sizes2.append(parentSplitWidget->width() - 33);
                }
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addSplitWidget(parentSplitWidget);
                newSplitter->addWidget(inserted);
                parentSplitter->setSizes(sizes1);
                newSplitter->setSizes(sizes2);
            }
            else if(parentSplitter->orientation() == Qt::Horizontal and event->x() > 32)
            {
                delete parentSplitter->widget(parentSplitter->indexOf(parentSplitWidget) + 1);
                if(parentSplitter->count() == 1 and parentSplitter != SPLITTER)
                {
                    Splitter* newParent{dynamic_cast<Splitter*>(parentSplitter->parentWidget())};
                    newParent->insertSplitWidget(newParent->indexOf(parentSplitter), parentSplitWidget);
                    delete parentSplitter;
                }
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->y() < 0)
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
