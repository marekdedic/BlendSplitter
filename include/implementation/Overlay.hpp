#pragma once

#include "Global.hpp"

class ExpanderBottom;
class ExpanderTop;

class Overlay : public QLabel
{
    Q_OBJECT
    Q_DISABLE_COPY(Overlay)
public:
    Overlay() = delete;
    explicit Overlay(QWidget* parent);
private:
    void reposition();
};
