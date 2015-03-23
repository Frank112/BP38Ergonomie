#include "factorysettingspopup.h"
#include <QGridLayout>

FactorySettingsPopUp::FactorySettingsPopUp(QWidget *parent):
    AbstractPopUpWidget(ConfirmMode::ACCEPT, tr("Restore Factory Settings"), parent)
{
    connect(this, SIGNAL(confirm()), this, SLOT(onConfirm()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel(tr("Are you sure? Restoring to Factory Settings will delete all data.")), 0, 0, 1, 2, 0);

    setLayout(mainLayout);
}

FactorySettingsPopUp::~FactorySettingsPopUp()
{

}


//PRIVATE SLOTS
void FactorySettingsPopUp::onConfirm(){
    emit closePopUp();
}
