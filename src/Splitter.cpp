#include "include/Splitter.hpp"

Splitter* Splitter::instance = nullptr;

Splitter::Splitter(QWidget* parent) : QSplitter{parent}
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
}

Splitter* Splitter::getInstance()
{
    if(instance == nullptr)
    {
        instance = new Splitter{};
    }
    return instance;
}

void Splitter::addWidget(QWidget* widget)
{
    SplitWidget* decorator{new SplitWidget{widget, getInstance()}};
    QSplitter::addWidget(decorator);
}

void Splitter::insertWidget(int index, QWidget* widget)
{
    //std::cerr << "inserted" << std::endl;
    SplitWidget* decorator{new SplitWidget{widget, getInstance()}};
    QSplitter::insertWidget(index, decorator);
}
