#pragma once

#include "Global.hpp"

class BlendSplitter;

class SplitterHandle : public QSplitterHandle
{
    Q_OBJECT
    Q_DISABLE_COPY(SplitterHandle)
public:
    SplitterHandle() = delete;
    SplitterHandle(Qt::Orientation orientation, QSplitter* parent);
protected slots:
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
