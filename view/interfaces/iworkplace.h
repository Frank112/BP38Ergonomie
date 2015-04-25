#ifndef IWORKPLACE
#define IWORKPLACE
#include <QtPlugin>

/**
 * @brief The IWorkplace class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a workplace is provided.
 *
 * @author Frank Loeffler
 */
class IWorkplace {

signals:

    /**
     * @brief saveWorkplace A signal that can be emitted to signal that a workplace with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveWorkplace(QHash<QString, QVariant> values) = 0;

public slots:

    /**
     * @brief setWorkplace Sets the workplace to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setWorkplace(QHash<QString, QVariant> values) = 0;

    /**
     * @brief setSavedLine Sets the corresponding line of the workplace to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setSavedLine(QHash<QString, QVariant> values) = 0;

    /**
     * @brief setSavedComment Sets the corresponding comment of the workplace to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setSavedComment(QHash<QString, QVariant> values) = 0;
};

#define IWorkplace_iid "IWorkplace"
Q_DECLARE_INTERFACE(IWorkplace, IWorkplace_iid)

#endif // IWORKPLACE

