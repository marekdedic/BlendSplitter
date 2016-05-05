#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QSplitter>

#include "RegistryItem.hpp"
#include "SwitchingBar.hpp"
#include "SwitchingWidget.hpp"
#include "WidgetRegistry.hpp"

class Expander;
class ExpanderBottom;
class ExpanderTop;
class WidgetDecorator;

class BLENDSPLITTER_EXPORT BlendSplitter : public QSplitter
{
    Q_OBJECT
public:
    BlendSplitter(QWidget* (*defaultWidget) () = []()->QWidget* {return new SwitchingWidget{};}, Qt::Orientation orientation = Qt::Horizontal);
    BlendSplitter(const BlendSplitter& other) = delete;
    BlendSplitter& operator=(const BlendSplitter& other) = delete;
    void addWidget();
    void addWidget(QWidget* widget);
    void insertWidget(int index);
    void insertWidget(int index, QWidget* widget);
    void addSplitter(BlendSplitter* splitter);
    void insertSplitter(int index, BlendSplitter* splitter);
protected:
    friend Expander;
    friend ExpanderBottom;
    friend ExpanderTop;
    QWidget* (*defaultWidget) ();
    virtual QSplitterHandle* createHandle();
    void addDecoratedWidget(WidgetDecorator* widget);
    void insertDecoratedWidget(int index, WidgetDecorator* widget);
};
