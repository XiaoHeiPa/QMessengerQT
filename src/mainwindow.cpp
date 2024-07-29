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
#include "translation.h"
QLineEdit* messageInput;
QTextEdit* messageDisplay;
MainWindow::MainWindow() {
    //loading translation
    translator.currentlanguage = "zh-hans";
    if (translator.loadTranslations("./translation")) {
        qDebug() << "Translations loaded successfully.";
    }
    else {
        qDebug() << "Failed to load translations.";
    }

    auto* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    auto* chatListWidget = new QListWidget;
    messageDisplay = new QTextEdit;
    messageDisplay->setReadOnly(true);

    messageInput = new QLineEdit;
    auto* sendButton = new QPushButton(translator.translate("main.send"));

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
        messageDisplay->append(translator.translate("main.myself") + tr(":%1").arg(message));

        messageInput->clear();
    }
}
void MainWindow::changeLanguage(const QString& language) {
    translator.setCurrentLanguage(language);

    QPushButton* sendButton = findChild<QPushButton*>();
    if (sendButton) {
        sendButton->setText(translator.translate("main.send"));
    }
}