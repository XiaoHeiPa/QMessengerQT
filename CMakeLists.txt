cmake_minimum_required(VERSION 3.27.2)
project(qmsg_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_PREFIX "D:/Qt/6.8.0")


set(CMAKE_PREFIX_PATH ${QT_PREFIX})

find_package(Qt6 COMPONENTS
        Core Widgets Network WebSockets
        REQUIRED)

add_subdirectory(src)