#ifndef APPLICATIONS_H
#define APPLICATIONS_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QProcess>
#include <QDebug>

class Applications
{
private:
    QHash<QString, QString> appHashTable;
    QStringList appList;
    QString settingsPath;
public:
    Applications();
    void loadFromJson(QString &path);
    bool contains(QString name);
    bool getPathByName(QString &path, QString name);
    bool launch(QString name);
};

#endif // APPLICATIONS_H
