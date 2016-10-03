#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QSplitter>

class SwitchingBar;

/** \brief A widget whose actual content can be selected from a combo box
 *
 * This widget displays a Widget with a SwitchingBar on the bottom. The widget displayed is one from WidgetRegistry and it can be selected using a combo box in the SwitchingBar.
 *
 * Note that constructing an object of this class when WidgetRegistry is empty will cause a default RegistryItem to be added to it. The height of the SwitchingBar can be modified by changing BlendSplitter::switchingBarHeight.
 */
class BLENDSPLITTER_EXPORT SwitchingWidget : public QSplitter
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchingWidget)
public:
    /** \brief A default constructor similar to that of QWidget
     *
     * Creates a SwitchingWidget containg the default widget specified in WidgetRegistry
     * \param parent A parent widget
     */
    explicit SwitchingWidget(QWidget* parent = nullptr);
private slots:
    void changeCurrentWidget(int index);
private:
    SwitchingBar* bar;
};
