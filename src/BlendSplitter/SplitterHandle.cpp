#include "include/BlendSplitter/SplitterHandle.hpp"

SplitterHandle::SplitterHandle(Qt::Orientation orientation, QSplitter* parent) : QSplitterHandle(orientation, parent) {}

void SplitterHandle::mouseReleaseEvent(QMouseEvent* event)
{
    QSplitterHandle::mouseReleaseEvent(event);
    releaseMouse();
}
