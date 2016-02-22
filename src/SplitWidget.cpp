#include "include/SplitWidget.hpp"

SplitWidget::SplitWidget(QWidget* parent) : QWidget{parent}, menuBar{nullptr}
{
    setMinimumSize(40, 40);
}

void SplitWidget::setMenuBar(QMenuBar *menuBar)
{
    this->menuBar = menuBar;
}
