//
// Created by zszf on 2024/7/28.
//

#ifndef AUTHORIZE_H
#define AUTHORIZE_H
#include <QObject>

class Authorize: public QObject {
    Q_OBJECT
private:
    QString username;
    QString role; // USER ADMIN
    QString token;
    QString email;
    long exprie = 0;

    QString password = nullptr;
};

#endif //AUTHORIZE_H
