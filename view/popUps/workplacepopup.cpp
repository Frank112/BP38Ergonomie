#include "workplacepopup.h"
#include "../../databaseHandler/dbconstants.h"

WorkplacePopUp::WorkplacePopUp(QWidget *parent) :
    AbstractPopUpWidget(ConfirmMode::ACCEPT, tr("Create Workplace"), parent),
    lblName(new QLabel(tr("Name:"))),
    lblDescription(new QLabel(tr("Description:"))),
    lblCode(new QLabel(tr("Code:"))),
    lblPercentageWomen(new QLabel(tr("User population:"))),
    txtBxName(new TextLineEdit()),
    txtBxDescription(new TextLineEdit()),
    txtBxCode(new TextLineEdit()),
    numBxPercentageWomen(new NumberLineEdit()),
    lblGuidelineTimes(new QLabel(tr("Guideline times  [mm:ss]"), this)),
    lblSetupTime(new QLabel(tr("Setup time:"), this)),
    lblBasicTime(new QLabel(tr("Basic time:"), this)),
    lblRestTime(new QLabel(tr("Rest time:"), this)),
    lblAllowanceTime(new QLabel(tr("Deploy time:"),this)),
    lblCycleTime(new QLabel(tr("Cycle time:"))),
    timeSetupTime(new TimeLineEdit(this, TimeLineType::MINUTE_SECOND)),
    timeBasicTime(new TimeLineEdit(this, TimeLineType::MINUTE_SECOND)),
    timeRestTime(new TimeLineEdit(this, TimeLineType::MINUTE_SECOND)),
    timeAllowanceTime(new TimeLineEdit(this, TimeLineType::MINUTE_SECOND)),
    timeCycleTime(new TimeLineEdit(this, TimeLineType::MINUTE_SECOND))
{
    lblGuidelineTimes->setObjectName("lblHeader");

    txtBxName->setPlaceholderText(tr("name of the workplace"));
    txtBxDescription->setPlaceholderText(tr("description of the workplace"));
    txtBxCode->setPlaceholderText(tr("code of the workplace"));

    timeSetupTime->setTime(QTime(0,0));
    timeBasicTime->setTime(QTime(0,0));
    timeRestTime->setTime(QTime(0,0));
    timeAllowanceTime->setTime(QTime(0,0));
    timeCycleTime->setTime(QTime(0,0));

    connect(this, SIGNAL(confirm()), this, SLOT(onConfirm()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(lblName, 0, 0, 1, 1, 0);
    mainLayout->addWidget(txtBxName, 0, 1, 1, 1, 0);
    mainLayout->addWidget(lblDescription, 1, 0, 1, 1, 0);
    mainLayout->addWidget(txtBxDescription, 1, 1, 1, 1, 0);
    mainLayout->addWidget(lblCode, 2, 0, 1, 1, 0);
    mainLayout->addWidget(txtBxCode, 2, 1, 1, 1, 0);
    mainLayout->addWidget(lblPercentageWomen, 3, 0, 1, 1, 0);
    mainLayout->addWidget(numBxPercentageWomen, 3, 1, 1, 1, 0);

    mainLayout->addWidget(lblGuidelineTimes, 4, 0, 1, 2, 0);

    mainLayout->addWidget(lblSetupTime, 5, 0, 1, 1, 0);
    mainLayout->addWidget(timeSetupTime, 5, 1, 1, 1, 0);
    mainLayout->addWidget(lblBasicTime, 6, 0, 1, 1, 0);
    mainLayout->addWidget(timeBasicTime, 6, 1, 1, 1, 0);
    mainLayout->addWidget(lblRestTime, 7, 0, 1, 1, 0);
    mainLayout->addWidget(timeRestTime, 7, 1, 1, 1, 0);
    mainLayout->addWidget(lblAllowanceTime, 8, 0, 1, 1, 0);
    mainLayout->addWidget(timeAllowanceTime, 8, 1, 1, 1, 0);
    mainLayout->addWidget(lblCycleTime, 9, 0, 1, 1, 0);
    mainLayout->addWidget(timeCycleTime, 9, 1, 1, 1, 0);

    setLayout(mainLayout);
}

WorkplacePopUp::~WorkplacePopUp(){

}

// PRIVATE SLOTS
void WorkplacePopUp::onConfirm(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_NAME, txtBxName->text());
    values.insert(DBConstants::COL_WORKPLACE_DESCRIPTION, txtBxDescription->text());
    values.insert(DBConstants::COL_WORKPLACE_CODE, txtBxCode->text());
    values.insert(DBConstants::COL_WORKPLACE_PERCENTAGE_WOMAN, numBxPercentageWomen->getValue());
    values.insert(DBConstants::COL_WORKPLACE_SETUP_TIME, timeSetupTime->getTime());
    values.insert(DBConstants::COL_WORKPLACE_BASIC_TIME, timeBasicTime->getTime());
    values.insert(DBConstants::COL_WORKPLACE_REST_TIME, timeRestTime->getTime());
    values.insert(DBConstants::COL_WORKPLACE_ALLOWANCE_TIME, timeAllowanceTime->getTime());
    values.insert(DBConstants::COL_WORKPLACE_CYCLE_TIME, timeCycleTime->getTime());
    emit saveWorkplace(values);
    txtBxName->clear();
    txtBxDescription->clear();
    txtBxCode->clear();
    numBxPercentageWomen->setValue(0);

    timeSetupTime->setTime(QTime(0,0));
    timeBasicTime->setTime(QTime(0,0));
    timeRestTime->setTime(QTime(0,0));
    timeAllowanceTime->setTime(QTime(0,0));
    timeCycleTime->setTime(QTime(0,0));
    emit closePopUp();
}
