#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QWidget>

class RegistryItem;

class BLENDSPLITTER_EXPORT WidgetRegistry
{
public:
    static WidgetRegistry* getRegistry();
    RegistryItem* item(const int i) const;
    RegistryItem* getDefault();
    int size();
private:
    WidgetRegistry() = default;
    static WidgetRegistry* theRegistry;
    QList<RegistryItem*> widgetList;
    int defaultWidget;
};
