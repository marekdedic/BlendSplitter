#pragma once

#include "Global.hpp"

#include "SplitterWidgetDecorator.hpp"
#include "SplitterHandle.hpp"
#include "SplitterDecorator.hpp"

class Splitter : public QSplitter
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
