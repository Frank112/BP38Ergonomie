#ifndef IEMPLOYEESELECT_H
#define IEMPLOYEESELECT_H

#include <QtPlugin>

/**
 * @brief The IEmployeeSelect class is an interface, that can be implemented to indicate that functionality
 * for displaying and saving the selection of an employee is provided.
 *
 * @author Markus Danz
 */
class IEmployeeSelect {

signals:
    /**
     * @brief saveEmployeeSelected A signal that can be emitted to signal that the employee corresponding idenfifier
     * should be selected
     * @param id The identifier of the employee to be selected.
     */
    virtual void saveEmployeeSelected(int id) = 0;

    /**
     * @brief resetEmployeeSelection A signal that can be emitted to signal that the selection of an employee should be cleared.
     */
    virtual void resetEmployeeSelection() = 0;
public slots:

    /**
     * @brief setEmployeeSelected Sets the employee with the given identifier selected.
     * @param id The identifier of the employee to select.
     */
    virtual void setEmployeeSelected(int id) = 0;

};

#define IEmployeeSelect_iid "IEmployeeSelect"
Q_DECLARE_INTERFACE(IEmployeeSelect, IEmployeeSelect_iid)

#endif // IEMPLOYEESELECT_H
