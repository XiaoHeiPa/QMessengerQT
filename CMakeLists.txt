cmake_minimum_required(VERSION 3.28)
project(qmsg_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_PREFIX "/home/zszf/Qt/6.7.2")

set(CMAKE_PREFIX_PATH ${QT_PREFIX})

find_package(Qt6 COMPONENTS
        Core Widgets Network
        REQUIRED)

add_executable(qmsg_qt main.cpp
        mainwindow.cpp
        mainwindow.h
        connecter.cpp
        connecter.h
        qmsgwebsocket.cpp
        qmsgwebsocket.h)
target_link_libraries(qmsg_qt
        Qt::Core
        Qt::Widgets
        Qt::Network
)

