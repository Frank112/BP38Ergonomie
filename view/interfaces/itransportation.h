#ifndef ITRANSPORTATION
#define ITRANSPORTATION

#include <QtPlugin>
/**
 * @brief The ITransportation class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an transportations is provided.
 *
 * @author Marius Gassen
 */
class ITransportation{

signals:
    /**
     * @brief saveTransportation A signal that can be emitted to signal that a transportation with the given <i>values</i> should be saved .
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveTransportation(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setTransportation Sets the transportation specified in <i>values</i> to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setTransportation(QHash<QString, QVariant> values) = 0;

};

#define ITransportation_iid "ITransportation"
Q_DECLARE_INTERFACE(ITransportation, ITransportation_iid)

#endif // ITRANSPORTATION

