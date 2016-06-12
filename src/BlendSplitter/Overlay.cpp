#include "include/implementation/Overlay.hpp"

Overlay::Overlay(QWidget* parent) : QLabel(parent)
{
    move(0, 0);
    reposition();
    setStyleSheet("background-color: rgba(0, 0, 0, 128);");
}

void Overlay::reposition()
{
    resize(parentWidget()->width(), parentWidget()->height());
    raise();
}
