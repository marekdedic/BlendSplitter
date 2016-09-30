#pragma once

#include "Global.hpp"

class BlendSplitter;
class ExpanderBottom;
class ExpanderTop;

class WidgetDecorator : public QWidget
{
    Q_OBJECT
private:
    friend BlendSplitter;
    QWidget* widget;
    ExpanderBottom* expanderBottom;
    ExpanderTop* expanderTop;
    WidgetDecorator() = delete;
    explicit WidgetDecorator(QWidget* widget);
protected slots:
    virtual void resizeEvent(QResizeEvent*);
};
