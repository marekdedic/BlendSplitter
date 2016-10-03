#pragma once

#include "Global.hpp"

class Overlay;
class WidgetDecorator;

class Expander : public QLabel
{
    Q_OBJECT
    Q_DISABLE_COPY(Expander)
protected:
    QPixmap* pixmap;
    Overlay* overlay;
    Expander() = delete;
    explicit Expander(WidgetDecorator* parent);
    virtual void reposition();
    ~Expander();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
