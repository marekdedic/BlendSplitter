#include "include/Splitter.hpp"

Splitter::Splitter(Qt::Orientation orientation) : QSplitter{orientation}
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
}

void Splitter::addWidget(QWidget* widget)
{
    insertWidget(-1, widget);
}

void Splitter::addSplitWidget(SplitWidget* widget)
{
    insertSplitWidget(-1, widget);
}

void Splitter::insertWidget(int index, QWidget* widget)
{
    SplitWidget* decorator{new SplitWidget{widget}};
    QSplitter::insertWidget(index, decorator);
}

void Splitter::insertSplitWidget(int index, SplitWidget* widget)
{
    QSplitter::insertWidget(index, widget);
}

void Splitter::insertSplitter(int index, Splitter* splitter)
{
    QSplitter::insertWidget(index, splitter);
}
