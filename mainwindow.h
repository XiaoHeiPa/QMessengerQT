//
// Created by zszf on 2024/7/27.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QVBoxLayout>
#include<QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    QLabel *label;
};

#endif //MAINWINDOW_H
