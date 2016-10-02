#pragma once

#include "Global.hpp"

#include "Expander.hpp"
class WidgetDecorator;

class ExpanderBottom : public Expander
{
    Q_OBJECT
    Q_DISABLE_COPY(ExpanderBottom)
public:
    ExpanderBottom() = delete;
    explicit ExpanderBottom(WidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mouseMoveEvent(QMouseEvent* event);
};
