#pragma once

#include "Global.hpp"

#include "Expander.hpp"
class WidgetDecorator;

class ExpanderBottom : public Expander
{
    Q_OBJECT
public:
    ExpanderBottom() = delete;
    explicit ExpanderBottom(WidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mouseMoveEvent(QMouseEvent* event);
};
