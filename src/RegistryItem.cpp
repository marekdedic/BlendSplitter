#include "include/BS/RegistryItem.hpp"

RegistryItem::RegistryItem(QString name, QWidget* (*widget) (), void (*populateBar) (SwitchingBar*, QWidget*)) : name{name}, widget{widget}, populateBar{populateBar} {}
