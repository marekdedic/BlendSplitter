#pragma once

#include "Global.hpp"

class SwitchingWidget;

class SwitchingBar : public QWidget
{
    Q_OBJECT
public:
    static int size;
protected:
    friend SwitchingWidget;
    SwitchingBar(QWidget* parent = nullptr);
};
