#include "include/Splitter.hpp"

Splitter::Splitter(QWidget* (*defaultWidget) (), Qt::Orientation orientation) : QSplitter{orientation}, defaultWidget{defaultWidget}
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: black;}");
}

void Splitter::addWidget()
{
    addWidget((*defaultWidget) ());
}

void Splitter::addWidget(QWidget* widget)
{
    insertWidget(-1, widget);
}

void Splitter::addSplitWidget(SplitWidget* widget)
{
    insertSplitWidget(-1, widget);
}

void Splitter::insertWidget(int index)
{
    insertWidget(index, (*defaultWidget) ());
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

QSplitterHandle* Splitter::createHandle()
{
    return new SplitterHandle(orientation(), this);
}
