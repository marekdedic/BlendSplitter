#include "include/Expander.hpp"

#include "include/Splitter.hpp"

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pressed{false}, pixmap{new QPixmap{filename}}
{
    *pixmap = pixmap->scaledToHeight(32, Qt::FastTransformation);
    setPixmap(*pixmap);
    resize(32, 32);
    reposition();
}

void Expander::reposition()
{
    move(parentWidget()->width() - width(), 0);
}

void Expander::mousePressEvent(QMouseEvent* event)
{
    if(event->x() >= event->y())
    {
        pressed = true;
    }
}

void Expander::mouseReleaseEvent(QMouseEvent* event)
{
    if(pressed and event->button() == Qt::LeftButton)
    {
        //std::cerr << "Release at: " << event->x() << ", " << event->y() << std::endl;
        pressed = false;
        QLabel* inserted{new QLabel{"Inserted"}};
        try
        {
            SplitWidget* parentSplitWidget{dynamic_cast<SplitWidget*>(parentWidget())};
            Splitter* parentSplitter{dynamic_cast<Splitter*>(parentSplitWidget->parentWidget())};

            if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 0 and event->y() > 0 and (32 - event->x()) > event->y())
            {
                parentSplitter->insertWidget(parentSplitter->indexOf(parentSplitWidget) + 1, inserted);
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 32 and event->y() > 32 and (32 - event->x()) < event->y())
            {
                parentSplitter->insertWidget(parentSplitter->indexOf(parentSplitWidget), inserted);
            }
            else if(parentSplitter->orientation() == Qt::Horizontal and event->x() < 32 and event->y() > 32 and (32 - event->x()) < event->y())
            {
                Splitter* newSplitter{new Splitter{Qt::Vertical}};
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addWidget(inserted);
                newSplitter->addSplitWidget(parentSplitWidget);
            }
            else if(parentSplitter->orientation() == Qt::Vertical and event->x() < 0 and event->y() > 0 and (32 - event->x()) > event->y())
            {
                Splitter* newSplitter{new Splitter{Qt::Horizontal}};
                parentSplitter->insertSplitter(parentSplitter->indexOf(parentSplitWidget), newSplitter);
                newSplitter->addSplitWidget(parentSplitWidget);
                newSplitter->addWidget(inserted);
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
        }
        catch(std::bad_cast& exception)
        {
            std::cerr << exception.what() << " caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            APPLICATION->exit(-1);
        }
    }
}
