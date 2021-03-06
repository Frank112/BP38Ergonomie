#include "notificationmessage.h"
#include <QStyleOption>
#include <QPainter>
#include <QApplication>
#include <QProcess>

NotificationMessage::NotificationMessage(QWidget *parent) : QPushButton(parent),
    timerID(-1),
    idle(true),
    msgQueue(QList<Message>())
{
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setIconSize(QSize(30, 30));
    this->setGeometry(0, 0, 100, 42);
    connect(this, SIGNAL(clicked()), this, SLOT(closeMessage()));
    this->hide();
}

NotificationMessage::~NotificationMessage()
{

}

//PUBLIC SLOTS
void NotificationMessage::showMessage(QString message, MessageType msgType, MessageDisplayType msgDisplayType){
    Message m;
    m.text = message;
    m.type = msgType;
    m.displayType = msgDisplayType;
    msgQueue.append(m);
    processMessageQueue();
}

void NotificationMessage::closeMessage(){
    idle = true;
    msgQueue.removeFirst();
    this->hide();
    processMessageQueue();
}

//PRIVATE METHODS
void NotificationMessage::processMessageQueue(){
    if(!msgQueue.isEmpty() && idle){
        Message msg = msgQueue.at(0);
        idle = false;
        int duration;
        switch(msg.displayType){
            case SHORT: duration = 1000; break;
            case MIDDLE: duration = 1500; break;
            case LONG: duration = 2500; break;
            default: duration = 1000; break;
        }
        if(msg.displayType != PERSISTENT){
            timerID = startTimer(duration);
        }
        switch(msg.type){
            case ACCEPT: this->setIcon(QIcon(":/blue/icons/Buttons/blue/accept.png")); break;
            case ERROR: this->setIcon(QIcon(":/blue/icons/Buttons/blue/error.png")); break;
            case WARNING: this->setIcon(QIcon(":/blue/icons/Buttons/blue/warning.png")); break;
            case INFORMATION: this->setIcon(QIcon(":/blue/icons/Buttons/blue/information.png")); break;
            case WELCOME: this->setIcon(QIcon(":/blue/icons/Buttons/blue/welcome.png")); break;
            default: this->setIcon(QIcon(":/blue/icons/Buttons/blue/information.png")); break;
        }
        this->setText(msg.text);

        int oldWidth = this->width();
        int oldHeight = this->height();
        this->adjustSize();

        int xPos = this->x() + (oldWidth - this->width()) / 2;
        int yPos = this->y() + (oldHeight - this->height());
        this->setGeometry(xPos, yPos, this->width(), this->height());

        this->show();
        update();

    }
}

void NotificationMessage::paintEvent(QPaintEvent *event){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QPushButton::paintEvent(event);
}

void NotificationMessage::timerEvent(QTimerEvent *){
    if(!idle){
        killTimer(timerID);
        closeMessage();
    }
}

