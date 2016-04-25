#include "include/BlendSplitter/WidgetDecorator.hpp"

#include "include/BlendSplitter/ExpanderBottom.hpp"
#include "include/BlendSplitter/ExpanderTop.hpp"

WidgetDecorator::WidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expanderBottom{new ExpanderBottom{this}}, expanderTop{new ExpanderTop{this}}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(Expander::size, Expander::size);
}

void WidgetDecorator::resizeEvent(QResizeEvent*)
{
    expanderBottom->reposition();
    expanderTop->reposition();
}
