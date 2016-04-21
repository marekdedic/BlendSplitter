#pragma once

#include "Global.hpp"
#include "Splitter.hpp"
#include "Expander.hpp"

class Overlay;

class SplitterDecorator : public QFrame
{
    Q_OBJECT
public:
    SplitterDecorator() = default;
    SplitterDecorator(Splitter* splitter);
    SplitterDecorator(const SplitterDecorator& other);
private:
    Splitter* splitter;
};

Q_DECLARE_METATYPE(SplitterDecorator);
