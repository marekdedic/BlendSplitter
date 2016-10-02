#pragma once

#include "Global.hpp"

class ExpanderBottom;
class ExpanderTop;

class Overlay : public QLabel
{
public:
    Overlay() = delete;
    explicit Overlay(QWidget* parent);
private:
    void reposition();
};
