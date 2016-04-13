#pragma once

#include "Global.hpp"

class SplitterHandle : public QSplitterHandle
{
    Q_OBJECT
public:
    SplitterHandle(Qt::Orientation orientation, QSplitter* parent);
protected slots:
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
