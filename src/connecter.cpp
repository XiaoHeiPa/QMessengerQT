//
// Created by zszf on 2024/7/27.
//

#include "connecter.h"

#include "Entities.h"
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
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

Authorize Connecter::login(std::string username, std::string password) {
    QNetworkRequest request;

    std::string data_str = "username="+username+"&password="+password;

    QByteArray data = QString::fromStdString(data_str).toUtf8();

    QUrl login_url;

    login_url.setScheme("https");
    login_url.setHost("backend.lunarclient.top");
    login_url.setPath("/user/login");

    request.setUrl(login_url);
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

    QNetworkReply *reply = manager_->post(request, data);

    if(reply->error()) {
        qDebug().noquote()<<"Login Failed";
    }

    reply->deleteLater();

    QByteArray reply_data = reply->readAll();

    auto reply_json = QJsonDocument::fromJson(reply_data);

    if(reply_json.isNull()) {
        qDebug()<< "Failed to get Json.";
    }if(!reply_json.isObject()) {
        qDebug()<< "json is not a object";
    }

    QJsonObject reply_object = reply_json.object();

    QVariantMap result = reply_object.toVariantMap();

    Authorize authorize;

    authorize.email = result["email"].toString();
    authorize.username = result["username"].toString();
    authorize.expire = result["expire"].toInt();
    authorize.token = result["token"].toString();
    authorize.role = result["role"].toString();

    return authorize;
}
void Connecter::getFriends(QString& token) {
    QUrl url("https://backend.lunarclient.top/user/friends/list");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", ("Bearer " + token).toUtf8());
    QNetworkReply* reply = manager_->get(request);
    QByteArray reply_data = reply->readAll();
    auto reply_json = QJsonDocument::fromJson(reply_data);
    QJsonObject reply_object = reply_json.object();

    QVariantMap result = reply_object.toVariantMap();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj["code"].toInt() == 200) {
            QJsonArray friendsArray = jsonObj["data"].toArray();
            for (const QJsonValue& value : friendsArray) {
                QString friendName = value.toObject()["name"].toString();
                qDebug() << "Friend: " << friendName.toStdString();
            }
        }
        else {
            qDebug() << "Failed to get friends: " << jsonObj["message"].toString().toStdString();
        }
    }
    else {
        qDebug() << "Network error: " << reply->errorString().toStdString();
    }
    reply->deleteLater();
}

