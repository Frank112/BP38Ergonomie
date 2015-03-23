#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "../navigation/simplenavigateablewidget.h"
#include "../iconbutton.h"
#include "../detailedlistitem.h"

class SettingsView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    explicit SettingsView(QWidget *parent = 0);

public slots:
    void languageChanged();
    void themeChanged();
    void onEnter();

private slots:
    void btnResetRecordingsClicked();
    void btnRestoreFactoryClicked();
    void btnErrorLogClicked();
    void btnSelectLanguageClicked();
    void btnSelectThemeClicked();
    void showTitlesClicked();
    void showNotificationsClicked();

private:
    IconButton *btnResetRecordings;
    IconButton *btnRestoreFactory;
    IconButton *btnErrorLog;
    IconButton *btnSelectLanguage;
    IconButton *btnSelectTheme;
    DetailedListItem *dliShowTitles;
    DetailedListItem *dliShowNotifications;
};

#endif // SETTINGSVIEW_H
