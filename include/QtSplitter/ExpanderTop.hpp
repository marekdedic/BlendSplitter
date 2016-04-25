#pragma once

#include "Global.hpp"

#include "Expander.hpp"
class SplitterWidgetDecorator;

class ExpanderTop : public Expander
{
    Q_OBJECT
private:
    friend SplitterWidgetDecorator;
    ExpanderTop() = delete;
    ExpanderTop(SplitterWidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mouseMoveEvent(QMouseEvent* event);
};
