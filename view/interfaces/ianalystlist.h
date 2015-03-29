#ifndef IANALYSTLIST
#define IANALYSTLIST

#include <QtPlugin>

/**
 * @brief The IAnalystList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of activities.
 *
 * @author Markus Danz
 */
class IAnalystList{

public slots:
    /**
     * @brief addAnalyst Add an analyst with the given values to the end of the list of analysts.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addAnalyst(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateAnalyst Updates the corresponding analyst to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateAnalyst(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeAnalyst Removes the analyst with the given id from the list of analysts.
     * @param id The identifier of the analyst to be removed.
     */
    virtual void removeAnalyst(int id) = 0;

    /**
     * @brief clearAnalysts Removes all analysts from the list of analysts.
     */
    virtual void clearAnalysts() = 0;

signals:
    /**
     * @brief createAnalyst A signal that can be emitted to signal that a new analyst should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createAnalyst(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteAnalyst A signal that can be emitted to signal that the analyst with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the activity to be deleted.
     */
    virtual void deleteAnalyst(int id) = 0;

    /**
     * @brief selectAnalyst A signal that can be emitted to signal that the analyst with its corresponding identifier
     * should be selected.
     * @param id The identifier of the activity to be selected.
     */
    virtual void selectAnalyst(int id) = 0;

};

#define IAnalystList_iid "IAnalystList"

Q_DECLARE_INTERFACE(IAnalystList, IAnalystList_iid)

#endif // IANALYSTLIST

