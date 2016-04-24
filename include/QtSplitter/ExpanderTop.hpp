#pragma once

#include "Global.hpp"

class Overlay;
class SplitterWidgetDecorator;

class ExpanderTop : public QLabel
{
    Q_OBJECT
private:
    friend SplitterWidgetDecorator;
    static int size;
    static QString image;
    QPixmap* pixmap;
    Overlay* overlay;
    ExpanderTop() = delete;
    ExpanderTop(SplitterWidgetDecorator* parent);
    void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
