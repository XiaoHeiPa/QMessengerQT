#include <QApplication>
#include <QTimer>

#include "connecter.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *main_window = new MainWindow;
    main_window->show();
    Connecter connecter;
    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [&connecter]() {
        connecter.ping();
    });
    timer.start();
    return QApplication::exec();
}
