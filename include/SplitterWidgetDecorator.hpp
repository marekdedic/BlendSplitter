#pragma once

#include "Global.hpp"

class Expander;

class SplitterWidgetDecorator : public QWidget
{
    Q_OBJECT
private:
    friend Splitter;
    QWidget* widget;
    Expander* expander;
    SplitterWidgetDecorator() = delete;
    SplitterWidgetDecorator(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
};
