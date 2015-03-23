#ifndef ISELECTEDDATABASERESET
#define ISELECTEDDATABASERESET

#include <QtPlugin>

class ISelectedDatabaseReset {

public:
    virtual bool headDataSelected() const = 0;
    virtual bool workplacesSelected() const = 0;
    virtual bool equipmentSelected() const = 0;
    virtual bool productsSelected() const = 0;
    virtual bool transportationSelected() const = 0;
    virtual bool employeeSelected() const = 0;
    virtual bool shiftDataSelected() const = 0;
    virtual bool ftpConnectionSelected() const = 0;

signals:
    virtual void resetSelectedEntries(ISelectedDatabaseReset *widget) = 0;
};

#define ISelectedDatabaseReset_iid "ISelectedDatabaseReset"
Q_DECLARE_INTERFACE(ISelectedDatabaseReset, ISelectedDatabaseReset_iid)

#endif // ISELECTEDDATABASERESET

