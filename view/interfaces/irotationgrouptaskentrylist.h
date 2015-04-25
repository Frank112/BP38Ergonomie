#ifndef IROTATIONGROUPTASKENTRYLIST_H
#define IROTATIONGROUPTASKENTRYLIST_H

#include <QtPlugin>

/**
 * @brief The IRotationGroupTaskEntryList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of rotation group task entries is provided.
 *
 * @author Marius Gassen
 */
class IRotationGroupTaskEntryList{

public slots:

    /**
     * @brief addRotationGroupTaskEntry Add a rotation group task entry with the given values to the end of the list.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addRotationGroupTaskEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeRotationGroupTaskEntry Removes the rotation group task entry with the given id from the list.
     * @param id The identifier of the rotation group task entry to be removed.
     */
    virtual void removeRotationGroupTaskEntry(int id) = 0;

    /**
     * @brief clearRotationGroupTaskEntries Removes all rotation group task entries from the list.
     */
    virtual void clearRotationGroupTaskEntries() = 0;

signals:
    /**
     * @brief createRotationGroupTaskEntry A signal that can be emitted to signal that a new rotation group task entry
     * should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createRotationGroupTaskEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteRotationGroupTaskEntry A signal that can be emitted to signal that the rotation group task entry
     * with its corresponding identifier should be deleted.
     * @param id The identifier of the rotation group task entry to be deleted.
     */
    virtual void deleteRotationGroupTaskEntry(int id) = 0;
};

#define IRotationGroupTaskEntryList_iid "IRotationGroupTaskEntryList"

Q_DECLARE_INTERFACE(IRotationGroupTaskEntryList, IRotationGroupTaskEntryList_iid)
#endif // IROTATIONGROUPTASKENTRYLIST_H
