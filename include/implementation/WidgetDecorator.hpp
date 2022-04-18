#pragma once

#include "Global.hpp"

class BlendSplitter;
class ExpanderBottom;
class ExpanderTop;
class ExpanderCorner;

class WidgetDecorator final : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(WidgetDecorator)
public:
    WidgetDecorator() = delete;
    explicit WidgetDecorator(QWidget* widget);
    ~WidgetDecorator();
private:
    QWidget* widget;
//    ExpanderBottom* expanderBottom;
//    ExpanderTop* expanderTop;
    ExpanderCorner* expanderCorner1;
    ExpanderCorner* expanderCorner2;
    ExpanderCorner* expanderCorner3;
    ExpanderCorner* expanderCorner4;

    enum class dropregions {
        top=0,
        left=1,
        right=2,
        bottom=3,
        center=4
    };

    dropregions dropzone;

    void determineDropZone(QPoint pos);

protected slots:
    virtual void resizeEvent(QResizeEvent*) override;
//    virtual void mouseMoveEvent(QMouseEvent* event) override;
//    virtual void paintEvent(QPaintEvent* event) override;

};
