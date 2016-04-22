#pragma once

#include "Global.hpp"

class SplitterHandle : public QSplitterHandle
{
    Q_OBJECT
private:
    friend Splitter;
    SplitterHandle() = delete;
    SplitterHandle(Qt::Orientation orientation, QSplitter* parent);
protected slots:
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
