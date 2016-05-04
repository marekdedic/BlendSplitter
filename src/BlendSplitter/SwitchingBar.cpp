#include "include/BlendSplitter/SwitchingBar.hpp"

#include "include/BlendSplitter/SwitchingCombo.hpp"
#include "include/BlendSplitter/Expander.hpp"

int SwitchingBar::size = 36;

SwitchingBar::SwitchingBar(QWidget* parent) : QWidget(parent), combo{new SwitchingCombo{}}
{
    QHBoxLayout* layout{new QHBoxLayout{}};
    layout->setContentsMargins(Expander::size * 3 / 4, 0, 0, 0);
    setLayout(layout);
    setMinimumHeight(size);
    setMaximumHeight(size);
    layout->addWidget(combo);
    layout->addStretch();
}
