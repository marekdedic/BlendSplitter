#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QSplitter>

class BLENDSPLITTER_EXPORT SwitchingWidget : public QSplitter
{
    Q_OBJECT
public:
    SwitchingWidget(QWidget* parent = nullptr);
};
