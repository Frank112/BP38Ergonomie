#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include "notificationmessage.h"
#include "abstractpopupwidget.h"

/**
 * @brief The NotificationWidget class
 *
 *
 * @author Frank Loeffler
 */
class NotificationWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief NotificationWidget Constructs a widget with a <i>parent</i>.
     * @param parent The <i>parent</i> widget.
     */
    explicit NotificationWidget(QWidget *parent = 0);
    ~NotificationWidget();

    /**
     * @brief setMainWidget
     * @param widget
     */
    void setMainWidget(QWidget *widget);

    /**
     * @brief sizeHint
     * @return
     */
    QSize sizeHint() const;

public slots:
    /**
     * @brief closePopUp
     */
    void closePopUp();

    /**
     * @brief showMessage
     * @param message
     * @param msgType
     * @param msgDisplayType
     */
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::INFORMATION, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

    /**
     * @brief closeMessage
     */
    void closeMessage();

protected slots:
    void openPopUp(AbstractPopUpWidget *popUp);

private:
    QGridLayout *popUpLayout;

    QWidget *mainWidget;
    QWidget *popUpWidget;
    QWidget *notificationMessageWidget;

    AbstractPopUpWidget *currentPopUp;
    NotificationMessage *notifiMessage;

    void resizeEvent(QResizeEvent *event);

};

#endif // NOTIFICATIONWIDGET_H
