#ifndef IEQUIPMENTLIST
#define IEQUIPMENTLIST

#include <QtPlugin>

/**
 * @brief The IEquipmentList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of equipments.
 *
 * @author Markus Danz
 */
class IEquipmentList{

signals:
    /**
     * @brief createEquipment  A signal that can be emitted to signal that a new equipment should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createEquipment(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteEquipment A signal that can be emitted to signal that the equipment with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the equipment to be deleted.
     */
    virtual void deleteEquipment(int id) = 0;

    /**
     * @brief selectEquipment A signal that can be emitted to signal that the equipment with its corresponding identifier
     * should be selected.
     * @param id The identifier of the equipment to be selected.
     */
    virtual void selectEquipment(int id) = 0;

public slots:
    /**
     * @brief addEquipment Add an equipment with the given values to the end of the list of equipments.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addEquipment(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeEquipment Removes the equipment with the given id from the list of equipments.
     * @param id The identifier of the equipment to be removed.
     */
    virtual void removeEquipment(int id) = 0;

    /**
     * @brief updateEquipment Updates the corresponding equipment to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateEquipment(QHash<QString, QVariant> values) = 0;

    /**
     * @brief clearEquipments Removes all equipments from the list of equipments.
     */
    virtual void clearEquipments() = 0;

};

#define IEquipmentList_iid "IEquipmentList"
Q_DECLARE_INTERFACE(IEquipmentList, IEquipmentList_iid)

#endif // IEQUIPMENTLIST

