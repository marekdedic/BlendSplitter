#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QLabel>

class SwitchingBar;

class BLENDSPLITTER_EXPORT RegistryItem
{
public:
    RegistryItem(QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Default Widget"};}, void (*populateBar) (SwitchingBar*, QWidget*) = [](SwitchingBar*, QWidget*)->void {});
    QString name;
    QWidget* (*widget) ();
    void (*populateBar) (SwitchingBar*, QWidget*);
};
