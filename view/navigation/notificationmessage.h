#ifndef NOTIFICATIONMESSAGE_H
#define NOTIFICATIONMESSAGE_H

#include <QPushButton>
#include <QList>

/**
 * @brief The NotificationMessage class provides functionality for displaying additional information.
 *
 * A NotificationMessage's icon is displayed differently depending on the NotificationMessage::MessageType parameter, passed in
 * showMessage(QString message, MessageType msgType, MessageDisplayType msgDisplayType).
 *
 * A NotificationMessage's display duration is determined by the NotificationMessage::MessageDisplayType parameter, passed in
 * showMessage(QString message, MessageType msgType, MessageDisplayType msgDisplayType).
 * In any case, the message can always be discarded by clicking it.
 *
 * @author Frank Loeffler
 */
class NotificationMessage : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief NotificationMessage Constructs an widget with a <i>parent</i>.
     * @param parent The <i>parent</i> widget of the abstract widget.
     */
    NotificationMessage(QWidget *parent = 0);
    ~NotificationMessage();

    /**
     * @brief The MessageType enum
     */
    enum MessageType{
        ACCEPT, ///< The message is shown with the <i>accept icon</i>.
        ERROR, ///< The message is shown with the <i>error icon</i>.
        WARNING, ///< The message is shown with the <i>warning icon</i>.
        INFORMATION, ///< The message is shown with the <i>information icon</i>.
        WELCOME ///< The message is shown with the <i>welcome icon</i>.
    };

    /**
     * @brief The MessageDisplayType enum
     */
    enum MessageDisplayType{
        PERSISTENT, ///< The message is shown persitently and can be discarded by clicking it.
        SHORT, ///< The message is shown for a <i>short</i> period of time.
        MIDDLE, ///< The message is shown for a <i>medium</i> period of time.
        LONG ///< The message is shown for a <i>long</i> period of time.
    };

public slots:
    /**
     * @brief showMessage In order to show the message, the message is appended to the queue of messages to be shown.
     * @param message The message to be displayed
     * @param msgType The message type of the message to be displayed
     * @param msgDisplayType The message display type of the message to be displayed
     */
    void showMessage(QString message, MessageType msgType = INFORMATION, MessageDisplayType msgDisplayType = MIDDLE);

    /**
     * @brief closeMessage The current message is removed from the queue, hidden and the next message in the queue
     * is processed iff the queue is not empty.
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
