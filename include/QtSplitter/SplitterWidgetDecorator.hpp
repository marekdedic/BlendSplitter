#pragma once

#include "Global.hpp"

class Splitter;
class ExpanderBottom;
class ExpanderTop;

class SplitterWidgetDecorator : public QWidget
{
    Q_OBJECT
private:
    friend Splitter;
    QWidget* widget;
    ExpanderBottom* expanderBottom;
    ExpanderTop* expanderTop;
    SplitterWidgetDecorator() = delete;
    SplitterWidgetDecorator(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
};
