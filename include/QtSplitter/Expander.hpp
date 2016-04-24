#pragma once

#include "Global.hpp"

class Overlay;
class SplitterWidgetDecorator;

class Expander : public QLabel
{
    Q_OBJECT
protected:
    friend SplitterWidgetDecorator;
    static int size;
    static QString image;
    QPixmap* pixmap;
    Overlay* overlay;
    Expander() = delete;
    Expander(SplitterWidgetDecorator* parent);
    virtual void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent* event) = 0;
};
