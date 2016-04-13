#include "include/SplitWidget.hpp"

#include "include/Expander.hpp"
#include "include/Overlay.hpp"

SplitWidget::SplitWidget(QWidget* widget) : QWidget{}, widget{widget}, expander{new Expander{":/UI/Splitter_expander", this}}
{
    widget->setParent(this);
    setMinimumSize(Expander::size, Expander::size);
}

void SplitWidget::resizeEvent(QResizeEvent*)
{
    expander->reposition();
}
