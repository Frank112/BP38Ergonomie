#include "languagepopup.h"
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include "../standardpaths.h"
#include "../../settings.h"

LanguagePopUp::LanguagePopUp(QWidget *parent):
   AbstractPopUpWidget(ConfirmMode::ACCEPT, tr("Select language"), parent),
   german(new DetailedListItem(this, "germanIcon",  "Deutsch", QList<QStringList>(), false, true, false, false, false)),
   english(new DetailedListItem(this, "englishIcon",  "English", QList<QStringList>(), false, true, false, false, false)),
   languages(new QList<DetailedListItem*>())
{
    connect(this, SIGNAL(confirm()), this, SLOT(onConfirm()));

    languages->append(german);
    languages->append(english);

    QGridLayout *mainLayout = new QGridLayout;

    for(int i = 0; i < languages->length(); ++i){
        DetailedListItem *language = languages->at(i);
        language->setID(i);
        connect(language, SIGNAL(selected(int)), this, SLOT(setSelectedLanguage(int)));
        connect(this, SIGNAL(languageSelected(int)), language, SLOT(selectExclusiveWithID(int)));
        mainLayout->addWidget(language);
    }

    setLayout(mainLayout);
}

LanguagePopUp::~LanguagePopUp()
{

}

//PUBLIC SLOTS
void LanguagePopUp::onEnter(){
    if(Settings::value(Settings::SETTING_LANGUAGE).toString() == Settings::LANGUAGE_GERMAN)
        german->select();
    else
        english->select();
}

//PRIVATE SLOTS
void LanguagePopUp::onConfirm(){
    if(Settings::value(Settings::SETTING_LANGUAGE).toString() == Settings::LANGUAGE_GERMAN){
        if(english->isSelected()){
            Settings::insert(Settings::SETTING_LANGUAGE, Settings::LANGUAGE_ENGLISH);
            emit showMessage(tr("Language changed"), NotificationMessage::ACCEPT);
            emit showMessage(("Restart App to apply changes"), NotificationMessage::INFORMATION, NotificationMessage::PERSISTENT);
            emit languageChanged();
        }
    }
    else {
        if(german->isSelected()){
            Settings::insert(Settings::SETTING_LANGUAGE, Settings::LANGUAGE_GERMAN);
            emit showMessage(tr("Language changed"), NotificationMessage::ACCEPT);
            emit showMessage(("Neustart erforderlich um die Änderungen zu übernehmen"), NotificationMessage::INFORMATION, NotificationMessage::PERSISTENT);
            emit languageChanged();
        }
    }
    Settings::saveSettings(StandardPaths::configFile());
    emit closePopUp();
}

void LanguagePopUp::setSelectedLanguage(int id){
    emit languageSelected(id);
}


