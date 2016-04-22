#include "include/QtSplitter/SplitterWidgetDecorator.hpp"

#include "include/QtSplitter/Expander.hpp"

SplitterWidgetDecorator::SplitterWidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expander{new Expander{this}}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(widget);
    layout->setMargin(0);
    setLayout(layout);
    setMinimumSize(Expander::size, Expander::size);
}

void SplitterWidgetDecorator::resizeEvent(QResizeEvent*)
{
    expander->reposition();
}
