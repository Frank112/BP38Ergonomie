#include "employeelistview.h"

#include <QList>
#include "../flickcharm.h"

EmployeeListView::EmployeeListView(QWidget *parent) :
       SimpleNavigateableWidget(tr("Employees"), parent),
       btnPlus(new QPushButton(this)),
       listContentLayout(new QVBoxLayout()),
       scEmployees(new QScrollArea())
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *listContent = new QWidget;

    btnPlus->setObjectName("plusIcon");
    btnPlus->setFixedSize(45, 45);

    connect(btnPlus, SIGNAL(clicked()), this, SLOT(btnPlusClicked()));

    scEmployees->setWidget(listContent);
    scEmployees->setWidgetResizable(true);
    FlickCharm *flickCharm = new FlickCharm(this);
    flickCharm->activateOn(scEmployees);

    listContent->setLayout(listContentLayout);
    listContentLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(scEmployees);

    this->setLayout(mainLayout);
}

//PUBLIC SLOTS
void EmployeeListView::addEmployee(QHash<QString, QVariant> values){
    QList<QStringList> dliValues = QList<QStringList>() << (QStringList() << values.value(DBConstants::COL_EMPLOYEE_STAFF_NUMBER).toString());
    DetailedListItem *newListItem = new DetailedListItem(this, "userIcon", tr("Employee"), employeeCaptions, true, false, true);
    newListItem->setValues(dliValues);
    newListItem->setID(values.value(DBConstants::COL_EMPLOYEE_ID).toInt());
    connect(newListItem, SIGNAL(pressed(int)), this, SLOT(dliEmployeeClicked(int)));
    connect(newListItem, SIGNAL(deleteItem(int)), this, SIGNAL(deleteEmployee(int)));
    listContentLayout->addWidget(newListItem);
}

void EmployeeListView::removeEmployee(int id){
    QLayoutItem *item;
    while((item = listContentLayout->takeAt(0)) != NULL){
        DetailedListItem *dli = qobject_cast<DetailedListItem*>(item->widget());
        if(dli->getID() == id){
            delete dli;
            delete item;
            break;
        }
    }
}

void EmployeeListView::clear(){
    QLayoutItem *item;
    while((item = listContentLayout->takeAt(0)) != NULL){
        delete item->widget();
        delete item;
    }
}

//PUBLIC METHODS
QList<QAbstractButton*> * EmployeeListView::getAdditionalNavigation() const{
    QList<QAbstractButton*> *additions = new QList<QAbstractButton*>();
    additions->append(btnPlus);
    return additions;
}

//PRIVATE SLOTS
void EmployeeListView::btnPlusClicked(){
    emit selectEmployee(0);
    emit showView(ViewType::EMPLOYEE_VIEW);
}

void EmployeeListView::dliEmployeeClicked(int id){
    emit selectEmployee(id);
    emit showView(ViewType::EMPLOYEE_VIEW);
}
