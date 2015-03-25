#include "errorlogview.h"
#include <QVBoxLayout>

ErrorLogView::ErrorLogView(QWidget *parent) :
    SimpleNavigateableWidget(tr("Error Log"), parent),
    txtBxErrors(new TextEdit(this)),
    btnClearErrorLog(new QPushButton(this))
{
    btnClearErrorLog->setObjectName("resetFactoryIcon");
    btnClearErrorLog->setFixedSize(45, 45);
    connect(btnClearErrorLog, SIGNAL(clicked()), this, SLOT(btnClearErrorLogClicked()));
    txtBxErrors->setReadOnly(true);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(txtBxErrors);
    setLayout(mainLayout);
}

// PUBLIC METHODS
QList<QAbstractButton*> * ErrorLogView::getAdditionalNavigation() const{
    QList<QAbstractButton*> *additions = new QList<QAbstractButton*>();
    additions->append(btnClearErrorLog);
    return additions;
}

// PUBLIC SLOTS
void ErrorLogView::onEnter(){
    QStringList errors = ErrorReporter::getErrorLog();
    for(int i = 0; i < errors.size(); ++i)
        txtBxErrors->append(errors.at(i));
}

void ErrorLogView::onLeaving(){
    txtBxErrors->clear();
}

// PRIVATE SLOTS
void ErrorLogView::btnClearErrorLogClicked(){
    ErrorReporter::clearErrorLog();
    txtBxErrors->clear();
}
