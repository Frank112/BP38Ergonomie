#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "../navigation/simplenavigateablewidget.h"
#include "../iconbutton.h"
#include "../detailedlistitem.h"

/**
 * @brief The SettingsView class provides functionality to display and select
 * different application settings.
 *
 * SettingsView inherits SimpleNavigateableWidget.
 *
 * @author Marius Gassen
 */
class SettingsView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    /**
     * @brief SettingsView Creates a new SettingsView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit SettingsView(QWidget *parent = 0);

public slots:
    /**
     * @brief languageChanged Sets the language icon according to the selected language.
     */
    void languageChanged();

    /**
     * @brief themeChanged Sets the theme icon according to the selected theme.
     */
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
