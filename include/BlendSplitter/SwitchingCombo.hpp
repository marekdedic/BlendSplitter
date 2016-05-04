#pragma once

#include "Global.hpp"

class SwitchingBar;

class SwitchingCombo : public QComboBox
{
    Q_OBJECT
protected:
    friend SwitchingBar;
    SwitchingCombo();
};
