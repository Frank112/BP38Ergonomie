#include <QApplication>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include "control/controller.h"
#include "../settings.h"

QString stringFromResource(const QString &resName)
{
    QFile file(resName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream ts(&file);
    return ts.readAll();
}

#if defined(Q_OS_IOS)
extern "C" int qtmn(int argc, char **argv)
#else
int main(int argc, char *argv[])
#endif
{
    Settings::loadSettings(StandardPaths::configFile());

    QApplication a(argc, argv); 
    QTranslator t;

    if(!Settings::contains(Settings::SETTING_THEME))
        Settings::insert(Settings::SETTING_THEME, Settings::THEME_BLUE);
    if(Settings::value(Settings::SETTING_THEME).toString() == Settings::THEME_GREEN)
        a.setStyleSheet(stringFromResource(":/assets/stylesheetGreen.qss"));
    else
        a.setStyleSheet(stringFromResource(":/assets/stylesheet.qss"));

    if(!Settings::contains(Settings::SETTING_LANGUAGE))
        Settings::insert(Settings::SETTING_LANGUAGE, Settings::LANGUAGE_GERMAN);
    if(Settings::value(Settings::SETTING_LANGUAGE).toString() == Settings::LANGUAGE_GERMAN)
        t.load(":/translations/ergo_trans_de");
    else
        t.load(":/translations/ergo_trans_en");

    if(!Settings::contains(Settings::SETTING_SHOW_NAVIGATION_TITLE))
        Settings::insert(Settings::SETTING_SHOW_NAVIGATION_TITLE, true);

    if(!Settings::contains(Settings::SETTING_SHOW_NOTIFICATIONS))
        Settings::insert(Settings::SETTING_SHOW_NOTIFICATIONS, true);

    a.installTranslator(&t);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps, true);

    Controller c(0, &a);

    return a.exec();
}
