#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class Splitter : public QSplitter
{
public:
    Splitter(Qt::Orientation orientation = Qt::Horizontal);
    void addWidget(QWidget* widget);
    void addSplitWidget(SplitWidget* widget);
    void insertWidget(int index, QWidget* widget);
    void insertSplitWidget(int index, SplitWidget* widget);
    void insertSplitter(int index, Splitter* splitter);
};
