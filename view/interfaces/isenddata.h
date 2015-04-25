#ifndef ISENDDATA
#define ISENDDATA

#include <QtPlugin>
#include "iftpconnections.h"

/**
 * @brief The ISendData is an interface which inherits from IFTPConnections and
 * is implemented when the widget can send the application data via ftp to
 * a destination.
 *
 */
class ISendData : public IFTPConnections
{

signals:
    /**
     * @brief Is emitted when ever sending of the data should be started.
     *
     * @param widget
     *          The reference to the object that implements this interface
     *          and wants to started the transfer of the data to a
     *          destination via ftp.
     */
    virtual void sendData(ISendData *widget) = 0;

};

#define ISendData_iid "ISendData"

Q_DECLARE_INTERFACE(ISendData, ISendData_iid)

#endif // ISENDDATA

