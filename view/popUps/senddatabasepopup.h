#ifndef SENDDATABASEPOPUP_H
#define SENDDATABASEPOPUP_H

#include "../view/navigation/abstractpopupwidget.h"
#include "../ftpconnectionswidget.h"
#include "../interfaces/isenddata.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The SendDatabasePopUp class provides functionality to send the database to a
 * server with a form displayed in a popup.
 *
 * SendDatabasePopUp inherits AbstractPopUpWidget and implements ISendData.
 *
 * Pressing confirm button of the popup emits the sendData() signal to indicate the
 * database should be send.
 *
 * @author Frank Loeffler
 */
class SendDatabasePopUp : public AbstractPopUpWidget, public ISendData
{
    Q_OBJECT
    Q_INTERFACES(ISendData)

public:
    /**
     * @brief SendDatabasePopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit SendDatabasePopUp(QWidget *parent = 0);
    ~SendDatabasePopUp();

    QHash<QString, QVariant> getFTPConnection() const;
    void setFTPConnection(QHash<QString, QVariant> values);

signals:
    void initializeFTPConnections(IFTPConnections *widget);
    void createFTPConnection(IFTPConnections *widget);
    void editFTPConnection(IFTPConnections *widget, int id);
    void selectFTPConnection(IFTPConnections *widget, int id);
    void sendData(ISendData *widget);

public slots:
    void addFTPConnection(QHash<QString, QVariant> values);
    void selectedFTPConnection(int id);
    void clearFTPConnections();

    void onEnter();

private slots:
    void selectedConnectionChanged(int id);
    void onConfirm();

private:
    FTPConnectionsWidget *ftpConnectionWidget;

};

#endif // SENDDATABASEPOPUP_H
