#include <QApplication>
#include <QTranslator>
#include "viewcontroller.h"
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>

#if defined(Q_OS_IOS)
extern "C" int qtmn(int argc, char **argv)
#else
int main(int argc, char *argv[])
#endif
{
    QApplication a(argc, argv);

    a.setStyleSheet(    "QWidget {background-color: #efeff4;}"
                        "QMainWindow {background-color: #efeff4;}"
                        "Separator {background-color: #c8c7cc; margin: 5px 5px 5px 5px;}"
                        "QLabel {font: 100 18px \"Serif\"; color: #8e8e93;}"
                        "QGroupBox {border:2px solid #c8c7cc; background-color: #efeff4; border-radius: 10px;}"
                        "QLineEdit {font: 100 18px \"Serif\";border: 2px solid #007aff; border-radius: 10px; background: #f5f5f5; color: #8e8e93; padding: 4px;}"
                        "QSlider::groove:horizontal {border: 1px solid #007aff; background: #efeff4; height: 5px;border-radius: 2px;}"
                        "QSlider::handle:horizontal {border: 2px solid #007aff; width: 38px; height: 38px; border-radius: 20px; background: #efeff4; margin: -20px 0;}"
                        "QSlider::add-page:horizontal {background: #b5b6b5;}"
                        "QSlider::sub-page:horizontal {background: #007aff;}"
                        "QPushButton {font: 100 18px \"Serif\";color: #007aff; border: 2px solid #007aff; border-radius: 10px; background-color: #f5f5f5; padding: 4px;}"
                        "QPushButton:pressed {color: #ffffff; background-color: #007aff;}"
                        "QPushButton#btnCamera {image: url(:/icons/specialPurposeIcons/camera.png); width: 50px; height: 50px; border: 0px; background-color: #efeff4;}"
                        "QPushButton#btnNavigation {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerStartPauseButton {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerStopResetButton {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerMinimizeButton {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerMaximizeButton {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerZoomInButton {border: 0px; background-color: #efeff4}"
                        "QPushButton#timerZoomOutButton {border: 0px; background-color: #efeff4}"
                        "QScrollArea {background-color: #efeff4; margin: 0 0; border: none;}"
                        "QScrollBar:vertical {border: 0px solid #007aff; margin: 0px 0px 0px 0px; background: #efeff4;}"
                        "QScrollBar::handle:vertical {background: #007aff; min-width: 60px; border-radius: 5px;}"
                        "QScrollBar::sub-line:vertical, QScrollBar::add-line:vertical  {border: 0px solid #007aff; background: #efeff4;}"
                        "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {width: 0px; height: 0px;}"
                        "QScrollBar:horizontal {border: 0px solid #007aff; margin: 0px 0px 0px 0px; background: #efeff4;}"
                        "QScrollBar::handle:horizontal {background: #007aff; min-width: 60px; border-radius: 5px;}"
                        "QScrollBar::sub-line:horizontal, QScrollBar::add-line:horizontal  {border: 0px solid #007aff; background: #efeff4;}"
                        "OwnCon {background-color: #efeff4;}"
                        "QTabWidget::pane {border-top: 2px solid #c8c7cc; margin-top: -35px;}"
                        "QTabWidget::tab-bar {alignment: center; }"
                        "QTabBar::Tab {border: 1px solid #007aff; border-top-left-radius: 4px; border-top-right-radius: 4px; padding: 6px; margin-bottom: -1px;}"
                        "QTabBar::Tab:selected {color: #ffffff; background-color: #007aff; margin-left: -4px; margin-right: -4px}"
                        "QTabBar::Tab:first:selected {margin-left: 0px}"
                        "QTabBar::Tab:last:selected {margin-right: 0px}"
                        "QTabBar::Tab:!selected {color: #007aff; background-color: #f5f5f5; margin-top: 2px}"
                        "QComboBox {font: 100 18px \"Serif\"; color: #007aff; border: 2px solid #007aff; border-radius: 10px; background-color: #f5f4f4; padding: 4px;}"
                        "QComboBox::drop-down {background-color: #007aff;}"
                        "QComboBox::down-arrow {image: url(:/icons/specialPurposeIcons/downarrow.png);}"
                        "QComboBox::down-arrow:on {image: url(:/icons/specialPurposeIcons/downarrowon.png);}"
                        );
    QString tmpString;
    QFileInfo databaseFileInfo;
    QString databaseOriginPath;

    #if defined(Q_OS_ANDROID)
        databaseOriginPath = QString(":/android/assets/ergoAppDB.sqlite");
        tmpString = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        databaseFileInfo = QFileInfo(QString("%1/%2").arg(tmpString).arg("ergoAppDB.sqlite"));
    #endif


    #if defined(Q_OS_IOS)
        databaseOriginPath = QString("%1/%2/%3").arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)).arg("Documents").arg("ergoAppDB.sqlite");
        tmpString = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        databaseFileInfo = QFileInfo(QString("%1/%2").arg(tmpString).arg("ergoAppDB.sqlite"));
    #endif

    QString databasePath = databaseFileInfo.absoluteFilePath();

    if ( !databaseFileInfo.exists() )
       {
           bool copySuccess = QFile::copy( databaseOriginPath, databasePath );
           if ( !copySuccess )
           {
               QMessageBox::critical(0, "Error:", QString("Could not copy database from %1 to %2").arg(databaseOriginPath).arg(databasePath));
               databasePath.clear();
           }
           else{
                if(!QFile::setPermissions(databasePath,QFile::WriteOwner | QFile::ReadOwner)){
                   QMessageBox::critical(0, "Error:", "Could not set permissions");
                }
           }
       }

    QTranslator translator;
    translator.load("ergo_trans_de");
    a.installTranslator(&translator);


    ViewController vc;
    vc.show();


    return a.exec();
}
