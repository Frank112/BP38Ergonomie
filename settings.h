#ifndef SETTINGS
#define SETTINGS

#include <QString>
#include <QHash>
#include <QVariant>
#include <QFile>
#include <QTextStream>

class Settings{

public:
    static void insert(const QString &key, const QVariant &value);

    static QVariant value(const QString &key);

    static bool contains(const QString &key);

    static void loadSettings(const QString &path);

    static void saveSettings(const QString &path);

    static const QString SETTING_THEME;
    static const QString THEME_BLUE;
    static const QString THEME_GREEN;

    static const QString SETTING_LANGUAGE;
    static const QString LANGUAGE_GERMAN;
    static const QString LANGUAGE_ENGLISH;

    static const QString SETTING_SHOW_NOTIFICATIONS;
    static const QString SETTING_SHOW_NAVIGATION_TITLE;

private:
    static QHash<QString, QVariant> settings;

};

#endif // SETTINGS

