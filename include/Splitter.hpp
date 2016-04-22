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
    void addWidget();
    void addWidget(QWidget* widget);
    void insertWidget(int index);
    void insertWidget(int index, QWidget* widget);
    void addDecoratedWidget(SplitterWidgetDecorator* widget);
    void insertDecoratedWidget(int index, SplitterWidgetDecorator* widget);
    void addSplitter(Splitter* splitter);
    void insertSplitter(int index, Splitter* splitter);
    QWidget* (*defaultWidget) ();
protected:
    virtual QSplitterHandle* createHandle();
};
