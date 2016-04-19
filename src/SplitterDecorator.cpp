#include "include/SplitterDecorator.hpp"

SplitterDecorator::SplitterDecorator(Splitter* splitter) : QFrame{}, splitter{splitter}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(splitter);
    layout->setMargin(0);
    setLayout(layout);
}
