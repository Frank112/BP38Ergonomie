#ifndef WORKPROCESSMETADATAVIEW_H
#define WORKPROCESSMETADATAVIEW_H

#include "../navigation/titledwidget.h"
#include <QLabel>
#include <QPushButton>
#include "../numberlineedit.h"
#include "../textcontrol.h"
#include "../optionselectioncontrol.h"
#include "../interfaces/iequipmentlist.h"
#include "../interfaces/iworkprocess.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The WorkProcessMetaDataView class provides functionality to display
 *
 * WorkProcessMetaDataView inherits TitledWidget and implements IEquipmentList and IWorkProcess.
 */
class WorkProcessMetaDataView : public TitledWidget, IEquipmentList, IWorkProcess
{
    Q_OBJECT
    Q_INTERFACES(IEquipmentList)
    Q_INTERFACES(IWorkProcess)
public:
    /**
     * @brief WorkProcessMetaDataView Creates a new WorkProcessMetaDataView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit WorkProcessMetaDataView(QWidget *parent = 0);
    ~WorkProcessMetaDataView();

signals:
    void saveWorkProcess(QHash<QString, QVariant> values);

    void createEquipment(QHash<QString, QVariant> values);
    void deleteEquipment(int id);
    void selectEquipment(int id);

    /**
     * @brief selectEquipmentExclusive Can be emitted to signal that the equipment with the given id
     * was selected.
     * @param id The id of the selected equipment.
     */
    void selectEquipmentExclusive(int id);

public slots:
    void setWorkProcess(QHash<QString, QVariant> values);

    void addEquipment(QHash<QString, QVariant> values);
    void updateEquipment(QHash<QString, QVariant> values);
    void removeEquipment(int id);
    void clearEquipments();

    void onLeaving();

private slots:
    void dliEquipmentSelected(int id);
    void dliEquipmentDeselect(int id);
    void btnCreateEquipmentClicked();

private:
    QLabel *lblDescription;
    QLabel *lblWorkingHeight;
    QLabel *lblDistance;
    QLabel *lblImpulseIntensity;
    QLabel *lblImpulseCount;
    QLabel *lblEquipment;

    QPushButton *btnCreateEquipment;

    TextLineEdit *txtBxDescription;
    TextControl *vcMTMCode;
    NumberLineEdit *numBxWorkingHeight;
    NumberLineEdit *numBxDistance;
    OptionSelectionControl *oscImpulseIntensity;
    NumberLineEdit *numBxImpulseCount;

    const QVector<QString> MTM_CODE_TEXTS = QVector<QString>()<<tr("taking/placing")<<tr("tool handling")<<tr("placing")<<tr("operate")<<tr("body movement");
    const QVector<QString> MTM_CODE_VALUES  = QVector<QString>()<<"A"<<"H"<<"P"<<"B"<<"K";
    const QStringList IMPULSE_INTENSITY_TEXTS = QStringList()<<tr("small")<<tr("middle")<<tr("strong");
    const QVector<QVariant> IMPULSE_INTENSITY_VALUES = QVector<QVariant>()<<1<<5<<10;
    const QList<QStringList> equipmentItemScheme = QList<QStringList>() << (QStringList() << tr("recoil count") << tr ("recoil intensity")) << (QStringList() << tr("vibration count") << tr("vibration intensity"));

    QVBoxLayout *equipmentListLayout;

    int selectedEquipment_ID;
};

#endif // WORKPROCESSMETADATAVIEW_H
