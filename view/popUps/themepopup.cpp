#include "themepopup.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include "../standardpaths.h"
#include "../../settings.h"


ThemePopUp::ThemePopUp(QWidget *parent) :
    AbstractPopUpWidget(ConfirmMode::ACCEPT, tr("Change Theme"), parent),
    blue(new DetailedListItem(0, "blueIcon", tr("Blue"), QList<QStringList>(), false, true, false, false, false)),
    green(new DetailedListItem(0, "greenIcon", tr("Green"), QList<QStringList>(), false, true, false, false, false)),
    themes(new QList<DetailedListItem*>())
{
    connect(this, SIGNAL(confirm()), this, SLOT(onConfirm()));
    QVBoxLayout *layout = new QVBoxLayout;

    themes->append(blue);
    themes->append(green);

    for(int i = 0; i < themes->length(); ++i){
        DetailedListItem *theme = themes->at(i);
        theme->setID(i);
        connect(theme, SIGNAL(selected(int)), this, SLOT(selectedThemeChanged(int)));
        connect(this, SIGNAL(themeSelected(int)), theme, SLOT(selectExclusiveWithID(int)));
        layout->addWidget(theme);
    }

    setLayout(layout);
}

ThemePopUp::~ThemePopUp()
{

}

//PUBLIC SLOTS
void ThemePopUp::onEnter(){
    if(Settings::value(Settings::SETTING_THEME).toString() == Settings::THEME_GREEN)
        green->select();
    else
        blue->select();
}

//PRIVATE SLOTS
void ThemePopUp::selectedThemeChanged(int id){
    emit themeSelected(id);
}

void ThemePopUp::onConfirm(){
    if(green->isSelected() && Settings::value(Settings::SETTING_THEME).toString() != Settings::THEME_GREEN){
        Settings::insert(Settings::SETTING_THEME, Settings::THEME_GREEN);
        emit themeChanged();
    }
    else if(blue->isSelected() && Settings::value(Settings::SETTING_THEME).toString() != Settings::THEME_BLUE){
        Settings::insert(Settings::SETTING_THEME, Settings::THEME_BLUE);
        emit themeChanged();
    }
    emit closePopUp();
}
