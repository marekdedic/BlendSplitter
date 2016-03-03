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
        if(event->x() < 0 and event->y() > 0 and (-event->x()) > event->y())
        {
                QLabel* inserted{new QLabel{"Inserted"}};
                try
                {
                    Splitter* parentSplitter = dynamic_cast<Splitter*>(parentWidget()->parentWidget());
                    parentSplitter->insertWidget(parentSplitter->indexOf(parentWidget()) + 1, inserted);
                }
                catch(std::bad_cast& exception)
                {
                    std::cerr << exception.what() << " caused by having an expander not properly inside a Splitter." << std::endl;
                    // TODO: move to main, terminate application, probably using own exception.
                }
        }
    }
}
