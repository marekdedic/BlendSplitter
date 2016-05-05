#include "include/WidgetRegistry.hpp"

#include "include/RegistryItem.hpp"

WidgetRegistry* WidgetRegistry::theRegistry;

WidgetRegistry* WidgetRegistry::getRegistry()
{
    if(theRegistry == nullptr)
    {
        theRegistry = new WidgetRegistry{};
    }
    return theRegistry;
}

RegistryItem* WidgetRegistry::item(const int i) const
{
    return widgetList.value(i);
}

RegistryItem* WidgetRegistry::getDefault()
{
    if(defaultWidget == nullptr)
    {
        if(widgetList.size() == 0)
        {
            addItem();
        }
        defaultWidget = item(0);
    }
    return defaultWidget;
}

void WidgetRegistry::addItem(RegistryItem* item)
{
    widgetList.append(item);
    emit registryChanged();
}

void WidgetRegistry::addItem(QString name, QWidget* (*widget) ())
{
    addItem(new RegistryItem{name, widget});
}

int WidgetRegistry::size()
{
    return widgetList.size();
}
