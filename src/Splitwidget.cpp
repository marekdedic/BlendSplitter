#include "include/Splitwidget.hpp"

SplitWidget::SplitWidget(QWidget* parent) : QFrame{parent}, component{nullptr}, menuBar{nullptr}
{
    setFrameStyle(QFrame::Panel);
    setLineWidth(1);
    setMinimumSize(40, 40);
}

void SplitWidget::setComponent(QWidget *component)
{
    this->component = component;
}

void SplitWidget::setMenuBar(QMenuBar *menuBar)
{
    this->menuBar = menuBar;
}
