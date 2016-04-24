#include "include/QtSplitter/Expander.hpp"

#include "include/Splitter.hpp"
#include "include/QtSplitter/Overlay.hpp"
#include "include/QtSplitter/SplitterWidgetDecorator.hpp"

int Expander::size = 32;
QString Expander::image = ":/UI/QtSplitter_expander";

Expander::Expander(SplitterWidgetDecorator* parent) : QLabel(parent), pixmap{new QPixmap{image}}, overlay{nullptr}
{
    *pixmap = pixmap->scaledToHeight(size, Qt::FastTransformation);
    setPixmap(*pixmap);
    resize(size, size);
    reposition();
}

void Expander::reposition()
{
    raise();
}

void Expander::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        event->accept();    // No-op
    }
    else
    {
        releaseMouse();
        event->ignore();    // Propagate event
    }
}
