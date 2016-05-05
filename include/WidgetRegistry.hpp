#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QLabel>

class RegistryItem;

class BLENDSPLITTER_EXPORT WidgetRegistry : public QObject
{
    Q_OBJECT
public:
    static WidgetRegistry* getRegistry();
    RegistryItem* item(const int i) const;
    RegistryItem* getDefault();
    void addItem(RegistryItem* item);
    void addItem(QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Inserted widget"};});
    int size();
signals:
    void registryChanged();
private:
    WidgetRegistry() = default;
    static WidgetRegistry* theRegistry;
    QList<RegistryItem*> widgetList;
    RegistryItem* defaultWidget;
};
