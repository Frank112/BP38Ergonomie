#ifndef IFTPCONNECTIONS_H
#define IFTPCONNECTIONS_H

#include <QtPlugin>

/**
 * @brief The IFTPConnections is an interface, that can be implemented to indicate that
 * the current view displays a list of ftp connections. This list manipulated via the
 * methods of this interface.
 *
 * @author Frank Loeffler
 */
class IFTPConnections{

public:
    /**
     * @brief Returns the current ftp connection as mapping of the
     * field name in the database and the value of the field.
     *
     * @return
     *       A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual QHash<QString, QVariant> getFTPConnection() const = 0;

    /**
     * @brief Sets the current ftp connection to the given values.
     *
     * @param values
     *      A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setFTPConnection(QHash<QString, QVariant> values) = 0;

signals:
    /**
     * @brief Is emitted when the widget should be initialized with the ftp connections.
     *
     * @param widget
     *          A reference to the widget that implements this interface.
     */
    virtual void initializeFTPConnections(IFTPConnections *widget) = 0;

    /**
     * @brief Is emitted when the widget wants to create a new ftp connection.
     *
     * @param widget
     *          A reference to the widget that implements this interface.
     */
    virtual void createFTPConnection(IFTPConnections *widget) = 0;

    /**
     * @brief Is emitted when the widget wants to edit the ftp connection with the given id.
     *
     * @param widget
     *          A reference to the widget that implements this interface.
     * @param id
     *          The id of the ftp connection entry.
     */
    virtual void editFTPConnection(IFTPConnections *widget, int id) = 0;

    /**
     * @brief Is emitted when the widget wants to select the ftp connection with the given id
     * as the selected ftp connection.
     *
     * @param widget
     *          A reference to the widget that implements this interface.
     * @param id
     *          The id of the ftp connection entry.
     */
    virtual void selectFTPConnection(IFTPConnections *widget, int id) = 0;

public slots:
    /**
     * @brief Adds the given ftp connection with the given values to the list of ftp connections.
     *
     * @param values
     *      A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void addFTPConnection(QHash<QString, QVariant> values) = 0;

    /**
     * @brief Sets the ftp connection with the given id as the currently selected ftp connection.
     *
     * @param id
     *      The id of the ftp connection entry.
     */
    virtual void selectedFTPConnection(int id) = 0;

    /**
     * @brief Removes all ftp connections currently stored in the list of ftp connections and
     * no ftp connection is selected afterwards.
     *
     */
    virtual void clearFTPConnections() = 0;
};

#define IFTPConnections_iid "IFTPConnections"

Q_DECLARE_INTERFACE(IFTPConnections, IFTPConnections_iid)

#endif // IFTPCONNECTIONS_H
