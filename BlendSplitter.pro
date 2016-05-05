#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlendSplitter

TEMPLATE = lib

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
    include/BlendSplitter.hpp \
    include/RegistryItem.hpp \
    include/SwitchingBar.hpp \
    include/SwitchingWidget.hpp \
    include/WidgetRegistry.hpp \
    include/BlendSplitter/Expander.hpp \
    include/BlendSplitter/ExpanderBottom.hpp \
    include/BlendSplitter/ExpanderTop.hpp \
    include/BlendSplitter/Global.hpp \
    include/BlendSplitter/Overlay.hpp \
    include/BlendSplitter/SplitterDecorator.hpp \
    include/BlendSplitter/SplitterHandle.hpp \
    include/BlendSplitter/SwitchingCombo.hpp \
    include/BlendSplitter/WidgetDecorator.hpp

DEFINES += BLENDSPLITTER_LIBRARY
