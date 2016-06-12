#pragma once

#include "Global.hpp"

class ExpanderBottom;
class ExpanderTop;

class Overlay : public QLabel
{
private:
    friend ExpanderBottom;
    friend ExpanderTop;
    Overlay() = delete;
    Overlay(QWidget* parent);
    void reposition();
};
