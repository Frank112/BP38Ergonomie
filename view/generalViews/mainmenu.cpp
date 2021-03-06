#include "mainmenu.h"
#include "../separator.h"
#include <QGridLayout>
#include <QVBoxLayout>

MainMenu::MainMenu(QWidget *parent) :
    SimpleNavigateableWidget(tr("Main menu"), parent),
    lblViewName(new QLabel(tr("Ergonomieapp"))),
    btnMetaDataView(new IconButton(this, "commentIcon", tr("Head Data"))),
    btnWorkplaceList(new IconButton(this, "workplaceIcon", tr("Workplaces"))),
    btnRessourceManagement(new IconButton(this, "equipmentIcon", tr ("Ressource Management"))),
    btnShift(new IconButton(this, "calendarIcon", tr("Shift Data"))),
    btnSettings(new QPushButton(this)),
    btnNewRecording(new QPushButton(this)),
    btnSendDatabase(new QPushButton(this)),
    btnImport(new QPushButton(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    btnMetaDataView->setMinimumSize(300, 60);
    btnWorkplaceList->setMinimumSize(300, 60);
    btnRessourceManagement->setMinimumSize(300, 60);
    btnShift->setMinimumSize(300, 60);

    btnSettings->setObjectName("settingsIcon");
    btnSettings->setFixedSize(45, 45);

    btnSendDatabase->setObjectName("sendIcon");
    btnSendDatabase->setFixedSize(45, 45);

    btnImport->setObjectName("receiveIcon");
    btnImport->setFixedSize(45, 45);

    btnNewRecording->setObjectName("quickRecordingIcon");
    btnNewRecording->setFixedSize(45, 45);

    connect(btnMetaDataView, SIGNAL(clicked()), this, SLOT(btnMetaDataViewClicked()));
    connect(btnWorkplaceList, SIGNAL(clicked()), this, SLOT(btnWorkplaceListClicked()));
    connect(btnRessourceManagement, SIGNAL(clicked()), this, SLOT(btnRessourceManagementClicked()));
    connect(btnShift, SIGNAL(clicked()), this, SLOT(btnShiftClicked()));
    connect(btnNewRecording, SIGNAL(clicked()), this, SLOT(btnNewRecordingClicked()));
    connect(btnSettings, SIGNAL(clicked()), this, SLOT(btnSettingsClicked()));
    connect(btnImport, SIGNAL(clicked()), this, SLOT(btnImportClicked()));
    connect(btnSendDatabase, SIGNAL(clicked()), this, SLOT(btnSendDatabaseClicked()));

    lblViewName->setObjectName("lblHeader");

    mainLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
    mainLayout->addWidget(btnMetaDataView, 0, Qt::AlignCenter);
    mainLayout->addSpacerItem(new QSpacerItem(0,60, QSizePolicy::Minimum, QSizePolicy::Fixed));
    mainLayout->addWidget(btnWorkplaceList, 0, Qt::AlignCenter);
    mainLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    mainLayout->addWidget(btnRessourceManagement, 0, Qt::AlignCenter);
    mainLayout->addSpacerItem(new QSpacerItem(0,60,QSizePolicy::Minimum, QSizePolicy::Fixed));
    mainLayout->addWidget(btnShift, 0, Qt::AlignCenter);
    mainLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::Expanding));

    setLayout(mainLayout);

}

//PUBLIC METHODS
QList<QAbstractButton*> * MainMenu::getAdditionalNavigation() const{
    QList<QAbstractButton*> *additions = new QList<QAbstractButton*>();
    additions->append(btnNewRecording);
    additions->append(btnImport);
    additions->append(btnSendDatabase);
    additions->append(btnSettings);
    return additions;
}

//PRIVATE SLOTS
void MainMenu::btnMetaDataViewClicked(){
    emit showView(Types::ViewType::METADATA_VIEW);
}
void MainMenu::btnSettingsClicked(){
    emit showView(Types::ViewType::SETTINGS_VIEW);
}

void MainMenu::btnWorkplaceListClicked(){
    emit showView(Types::ViewType::WORKPLACELIST_VIEW);
}

void MainMenu::btnRessourceManagementClicked(){
    emit showView(Types::ViewType::RESSOURCE_MANAGMENT_VIEW);
}

void MainMenu::btnShiftClicked(){
    emit showView(Types::ViewType::SHIFT_VIEW);
}

void MainMenu::btnNewRecordingClicked(){
    emit createBlankRecording();
}

void MainMenu::btnSendDatabaseClicked(){
    emit showPopUp(Types::PopUpType::DB_SEND_POPUP);
}

void MainMenu::btnImportClicked(){
    emit showPopUp(Types::PopUpType::IMPORT_DATA_POPUP);
}
