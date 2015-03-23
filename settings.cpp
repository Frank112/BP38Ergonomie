#include "settings.h"
void Settings::insert(const QString &key, const QVariant &value){
    settings.insert(key, value);
}

QVariant Settings::value(const QString &key){
    return settings.value(key);
}

bool Settings::contains(const QString &key){
    return settings.contains(key);
}

void Settings::loadSettings(const QString &path){
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList keyValuePair = line.split('=');
            insert(keyValuePair.at(0).trimmed(), keyValuePair.at(1).trimmed());
        }
        file.close();
    }

}

void Settings::saveSettings(const QString &path){
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        foreach(QString key, settings.keys()){
            out<<key<<"="<<settings.value(key).toString()<<"\n";
        }
        file.close();
    }
}

const QString Settings::SETTING_THEME = "Theme";
const QString Settings::THEME_BLUE = "blue";
const QString Settings::THEME_GREEN = "green";

const QString Settings::SETTING_LANGUAGE = "Language";
const QString Settings::LANGUAGE_GERMAN = "german";
const QString Settings::LANGUAGE_ENGLISH = "english";

const QString Settings::SETTING_SHOW_NOTIFICATIONS = "showNotifications";
const QString Settings::SETTING_SHOW_NAVIGATION_TITLE = "showNavigationTitle";

QHash<QString, QVariant> Settings::settings = QHash<QString, QVariant>();
