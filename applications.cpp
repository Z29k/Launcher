#include "applications.h"

Applications::Applications()
{

}

void Applications::loadFromJson(QString &path)
{
    settingsPath = path;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }
    QTextStream input(&file);
    QJsonObject jsonObject = QJsonDocument::fromJson(input.readAll().toUtf8()).object();
    QJsonArray jsonArray = jsonObject.value("apps").toArray();

    foreach (const QJsonValue &v, jsonArray)
    {
        appList << v.toObject().value("name").toString();
        appHashTable.insert(v.toObject().value("name").toString(), v.toObject().value("path").toString());
    }
}

bool Applications::contains(QString name)
{
    return appHashTable.contains(name);
}

bool Applications::getPathByName(QString &path, QString name)
{
    if (!this->contains(name))
        return false;
    path = appHashTable.value(name);
    return true;
}

bool Applications::launch(QString name)
{
    if (!this->contains(name))
        return false;
    QString exePath = appHashTable.value(name);
    qDebug() << "Launching " + name + " - " + exePath;
    QProcess::startDetached(exePath, QStringList());
    return true;
}

