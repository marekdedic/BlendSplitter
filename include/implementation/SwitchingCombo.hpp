#pragma once

#include "Global.hpp"

class SwitchingBar;

class SwitchingCombo : public QComboBox
{
    Q_OBJECT
public:
    SwitchingCombo();
public slots:
    void repopulate();
};
