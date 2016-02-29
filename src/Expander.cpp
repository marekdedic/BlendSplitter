#include "include/Expander.hpp"

Expander::Expander(QString filename, SplitWidget* parent) : QLabel(parent), pixmap{new QPixmap{filename}}
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
