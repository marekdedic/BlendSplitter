#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include<QWidget>

class RegistryItem;

class BLENDSPLITTER_EXPORT Registry
{
public:
    static Registry* getRegistry();
    RegistryItem* operator[](const int i) const;
    RegistryItem* getDefault();
private:
    Registry() = default;
    static Registry* theRegistry;
    QList<RegistryItem*> widgetList;
};
