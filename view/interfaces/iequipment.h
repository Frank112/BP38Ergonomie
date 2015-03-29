#ifndef IEQUIPMENT
#define IEQUIPMENT

#include <QtPlugin>

/**
 * @brief The IEquipment class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an equipment is provided.
 *
 * @author Markus Danz
 */
class IEquipment{

signals:
    /**
     * @brief saveEquipment A signal that can be emitted to signal that an equipment with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveEquipment(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setEquipment Sets the equipment to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setEquipment(QHash<QString, QVariant> values) = 0;

};

#define IEquipment_iid "IEquipment"
Q_DECLARE_INTERFACE(IEquipment, IEquipment_iid)

#endif // IEQUIPMENT

