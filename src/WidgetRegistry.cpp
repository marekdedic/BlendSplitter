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

RegistryItem* WidgetRegistry::item(int i) const
{
    return list.value(i);
}

int WidgetRegistry::indexOf(RegistryItem* item) const
{
    return list.indexOf(item);
}

RegistryItem* WidgetRegistry::getDefault()
{
    if(defaultItem == nullptr)
    {
        if(list.size() == 0)
        {
            addItem();
        }
        defaultItem = item(0);
    }
    return defaultItem;
}

void WidgetRegistry::setDefault(RegistryItem* item)
{
    if(!list.contains(item))
    {
        addItem(item);
    }
    defaultItem = item;
}

void WidgetRegistry::setDefault(int index)
{
    setDefault(item(index));
}

void WidgetRegistry::addItem(RegistryItem* item)
{
    list.append(item);
    emit registryChanged();
}

void WidgetRegistry::addItem(QString name, QWidget* (*widget) (), void (*populateBar) (SwitchingBar*))
{
    addItem(new RegistryItem{name, widget, populateBar});
}

void WidgetRegistry::insertItem(int index, RegistryItem* item)
{
    list.insert(index, item);
    emit registryChanged();
}

void WidgetRegistry::insertItem(int index, QString name, QWidget* (*widget) (), void (*populateBar) (SwitchingBar*))
{
    insertItem(index, new RegistryItem{name, widget, populateBar});
}

void WidgetRegistry::removeItem(RegistryItem* item)
{
    removeItem(indexOf(item));
}

void WidgetRegistry::removeItem(int index)
{
    bool isDefault{index == indexOf(defaultItem) ? true : false};
    list.removeAt(index);
    if(isDefault)
    {
        setDefault();
    }
    emit registryChanged();
}

int WidgetRegistry::size() const
{
    return list.size();
}
