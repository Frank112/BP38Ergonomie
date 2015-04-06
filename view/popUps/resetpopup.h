#ifndef RESETPOPUP_H
#define RESETPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include "../interfaces/iselecteddatabasereset.h"

/**
 * @brief The ResetPopUp class provides functionality to select various entries to reset from a list
 *  of entries displayed in a popup.
 *
 * ResetPopUp inherits AbstractPopUpWidget and implements ISelectedDatabaseReset.
 *
 * Pressing confirm button of the popup emits the resetSelectedEntries() signal to indicate the
 * corresponding data of the selected entries should be reset.
 *
 * @author Markus Danz
 */
class ResetPopUp : public AbstractPopUpWidget, ISelectedDatabaseReset
{
    Q_OBJECT
    Q_INTERFACES(ISelectedDatabaseReset)
public:
    /**
     * @brief ResetPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
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
