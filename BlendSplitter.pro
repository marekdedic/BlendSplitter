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

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

SOURCES += \
    src/BlendSplitter.cpp \
    src/Expander.cpp \
    src/ExpanderBottom.cpp \
    src/ExpanderTop.cpp \
    src/SplitterHandle.cpp \
    src/Overlay.cpp \
    src/SplitterDecorator.cpp \
    src/WidgetDecorator.cpp \
    src/Registry.cpp \
    src/RegistryItem.cpp

HEADERS  += \
    include/BlendSplitter.hpp \
    include/BlendSplitter/Expander.hpp \
    include/BlendSplitter/ExpanderBottom.hpp \
    include/BlendSplitter/ExpanderTop.hpp \
    include/BlendSplitter/Global.hpp \
    include/BlendSplitter/Overlay.hpp \
    include/BlendSplitter/SplitterDecorator.hpp \
    include/BlendSplitter/SplitterHandle.hpp \
    include/BlendSplitter/WidgetDecorator.hpp \
    include/Registry.hpp \
    include/BlendSplitter/RegistryItem.hpp

DEFINES += BLENDSPLITTER_LIBRARY
