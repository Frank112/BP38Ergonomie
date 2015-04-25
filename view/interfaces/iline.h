#ifndef ILINE_H
#define ILINE_H

#include <QtPlugin>
/**
 * @brief The ILine class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a line is provided.
 *
 * @author Marius Gassen
 */
class ILine {

signals:
    /**
     * @brief saveLine A signal that can be emitted to signal that a line with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveLine(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setLine Sets the line to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setLine(QHash<QString, QVariant> values) = 0;
};

#define ILine_iid "ILine"
Q_DECLARE_INTERFACE(ILine, ILine_iid)

#endif // ILINE_H
