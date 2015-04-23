#ifndef FTPCONNECTIONSWIDGET_H
#define FTPCONNECTIONSWIDGET_H

#include "numberlineedit.h"
#include <QComboBox>
#include <QCheckBox>

/**
 * @brief The FTPConnectionsWidget class provides functionality to show information for a selected ftp connection, which
 * can be added to this widget or to create a new ftp connection, with a name, a username and password for the ftp user,
 * a server address for the ftp server, a port to use for the ftp connection, the option to indicate that you wish to save
 * the ftp connection and to indicate that you want or use this as the default ftp connection.
 *
 * @author Frank Loeffler
 */
class FTPConnectionsWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new widget for showing ftp connection information.
     *
     * @param parent
     *          The parent object of this widget.
     */
    explicit FTPConnectionsWidget(QWidget *parent = 0);
    ~FTPConnectionsWidget();

    /**
     * @brief Returns the name for the selected ftp connection.
     *
     * @return
     *      The name of the ftp connection.
     */
    QString getName() const;

    /**
     * @brief Sets the name of this ftp connection to show.
     *
     * @param name
     *          The name of the ftp connection to show.
     */
    void setName(const QString &name);

    /**
     * @brief Returns the user name of the selected ftp connection
     *
     * @return
     *          The user name of the ftp connection
     */
    QString getUserName() const;

    /**
     * @brief Sets the user name for the ftp connection to show.
     *
     * @param username
     *          The user name of the ftp connection to show.
     */
    void setUserName(const QString &username);

    /**
     * @brief Returns the password of the selected ftp connection.
     *
     * @return
     *          The password of the ftp connection.
     */
    QString getPassword() const;

    /**
     * @brief Sets the password of the ftp connection to show.
     *
     * <b>Note: </b> The password is shown always masked for the user.
     *
     * @param password
     *          The password of the ftp connection to show.
     */
    void setPassword(const QString &password);

    /**
     * @brief Returns the server address of the selected ftp connection.
     *
     * @return
     *          The server address of the ftp connection.
     */
    QString getAddress() const;

    /**
     * @brief Sets the server address of the ftp connection to show.
     *
     * @param address
     *          The server address of the ftp connection to show.
     */
    void setAddress(const QString &address);

    /**
     * @brief Returns the port of the selected ftp connection.
     *
     * @return
     *          The port of the ftp connection.
     */
    int getPort() const;

    /**
     * @brief Sets the port of the ftp connection to show.
     *
     * @param port
     *          The port of the ftp connection to show.
     */
    void setPort(int port);

    /**
     * @brief Indicates if the selected ftp connection is set as the default connection.
     *
     * @return
     *          true iff this is the default ftp connection.
     */
    bool getSetAsDefault() const;

    /**
     * @brief Sets this selected ftp connection as the default connection or not.
     *
     * @param setAsDefault
     *          Sets this as the default ftp connection iff this is true
     */
    void setSetAsDefault(bool setAsDefault);

    /**
     * @brief Indicates whether the selected ftp connection should be saved or not.
     *
     * @return
     *          true iff this ftp connection should be saved.
     */
    bool getSaved() const;

    /**
     * @brief Returns the index of the currently selected ftp connection.
     *
     * @return
     *          The index of the selected ftp connection.
     */
    int getSelectedIndex() const;

    /**
     * @brief Returns the id of the currently selected ftp connection.
     *
     * @return
     *          The id of the selected ftp connection.
     */
    int getSelectedID() const;

signals:
    /**
     * @brief Is emitted if the currently selected ftp connection changed.
     *
     * @param id
     *          The id of the new selected ftp connection.
     */
    void selectedConnectionChanged(int id);

public slots:
    /**
     * @brief Adds a new ftp connection with the given name and id to
     * the list of selectable ftp connections.
     *
     * @param name
     *          The name of the ftp connection to add.
     * @param id
     *          The id of the ftp connection to add in the database.
     */
    void add(const QString &name, int id);

    /**
     * @brief Sets the ftp connection with the given id as the selected
     * ftp connection. If there is no connection with that id nothing changes.
     *
     * @param id
     *          The id of the ftp connection to select.
     */
    void select(int id);

    /**
     * @brief Removes all selectable ftp connections in the list.
     */
    void clear();

private slots:
    void cmBxFTPConnectionsIndexChanged(int index);

private:
    QComboBox *cmBxFTPConnections;
    TextLineEdit *txtBxName;
    TextLineEdit *txtBxUserName;
    TextLineEdit *txtBxPassword;
    TextLineEdit *txtBxAddress;
    NumberLineEdit *numBxPort;
    QCheckBox *chBxSave;
    QCheckBox *chBxSetDefault;
};

#endif // FTPCONNECTIONSWIDGET_H
