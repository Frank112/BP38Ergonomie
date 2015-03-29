#ifndef IEMPLOYEELIST
#define IEMPLOYEELIST

#include <QtPlugin>
/**
 * @brief The IEmployeeList class is an interface, that can be implemented to indicate that functionality
 * for displaying and manipulating a list of employees.
 *
 * @author Markus Danz
 */
class IEmployeeList{

public slots:
    /**
     * @brief addEmployee Add an employee with the given values to the end of the list of employees.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addEmployee(QHash<QString, QVariant> values) = 0;

    /**
     * @brief updateEmployee Updates the corresponding employee to the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void updateEmployee(QHash<QString, QVariant> values) = 0;

    /**
     * @brief removeEmployee Removes the employee with the given id from the list of employees.
     * @param id The identifier of the employee to be removed.
     */
    virtual void removeEmployee(int id) = 0;

    /**
     * @brief clearEmployees Removes all employees from the list of employees.
     */
    virtual void clearEmployees() = 0;

signals:
    /**
     * @brief createEmployee A signal that can be emitted to signal that a new employee should be created with the given values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void createEmployee(QHash<QString, QVariant> values) = 0;

    /**
     * @brief deleteEmployee A signal that can be emitted to signal that the employee with its corresponding identifier
     * should be deleted.
     * @param id The identifier of the employee to be deleted.
     */
    virtual void deleteEmployee(int id) = 0;

    /**
     * @brief selectEmployee A signal that can be emitted to signal that the employee with its corresponding identifier
     * should be selected.
     * @param id The identifier of the employee to be selected.
     */
    virtual void selectEmployee(int id) = 0;

};

#define IEmployeeList_iid "IEmployeeList"

Q_DECLARE_INTERFACE(IEmployeeList, IEmployeeList_iid)

#endif // IEMPLOYEELIST

