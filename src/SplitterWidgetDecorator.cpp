#include "include/SplitterWidgetDecorator.hpp"

#include "include/Expander.hpp"
#include "include/Overlay.hpp"

SplitterWidgetDecorator::SplitterWidgetDecorator(QWidget* widget) : QWidget{}, widget{widget}, expander{new Expander{":/UI/Splitter_expander", this}}
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
