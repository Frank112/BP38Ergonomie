#ifndef EMPLOYEEVIEW_H
#define EMPLOYEEVIEW_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QPushButton>
#include "../optionselectioncontrol.h"
#include "../textedit.h"
#include "../textlineedit.h"
#include "../valuecontrol.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/iemployee.h"
#include "../databaseHandler/dbconstants.h"

/**
 * @brief The EmployeeView class provides functionality to display and document employee data.
 *
 * EmployeeView inherits SimpleNavigateableWidget and implements IEmployee.
 *
 * @author Marius Gassen
 */
class EmployeeView : public SimpleNavigateableWidget, IEmployee
{
    Q_OBJECT
    Q_INTERFACES(IEmployee)
public:
    /**
     * @brief EmployeeView Creates a new EmployeeView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit EmployeeView(QWidget *parent = 0);
    ~EmployeeView();

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:
    void saveEmployee(QHash<QString, QVariant> values);


public slots:
    void setEmployee(QHash<QString, QVariant> values);
    void onLeaving();

private slots:
    void btnBodyMeasurementsClicked();

private:
    QLabel *lblGender;
    QLabel *lblStaffNumber;
    QLabel *lblNote;

    OptionSelectionControl *oscGender;
    ValueControl *vcAge;
    ValueControl *vcHeight;
    TextLineEdit *txtBxStaffNumber;
    TextEdit *txtBxNote;

    QPushButton *btnBodyMeasurements;

    const QStringList genderTextValues = QStringList()<<tr("male")<<tr("female");
    const QVector<int> heightValues = QVector<int>()<<150<<160<<170<<180<<190;
    const QVector<int> ageValues = QVector<int>()<<20<<30<<40<<50<<60;
};

#endif // EMPLOYEEVIEW_H
