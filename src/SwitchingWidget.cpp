#include "include/SwitchingWidget.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"
#include "include/BlendSplitter/SwitchingBar.hpp"
#include "include/BlendSplitter/SwitchingCombo.hpp"

SwitchingWidget::SwitchingWidget(QWidget* parent) : QSplitter(Qt::Vertical, parent), bar{new SwitchingBar{}}
{
    setChildrenCollapsible(true);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: grey;}");
    addWidget((*WidgetRegistry::getRegistry()->getDefault()->widget) ());
    addWidget(bar);
    connect(bar->combo, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SwitchingWidget::changeCurrentWidget);
}

void SwitchingWidget::changeCurrentWidget(int index)
{
    delete widget(0);
    insertWidget(0, (*WidgetRegistry::getRegistry()->item(index)->widget) ());
}
