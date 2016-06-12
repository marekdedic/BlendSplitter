#include "include/BS/SwitchingWidget.hpp"

#include "include/BS/WidgetRegistry.hpp"
#include "include/BS/RegistryItem.hpp"
#include "include/BS/SwitchingBar.hpp"
#include "include/implementation/SwitchingCombo.hpp"

SwitchingWidget::SwitchingWidget(QWidget* parent) : QSplitter(Qt::Vertical, parent), bar{new SwitchingBar{}}
{
    setChildrenCollapsible(true);
    setHandleWidth(1);
    setStyleSheet("QSplitter::handle{background: grey;}");
    addWidget((*WidgetRegistry::getRegistry()->getDefault()->widget) ());
    addWidget(bar);
    bar->reconstruct(*WidgetRegistry::getRegistry()->getDefault()->populateBar, widget(0));
    connect(bar->combo, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SwitchingWidget::changeCurrentWidget);
}

void SwitchingWidget::changeCurrentWidget(int index)
{
    if(index >= 0)
    {
        delete widget(0);
        insertWidget(0, (*WidgetRegistry::getRegistry()->item(index)->widget) ());
        bar->reconstruct(*WidgetRegistry::getRegistry()->item(index)->populateBar, widget(0));
    }
}
