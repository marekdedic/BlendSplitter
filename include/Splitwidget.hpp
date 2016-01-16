#pragma once

#include <QFrame>
#include <QMenuBar>

class SplitWidget : public QFrame
{
public:
    SplitWidget(QWidget* parent = 0);
    void setComponent(QWidget* component);
    void setMenuBar(QMenuBar* menuBar);
private:
    QWidget* component;
    QMenuBar* menuBar;
};
