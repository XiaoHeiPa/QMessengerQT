#include <QApplication>

#include "connecter.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *main_window = new MainWindow;
    main_window->show();
    qDebug()<<11;

    Connecter connecter;
    connecter.ping();
    Authorize authorize = connecter.login("zszf", "114514");
    connecter.getFriends(authorize.token);

    qDebug()<<authorize.token;
    return QApplication::exec();
}
