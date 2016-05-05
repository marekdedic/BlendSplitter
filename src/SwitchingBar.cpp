#include "include/SwitchingBar.hpp"

#include <QMenuBar>
#include "include/BlendSplitter/SwitchingCombo.hpp"
#include "include/BlendSplitter/Expander.hpp"

int SwitchingBar::size = 36;

QAction* SwitchingBar::addMenu(QMenu* menu)
{
    QMenuBar* menuBar{new QMenuBar};
    layout->insertWidget(layout->count() - 1, menuBar);
    return menuBar->addMenu(menu);
}

void SwitchingBar::addWidget(QWidget* widget)
{
    layout->insertWidget(layout->count() - 1, widget);
}

SwitchingBar::SwitchingBar(QWidget* parent) : QWidget(parent), layout{new QHBoxLayout{}}, combo{new SwitchingCombo{}}
{
    layout->setContentsMargins(Expander::size * 3 / 4, 0, 0, 0);
    setLayout(layout);
    setMinimumHeight(size);
    setMaximumHeight(size);
    layout->addWidget(combo);
    layout->addStretch();
}

void SwitchingBar::reconstruct(void (*populateBar) (SwitchingBar*))
{
    int count{layout->count() - 1};
    for(int i = 1; i < count; i++)
    {
        QLayoutItem* it{layout->takeAt(1)};
        delete it->widget();
        delete it;
    }
    (*populateBar) (this);
}
