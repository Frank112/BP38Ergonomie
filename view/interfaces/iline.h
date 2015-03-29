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
     * @brief saveLine
     * @param values
     */
    virtual void saveLine(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setLine
     * @param values
     */
    virtual void setLine(QHash<QString, QVariant> values) = 0;
};

#define ILine_iid "ILine"
Q_DECLARE_INTERFACE(ILine, ILine_iid)

#endif // ILINE_H
