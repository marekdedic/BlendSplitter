#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT += core gui widgets

TARGET = BlendSplitter

TEMPLATE = lib

VERSION = 3.0.0

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

SOURCES += \
    src/BlendSplitter.cpp \
    src/RegistryItem.cpp \
    src/SwitchingBar.cpp \
    src/SwitchingWidget.cpp \
    src/WidgetRegistry.cpp \
    src/BlendSplitter/Expander.cpp \
    src/BlendSplitter/ExpanderBottom.cpp \
    src/BlendSplitter/ExpanderTop.cpp \
    src/BlendSplitter/Overlay.cpp \
    src/BlendSplitter/SplitterDecorator.cpp \
    src/BlendSplitter/SplitterHandle.cpp \
    src/BlendSplitter/SwitchingCombo.cpp \
    src/BlendSplitter/WidgetDecorator.cpp

HEADERS  += \
    include/BlendSplitter \
    include/BlendSplitter.hpp \
    include/BS/RegistryItem.hpp \
    include/BS/SwitchingBar.hpp \
    include/BS/SwitchingWidget.hpp \
    include/BS/WidgetRegistry.hpp \
    include/implementation/Expander.hpp \
    include/implementation/ExpanderBottom.hpp \
    include/implementation/ExpanderTop.hpp \
    include/implementation/Global.hpp \
    include/implementation/Overlay.hpp \
    include/implementation/SplitterDecorator.hpp \
    include/implementation/SplitterHandle.hpp \
    include/implementation/SwitchingCombo.hpp \
    include/implementation/WidgetDecorator.hpp

DEFINES += BLENDSPLITTER_LIBRARY
