#ifndef IEMPLOYEE
#define IEMPLOYEE

#include <QtPlugin>

/**
 * @brief The IEmployee class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving an employee is provided.
 *
 * @author Markus Danz
 */
class IEmployee {

public slots:
    /**
     * @brief setEmployee A signal that can be emitted to signal that an employee with the given values should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setEmployee(QHash<QString, QVariant> values) = 0;

signals:
    /**
     * @brief saveEmployee Sets the employee to be displayed.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveEmployee(QHash<QString, QVariant> values) = 0;
};

#define IEmployee_iid "IEmployee"
Q_DECLARE_INTERFACE(IEmployee, IEmployee_iid)

#endif // IEMPLOYEE

