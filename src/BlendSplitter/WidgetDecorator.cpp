#include "include/implementation/WidgetDecorator.hpp"

#include "include/BlendSplitter.hpp"
#include "include/implementation/ExpanderBottom.hpp"
#include "include/implementation/ExpanderTop.hpp"

WidgetDecorator::WidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expanderBottom{new ExpanderBottom{this}}, expanderTop{new ExpanderTop{this}}
{
    QHBoxLayout* layout{new QHBoxLayout{}};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(2 * BlendSplitter::expanderSize, 2 * BlendSplitter::expanderSize);
}

void WidgetDecorator::resizeEvent(QResizeEvent*)
{
    expanderBottom->reposition();
    expanderTop->reposition();
}
