#pragma once

#include "Global.hpp"
#include "Splitter.hpp"
#include "Expander.hpp"

class Overlay;

class SplitterDecorator : public QFrame
{
    Q_OBJECT
public:
    SplitterDecorator(Splitter* splitter);
private:
    Splitter* splitter;
};
