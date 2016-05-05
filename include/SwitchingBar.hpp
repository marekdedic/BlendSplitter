#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QWidget>
#include <QMenu>
#include <QHBoxLayout>

class SwitchingWidget;
class SwitchingCombo;

class BLENDSPLITTER_EXPORT SwitchingBar : public QWidget
{
    Q_OBJECT
public:
    static int size;
    QAction* addMenu(QMenu* menu);
    void addWidget(QWidget* widget);
protected:
    friend SwitchingWidget;
    QHBoxLayout* layout;
    SwitchingCombo* combo;
    SwitchingBar(QWidget* parent = nullptr);
    void reconstruct(void (*populateBar) (SwitchingBar*));
};
