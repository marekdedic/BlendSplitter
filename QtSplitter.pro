#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSplitter

TEMPLATE = lib

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

SOURCES += \
    src/Splitter.cpp \
    src/Expander.cpp \
    src/SplitterHandle.cpp \
    src/Overlay.cpp \
    src/SplitterWidgetDecorator.cpp \
    src/SplitterDecorator.cpp

HEADERS  += \
    include/Splitter.hpp \
    include/QtSplitter/Expander.hpp \
    include/QtSplitter/Global.hpp \
    include/QtSplitter/Overlay.hpp \
    include/QtSplitter/SplitterDecorator.hpp \
    include/QtSplitter/SplitterHandle.hpp \
    include/QtSplitter/SplitterWidgetDecorator.hpp

DEFINES += QTSPLITTER_LIBRARY
