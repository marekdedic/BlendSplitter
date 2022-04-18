#pragma once

#include "Global.hpp"

class BlendSplitter;
class QAction;
class QMenu;

class SplitterHandle final : public QSplitterHandle
{
    Q_OBJECT
    Q_DISABLE_COPY(SplitterHandle)
public:
    SplitterHandle() = delete;
    SplitterHandle(Qt::Orientation orientation, QSplitter* parent);
    ~SplitterHandle();

protected slots:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QMenu* popupmenu;
    QAction* joinAction;
    QAction* splitAction;
};
