#ifndef ISELECTEDDATABASERESET
#define ISELECTEDDATABASERESET

#include <QtPlugin>

/**
 * @brief The ISelectedDatabaseReset class is an interface that can be implemented to indicate that
 * functionality for displaying and selecting entries for a selective database reset is provided.
 */
class ISelectedDatabaseReset {

public:

    /**
     * @brief headDataSelected Returns true, if the head data is selected for removing.
     * @return True, iff the head data is selected.
     */
    virtual bool headDataSelected() const = 0;

    /**
     * @brief workplacesSelected Returns true, if the workplaces are selected for removing.
     * @return True, iff the workplaces are selected.
     * /
    virtual bool workplacesSelected() const = 0;

    /**
     * @brief equipmentSelected Returns true, if the equipments are selected for removing.
     * @return True, iff the equipments are selected.
     * /
    virtual bool equipmentSelected() const = 0;

    /**
     * @brief productsSelected Returns true, if the products are selected for removing.
     * @return True, iff the products are selected.
     * /
    virtual bool productsSelected() const = 0;

    /**
     * @brief transportationSelected Returns true, if the transportations are selected for removing.
     * @return True, iff the transportations are selected.
     * /
    virtual bool transportationSelected() const = 0;

    /**
     * @brief employeeSelected Returns true, if the employees are selected for removing.
     * @return True, iff the employees are selected.
     * /
    virtual bool employeeSelected() const = 0;

    /**
     * @brief shiftDataSelected Returns true, if the shift data is selected for removing.
     * @return True, iff the shift data is selected.
     */
    virtual bool shiftDataSelected() const = 0;

    /**
     * @brief ftpConnectionSelected Returns true, if the ftp connections are selected for removing.
     * @return True, iff the ftp connections are selected.
     */
    virtual bool ftpConnectionSelected() const = 0;

signals:

    /**
     * @brief resetSelectedEntries A signal that can be emitted to signal that all selected entries
     * should be reset.
     * @param widget The widget on which the selections were chosen
     */
    virtual void resetSelectedEntries(ISelectedDatabaseReset *widget) = 0;
};

#define ISelectedDatabaseReset_iid "ISelectedDatabaseReset"
Q_DECLARE_INTERFACE(ISelectedDatabaseReset, ISelectedDatabaseReset_iid)

#endif // ISELECTEDDATABASERESET

