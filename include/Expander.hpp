#pragma once

#include "Global.hpp"

#include "SplitterWidgetDecorator.hpp"

#include "Overlay.hpp"

class SplitterWidgetDecorator;

class Expander : public QLabel
{
    Q_OBJECT
public:
    static int size;
    Expander() = delete;
    Expander(QString filename, SplitterWidgetDecorator* parent);
    void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
private:
    QPixmap* pixmap;
    Overlay* overlay;
};
