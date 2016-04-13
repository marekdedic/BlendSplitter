#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

#include "Overlay.hpp"

class SplitWidget;

class Expander : public QLabel
{
    Q_OBJECT
public:
    static int size;
    Expander(QString filename, SplitWidget* parent);
    void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
private:
    QPixmap* pixmap;
    Overlay* overlay;
};
