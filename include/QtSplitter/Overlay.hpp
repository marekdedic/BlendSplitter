#pragma once

#include "Global.hpp"

class Expander;

class Overlay : public QLabel
{
private:
    friend Expander;
    Overlay() = delete;
    Overlay(QWidget* parent);
    void reposition();
};
