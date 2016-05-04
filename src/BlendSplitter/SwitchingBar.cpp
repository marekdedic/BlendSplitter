#include "include/BlendSplitter/SwitchingBar.hpp"

#include "include/BlendSplitter/SplitterCombo.hpp"
#include "include/BlendSplitter/Expander.hpp"

int SwitchingBar::size = 48;

SwitchingBar::SwitchingBar(QWidget* parent) : QWidget(parent)
{
    QHBoxLayout* layout{new QHBoxLayout{}};
    layout->setContentsMargins(Expander::size * 3 / 4, 0, 0, 0);
    setLayout(layout);
    setMinimumHeight(size);
    setMaximumHeight(size);
    layout->addWidget(new SplitterCombo{});
    layout->addStretch();
}
