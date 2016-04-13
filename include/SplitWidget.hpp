#pragma once

#include "Global.hpp"

class Overlay;

class Expander;

class SplitWidget : public QWidget
{
    Q_OBJECT
public:
    SplitWidget(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
private:
    friend Expander;
    QWidget* widget;
    Expander* expander;
};
