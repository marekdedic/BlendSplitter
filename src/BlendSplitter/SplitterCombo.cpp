#include "include/BlendSplitter/SplitterCombo.hpp"

#include "include/WidgetRegistry.hpp"
#include "include/RegistryItem.hpp"

SplitterCombo::SplitterCombo()
{
    for(int i{0}; i < WidgetRegistry::getRegistry()->size(); i++)
    {
        QComboBox::insertItem(-1, WidgetRegistry::getRegistry()->item(i)->name);
    }
}
