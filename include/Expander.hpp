#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class SplitWidget;

class Expander : public QLabel
{
public:
    static int size;
    Expander(QString filename, SplitWidget* parent);
    void reposition();
    virtual bool eventFilter(QObject*, QEvent* event);
protected slots:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
private:
    QPixmap* pixmap;
};
