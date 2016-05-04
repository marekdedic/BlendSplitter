#include "include/SwitchingWidget.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"
#include "include/BlendSplitter/SwitchingBar.hpp"

SwitchingWidget::SwitchingWidget(QWidget* parent) : QSplitter(Qt::Vertical, parent)
{
    setChildrenCollapsible(true);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: grey;}");
    addWidget((*WidgetRegistry::getRegistry()->getDefault()->widget) ());
    addWidget(new SwitchingBar{});
}
