#pragma once

#include "Global.hpp"

class BlendSplitter;

class SplitterDecorator : public QWidget
{
    Q_OBJECT
public:
    SplitterDecorator() = default;
    SplitterDecorator(BlendSplitter* splitter);
    SplitterDecorator(const SplitterDecorator& other); // DO NOT USE!
private:
    BlendSplitter* splitter;
};

Q_DECLARE_METATYPE(SplitterDecorator);
