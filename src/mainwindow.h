//
// Created by zszf on 2024/7/27.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QTextEdit>
#include <QComboBox>

#include "connecter.h"
#include "translation.h"
#include <QLineEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    void sendMessage();
    void changeLanguage(const QString& language);
    Translation translator;
private:
    QLabel *label;
    QPushButton *connecter;
    QAction *connectAction;
    Connecter connection;
};

#endif //MAINWINDOW_H
