#ifndef TITLEDWIDGET_H
#define TITLEDWIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include "viewtype.h"
#include "notificationmessage.h"

/**
 * @brief The TitledWidget class is the abstract base class of titled widgets, providing functionality common to view widgets.
 *
 * Any widget holds a title set in the constructor which can be accessed with getTitle().
 *
 * TitledWidget provides three signals:
 *
 * 1. showView(Types::ViewType type) is emitted when another view should be displayed.
 * 2. showPopUp(Types::PopUpType type) is emitted when a popup should be displayed, overlaying the current widget.
 * 3. showMessage(const QString &message, NotificationMessage::MessageType msgType, NotificationMessage::MessageDisplayType msgDisplayType)
 *    is emitted when a NotificationMessage should be displayed, overlaying the current widget.
 *
 * @author Frank Loeffler
 */
class TitledWidget : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief TitledWidget Constructs an abstract widget with a <i>title</i> and a <i>parent</i>.
     * @param title The <i>title</i> of the widget.
     * @param parent The <i>parent</i> widget of the abstract widget.
     *
     * <b>Note:</b> The title set in the constructor cannot be modified after the initialization.
     */
    explicit TitledWidget(const QString &title, QWidget *parent = 0):
    QWidget(parent),
    title(title){

    }

    ~TitledWidget(){

    }

    /**
     * @brief getTitle Gets the <i>title</i> property held by the TitledWidget.
     * @return The value of the title of the TitledWidget as a <a href="http://doc.qt.io/qt-5/QString.html">QString</a>.
     */
    const QString getTitle() const{
        return title;
    }

signals:
    /**
     * @brief showView A signal that can be emitted to signal that the view
     * with the Types::ViewType::ViewType <i>type</i> should be shown.
     * @param type The view type of the widget that is requested to be shown.
     */
    void showView(Types::ViewType type);

    /**
     * @brief showPopUp A signal that can be emitted to signal that a popup with the
     * Types::PopUpType <i>type</i> should be shown.
     * @param type The type of the popup that is requested to be shown.
     */
    void showPopUp(Types::PopUpType type);

    /**
     * @brief showMessage A signal that can be emitted to signal that a NotificationMessage should be shown
     * with a provided message text, a NotificationMessage::MessageType, and a NotificationMessage::MessageDisplayType.
     * @param message The message requested to be displayed.
     * @param msgType The message type of the message to be displayed.
     * @param msgDisplayType The message display type of the message to be displayed.
     *
     * @see NotificationMessage::showMessage(QString message, MessageType msgType, MessageDisplayType msgDisplayType)
     * @see NotificationMessage::MessageType
     * @see NotificationMessage::MessageDisplayType
     */
    void showMessage(const QString &message, NotificationMessage::MessageType msgType = NotificationMessage::ACCEPT, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

public slots:

    /**
     * @brief onLeaving A slot that should be called every time another view is about to be displayed,
     * such that this widget is being <i>left</i>.
     */
    virtual void onLeaving(){
    }

    /**
     * @brief onEnter A slot that should be called every time this widget is about to be displayed, ergo <i>entered</i>.
     */
    virtual void onEnter(){
    }


private:
    const QString title;

    void paintEvent(QPaintEvent *){
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }


};

#endif // TITLEDWIDGET_H
