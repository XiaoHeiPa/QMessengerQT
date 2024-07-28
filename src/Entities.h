//
// Created by zszf on 2024/7/28.
//

#ifndef ENTITIES_H
#define ENTITIES_H
#include <QObject>

struct Authorize {
    QString username;
    QString email;
    int expire;
    QString token;
    QString role;
};
#endif // ENTITIES_H