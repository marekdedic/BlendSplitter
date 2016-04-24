#pragma once

#include "Global.hpp"

class Splitter;
class ExpanderTop;

class SplitterWidgetDecorator : public QWidget
{
    Q_OBJECT
private:
    friend Splitter;
    QWidget* widget;
    ExpanderTop* expander;
    SplitterWidgetDecorator() = delete;
    SplitterWidgetDecorator(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
};
