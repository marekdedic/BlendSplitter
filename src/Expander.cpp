#include "include/Expander.hpp"

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pixmap{new QPixmap{filename}}
{
    setPixmap(*pixmap);
    reposition();
}

void Expander::reposition()
{
    move(parentWidget()->width() - 128, 0);
}

void Expander::paintEvent(QPaintEvent * event)
{
    reposition();
    QLabel::paintEvent(event);
}
