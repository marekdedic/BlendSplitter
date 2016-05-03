#pragma once

#include "Global.hpp"

class SwitchingBar : public QWidget
{
    Q_OBJECT
public:
    static int size;
    SwitchingBar(QWidget* parent = nullptr);
};
