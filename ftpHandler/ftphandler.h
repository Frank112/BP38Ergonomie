#ifndef FTPHANDLER_H
#define FTPHANDLER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

/**
 * @brief The FtpHandler class is a abstract way to upload and download files via the
 * FTP.
 *
 * <b>Note: </b> The FTP Server that you use has to <b>not</b> enforce SSL for the
 * login and the transfer of the data. This has to be due to the fact that there
 * is no implementation of the QSllSocket on iOS.
 *
 * @author Frank Loeffler
 */
class FtpHandler : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new FTPHandler object.
     * @param parent
     *          The parent object of the created object.
     */
    explicit FtpHandler(QObject *parent = 0);
    ~FtpHandler();

    /**
     * @brief Uploads the given file to the given server address
     * with the given user via ftp.
     *
     * @param filename
     *          The path to the file to upload.
     */
    void uploadFile(const QString &filename);

    /**
     * @brief Downloads the given file from the given server address with
     * the given user via ftp.
     *
     * @param filename
     *          The file path of the file to download on the ftp server relative
     *          to the given server address.
     *
     * @param downloadLocation
     *          The path to the directory to save the downloaded file.
     */
    void downloadFile(const QString &filename, const QString &downloadLocation);

    /**
     * @brief Sets the user to use for the ftp connection with the
     * given username and a [optional] password.
     * Iff you never set the user the default user "anonymous" with the
     * passwort "" is used.
     *
     * @param username
     *          The username of the ftpuser.
     * @param password
     *          The password to the given username of the ftpuser.
     */
    void setUser(const QString &username, const QString &password = "");

    /**
     * @brief Sets the port for the ftp connection.
     * Iff you never set the port the default port 22 is used.
     *
     * @param port
     *          The port to use for the connection.
     */
    void setPort(int port);

    /**
     * @brief Sets the server address to connect to
     * the given server.
     * Iff you never set the server address the "localhost" is used.
     *
     * Example: "127.0.0.1/download" to connect to
     * your local Computer to the directory download in the
     * ftp home directory of the given ftp user.
     *
     * @param address
     *          The server adress to use for the connection.
     */
    void setServer(const QString &address);

signals:
    /**
     * @brief Signals the progress of the currently executed command.
     *
     * @param progress
     *          The progess in percent.
     */
    void progress(int progress);

    /**
     * @brief Is emitted when ever a ftp command is started to execute.
     */
    void started();

    /**
     * @brief Is emitted when ever a command has been finished.
     *
     * <b>Note: </b> The finished signal is also emitted if the
     * command is finished with an error.
     *
     * @param filename
     *          The filename that has been downloaded/uploaded in the
     *          finished command.
     */
    void finished(const QString filename);

    /**
     * @brief Is emitted when ever a error occurs durring the execution
     * of an ftp command.
     *
     * @param error
     *          The error message of the occured error.
     */
    void error(const QString &error);

private slots:
    void managerFinished(QNetworkReply *reply);
    void progress(qint64 bytesSend, qint64 totalBytes);

private:
    class FTPCommand
    {
    public:
        enum Mode {DOWNLOAD, UPLOAD};

        static FTPCommand* createUploadCommand(const QUrl &url, const QString &filename, QFile *data)
        {
            return new FTPCommand(url, filename, data);
        }

        static FTPCommand* createDownloadCommand(const QUrl &url, const QString &filename, const QString &downloadLocation)
        {
            return new FTPCommand(url, filename, downloadLocation);
        }

        ~FTPCommand()
        {

        }

        Mode getMode() const
        {
            return mode;
        }
        QUrl getUrl() const
        {
            return url;
        }
        QString getFilename() const
        {
            return filename;
        }
        QString getDownloadLocation() const
        {
            if(mode == Mode::DOWNLOAD)
                return downloadLocation;
            return "";
        }
        QFile* getUploadData() const
        {
            if(mode == Mode::UPLOAD)
                return data;
            return 0;
        }

    private:
        explicit FTPCommand(const QUrl &url, const QString &filename) :
            url(url),
            filename(filename)
        {

        }

        explicit FTPCommand(const QUrl &url, const QString &filename, const QString &downloadLocation) :
            FTPCommand(url, filename)
        {
            mode = Mode::DOWNLOAD;
            this->downloadLocation = downloadLocation;
        }

        explicit FTPCommand(const QUrl &url, const QString &filename, QFile *data) :
            FTPCommand(url, filename)
        {
            mode = Mode::UPLOAD;
            this->data = data;
        }

        Mode mode;
        QUrl url;
        QString filename;
        QString downloadLocation;
        QFile *data;
    };
    enum State {IDLE, BUSY};

    State state;

    QString username;
    QString password;
    int port;
    QString address;

    QNetworkAccessManager *manager;

    QList<FTPCommand*> cmdList;

    void sheduleCommand(FTPCommand *cmd);
    void processCommand();

};

#endif // FTPHANDLER_H
