#ifndef EQUIPMENTVIEW_H
#define EQUIPMENTVIEW_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include "../numberlineedit.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/iequipmentlist.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The EquipmentView class provides functionality to display and document equipment data.
 *
 * EquipmentView inherits SimpleNavigateableWidget and implements IEquipmentList.
 *
 * @author Marius Gassen
 */
class EquipmentView : public SimpleNavigateableWidget, IEquipmentList
{
    Q_OBJECT
    Q_INTERFACES(IEquipmentList)
public:
    /**
     * @brief EquipmentView Creates a new EquipmentView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit EquipmentView(QWidget *parent = 0);
    ~EquipmentView();

signals:
    void createEquipment(QHash<QString, QVariant> values);
    void deleteEquipment(int id);
    void selectEquipment(int id);


public slots:
    void addEquipment(QHash<QString, QVariant> values);
    void removeEquipment(int id);
    void updateEquipment(QHash<QString, QVariant> values);
    void clearEquipments();


private slots:
    void btnAddClicked();

private:
    const QList<QStringList> equipmentItemScheme = QList<QStringList>() << (QStringList() << tr("recoil count") << tr ("recoil intensity")) << (QStringList() << tr("vibration count") << tr("vibration intensity"));

    QScrollArea *scEquipment;
    QLabel *lblAddEquipment;
    QLabel *lblName;
    QLabel *lblRecoilCount;
    QLabel *lblRecoilIntensity;
    QLabel *lblVibrationCount;
    QLabel *lblVibrationIntensity;

    TextLineEdit *txtBxName;
    NumberLineEdit *numBxRecoilCount;
    NumberLineEdit *numBxRecoilIntensity;
    NumberLineEdit *numBxVibrationCount;
    NumberLineEdit *numBxVibrationIntensity;

    QPushButton *btnAdd;

    QVBoxLayout *equipmentListLayout;

};

#endif // EQUIPMENTVIEW_H
