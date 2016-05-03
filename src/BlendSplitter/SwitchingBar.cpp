#include "include/BlendSplitter/SwitchingBar.hpp"

#include "include/BlendSplitter/SplitterCombo.hpp"

int SwitchingBar::size = 48;

SwitchingBar::SwitchingBar(QWidget* parent) : QWidget(parent)
{
    QHBoxLayout* layout{new QHBoxLayout{}};
    layout->addWidget(new SplitterCombo{});
    layout->setMargin(0);
    setLayout(layout);
    setMinimumHeight(size);
    setMaximumHeight(size);
}
