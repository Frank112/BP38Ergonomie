#ifndef ISHIFT_H
#define ISHIFT_H

#include <QtPlugin>

/**
 * @brief The IShift class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a shift is provided.
 *
 * @author Marius Gassen
 */
class IShift {

signals:

    /**
     * @brief saveShift A signal that can be emitted to signal that a shift with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveShift(QHash<QString, QVariant> values) = 0;

public slots:

    /**
     * @brief setShift Sets the shift to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setShift(QHash<QString, QVariant> values) = 0;
};

#define IShift_iid "IShift"
Q_DECLARE_INTERFACE(IShift, IShift_iid)
#endif // ISHIFT_H
