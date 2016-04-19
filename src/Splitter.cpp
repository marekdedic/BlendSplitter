#include "include/Splitter.hpp"

Splitter::Splitter(QWidget* (*defaultWidget) (), Qt::Orientation orientation) : QSplitter{orientation, nullptr}, defaultWidget{defaultWidget}
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

void Splitter::addSplitWidget(SplitterWidgetDecorator* widget)
{
    insertDecoratedWidget(-1, widget);
}

void Splitter::insertWidget(int index)
{
    insertWidget(index, (*defaultWidget) ());
}

void Splitter::insertWidget(int index, QWidget* widget)
{
    SplitterWidgetDecorator* decorator{new SplitterWidgetDecorator{widget}};
    QSplitter::insertWidget(index, decorator);
}

void Splitter::insertDecoratedWidget(int index, SplitterWidgetDecorator* widget)
{
    QSplitter::insertWidget(index, widget);
}

void Splitter::insertSplitter(int index, Splitter* splitter)
{
    SplitterDecorator* decorator{new SplitterDecorator{splitter}};
    QSplitter::insertWidget(index, decorator);
}

QSplitterHandle* Splitter::createHandle()
{
    return new SplitterHandle(orientation(), this);
}
