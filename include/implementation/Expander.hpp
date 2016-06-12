#pragma once

#include "Global.hpp"

class Overlay;
class WidgetDecorator;

class Expander : public QLabel
{
    Q_OBJECT
public:
    static int size;
    static QString image;
protected:
    friend WidgetDecorator;
    QPixmap* pixmap;
    Overlay* overlay;
    Expander() = delete;
    Expander(WidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
