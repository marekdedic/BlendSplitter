#include "include/BlendSplitter.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"
#include "include/BlendSplitter/SplitterDecorator.hpp"
#include "include/BlendSplitter/SplitterHandle.hpp"
#include "include/BlendSplitter/WidgetDecorator.hpp"

BlendSplitter::BlendSplitter(Qt::Orientation orientation) : QSplitter{orientation, nullptr}
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: black;}");
}

BlendSplitter::BlendSplitter(const BlendSplitter& other) : BlendSplitter(other.orientation()) {}

BlendSplitter& BlendSplitter::operator=(const BlendSplitter& other)
{
    //QSplitter::operator=(other);  // TODO
    return *this;
}

void BlendSplitter::addWidget()
{
    addWidget((*WidgetRegistry::getRegistry()->getDefault()->widget) ());
}

void BlendSplitter::addWidget(QWidget* widget)
{
    insertWidget(-1, widget);
}

void BlendSplitter::insertWidget(int index)
{
    insertWidget(index, (*WidgetRegistry::getRegistry()->getDefault()->widget) ());
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
