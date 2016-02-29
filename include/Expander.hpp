#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class SplitWidget;

class Expander : public QLabel
{
public:
    Expander(QString filename, SplitWidget* parent);
    void reposition();
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
private:
    bool pressed;
    QPixmap* pixmap;
};
