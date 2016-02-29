#include "include/SplitWidget.hpp"

#include "include/Expander.hpp"

SplitWidget::SplitWidget(QWidget* widget, QWidget* parent) : QWidget{parent}, widget{widget}, expander{new Expander{":/UI/Splitter_expander", this}}, menuBar{nullptr}
{
    widget->setParent(this);
    setMinimumSize(40, 40);
}

void SplitWidget::setMenuBar(QMenuBar *menuBar)
{
    this->menuBar = menuBar;
}

void SplitWidget::resizeEvent(QResizeEvent*)
{
    expander->reposition();
}
