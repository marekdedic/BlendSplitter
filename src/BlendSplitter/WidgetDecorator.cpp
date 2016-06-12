#include "include/implementation/WidgetDecorator.hpp"

#include "include/implementation/ExpanderBottom.hpp"
#include "include/implementation/ExpanderTop.hpp"

WidgetDecorator::WidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expanderBottom{new ExpanderBottom{this}}, expanderTop{new ExpanderTop{this}}
{
    QHBoxLayout* layout{new QHBoxLayout{}};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(2 * Expander::size, 2 * Expander::size);
}

void WidgetDecorator::resizeEvent(QResizeEvent*)
{
    expanderBottom->reposition();
    expanderTop->reposition();
}
