#ifndef IIMPORTDATA
#define IIMPORTDATA

#include <QtPlugin>
#include "iftpconnections.h"

/**
 * @brief The IImportData is an interface which inherits from IFTPConnections and adds
 * additional functionality to signal which data should be imported while importing data
 * to the application.
 *
 */
class IImportData : public IFTPConnections
{

public:
    /**
     * @brief Returns the import mode which is selected.
     * Example: XML as the import mode.
     *
     * @return
     *      The import mode which is selected.
     */
    virtual QString getImportMode() const = 0;

    /**
     * @brief Indicates whether transportations should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importTransportations() const = 0;

    /**
     * @brief Indicates whether equipments should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importEquipments() const = 0;

    /**
     * @brief Indicates whether products should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importProducts() const = 0;

    /**
     * @brief Indicates whether employees should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importEmployees() const = 0;

    /**
     * @brief Indicates whether workplaces should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importWorkplaces() const = 0;

    /**
     * @brief Indicates whether workprocess lists should be imported.
     *
     * @return
     *      true iff the data should be imported.
     */
    virtual bool importWorkprocessLists() const = 0;

signals:
    /**
     * @brief Is emitted when ever a import of data should be started.
     *
     * @param widget
     *          The reference to the widget which implements this interface
     *          and wants to start the import of data.
     */
    virtual void importData(IImportData *widget) = 0;

};

#define IImportData_iid "IImportData"

Q_DECLARE_INTERFACE(IImportData, IImportData_iid)

#endif // IIMPORTDATA

