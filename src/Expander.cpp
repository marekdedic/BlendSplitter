#include "include/BlendSplitter/Expander.hpp"

#include "include/BlendSplitter.hpp"
#include "include/BlendSplitter/Overlay.hpp"
#include "include/BlendSplitter/WidgetDecorator.hpp"

int Expander::size = 32;
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
        WidgetDecorator* parentSplitWidget{qobject_cast<WidgetDecorator*>(parentWidget())};
        if(parentSplitWidget == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        WidgetDecorator* overlaySplitWidget{qobject_cast<WidgetDecorator*>(overlay->parentWidget())};
        if(overlaySplitWidget == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        BlendSplitter* parentSplitter{qobject_cast<BlendSplitter*>(overlaySplitWidget->parentWidget())};
        if(parentSplitter == 0)
        {
            std::cerr << "Bad cast caused by having an expander not properly inside a SplitWidget inside a Splitter." << std::endl;
            qApp->exit(-1);
        }
        QList<int> sizes{parentSplitter->sizes()};
        int parentIndex{parentSplitter->indexOf(parentSplitWidget)};
        int overlayIndex{parentSplitter->indexOf(overlaySplitWidget)};
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
            newParent->insertDecoratedWidget(newParent->indexOf(parentSplitter->parentWidget()), parentSplitWidget);
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
