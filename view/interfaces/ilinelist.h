#ifndef ILINELIST_H
#define ILINELIST_H

#include <QtPlugin>

/**
 * @brief The ILineList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of lines is provided.
 *
 * @author Frank Loeffler
 */
class ILineList{

signals:

    /**
     * @brief createLine A signal that can be emitted to signal that a new line should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createLine(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteLine A signal that can be emitted to signal that the line with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the line to be deleted.
     */
    virtual void deleteLine(int id) = 0;

    /**
     * @brief selectLine A signal that can be emitted to signal that the line with its corresponding identifier
     * should be selected.
     * @param id The identifier of the line to be selected.
     */
    virtual void selectLine(int id) = 0;

    /**
     * @brief editLine A signal that can be emitted to signal that the line with its corresponding identifier
     * should be edited.
     * @param id The identifier of the line to be edited.
     */
    virtual void editLine(int id) = 0;

public slots:
    /**
     * @brief addLine Add a line with the given values to the end of the list of lines.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addLine(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateLine Updates the corresponding line to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateLine(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeLine Removes the line with the given id from the list of lines.
     * @param id The identifier of the activity to be removed.
     */
    virtual void removeLine(int id) = 0;

    /**
     * @brief selectedLine Selects the line specified in the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void selectedLine(QHash<QString, QVariant> values) = 0;

    /**
     * @brief clearLines Removes all lines from the list of lines.
     */
    virtual void clearLines() = 0;

};

#define ILineList_iid "ILineList"

Q_DECLARE_INTERFACE(ILineList, ILineList_iid)
#endif // ILINELIST_H
