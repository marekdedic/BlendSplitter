#include "include/QtSplitter/SplitterWidgetDecorator.hpp"

#include "include/QtSplitter/ExpanderBottom.hpp"
#include "include/QtSplitter/ExpanderTop.hpp"

SplitterWidgetDecorator::SplitterWidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expanderBottom{new ExpanderBottom{this}}, expanderTop{new ExpanderTop{this}}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(Expander::size, Expander::size);
}

void SplitterWidgetDecorator::resizeEvent(QResizeEvent*)
{
    expanderBottom->reposition();
    expanderTop->reposition();
}
