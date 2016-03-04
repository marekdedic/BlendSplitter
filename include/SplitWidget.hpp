#pragma once

#include "Global.hpp"

class Expander;

class SplitWidget : public QWidget
{
public:
    SplitWidget(QWidget* widget);
    void setMenuBar(QMenuBar* menuBar);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
private:
    friend Expander;
    QWidget* widget;
    Expander* expander;
    QMenuBar* menuBar;
};
