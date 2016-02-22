#pragma once

#include "Global.hpp"

class Expander;

class SplitWidget : public QWidget
{
public:
    SplitWidget(QWidget* widget, QWidget* parent = 0);
    void setMenuBar(QMenuBar* menuBar);
private:
    friend Expander;
    QWidget* widget;
    Expander* expander;
    QMenuBar* menuBar;
};
