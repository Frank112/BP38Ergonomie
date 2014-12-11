#include "documentationview.h"
#include <QVBoxLayout>
#include "angleview.h"
#include "transportview.h"
#include "actionforceview.h"
#include "executionconditionview.h"

DocumentationView::DocumentationView(QWidget *parent) :
    QWidget(parent)
{
    this->tabs = new QTabWidget;
    this->timer = new StopWatch;

    tabs->addTab(new AngleView, "Körperhaltung");
    tabs->addTab(new TransportView, "Lastenhandhabung");
    tabs->addTab(new ActionForceView, "Aktionskraft");
    tabs->addTab(new ExecutionConditionView, "Ausführungsbedingungen");
    tabs->addTab(timer->btnView, "AV anzeigen");

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(timer);
    this->setLayout(mainLayout);


}
