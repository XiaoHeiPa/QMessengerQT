#include "translation.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
Translation Translation::translator;
Translation::Translation(QObject* parent) : QObject(parent)
{
}

bool Translation::loadTranslations(const QString& directoryPath)
{
    QDir dir(directoryPath);
    if (!dir.exists()) {
        qDebug() << "Directory does not exist:" << directoryPath;
        return false;
    }

    QStringList filters;
    filters << "*.lang";
    dir.setNameFilters(filters);

    foreach(QString fileName, dir.entryList()) {
        QFile file(dir.filePath(fileName));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file:" << file.fileName();
            continue;
        }

        QString language = fileName.split(".").first();

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("=");
            if (parts.size() == 2) {
                QString key = parts[0].trimmed();
                QString value = parts[1].trimmed();
                translations[language][key] = value;
            }
            else {
                qDebug() << "Invalid line format in file:" << file.fileName() << " Line:" << line;
            }
        }

        file.close();
    }

    return true;
}

QString Translation::translatetext(const QString& key) const
{
    if (translations.contains(currentlanguage)) {
        return translations[currentlanguage].value(key, key);
    }
    return QString("Language not supported");
}

QStringList Translation::availableLanguages() const
{
     return translations.keys();
}

void Translation::setCurrentLanguage(const QString& language)
{
    currentlanguage = language;
}

void Translation::initTranslation()
{
    QLocale locale;
    QString systemLanguage = locale.name();
    translator.setCurrentLanguage(systemLanguage);
    //language should on runningDir/translation/
    if (translator.loadTranslations("./translations")) {
        qDebug() << "Translations loaded successfully.";
    }
    else {
        qDebug() << "Translations loaded unsuccessfully.";
    }
}
QString Translation::translate(const QString& key) {
    return translator.translatetext(key);
}