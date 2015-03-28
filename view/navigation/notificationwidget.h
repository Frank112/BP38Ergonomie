#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include "notificationmessage.h"
#include "abstractpopupwidget.h"

/**
 * @brief The NotificationWidget class provides functionality to display a NotificationMessage and
 * an AbstractPopUpWidget overlaying the actual content.
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
     * @brief setMainWidget Sets a widget as main content of the NotificationWidget and sets the existing popup
     * and a notification message on the layers above.
     * @param widget The main content to be set.
     */
    void setMainWidget(QWidget *widget);

public slots:
    /**
     * @brief closePopUp Hides the popup <i>layer</i> of the NotificationWidget.
     *
     * <b>Note:</b> The popup still exists but is not visible.
     */
    void closePopUp();

    /**
     * @brief showMessage Shows a <i>notification message</i> with a provided message text,
     * a NotificationMessage::MessageType, and a NotificationMessage::MessageDisplayType on the <i>topmost layer</i>.
     * @param message The message <i>text</i> to be displayed.
     * @param msgType The <i>type</i> of the message to be displayed.
     * @param msgDisplayType The <i>display type</i> of the message to be displayed.
     *
     * <b>Note:</b> The message is not shown if Settings::SETTING_SHOW_NOTIFICATIONS is set to <i>false</i>, unless the
     * NotificationMessage::MessageType is NotificationMessage::ERROR.
     */
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::INFORMATION, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

    /**
     * @brief closeMessage Hides the currently shown message.
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
