#pragma once

#include "Global.hpp"

class RegistryItem
{
public:
    RegistryItem(QWidget* (*widget) () = []()->QWidget* {return new QLabel{"Inserted widget from Registry!"};});
    QWidget* (*widget) ();
};
