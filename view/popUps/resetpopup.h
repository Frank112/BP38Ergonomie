#ifndef RESETPOPUP_H
#define RESETPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include "../interfaces/iselecteddatabasereset.h"

class ResetPopUp : public AbstractPopUpWidget, ISelectedDatabaseReset
{
    Q_OBJECT
    Q_INTERFACES(ISelectedDatabaseReset)
public:
    explicit ResetPopUp(QWidget *parent = 0);
    ~ResetPopUp();

    bool headDataSelected() const;
    bool workplacesSelected() const;
    bool equipmentSelected() const;
    bool productsSelected() const;
    bool transportationSelected() const;
    bool employeeSelected() const;
    bool shiftDataSelected() const;
    bool ftpConnectionSelected() const;

signals:
    void resetSelectedEntries(ISelectedDatabaseReset *widget);

public slots:
    void onEnter();

private slots:
    void headDataClicked();
    void workplacesClicked();
    void equipmentClicked();
    void productsClicked();
    void transportationClicked();
    void employeeClicked();
    void shiftDataClicked();
    void ftpConnectionClicked();

    void onConfirm();

private:
    DetailedListItem *headData;
    DetailedListItem *workplaces;
    DetailedListItem *equipment;
    DetailedListItem *products;
    DetailedListItem *transportation;
    DetailedListItem *employee;
    DetailedListItem *shiftData;
    DetailedListItem *ftpConnection;

    bool bHeadData;
    bool bWorklpaces;
    bool bEquipment;
    bool bProducts;
    bool bTransportation;
    bool bEmployee;
    bool bShiftData;
    bool bFtpConnection;
};

#endif // RESETPOPUP_H
