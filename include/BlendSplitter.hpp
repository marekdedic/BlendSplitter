#pragma once

#ifdef BLENDSPLITTER_LIBRARY
    #define BLENDSPLITTER_EXPORT Q_DECL_EXPORT
#else
    #define BLENDSPLITTER_EXPORT Q_DECL_IMPORT
#endif

#include <QSplitter>

#include "BS/RegistryItem.hpp"
#include "BS/SwitchingBar.hpp"
#include "BS/SwitchingWidget.hpp"
#include "BS/WidgetRegistry.hpp"

class Expander;
class ExpanderBottom;
class ExpanderTop;
class WidgetDecorator;

/** \brief A user-defined Splitter
 *
 * This widget implements the functionality of Blender (Open-source 3D modelling software) widget management. This widget displays a splitter similar to QSplitter. However, each widget in BlendSplitter has a pair of Expanders (one in top right and one in bottom left corner). By dragging from these Expanders inwards a new widget is created in the direction of the drag. If the direction is different to that of the BlendSplitter, a new BlendSplitter with parallel direction is created in place of the widget with the widget and the new widget in it. By dragging from these expanders outwards, a neighbouring widget (or a collection of widgets) can be closed. While the mouse is held, the widgets to be closed are marked with black overlay. When the mouse is released, they are closed. BlendSplitter can be used like any other QWidget, although setting one as the central widget is recommended. A BlendSplitter can contain any QWidget, but to achieve best results, use it together with SwitchingWidget.
 */
class BLENDSPLITTER_EXPORT BlendSplitter : public QSplitter
{
    Q_OBJECT
public:
    /** \brief BlendSplitter class constructor
     * \param defaultWidget A pointer to function constructing the default widget. This function is called when a new widget is added to BlendSplitter.
     * \param orientation Orientation of the main BlendSplitter
     */
    BlendSplitter(QWidget* (*defaultWidget) () = []()->QWidget* {return new SwitchingWidget{};}, Qt::Orientation orientation = Qt::Horizontal);
    BlendSplitter(const BlendSplitter& other) = delete;
    BlendSplitter& operator=(const BlendSplitter& other) = delete;
    /** \brief Add a widget to the BlendSplitter
     *
     * Adds the default widget to the very bottom/right of the BlendSplitter.
     */
    void addWidget();
    /** \brief Add a widget to the BlendSplitter
     *
     * Adds the specified widget to the very bottom/right of the BlendSplitter
     * \param widget A pointer to the widget to be added
     */
    void addWidget(QWidget* widget);
    /** \brief Insert a widget into the BlendSplitter
     *
     * Inserts the default widget into the BlendSplitter at the given position counting from top/left (counting starts at 0). This function should NOT be called with a BlendSplitter as a parameter.
     * \param index The desired position
     */
    void insertWidget(int index);
    /** \brief Insert a widget into the BlendSplitter
     *
     * Inserts the specified widget into the BlendSplitter at the given position counting from top/left (counting starts at 0). This function should NOT be called with a BlendSplitter as a parameter.
     * \param index The desired position
     * \param widget A pointer to the widget to be inserted
     */
    void insertWidget(int index, QWidget* widget);
    /** \brief Add another BlendSplitter to this BlendSplitter
     *
     * Adds a BlendSplitter (usually with parallel orientation) to the BlendSplitter
     * \param splitter A pointer to the BlendSplitter to be added
     */
    void addSplitter(BlendSplitter* splitter);
    /** \brief Insert another BlendSplitter into this BlendSplitter
     *
     * Inserts a BlendSplitter (usually with parallel orientation) into the BlendSplitter at the given position counting from top/left (counting starts at 0).
     * \param index The desired position
     * \param splitter A pointer to the BlendSplitter to be inserted
     */
    void insertSplitter(int index, BlendSplitter* splitter);
private:
    friend Expander;
    friend ExpanderBottom;
    friend ExpanderTop;
    QWidget* (*defaultWidget) ();
    virtual QSplitterHandle* createHandle();
    void addDecoratedWidget(WidgetDecorator* widget);
    void insertDecoratedWidget(int index, WidgetDecorator* widget);
};
