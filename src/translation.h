#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QMap>
#include <QString>

class Translation : public QObject
{
    Q_OBJECT

public:
    explicit Translation(QObject* parent = nullptr);
    bool loadTranslations(const QString& directoryPath);
    QString translate(const QString& key) const;
    QString currentlanguage;
    QStringList availableLanguages() const;
    void setCurrentLanguage(const QString& language);

private:
    QMap<QString, QMap<QString, QString>> translations;
};

#endif // TRANSLATION_H
