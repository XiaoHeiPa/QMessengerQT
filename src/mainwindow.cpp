//
// Created by zszf on 2024/7/27.
//

#include "mainwindow.h"
#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
QLineEdit* messageInput;
QTextEdit* messageDisplay;
MainWindow::MainWindow() {
    auto* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    auto* chatListWidget = new QListWidget;
    messageDisplay = new QTextEdit;
    messageDisplay->setReadOnly(true);

    messageInput = new QLineEdit;
    auto* sendButton = new QPushButton(tr("Send"));

    auto* inputLayout = new QHBoxLayout;
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);

    auto* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(messageDisplay);
    rightLayout->addLayout(inputLayout);

    auto* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(chatListWidget);
    mainLayout->addLayout(rightLayout);

    centralWidget->setLayout(mainLayout);

    setWindowTitle(tr("QMessenger"));
    setMinimumSize(680, 360);
    resize(680, 360);
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
}

void MainWindow::sendMessage() {
    QString message = messageInput->text();
    if (!message.isEmpty()) {
        messageDisplay->append(tr("Me: %1").arg(message));
        messageInput->clear();
    }
}