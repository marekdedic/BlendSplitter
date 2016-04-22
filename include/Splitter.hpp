#pragma once

#ifdef QTSPLITTER_LIBRARY
    #define QTSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define QTSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include "QtSplitter/Global.hpp"

#include "QtSplitter/Expander.hpp"
#include "QtSplitter/Overlay.hpp"
#include "QtSplitter/SplitterDecorator.hpp"
#include "QtSplitter/SplitterHandle.hpp"
#include "QtSplitter/SplitterWidgetDecorator.hpp"

class QTSPLITTER_EXPORT Splitter : public QSplitter
{
    Q_OBJECT
public:
    Splitter(QWidget* (*defaultWidget) () = []()->QWidget* {return new QLabel{"Inserted widget"};}, Qt::Orientation orientation = Qt::Horizontal);
    Splitter(const Splitter& other);
    Splitter& operator=(const Splitter& other);
    void addWidget();
    void addWidget(QWidget* widget);
    void insertWidget(int index);
    void insertWidget(int index, QWidget* widget);
    void addSplitter(Splitter* splitter);
    void insertSplitter(int index, Splitter* splitter);
protected:
    friend Expander;
    QWidget* (*defaultWidget) ();
    virtual QSplitterHandle* createHandle();
    void addDecoratedWidget(SplitterWidgetDecorator* widget);
    void insertDecoratedWidget(int index, SplitterWidgetDecorator* widget);
};
