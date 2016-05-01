#include "include/Registry.hpp"

#include "include/BlendSplitter/RegistryItem.hpp"

Registry* Registry::theRegistry;

Registry* Registry::getRegistry()
{
    if(theRegistry == nullptr)
    {
        theRegistry = new Registry{};
        theRegistry->widgetList.append(new RegistryItem{});
    }
    return theRegistry;
}

RegistryItem* Registry::operator[](const int i) const
{
    return widgetList[i];
}

RegistryItem* Registry::getDefault()
{
    return widgetList[0];
}
