#pragma once

#include "Global.hpp"

class Overlay;

class Expander;

class SplitterWidgetDecorator : public QWidget
{
    Q_OBJECT
public:
    SplitterWidgetDecorator(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
private:
    friend Expander;
    QWidget* widget;
    Expander* expander;
};
