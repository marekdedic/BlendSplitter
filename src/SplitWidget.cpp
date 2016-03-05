#include "include/SplitWidget.hpp"

#include "include/Expander.hpp"

SplitWidget::SplitWidget(QWidget* widget) : QWidget{}, widget{widget}, expander{new Expander{":/UI/Splitter_expander", this}}, menuBar{nullptr}
{
    widget->setParent(this);
    setMinimumSize(40, 40);
    widget->installEventFilter(expander);
}

void SplitWidget::setMenuBar(QMenuBar *menuBar)
{
    this->menuBar = menuBar;
}

void SplitWidget::resizeEvent(QResizeEvent*)
{
    expander->reposition();
}
