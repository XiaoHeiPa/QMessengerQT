//
// Created by zszf on 2024/7/27.
//

#include "connecter.h"

#include "Entities.h"

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

