#include <QApplication>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include "control/controller.h"
#include "translator.h"
#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
#include <opencv2/core/core.hpp>
Q_DECLARE_METATYPE(cv::Mat)
#endif

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
    #if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    qRegisterMetaType<cv::Mat>();
    #endif

    QApplication a(argc, argv);

    a.setStyleSheet(stringFromResource(":/assets/stylesheet.qss"));
    a.setAttribute(Qt::AA_UseHighDpiPixmaps, true);

    Translator t(&a);
    t.loadTranslations(":/translations");
    t.setLanguage("trans_DE");

    Controller c(0, &a, &t);
    /*QTranslator translator;
    translator.load(":/translations/ergo_trans_de");
    a.installTranslator(&translator);*/

    return a.exec();
}
