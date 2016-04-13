#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

#include "SplitterHandle.hpp"

class Splitter : public QSplitter
{
public:
    Splitter(QWidget* (*defaultWidget) () = []()->QWidget* {return new QLabel{"Inserted widget"};}, Qt::Orientation orientation = Qt::Horizontal);
    void addWidget();
    void addWidget(QWidget* widget);
    void addSplitWidget(SplitWidget* widget);
    void insertWidget(int index);
    void insertWidget(int index, QWidget* widget);
    void insertSplitWidget(int index, SplitWidget* widget);
    void insertSplitter(int index, Splitter* splitter);
    QWidget* (*defaultWidget) ();
protected:
    virtual QSplitterHandle* createHandle();
};
