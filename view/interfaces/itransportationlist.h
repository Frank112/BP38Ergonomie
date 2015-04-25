#ifndef ITRANSPORTATIONLIST
#define ITRANSPORTATIONLIST

#include <QtPlugin>

/**
 * @brief The ITransportationList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of transportations is provided.
 *
 * @author Marius Gassen
 */
class ITransportationList{

signals:

    /**
     * @brief createTransportation A signal that can be emitted to signal that a new transportation should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createTransportation(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteTransportation A signal that can be emitted to signal that the transportation with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the transportation to be deleted.
     */
    virtual void deleteTransportation(int id) = 0;

    /**
     * @brief selectTransportation A signal that can be emitted to signal that the transportation with its corresponding identifier
     * should be selected.
     * @param id The identifier of the transportation to be selected.
     */
    virtual void selectTransportation(int id) = 0;

public slots:

    /**
     * @brief addTransportation Add a transportation with the given values to the end of the list of transportations.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addTransportation(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeTransportation Removes the transportation with the given id from the list of transportations.
     * @param id The identifier of the transportation to be removed.
     */
    virtual void removeTransportation(int id) = 0;

    /**
     * @brief updateTransportation Updates the corresponding transportation to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateTransportation(QHash<QString, QVariant> values) = 0;

    /**
     * @brief clearTransportations Removes all products from the list of transportations.
     */
    virtual void clearTransportations() = 0;

};

#define ITransportationList_iid "ITransportationList"
Q_DECLARE_INTERFACE(ITransportationList, ITransportationList_iid)

#endif // ITRANSPORTATIONLIST

