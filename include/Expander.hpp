#pragma once

#include "Global.hpp"

#include "SplitWidget.hpp"

class SplitWidget;

class Expander : public QLabel
{
public:
    Expander(QString filename, SplitWidget* parent);
private:
    QPixmap* pixmap;
};
