#ifndef IROTATIONGROUP_H
#define IROTATIONGROUP_H

#include <QtPlugin>

/**
 * @brief The IRotationGroup class is an interface, that can be implemented to indicate that functionality
 * for displaying and rearranging a list of rotationgroup tasks and breaks is provided.
 */
class IRotationGroup {

public slots:

    /**
     * @brief addRotationGroupEntry Add a rotation group task with the given values to the
     * end of the list of entries.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addRotationGroupEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateRotationGroupEntry Updates the corresponding entry to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateRotationGroupEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief addRotationGroupBreakEntry Add a rotation group task with the given values to the
     * end of the list of entires.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addRotationGroupBreakEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief clearRotationGroup Removes all entries for the list of rotation group tasks and breaks.
     */
    virtual void clearRotationGroup() = 0;

signals:

    /**
     * @brief createRotationGroupEntry A signal that can be emitted to signal that a new rotation group task
     * should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createRotationGroupEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief createRotationGroupBreakEntry A signal that can be emitted to signal that a new break
     * should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createRotationGroupBreakEntry(QHash<QString, QVariant> values) = 0;

    /**
     * @brief requestRemoveEntry A signal that can be emitted to signal that the entry at position <i>order</i>
     * should be removed.
     * @param order The index in the list of entry to remove.
     */
    virtual void requestRemoveEntry(int order) = 0;

    /**
     * @brief requestMoveEntryUp A signal that can be emitted to signal that the entry at position <i>order</i>
     * should be moved one position up in the list.
     * @param order The index in the list of entry to move up.
     */
    virtual void requestMoveEntryUp(int order) = 0;

    /**
     * @brief requestMoveEntryDown A signal that can be emitted to signal that the entry at position <i>order</i>
     * should be moved one position down in the list.
     * @param order The index in the list of entry to move down.
     */
    virtual void requestMoveEntryDown(int order) = 0;
};

#define IRotationGroup_iid "IRotationGroup"

Q_DECLARE_INTERFACE(IRotationGroup, IRotationGroup_iid)
#endif // IROTATIONGROUP_H
