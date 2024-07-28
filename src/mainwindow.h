//
// Created by zszf on 2024/7/27.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>

#include "connecter.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    QLabel *label;
    QPushButton *connect;
    QAction *connectAction;
};

#endif //MAINWINDOW_H
