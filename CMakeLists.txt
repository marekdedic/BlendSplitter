cmake_minimum_required(VERSION 3.6)
project(BlendSplitter)

set(BLENDSPLITTER_VERSION_MAJOR 3)
set(BLENDSPLITTER_VERSION_MINOR 2)
set(BLENDSPLITTER_VERSION_PATCH 0)

add_definitions(-DBLENDSPLITTER_LIBRARY)

set(WARNINGS "-Wall -Weffc++ -pedantic -Wextra -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment -Wconversion -Wdisabled-optimization -Wfloat-equal -Wformat -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self -Winline -Winvalid-pch -Wunsafe-loop-optimizations -Wlong-long -Wmissing-braces -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wparentheses -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wsign-compare -Wstack-protector -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wswitch-default -Wswitch-enum -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable -Wvariadic-macros -Wvolatile-register-var -Wwrite-strings -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

include_directories(include)

set(HEADER_FILES
    include/BS/RegistryItem.hpp
    include/BS/SwitchingBar.hpp
    include/BS/SwitchingWidget.hpp
    include/BS/WidgetRegistry.hpp
    include/implementation/Expander.hpp
    include/implementation/ExpanderCorner.hpp
    include/implementation/ExpanderBottom.hpp
    include/implementation/ExpanderTop.hpp
    include/implementation/Global.hpp
    include/implementation/Overlay.hpp
    include/implementation/SplitterDecorator.hpp
    include/implementation/SplitterHandle.hpp
    include/implementation/SwitchingCombo.hpp
    include/implementation/WidgetDecorator.hpp
    include/BlendSplitter.hpp)

set(SOURCE_FILES
    src/BlendSplitter/Expander.cpp
    src/BlendSplitter/ExpanderCorner.cpp
    src/BlendSplitter/ExpanderBottom.cpp
    src/BlendSplitter/ExpanderTop.cpp
    src/BlendSplitter/Overlay.cpp
    src/BlendSplitter/SplitterDecorator.cpp
    src/BlendSplitter/SplitterHandle.cpp
    src/BlendSplitter/SwitchingCombo.cpp
    src/BlendSplitter/WidgetDecorator.cpp
    src/BlendSplitter.cpp
    src/RegistryItem.cpp
    src/SwitchingBar.cpp
    src/SwitchingWidget.cpp
    src/WidgetRegistry.cpp)

set(RESOURCE_FILES
    BlendSplitterResources.qrc)

add_library(BlendSplitter SHARED ${HEADER_FILES} ${SOURCE_FILES} ${RESOURCE_FILES})

target_link_libraries(BlendSplitter Qt5::Core Qt5::Widgets)

set(BLENDSPLITTER_VERSION_MAJOR_MINOR ${BLENDSPLITTER_VERSION_MAJOR}.${BLENDSPLITTER_VERSION_MINOR})
set(BLENDSPLITTER_VERSION ${BLENDSPLITTER_VERSION_MAJOR_MINOR}.${BLENDSPLITTER_VERSION_PATCH})

add_custom_command(TARGET BlendSplitter POST_BUILD
        COMMAND ln -sf libBlendSplitter.so.${BLENDSPLITTER_VERSION} libBlendSplitter.so.${BLENDSPLITTER_VERSION_MAJOR_MINOR}
        COMMAND ln -sf libBlendSplitter.so.${BLENDSPLITTER_VERSION} libBlendSplitter.so.${BLENDSPLITTER_VERSION_MAJOR})

	set_target_properties(BlendSplitter PROPERTIES VERSION ${BLENDSPLITTER_VERSION} SOVERSION ${BLENDSPLITTER_VERSION_MAJOR})
