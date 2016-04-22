#pragma once

#include "Global.hpp"

class Overlay;
class SplitterWidgetDecorator;

class Expander : public QLabel
{
    Q_OBJECT
private:
    friend SplitterWidgetDecorator;
    static int size;
    QPixmap* pixmap;
    Overlay* overlay;
    Expander() = delete;
    Expander(QString filename, SplitterWidgetDecorator* parent);
    void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
