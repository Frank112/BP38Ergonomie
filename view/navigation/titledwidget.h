#ifndef TITLEDWIDGET_H
#define TITLEDWIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include "viewtype.h"

class TitledWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitledWidget(const QString &title, QWidget *parent = 0):
    QWidget(parent),
    title(title){

    }

    ~TitledWidget(){

    }

    const QString getTitle() const{
        return title;
    }

signals:
    void showView(ViewType type);
    void showPopUp(PopUpType type);

public slots:
    virtual void onLeaving(){
    }

    virtual void onEnter(){

    }


private:
    const QString title;
};

#endif // TITLEDWIDGET_H
