#ifndef EMPLOYEELISTVIEW_H
#define EMPLOYEELISTVIEW_H

#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/iemployeelist.h"
#include "../detailedlistitem.h"
#include "../databaseHandler/dbconstants.h"
#include <QPushButton>
#include <QScrollArea>

/**
 * @brief The EmployeeListView class provides functionality to display and edit a list
 * of employees.
 *
 * EmployeeListView inherits SimpleNavigateableWidget and implements IEmployeeList.
 *
 * @author Marius Gassen
 */
class EmployeeListView : public SimpleNavigateableWidget, IEmployeeList
{
    Q_OBJECT
    Q_INTERFACES(IEmployeeList)
public:
    /**
     * @brief EmployeeListView Creates a new EmployeeListView object with the given parent.
     * @param parent The parent of the object.
     */
    EmployeeListView(QWidget *parent = 0);

    bool hasAdditionalNavigation() const {
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:
    void createEmployee(QHash<QString, QVariant> values);
    void deleteEmployee(int id);
    void selectEmployee(int id);

public slots:
    void addEmployee(QHash<QString, QVariant> values);
    void updateEmployee(QHash<QString, QVariant> values);
    void removeEmployee(int id);
    void clearEmployees();

private slots:
    void btnPlusClicked();
    void dliEmployeeClicked(int id);

private:
    const QList<QStringList> employeeCaptions = QList<QStringList>() <<(QStringList() << tr("Staff number"));
    QPushButton *btnPlus;
    QVBoxLayout *listContentLayout;
    QScrollArea *scEmployees;
};

#endif // EMPLOYEELISTVIEW_H
