#include "include/BlendSplitter/RegistryItem.hpp"

RegistryItem::RegistryItem(QWidget* (*widget) ()) : widget{widget}
{

}
