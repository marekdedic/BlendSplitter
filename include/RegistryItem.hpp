#pragma once

#include <QLabel>

class RegistryItem
{
public:
    RegistryItem(QString name = "Default", QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Inserted widget"};});
    QString name;
    QWidget* (*widget) ();
};
