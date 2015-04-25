#ifndef IROTATIONGROUPTASK_H
#define IROTATIONGROUPTASK_H

#include <QtPlugin>

/**
 * @brief The IRotationGroupTask class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving a rotation group task is provided.
 *
 * @author Marius Gassen
 */
class IRotationGroupTask {

public slots:

    /**
     * @brief setRotationGroupTask Sets the rotation group task to be displayed specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setRotationGroupTask(QHash<QString, QVariant> values) = 0;

signals:

    /**
     * @brief saveRotationGroupTask A signal that can be emitted to signal that a rotation group task with the given <i>values</i> should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveRotationGroupTask(QHash<QString, QVariant> values) = 0;
};

#define IRotationGroupTask_iid "IRotationGroupTask"

Q_DECLARE_INTERFACE(IRotationGroupTask, IRotationGroupTask_iid)

#endif // IROTATIONGROUPTASK_H
