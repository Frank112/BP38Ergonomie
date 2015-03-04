#ifndef EMPLOYEEVIEW_H
#define EMPLOYEEVIEW_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QPushButton>
#include "view/optionselectioncontrol.h"
#include "view/textedit.h"
#include "view/textlineedit.h"
#include "view/valuecontrol.h"
#include "../navigation/simplenavigateablewidget.h"

class EmployeeView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    explicit EmployeeView(QWidget *parent = 0);
    ~EmployeeView();

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

    int getGender() const;
    int getAge() const;
    int getHeight() const;
    QString getStaffNumber() const;
    QString getNote() const;

public slots:
    void setEmployee(int gender, int age, int height, const QString &staffNumber, const QString &note);

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
