#include "include/SplitterDecorator.hpp"

SplitterDecorator::SplitterDecorator(Splitter* splitter) : QWidget{}, splitter{splitter}
{
    QHBoxLayout *layout = new QHBoxLayout{};
    layout->addWidget(splitter);
    layout->setMargin(0);
    setLayout(layout);
}

SplitterDecorator::SplitterDecorator(const SplitterDecorator& other) : SplitterDecorator(new Splitter{*(other.splitter)}) {}
