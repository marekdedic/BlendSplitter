#pragma once

#include "Global.hpp"

#include "SplitterWidgetDecorator.hpp"

class Overlay : public QLabel
{
public:
    Overlay(QWidget* parent);
    void reposition();
};
