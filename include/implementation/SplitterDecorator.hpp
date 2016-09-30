#pragma once

#include "Global.hpp"

class BlendSplitter;

class SplitterDecorator : public QWidget
{
    Q_OBJECT
public:
    SplitterDecorator() = delete;
    explicit SplitterDecorator(BlendSplitter* splitter);
private:
    BlendSplitter* splitter;
};
