#include "include/QtSplitter/SplitterWidgetDecorator.hpp"

#include "include/QtSplitter/ExpanderTop.hpp"

SplitterWidgetDecorator::SplitterWidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expander{new ExpanderTop{this}}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(ExpanderTop::size, ExpanderTop::size);
}

void SplitterWidgetDecorator::resizeEvent(QResizeEvent*)
{
    expander->reposition();
}
