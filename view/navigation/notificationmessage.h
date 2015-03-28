#ifndef NOTIFICATIONMESSAGE_H
#define NOTIFICATIONMESSAGE_H

#include <QPushButton>
#include <QList>

/**
 * @brief The NotificationMessage class
 */
class NotificationMessage : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief NotificationMessage
     * @param parent
     */
    NotificationMessage(QWidget *parent = 0);
    ~NotificationMessage();

    /**
     * @brief The MessageType enum
     */
    enum MessageType{ACCEPT, ERROR, WARNING, INFORMATION, WELCOME};

    /**
     * @brief The MessageDisplayType enum
     */
    enum MessageDisplayType{PERSISTENT, SHORT, MIDDLE, LONG};

public slots:
    /**
     * @brief showMessage
     * @param message
     * @param msgType
     * @param msgDisplayType
     */
    void showMessage(QString message, MessageType msgType = INFORMATION, MessageDisplayType msgDisplayType = MIDDLE);

    /**
     * @brief closeMessage
     */
    void closeMessage();

private:
    struct Message {
        QString text;
        MessageType type;
        MessageDisplayType displayType;
    };

    int timerID;
    bool idle;
    QList<Message> msgQueue;

    void processMessageQueue();

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *);
};

#endif // NOTIFICATIONMESSAGE_H
