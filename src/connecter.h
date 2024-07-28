//
// Created by zszf on 2024/7/27.
//

#ifndef CONNECTER_H
#define CONNECTER_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

#include "qmsgwebsocket.h"

class Connecter : public QObject{
    Q_OBJECT
public:
    Connecter(QObject *parent = nullptr);
    ~Connecter();
    void ping();
    Authorize login(std::string username, std::string password);
    void getFriends(QString& token);
private Q_SLOTS:
    void replyFinished(QNetworkReply *rep);
private:
    QNetworkAccessManager *manager_;
};

#endif //CONNECTER_H
