//
// Created by zszf on 2024/7/27.
//

#include "connecter.h"

Connecter::Connecter(QObject *parent)
    : QObject(parent), manager_(new QNetworkAccessManager(this))
{
    connect(manager_, &QNetworkAccessManager::finished, this, &Connecter::replyFinished);
}

Connecter::~Connecter() {
    delete manager_;
    manager_ = nullptr;
}

void Connecter::ping() {
    QNetworkRequest request;

    QUrl backend_address;

    backend_address.setScheme("http");
    backend_address.setHost("backend.lunarclient.top");
    backend_address.setPath("/");

    request.setUrl(backend_address);
    manager_->get(request);
}

void Connecter::replyFinished(QNetworkReply *rep) {
    QByteArray bts = rep->readAll();
    QString str = QString::fromUtf8(bts);
    qDebug().noquote()<<"Reply: "<<str;
    rep->deleteLater();
}
