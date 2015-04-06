#ifndef EQUIPMENTPOPUP_H
#define EQUIPMENTPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../interfaces/iequipment.h"
#include "../numberlineedit.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The EquipmentPopUp class provides functionality to create a new equipment with a form
 * displayed in a popup.
 *
 * EquipmentPopUp inherits AbstractPopUpWidget and implements IEquipment.
 *
 * Pressing confirm button of the popup emits the saveEquipment() signal to indicate the
 * entered data should be saved and a new equipment is created.
 *
 * @author Marius Gassen
 */
class EquipmentPopUp : public AbstractPopUpWidget, IEquipment
{
    Q_OBJECT
    Q_INTERFACES(IEquipment)
public:
    /**
     * @brief EquipmentPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit EquipmentPopUp(QWidget *parent = 0);
    ~EquipmentPopUp();

signals:
    void saveEquipment(QHash<QString, QVariant> values);

public slots:
    void setEquipment(QHash<QString, QVariant>){}

private slots:
    void onConfirm();
    void onClose();

private:
    TextLineEdit *txtBxName;
    NumberLineEdit *numBxRecoilCount;
    NumberLineEdit *numBxRecoilIntensity;
    NumberLineEdit *numBxVibrationCount;
    NumberLineEdit *numBxVibrationIntensity;

};

#endif // EQUIPMENTPOPUP_H
