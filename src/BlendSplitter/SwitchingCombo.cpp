#include "include/BlendSplitter/SwitchingCombo.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"

SwitchingCombo::SwitchingCombo()
{
    repopulate();
    connect(WidgetRegistry::getRegistry(), &WidgetRegistry::registryChanged, this, &SwitchingCombo::repopulate);
}

void SwitchingCombo::repopulate()
{
    RegistryItem* current{WidgetRegistry::getRegistry()->item(currentIndex())};
    clear();
    for(int i{0}; i < WidgetRegistry::getRegistry()->size(); i++)
    {
        QComboBox::addItem(WidgetRegistry::getRegistry()->item(i)->name);
    }
    if(current != 0)
    {
        setCurrentIndex(findText(current->name));
    }
    else
    {
        setCurrentIndex(findText(WidgetRegistry::getRegistry()->getDefault()->name));
    }
}
