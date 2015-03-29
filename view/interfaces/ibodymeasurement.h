#ifndef IBODYMEASUREMENT
#define IBODYMEASUREMENT

#include <QtPlugin>

/**
 * @brief The IBodyMeasurement class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a body measurement is provided.
 *
 * @author Markus Danz
 */
class IBodyMeasurement {
signals:
    /**
     * @brief saveBodyMeasurement A signal that can be emitted to signal that a body measurement with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveBodyMeasurement(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setBodyMeasurement Sets the body measurement to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setBodyMeasurement(QHash<QString, QVariant> values) = 0;
};

#define IBodyMeasurement_iid "IBodyMeasurement"
Q_DECLARE_INTERFACE(IBodyMeasurement, IBodyMeasurement_iid)

#endif // IBODYMEASUREMENT

