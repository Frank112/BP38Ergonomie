#ifndef IROTATIONGROUPTASKLIST_H
#define IROTATIONGROUPTASKLIST_H

#include <QtPlugin>

/**
 * @brief The IRotationGroupTaskList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of rotation group tasks is provided.
 *
 * @author Marius Gassen
 */
class IRotationGroupTaskList
{
public slots:

    /**
     * @brief addRotationGroupTask Add a rotation group task with the given values to the end of the list.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addRotationGroupTask(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateRotationGroupTask Updates the corresponding rotation gropu task to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateRotationGroupTask(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeRotationGroupTask Removes the rotation group task with the given id from the list.
     * @param id The identifier of the rotation group task entry to be removed.
     */
    virtual void removeRotationGroupTask(int id) = 0;

    /**
     * @brief clearRotationGroupTasks Removes all rotation group tasks from the list.
     */
    virtual void clearRotationGroupTasks() = 0;

signals:

    /**
     * @brief createRotationGroupTask A signal that can be emitted to signal that a new rotation group task
     * should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createRotationGroupTask(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteRotationGroupTask A signal that can be emitted to signal that the rotation group task
     * with its corresponding identifier should be deleted.
     * @param id The identifier of the rotation group task to be deleted.
     */
    virtual void deleteRotationGroupTask(int id) = 0;

    /**
     * @brief selectRotationGroupTask A signal that can be emitted to signal that the rotation group task
     * with its corresponding identifier should be selected.
     * @param id The identifier of the rotation group task to be selected.
     */
    virtual void selectRotationGroupTask(int id) = 0;
};

#define IRotationGroupTaskList_iid "IRotationGroupTaskList"

Q_DECLARE_INTERFACE(IRotationGroupTaskList, IRotationGroupTaskList_iid)

#endif // IROTATIONGROUPTASKLIST_H
