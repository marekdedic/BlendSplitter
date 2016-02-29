#include "include/Expander.hpp"

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
    std::cerr << "Release at: " << event->x() << ", " << event->y() << std::endl;
}
