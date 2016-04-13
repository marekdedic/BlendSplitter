#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class Overlay : public QLabel
{
public:
    Overlay(QWidget* parent);
    void reposition();
private:
    QWidget* parent;
};
