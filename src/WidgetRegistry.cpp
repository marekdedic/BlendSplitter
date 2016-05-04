#include "include/WidgetRegistry.hpp"

#include "include/RegistryItem.hpp"

WidgetRegistry* WidgetRegistry::theRegistry;

WidgetRegistry* WidgetRegistry::getRegistry()
{
    if(theRegistry == nullptr)
    {
        theRegistry = new WidgetRegistry{};
        theRegistry->widgetList.append(new RegistryItem{}); // TODO
        theRegistry->widgetList.append(new RegistryItem{"Type1", []()->QWidget* {return new QLabel{"Type 1 Label"};}});
        theRegistry->widgetList.append(new RegistryItem{"Type2", []()->QWidget* {return new QLabel{"Type 2 Label"};}});
        theRegistry->widgetList.append(new RegistryItem{"Type3", []()->QWidget* {return new QLabel{"Type 3 Label"};}});
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
