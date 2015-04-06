#include "appliedforceview.h"
#include "../separator.h"
#include "../flickcharm.h"
#include "../../databaseHandler/dbconstants.h"
#include <QScroller>

const QVector<int> AppliedForceView::INTENSITY_VALUES = QVector<int>()<<5<<20<<50<<100<<150;


AppliedForceView::AppliedForceView(QWidget *parent) :
    TitledWidget(tr("Applied force"), parent),
    valConIntensity(new ValueControl(this)),
    txtConDirection(new TextControl(this)),
    txtConOrgan(new TextControl(this))
{
    valConIntensity->setValues(0, 300, INTENSITY_VALUES, QString(""));
    valConIntensity->setUnit(tr("N"));
    valConIntensity->setText(tr("intensity"));

    txtConDirection->setValues(true, DIRECTION_TEXTS, DIRECTION_VALUES, QString(""));
    txtConDirection->setText(tr("direction:"));

    txtConOrgan->setValues(true, ORGAN_TEXTS, ORGAN_TEXTS, QString(""));
    txtConOrgan->setText(tr("organ:"));

    QVBoxLayout *lytMainContent = new QVBoxLayout;
    lytMainContent->addWidget(valConIntensity);
    lytMainContent->addWidget(new Separator(Qt::Horizontal, 3, this));
    lytMainContent->addWidget(txtConDirection);
    lytMainContent->addWidget(new Separator(Qt::Horizontal, 3, this));
    lytMainContent->addWidget(txtConOrgan);

    QWidget *wdgtMainContent = new QWidget(this);
    wdgtMainContent->setLayout(lytMainContent);

    QScrollArea *scMainContent = new QScrollArea(this);
    scMainContent->setWidget(wdgtMainContent);
    scMainContent->setWidgetResizable(true);

    FlickCharm *flickCharm = new FlickCharm(this);
    flickCharm->activateOn(scMainContent);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(scMainContent);
    this->setLayout(mainLayout);
}

//PUBLIC SLOTS
void AppliedForceView::setAppliedForce(QHash<QString, QVariant> values){
    txtConOrgan->setValue(values.value(DBConstants::COL_APPLIED_FORCE_ORGAN).toString());
    txtConDirection->setValue(values.value(DBConstants::COL_APPLIED_FORCE_DIRECTION).toString());
    valConIntensity->setValue(values.value(DBConstants::COL_APPLIED_FORCE_INTENSITY).toInt());
}

void AppliedForceView::onLeaving(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_APPLIED_FORCE_ORGAN, txtConOrgan->getTextValue());
    values.insert(DBConstants::COL_APPLIED_FORCE_DIRECTION, txtConDirection->getTextValue());
    values.insert(DBConstants::COL_APPLIED_FORCE_INTENSITY, valConIntensity->getValue());
    emit saveAppliedForce(values);
}
