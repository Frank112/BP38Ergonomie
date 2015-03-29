#ifndef IACTIVITYLIST_H
#define IACTIVITYLIST_H

#include <QtPlugin>

/**
 * @brief The IActivityList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of activities.
 *
 * @author Marius Gassen
 */
class IActivityList{

signals:
    /**
     * @brief createActivity A signal that can be emitted to signal that a new activity should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createActivity(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteActivity A signal that can be emitted to signal that the activity with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the activity to be deleted.
     */
    virtual void deleteActivity(int id) = 0;

    /**
     * @brief editActivity A signal that can be emitted to signal that the activity with its corresponding identifier
     * should be edited.
     * @param id The identifier of the activity to be edited.
     */
    virtual void editActivity(int id) = 0;

    /**
     * @brief selectActivity A signal that can be emitted to signal that the activity with its corresponding identifier
     * should be selected.
     * @param id The identifier of the activity to be selected.
     */
    virtual void selectActivity(int id) = 0;

public slots:
    /**
     * @brief addActivity Add an activity with the given values to the end of the list of activities.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addActivity(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateActivity Updates the corresponding activity to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateActivity(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeActivity Removes the activity with the given id from the list of activities.
     * @param id The identifier of the activity to be removed.
     */
    virtual void removeActivity(int id) = 0;

    /**
     * @brief clearActivities Removes all activities from the list of activities.
     */
    virtual void clearActivities() = 0;
};

#define IActivityList_iid "IActivityList"

Q_DECLARE_INTERFACE(IActivityList, IActivityList_iid)

#endif // IACTIVITYLIST_H
