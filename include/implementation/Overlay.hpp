#pragma once

#include "Global.hpp"

class ExpanderBottom;
class ExpanderTop;

class Overlay final : public QLabel
{
    Q_OBJECT
    Q_DISABLE_COPY(Overlay)
public:
    Overlay() = delete;
    explicit Overlay(QWidget* parent, Qt::ArrowType direction=Qt::NoArrow);
private:
    void makeArrowshape();
    void reposition();

    QPolygon arrow;

    Qt::ArrowType arrowtype;

protected:
    void paintEvent(QPaintEvent *) override;
};
