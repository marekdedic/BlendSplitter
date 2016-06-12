#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QLabel>

class RegistryItem;
class SwitchingBar;

class BLENDSPLITTER_EXPORT WidgetRegistry : public QObject
{
    Q_OBJECT
public:
    static WidgetRegistry* getRegistry();
    RegistryItem* item(int i) const;
    int indexOf(RegistryItem* item) const;
    RegistryItem* getDefault();
    void setDefault(RegistryItem* item);
    void setDefault(int index = 0);
    void addItem(RegistryItem* item);
    void addItem(QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Default widget"};}, void (*populateBar) (SwitchingBar*, QWidget*) = [](SwitchingBar*, QWidget*)->void {});
    void insertItem(int index, RegistryItem* item);
    void insertItem(int index, QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Default widget"};}, void (*populateBar) (SwitchingBar*, QWidget*) = [](SwitchingBar*, QWidget*)->void {});
    void removeItem(RegistryItem* item);
    void removeItem(int index);
    int size() const;
signals:
    void registryChanged();
private:
    WidgetRegistry() = default;
    static WidgetRegistry* theRegistry;
    QList<RegistryItem*> list;
    RegistryItem* defaultItem;
};
