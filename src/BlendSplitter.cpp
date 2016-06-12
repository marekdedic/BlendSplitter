#include "include/BlendSplitter.hpp"

#include "include/BS/WidgetRegistry.hpp"
#include "include/BS/RegistryItem.hpp"
#include "include/implementation/SplitterDecorator.hpp"
#include "include/implementation/SplitterHandle.hpp"
#include "include/implementation/WidgetDecorator.hpp"

BlendSplitter::BlendSplitter(QWidget* (*defaultWidget) (), Qt::Orientation orientation) : QSplitter{orientation, nullptr}, defaultWidget{defaultWidget}
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: black;}");
}

void BlendSplitter::addWidget()
{
    addWidget((*defaultWidget) ());
}

void BlendSplitter::addWidget(QWidget* widget)
{
    insertWidget(-1, widget);
}

void BlendSplitter::insertWidget(int index)
{
    insertWidget(index, (*defaultWidget) ());
}

void BlendSplitter::insertWidget(int index, QWidget* widget)
{
    WidgetDecorator* decorator{new WidgetDecorator{widget}};
    QSplitter::insertWidget(index, decorator);
}

void BlendSplitter::addDecoratedWidget(WidgetDecorator* widget)
{
    insertDecoratedWidget(-1, widget);
}

void BlendSplitter::insertDecoratedWidget(int index, WidgetDecorator* widget)
{
    QSplitter::insertWidget(index, widget);
}

void BlendSplitter::addSplitter(BlendSplitter *splitter)
{
    insertSplitter(-1, splitter);
}

void BlendSplitter::insertSplitter(int index, BlendSplitter* splitter)
{
    SplitterDecorator* decorator{new SplitterDecorator{splitter}};
    QSplitter::insertWidget(index, decorator);
}

QSplitterHandle* BlendSplitter::createHandle()
{
    return new SplitterHandle(orientation(), this);
}
