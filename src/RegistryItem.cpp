#include "include/RegistryItem.hpp"

RegistryItem::RegistryItem(QString name, QWidget* (*widget) ()) : name{name}, widget{widget} {}
