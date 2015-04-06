#include "settingsview.h"
#include "../separator.h"
#include "../../standardpaths.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextStream>
#include "../../settings.h"

SettingsView::SettingsView(QWidget *parent) :
    SimpleNavigateableWidget(tr("Settings"), parent),
    btnResetRecordings(new IconButton(this, "resetIcon", tr("Reset Recordings"))),
    btnRestoreFactory(new IconButton(this, "resetFactoryIcon", tr("Restore Factory Settings"))),
    btnErrorLog(new IconButton(this, "errorIcon", tr("Error Log"))),
    btnSelectLanguage(new IconButton(this, "germanIcon", tr("Change Language"))),
    btnSelectTheme(new IconButton(this, "blueIcon", tr("Change Theme"))),
    dliShowTitles(new DetailedListItem(this, "titleIcon", tr("Show Titles"), QList<QStringList>(), false, true, false, false, false)),
    dliShowNotifications(new DetailedListItem(this, "notificationIcon", tr("Show Notifications"), QList<QStringList>(), false, true, false, false, false))
{


    btnResetRecordings->setMinimumSize(400, 60);
    connect(btnResetRecordings, SIGNAL(clicked()), this, SLOT(btnResetRecordingsClicked()));

    btnRestoreFactory->setMinimumSize(400, 60);
    connect(btnRestoreFactory, SIGNAL(clicked()), this, SLOT(btnRestoreFactoryClicked()));

    btnErrorLog->setMinimumSize(400, 60);
    connect(btnErrorLog, SIGNAL(clicked()), this, SLOT(btnErrorLogClicked()));

    btnSelectLanguage->setMinimumSize(400, 60);
    connect(btnSelectLanguage, SIGNAL(clicked()), this, SLOT(btnSelectLanguageClicked()));

    btnSelectTheme->setMinimumSize(400, 60);
    connect(btnSelectTheme, SIGNAL(clicked()), this, SLOT(btnSelectThemeClicked()));

    connect(dliShowNotifications, SIGNAL(clicked()), this, SLOT(showNotificationsClicked()));
    connect(dliShowTitles, SIGNAL(clicked()), this, SLOT(showTitlesClicked()));

    QLabel *lblUiSettings = new QLabel(tr("User Interface Settings"));
    QLabel *lblAdvancedSettings = new QLabel(tr("Advanced Settings"));
    lblUiSettings->setObjectName("lblBig");
    lblAdvancedSettings->setObjectName("lblBig");
    QLabel *lblShowTitlesDescription = new QLabel(tr("Disabling this option will cause the the Application not to show titles in the navigation bar."));
    QLabel *lblShowNotificationsDescription = new QLabel(tr("Disabling this option will cause the the Application not to provide notification messages."));
    lblShowTitlesDescription->setWordWrap(true);
    lblShowNotificationsDescription->setWordWrap(true);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->setAlignment(Qt::AlignTop);
    leftLayout->addWidget(lblUiSettings, 0, Qt::AlignCenter);
    leftLayout->addSpacerItem(new QSpacerItem(0,20, QSizePolicy::Minimum, QSizePolicy::Fixed));
    leftLayout->addWidget(new Separator(Qt::Horizontal, 3, this));
    leftLayout->addSpacerItem(new QSpacerItem(0,20, QSizePolicy::Minimum, QSizePolicy::Fixed));

    leftLayout->addWidget(dliShowNotifications);
    leftLayout->addWidget(lblShowNotificationsDescription);
    leftLayout->addSpacerItem(new QSpacerItem(0,60, QSizePolicy::Minimum, QSizePolicy::Fixed));
    leftLayout->addWidget(dliShowTitles);
    leftLayout->addWidget(lblShowTitlesDescription);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->setAlignment(Qt::AlignTop);
    rightLayout->addWidget(lblAdvancedSettings, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,20, QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(new Separator(Qt::Horizontal, 3, this));
    rightLayout->addSpacerItem(new QSpacerItem(0,20, QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(btnResetRecordings, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(btnRestoreFactory, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(btnErrorLog, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(btnSelectLanguage, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    rightLayout->addWidget(btnSelectTheme, 0, Qt::AlignCenter);
    rightLayout->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::Fixed));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(leftLayout);
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addWidget(new Separator(Qt::Vertical, 3, this));
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addLayout(rightLayout);
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    setLayout(mainLayout);
}

//PUBLIC SLOTS
void SettingsView::languageChanged(){
    if(Settings::value(Settings::SETTING_LANGUAGE).toString() == Settings::LANGUAGE_ENGLISH)
        btnSelectLanguage->setIcon("englishIcon");
    else
        btnSelectLanguage->setIcon("germanIcon");
}

void SettingsView::themeChanged(){
    if(Settings::value(Settings::SETTING_THEME).toString() == Settings::THEME_GREEN)
        btnSelectTheme->setIcon("greenIcon");
    else
        btnSelectTheme->setIcon("blueIcon");
}

void SettingsView::onEnter(){
    if(Settings::value(Settings::SETTING_LANGUAGE).toString() == Settings::LANGUAGE_ENGLISH)
        btnSelectLanguage->setIcon("englishIcon");
    else
        btnSelectLanguage->setIcon("germanIcon");

    if(Settings::value(Settings::SETTING_THEME).toString() == Settings::THEME_GREEN)
        btnSelectTheme->setIcon("greenIcon");
    else
        btnSelectTheme->setIcon("blueIcon");

    if(Settings::value(Settings::SETTING_SHOW_NOTIFICATIONS).toBool()){
        dliShowNotifications->select();
    }
    else{
        dliShowNotifications->deselect();
    }
    if(Settings::value(Settings::SETTING_SHOW_NAVIGATION_TITLE).toBool()){
        dliShowTitles->select();
    }
    else{
        dliShowTitles->deselect();
    }
}

//PRIVATE SLOTS
void SettingsView::btnRestoreFactoryClicked(){
    emit showPopUp((Types::PopUpType::FACTORYSETTINGS_POPUP));
}

void SettingsView::btnResetRecordingsClicked(){
    emit showPopUp(Types::PopUpType::RESET_POPUP);
}

void SettingsView::btnErrorLogClicked(){
    emit showView(Types::ViewType::ERROR_LOG_VIEW);
}

void SettingsView::btnSelectLanguageClicked(){
    emit showPopUp(Types::PopUpType::LANGUAGE_POPUP);
}

void SettingsView::btnSelectThemeClicked(){
    emit showPopUp(Types::PopUpType::THEME_POPUP);
}

void SettingsView::showNotificationsClicked(){
    bool oldSetting = Settings::value(Settings::SETTING_SHOW_NOTIFICATIONS).toBool();
    Settings::insert(Settings::SETTING_SHOW_NOTIFICATIONS, !oldSetting);
    Settings::saveSettings(StandardPaths::configFile());
}

void SettingsView::showTitlesClicked(){
    bool oldSetting = Settings::value(Settings::SETTING_SHOW_NAVIGATION_TITLE).toBool();
    Settings::insert(Settings::SETTING_SHOW_NAVIGATION_TITLE, !oldSetting);
    Settings::saveSettings(StandardPaths::configFile());
}
