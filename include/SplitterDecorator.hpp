#pragma once

#include "Global.hpp"

class Splitter;

class SplitterDecorator : public QWidget
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
