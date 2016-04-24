#pragma once

#include "Global.hpp"

class ExpanderTop;

class Overlay : public QLabel
{
private:
    friend ExpanderTop;
    Overlay() = delete;
    Overlay(QWidget* parent);
    void reposition();
};
