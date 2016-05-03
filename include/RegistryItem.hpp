#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QLabel>

class BLENDSPLITTER_EXPORT RegistryItem
{
public:
    RegistryItem(QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Inserted widget from Registry"};});
    QString name;
    QWidget* (*widget) ();
};
