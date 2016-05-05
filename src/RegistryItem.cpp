#include "include/RegistryItem.hpp"

RegistryItem::RegistryItem(QString name, QWidget* (*widget) (), void (*populateBar) (SwitchingBar*)) : name{name}, widget{widget}, populateBar{populateBar} {}
