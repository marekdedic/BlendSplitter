#pragma once

#include "Global.hpp"

class BlendSplitter;
class ExpanderBottom;
class ExpanderTop;

class WidgetDecorator : public QWidget
{
    Q_OBJECT
public:
    WidgetDecorator() = delete;
    explicit WidgetDecorator(QWidget* widget);
private:
    QWidget* widget;
    ExpanderBottom* expanderBottom;
    ExpanderTop* expanderTop;
protected slots:
    virtual void resizeEvent(QResizeEvent*);
};
