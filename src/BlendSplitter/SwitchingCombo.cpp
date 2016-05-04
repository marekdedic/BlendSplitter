#include "include/BlendSplitter/SwitchingCombo.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"

SwitchingCombo::SwitchingCombo()
{
    for(int i{0}; i < WidgetRegistry::getRegistry()->size(); i++)
    {
        QComboBox::insertItem(-1, WidgetRegistry::getRegistry()->item(i)->name);
    }
}
