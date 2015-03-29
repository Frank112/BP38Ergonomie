#ifndef IAPPLIEDFORCE
#define IAPPLIEDFORCE

#include <QtPlugin>

/**
 * @brief The IAppliedForce class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an applied force is provided.
 *
 * @author Frank Loeffler
 */
class IAppliedForce{

signals:
    /**
     * @brief saveAppliedForce A signal that can be emitted to signal that an applied force with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveAppliedForce(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setAppliedForce Sets the applied force to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setAppliedForce(QHash<QString, QVariant> values) = 0;

};

#define IAppliedForce_iid "IAppliedForce"
Q_DECLARE_INTERFACE(IAppliedForce, IAppliedForce_iid)

#endif // IAPPLIEDFORCE

