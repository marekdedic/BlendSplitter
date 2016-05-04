#include "include/BlendSplitter/Expander.hpp"

#include "include/BlendSplitter.hpp"
#include "include/BlendSplitter/Overlay.hpp"
#include "include/BlendSplitter/WidgetDecorator.hpp"

int Expander::size = 12;
QString Expander::image = ":/UI/QtSplitter_expander";

Expander::Expander(WidgetDecorator* parent) : QLabel(parent), pixmap{new QPixmap{image}}, overlay{nullptr}
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

void Expander::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton and overlay != nullptr)
    {
        WidgetDecorator* parentDecorator{qobject_cast<WidgetDecorator*>(parentWidget())};
        if(parentDecorator == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        WidgetDecorator* overlayDecorator{qobject_cast<WidgetDecorator*>(overlay->parentWidget())};
        if(overlayDecorator == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(overlayDecorator->parentWidget())};
        if(parentSplitter == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        QList<int> sizes{parentSplitter->sizes()};
        int parentIndex{parentSplitter->indexOf(parentDecorator)};
        int overlayIndex{parentSplitter->indexOf(overlayDecorator)};
        sizes[parentIndex] += sizes[overlayIndex] + 1;
        sizes.removeAt(overlayIndex);
        delete parentSplitter->widget(overlayIndex);
        if(parentSplitter->count() == 1 and parentSplitter->parentWidget()->inherits("SplitterDecorator"))
        {
            BlendSplitter* newParent{qobject_cast<BlendSplitter*>(parentSplitter->parentWidget()->parentWidget())};
            if(newParent == 0)
            {
                std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
                qApp->exit(-1);
            }
            QList<int> sizes2{newParent->sizes()};
            newParent->insertDecoratedWidget(newParent->indexOf(parentSplitter->parentWidget()), parentDecorator);
            delete parentSplitter->parentWidget();
            newParent->setSizes(sizes2);
        }
        else
        {
            parentSplitter->setSizes(sizes);
        }
        overlay = nullptr;
    }
}
