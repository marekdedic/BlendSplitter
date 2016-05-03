#include "include/SwitchingWidget.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"

SwitchingWidget::SwitchingWidget(QWidget* parent) : QSplitter(Qt::Vertical, parent)
{
    setChildrenCollapsible(false);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: black;}");
    addWidget((*WidgetRegistry::getRegistry()->getDefault()->widget) ());
}
