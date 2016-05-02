#include "include/WidgetRegistry.hpp"

#include "include/RegistryItem.hpp"

WidgetRegistry* WidgetRegistry::theRegistry;

WidgetRegistry* WidgetRegistry::getRegistry()
{
    if(theRegistry == nullptr)
    {
        theRegistry = new WidgetRegistry{};
        theRegistry->widgetList.append(new RegistryItem{}); // TODO
    }
    return theRegistry;
}

RegistryItem* WidgetRegistry::item(const int i) const
{
    return widgetList[i];
}

RegistryItem* WidgetRegistry::getDefault()
{
    return item(defaultWidget);
}

int WidgetRegistry::size()
{
    return widgetList.size();
}
