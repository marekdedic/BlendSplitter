#include "include/Expander.hpp"

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pixmap{new QPixmap{filename}}
{
    setPixmap(*pixmap);
    move(parent->width(), 0);
    //setGeometry(50, 50, 50, 50);
}
