#ifndef IWORKPLACELIST_H
#define IWORKPLACELIST_H

#include <QtPlugin>

/**
 * @brief The IWorkplaceList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of workplaces is provided.
 *
 * @author Frank Loeffler
 */
class IWorkplaceList{

public slots:
    /**
     * @brief addWorkplace Add a workplace with the given values to the end of the list of workplaces.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addWorkplace(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateWorkplace Updates the corresponding workplace to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateWorkplace(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeWorkplace Removes the workplace with the given id from the list of workplaces.
     * @param id The identifier of the activity to be removed.
     */
    virtual void removeWorkplace(int id) = 0;

    /**
     * @brief clearWorkplaces Removes all workplaces from the list of workplaces.
     */
    virtual void clearWorkplaces() = 0;

signals:

    /**
     * @brief createWorkplace A signal that can be emitted to signal that a new workplace should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createWorkplace(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteWorkplace A signal that can be emitted to signal that the workplace with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the workplace to be deleted.
     */
    virtual void deleteWorkplace(int id) = 0;

    /**
     * @brief selectWorkplace A signal that can be emitted to signal that the workplace with its corresponding identifier
     * should be selected.
     * @param id The identifier of the workplace to be selected.
     */
    virtual void selectWorkplace(int id) = 0;

};

#define IWorkplaceList_iid "IWorkplaceList"

Q_DECLARE_INTERFACE(IWorkplaceList, IWorkplaceList_iid)

#endif // IWORKPLACELIST_H
