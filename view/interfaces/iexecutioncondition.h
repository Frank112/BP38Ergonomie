#ifndef IEXECUTIONCONDITION
#define IEXECUTIONCONDITION

#include <QtPlugin>
/**
 * @brief The IExecutionCondition class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an execution condition is provided.
 *
 * @author Frank Loeffler
 */
class IExecutionCondition{

signals:
    /**
     * @brief saveExecutionCondition A signal that can be emitted to signal that an execution condition with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveExecutionCondition(QHash<QString, QVariant> values) = 0;

public slots:
    /**
     * @brief setExecutionCondition Sets the execution condition to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setExecutionCondition(QHash<QString, QVariant> values) = 0;

};

#define IExecutionCondition_iid "IExecutionCondition"
Q_DECLARE_INTERFACE(IExecutionCondition, IExecutionCondition_iid)

#endif // IEXECUTIONCONDITION

