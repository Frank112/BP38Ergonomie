#ifndef WORKPLACEPOPUP_H
#define WORKPLACEPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../numberlineedit.h"
#include "../timelineedit.h"
#include "../interfaces/iworkplace.h"

class WorkplacePopUp : public AbstractPopUpWidget, IWorkplace
{
    Q_OBJECT
    Q_INTERFACES(IWorkplace)
public:
    explicit WorkplacePopUp(QWidget *parent = 0);
    ~WorkplacePopUp();

signals:
    void saveWorkplace(QHash<QString, QVariant> values);

public slots:
    void setWorkplace(QHash<QString, QVariant>){}
    void setSavedLine(QHash<QString, QVariant>){}
    void setSavedComment(QHash<QString, QVariant>){}

private slots:
    void onConfirm();

private:
    QLabel *lblName;
    QLabel *lblDescription;
    QLabel *lblCode;
    QLabel *lblPercentageWomen;

    TextLineEdit *txtBxName;
    TextLineEdit *txtBxDescription;
    TextLineEdit *txtBxCode;
    NumberLineEdit *numBxPercentageWomen;


    QLabel *lblGuidelineTimes;
    QLabel* lblAllowedTime;
    QLabel* lblSetupTime;
    QLabel* lblBasicTime;
    QLabel* lblRestTime;
    QLabel* lblAllowanceTime;
    QLabel* lblCycleTime;

    TimeLineEdit* timeSetupTime;
    TimeLineEdit* timeBasicTime;
    TimeLineEdit* timeRestTime;
    TimeLineEdit* timeAllowanceTime;
    TimeLineEdit* timeCycleTime;
};

#endif // WORKPLACEPOPUP_H
