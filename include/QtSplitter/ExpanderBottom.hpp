#pragma once

#include "Global.hpp"

#include "Expander.hpp"
class SplitterWidgetDecorator;

class ExpanderBottom : public Expander
{
    Q_OBJECT
private:
    friend SplitterWidgetDecorator;
    ExpanderBottom() = delete;
    ExpanderBottom(SplitterWidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
