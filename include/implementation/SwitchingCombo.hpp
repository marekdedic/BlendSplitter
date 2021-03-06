#pragma once

#include "Global.hpp"

class SwitchingBar;

class SwitchingCombo : public QComboBox
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchingCombo)
public:
    SwitchingCombo();
public slots:
    void repopulate();
};
