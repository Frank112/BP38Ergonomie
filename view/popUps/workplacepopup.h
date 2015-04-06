#ifndef WORKPLACEPOPUP_H
#define WORKPLACEPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../numberlineedit.h"
#include "../timelineedit.h"
#include "../interfaces/iworkplace.h"

/**
 * @brief The WorkplacePopUp class provides functionality to create a new workplace with a form
 * displayed in a popup.
 *
 * WorkplacePopUp inherits AbstractPopUpWidget and implements IWorkplace.
 *
 * Pressing confirm button of the popup emits the saveWorkplace() signal to indicate the
 * entered data should be saved and a new workplace is created.
 *
 * @author Marius Gassen
 */
class WorkplacePopUp : public AbstractPopUpWidget, IWorkplace
{
    Q_OBJECT
    Q_INTERFACES(IWorkplace)
public:
    /**
     * @brief WorkplacePopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
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
