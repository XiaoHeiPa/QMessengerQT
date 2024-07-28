qt_add_executable(qmsg_qt
        main.cpp
        mainwindow.cpp
        connecter.cpp
        qmsgwebsocket.cpp
)

target_link_libraries(qmsg_qt PRIVATE Qt6::Core Qt6::Widgets Qt6::WebSockets Qt6::Network)

set_target_properties(qmsg_qt PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)