#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class Splitter : public QSplitter
{
public:
    Splitter(QWidget* parent = 0);
    static Splitter* getInstance();
    void addWidget(QWidget* widget);
private:
    static Splitter* instance;
};
