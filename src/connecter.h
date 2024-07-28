//
// Created by zszf on 2024/7/27.
//

#ifndef CONNECTER_H
#define CONNECTER_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "qmsgwebsocket.h"

class Connecter : public QObject{
    Q_OBJECT
public:
    Connecter(QObject *parent = nullptr);
    ~Connecter();
    void ping();
private Q_SLOTS:
    void replyFinished(QNetworkReply *rep);
private:
    qmsgwebsocket qmsgwebsocket_;
    QNetworkAccessManager *manager_;
    QNetworkRequest request_;
};

#endif //CONNECTER_H
