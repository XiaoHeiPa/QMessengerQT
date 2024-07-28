//
// Created by zszf on 2024/7/27.
//

#include "mainwindow.h"

MainWindow::MainWindow() {
    auto *widget = new QWidget;
    setCentralWidget(widget);

    auto *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(label);
    layout->addWidget(connect);
    widget->setLayout(layout);
    setWindowTitle(tr("Qmsg"));
    setMinimumSize(160, 160);
    resize(680, 360);
}
