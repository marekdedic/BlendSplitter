#pragma once

#include "Global.hpp"

class BlendSplitter;
class ExpanderBottom;
class ExpanderTop;

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
    ExpanderBottom* expanderBottom;
    ExpanderTop* expanderTop;
protected slots:
    virtual void resizeEvent(QResizeEvent*) override;
};
