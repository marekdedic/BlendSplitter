#pragma once

#include "Global.hpp"

class SplitWidget : public QWidget
{
public:
    SplitWidget(QWidget* parent = 0);
    void setMenuBar(QMenuBar* menuBar);
private:
    QMenuBar* menuBar;
};
