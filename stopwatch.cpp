#include "stopwatch.h"
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>
#include <QTimerEvent>
#include <QDebug>
#include <QScrollArea>
#include <QScroller>
#include <QScrollBar>
#include <QFile>
#include <QIODevice>


StopWatch::StopWatch(QWidget *parent) : QMainWindow(parent)
  , running(false)
  , timerStarted(false)
  , totalAV(0)
  , totalLeftAV(0)
  , totalRightAV(0)
  , currentAV(0)
  , currentLeftAV(0)
  , currentRightAV(0)
  , startTime()
  , currentAVTime()
  , timerTitle(new QLabel("Gesamtlaufzeit:"))
  , timer(new QLabel("00:00"))
  , avTime(new QLineEdit("00:00"))
  , totalTime(0)
  , lstAV(new QStringList)
  , lstAVTime(new QList<int>)
  , lstLeftAVTime(new QList<int>)
  , lstRightAVTime(new QList<int>)
  , btnSelAV(new QPushButton("leer"))
  , btnAV(new QPushButton("AV"))
  , btnAVLeft(new QPushButton("Links"))
  , btnAVRight(new QPushButton("Rechts"))
  , btnPlus(new QPushButton("+"))
  , btnMinus(new QPushButton("-"))
  , btnNextAV(new QPushButton(">"))
  , btnPrevAV(new QPushButton("<"))
  , btnStartPause(new QPushButton())
  , btnStopReset(new QPushButton())
  , btnSetAv(new QPushButton("AV"))
  , btnSetLeft(new QPushButton("L"))
  , btnSetRight(new QPushButton("R"))
  , btnBothAV(new QPushButton("L/R"))
  , btnMinimize(new QPushButton())
  , btnMaximize(new QPushButton())
  , counter(0)
  , leftPressed(false)
  , rightPressed(false)
  , lstLeftAVs(new QStringList)
  , lstRightAVs(new QStringList)
  , avPressed(false)
  , leftAVButtons(new QVector<SelectableValueButton*>)
  , rightAVButtons(new QVector<SelectableValueButton*>)
  , avButtons(new QVector<SelectableValueButton*>)
  , stopped(false)
  , btnView(new ButtonTimelineView)
  , leftSelected(false)
  , rightSelected(false)
  , avSelected(true)
  , windowMinimized(false)
  , graphView(new GraphTimelineView)
{
    main = new QWidget();

    mainLayout = new QHBoxLayout();
    mainTimerLayout = new QVBoxLayout();
    timerBtnLayout = new QVBoxLayout();
    mainAVLayout = new QVBoxLayout();
    avSelLayout = new QHBoxLayout();
    avTimeLayout = new QHBoxLayout();
    avLeftRightLayout = new QHBoxLayout();
    avSetLayout = new QVBoxLayout();
    timerBtnLayout2 = new QHBoxLayout();

    avLeftRightLayout->addWidget(btnMinimize);
    avLeftRightLayout->addWidget(btnMaximize);

    avLeftRightLayout->addWidget(btnAVLeft);
    avLeftRightLayout->addWidget(btnAVRight);
    avLeftRightLayout->addWidget(btnAV);
    avSelLayout->addWidget(btnPrevAV);
    avSelLayout->addWidget(btnSelAV);
    avSelLayout->addWidget(btnNextAV);
    avTimeLayout->addWidget(btnMinus);
    avTimeLayout->addWidget(avTime);
    avTimeLayout->addWidget(btnPlus);
    mainAVLayout->addLayout(avLeftRightLayout);
    mainAVLayout->addLayout(avSelLayout);
    mainAVLayout->addLayout(avTimeLayout);

    avSetLayout->addWidget(btnSetLeft);
    avSetLayout->addWidget(btnSetRight);
    avSetLayout->addWidget(btnSetAv);

    timerBtnLayout->addWidget(btnStartPause);
    timerBtnLayout->addWidget(btnStopReset);

    timerBtnLayout2->addWidget(btnBothAV);
    timerBtnLayout2->addLayout(timerBtnLayout);
    mainTimerLayout->addLayout(timerBtnLayout2);
    mainTimerLayout->addWidget(timerTitle);
    mainTimerLayout->addWidget(timer);
    mainTimerLayout->setAlignment(timer, Qt::AlignCenter);

    mainLayout->addLayout(mainAVLayout);
    mainLayout->addWidget(graphView);
    mainLayout->addLayout(avSetLayout);
    mainLayout->addLayout(mainTimerLayout);

    this->setMaximumHeight(175);

    main->setLayout(mainLayout);
    this->setCentralWidget(main);

    btnMinimize->setFixedSize(45,45);
    btnMaximize->setFixedSize(45,45);
    btnMaximize->setVisible(false);

    btnPlus->setFixedSize(45,45);
    btnMinus->setFixedSize(45,45);
    btnNextAV->setFixedSize(45,45);
    btnPrevAV->setFixedSize(45,45);
    btnStartPause->setFixedSize(45,45);
    btnStopReset->setFixedSize(45,45);
    btnSetAv->setFixedSize(45,45);
    btnSetLeft->setFixedSize(45,45);
    btnSetRight->setFixedSize(45,45);
    btnBothAV->setFixedSize(45, 100);
    btnAVLeft->setFixedSize(70, 45);
    btnAVRight->setFixedSize(70, 45);
    btnAV->setFixedSize(70, 45);
    btnSelAV->setFixedSize(105, 45);
    avTime->setFixedSize(105,45);
    avTime->setInputMask("00:99");
    avTime->setAlignment(Qt::AlignCenter);

    btnStartPause->setIcon(QIcon(":/timer/icons/Timer/start.png"));
    btnStartPause->setIconSize(QSize(25,25));
    btnStartPause->setToolTip("Start");
    btnStopReset->setIcon(QIcon(":/timer/icons/Timer/reset.png"));
    btnStopReset->setIconSize(QSize(25,25));
    btnStopReset->setToolTip("Reset");
    btnMinimize->setIcon(QIcon(":/timer/icons/Timer/minimize.png"));
    btnMinimize->setIconSize(QSize(25,25));
    btnMaximize->setIcon(QIcon(":/timer/icons/Timer/maximize.png"));
    btnMaximize->setIconSize(QSize(25,25));

    timerTitle->setStyleSheet("font: 12px");
    timer->setStyleSheet("font: 15pt");

    startTimer(0);
    lstAV->clear();
    lstLeftAVs->clear();
    lstRightAVs->clear();
    btnStartPause->setEnabled(true);
    btnStopReset->setEnabled(false);
    btnSetAv->setEnabled(false);
    btnSelAV->setEnabled(false);
    btnAV->setEnabled(false);
    btnAVLeft->setEnabled(false);
    btnAVRight->setEnabled(false);
    avTime->setEnabled(false);
    btnPlus->setEnabled(false);
    btnMinus->setEnabled(false);
    btnNextAV->setEnabled(false);
    btnPrevAV->setEnabled(false);

    btnView->btnPlus->setEnabled(false);
    btnView->btnMinus->setEnabled(false);

    connect(btnStartPause, SIGNAL(clicked()), SLOT(btnStartPauseClicked()));
    connect(btnStopReset, SIGNAL(clicked()), SLOT(btnStopResetClicked()));
    connect(btnSetAv, SIGNAL(clicked()), SLOT(btnSetAVClicked()));
    connect(btnSelAV, SIGNAL(clicked()), SLOT(btnSelAVClicked()));
    connect(btnAV, SIGNAL(clicked()), SLOT(btnAVClicked()));
    connect(btnAVLeft, SIGNAL(clicked()), SLOT(btnAVLeftClicked()));
    connect(btnAVRight, SIGNAL(clicked()), SLOT(btnAVRightClicked()));
    connect(btnPlus, SIGNAL(clicked()), SLOT(btnPlusClicked()));
    connect(btnMinus, SIGNAL(clicked()), SLOT(btnMinusClicked()));
    connect(btnNextAV, SIGNAL(clicked()), SLOT(btnNextAVClicked()));
    connect(btnPrevAV, SIGNAL(clicked()), SLOT(btnPrevAVClicked()));
    connect(btnSetLeft, SIGNAL(clicked()), SLOT(btnSetLeftClicked()));
    connect(btnSetRight, SIGNAL(clicked()), SLOT(btnSetRightClicked()));
    connect(btnBothAV, SIGNAL(clicked()), SLOT(btnBothAVClicked()));
    connect(btnMinimize, SIGNAL(clicked()), SLOT(btnMinimizeClicked()));
    connect(btnMaximize, SIGNAL(clicked()), SLOT(btnMaximizeClicked()));
}
    const QString StopWatch::qssSelected = "QPushButton {font: 100 20px \"Serif\";color: #FFFFFF; border: 2px solid #007aff; border-radius: 10px; background-color: #007aff;} QPushButton:pressed {color: #FFFFFF;background-color: #007aff;}";
    const QString StopWatch::qssNotSelected = "QPushButton {font: 100 20px \"Serif\";color: #007aff; border: 2px solid #007aff; border-radius: 10px; background-color: #f5f5f5;} QPushButton:pressed {color: #FFFFFF;background-color: #007aff;}";

    /**
     * @brief logic of the Start/Pause button
     */
    void StopWatch::btnStartPauseClicked(){
        if(btnStartPause->toolTip() != "Pause"){
            startTime = QDateTime::currentDateTime();
            running = true;
            timerStarted = true;
            btnStartPause->setIcon(QIcon(":/timer/icons/Timer/pause.png"));
            btnStartPause->setToolTip("Pause");
            if(!windowMinimized){
                btnStopReset->setIcon(QIcon(":/timer/icons/Timer/stop.png"));
                btnStopReset->setToolTip("Stop");
                btnStopReset->setEnabled(true);
                btnSetAv->setEnabled(true);
            }
        }
        else {
            running = false;
            btnStartPause->setIcon(QIcon(":/timer/icons/Timer/start.png"));
            btnStartPause->setToolTip("Start");
            timerEvent(new QTimerEvent(0));
            totalTime += sessionTime;
        }
        if(timerStarted)
            currentAVTime = startTime;
    }

    /**
     * @brief logic of the Stop/Reset Button
     */
    void StopWatch::btnStopResetClicked(){
        running = false;
        btnStartPause->setIcon(QIcon(":/timer/icons/Timer/start.png"));
        btnStartPause->setToolTip("Start");

        if(btnStopReset->toolTip() != "Reset"){
            btnStopReset->setIcon(QIcon(":/timer/icons/Timer/reset.png"));
            btnStopReset->setToolTip("Reset");
            btnStartPause->setEnabled(false);
            stopped = true;
            lstAV->append("true");
            lstLeftAVs->append("false");
            lstRightAVs->append("false");
        }
        else {
            btnStopReset->setEnabled(false);
            btnSetAv->setEnabled(false);
            btnStartPause->setEnabled(true);
            stopped = false;
            totalTime = 0;
            sessionTime = 0;
            timer->setText("00:00");
            lstAV->clear();
            lstLeftAVs->clear();
            lstRightAVs->clear();
            lstAVTime->clear();
            lstLeftAVTime->clear();
            lstRightAVTime->clear();
            graphView->updateGraph(lstAV, lstLeftAVs, lstRightAVs);
            avTime->setText("00:00");
            btnSelAV->setText("leer");
            btnSelAV->setEnabled(false);
            btnAV->setEnabled(false);
            btnAVLeft->setEnabled(false);
            btnAVRight->setEnabled(false);
            btnPlus->setEnabled(false);
            btnMinus->setEnabled(false);
            btnNextAV->setEnabled(false);
            btnPrevAV->setEnabled(false);
            totalAV = 0;
            currentAV = 0;
            currentLeftAV = 0;
            currentRightAV = 0;
            totalLeftAV = 0;
            totalRightAV = 0;
            counter = 0;
            btnSetLeft->setStyleSheet(this->qssNotSelected);
            btnSetRight->setStyleSheet(this->qssNotSelected);
            btnBothAV->setStyleSheet(this->qssNotSelected);
            btnSelAV->setStyleSheet(this->qssNotSelected);
            btnAVLeft->setStyleSheet(this->qssNotSelected);
            btnAVRight->setStyleSheet(this->qssNotSelected);
            btnAV->setStyleSheet(this->qssNotSelected);
        }
    }

    /**
     * @brief sets a new AV, saves the time and enables necessary buttons
     */
    void StopWatch::btnSetAVClicked(){
        totalAV++;
        currentAV = totalAV;

        QString str;
        str.append(QString("%1").arg(currentAV));
        btnSelAV->setText("AV " + str);
        lstAVTime->append(getTime(currentAV));

        int t = lstAVTime->at(currentAV -1);
        unsigned int m = (t/ 60);
        unsigned int s = (t - 60*m);
        const QString diff = QString("%1:%2")
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
        avTime->setText(diff);

        btnSelAV->setEnabled(true);
        btnAV->setEnabled(true);
        avTime->setEnabled(true);
        btnPlus->setEnabled(true);
        btnMinus->setEnabled(true);

        avSelected = true;
        leftSelected = false;
        rightSelected = false;

        btnAV->setStyleSheet(qssSelected);
        btnAVLeft->setStyleSheet(qssNotSelected);
        btnAVRight->setStyleSheet(qssNotSelected);

        if(totalAV > 1)
            btnPrevAV->setEnabled(true);
        btnNextAV->setEnabled(false);

        avPressed = true;
    }

    /**
     * @brief sets a new left AV, saves the time and enables necessary buttons, if button was selected
     * otherwise selects button
     */
    void StopWatch::btnSetLeftClicked(){
        if(leftPressed){
            leftPressed = false;
            btnSetLeft->setStyleSheet(this->qssNotSelected);
            totalLeftAV++;
            currentLeftAV = totalLeftAV;
            lstLeftAVTime->append(getLeftRightTime(currentLeftAV, "left"));
            btnAVLeft->setEnabled(true);
            btnBothAV->setStyleSheet(this->qssNotSelected);
            btnPlus->setEnabled(true);
            btnMinus->setEnabled(true);
        }
        else {
            leftPressed = true;
            btnSetLeft->setStyleSheet(this->qssSelected);
            if(rightPressed)
                btnBothAV->setStyleSheet(this->qssSelected);
        }
    }

    /**
     * @brief sets a new right AV, saves the time and enables necessary buttons, if button was selected
     * otherwise, selects button
     */
    void StopWatch::btnSetRightClicked(){
        if(rightPressed){
            rightPressed = false;
            btnSetRight->setStyleSheet(this->qssNotSelected);
            totalRightAV++;
            currentRightAV = totalRightAV;
            lstRightAVTime->append(getLeftRightTime(currentRightAV, "right"));
            btnAVRight->setEnabled(true);
            btnBothAV->setStyleSheet(this->qssNotSelected);
            btnPlus->setEnabled(true);
            btnMinus->setEnabled(true);
        }
        else {
            rightPressed = true;
            btnSetRight->setStyleSheet(this->qssSelected);
            if(leftPressed)
                btnBothAV->setStyleSheet(this->qssSelected);
        }
    }

    /**
     * @brief sets new left and right AVs, if buttons were selected,
     * otherwise selects the buttons
     */
    void StopWatch::btnBothAVClicked(){
        if(rightPressed && leftPressed){
            rightPressed = false;
            leftPressed = false;
            btnSetRight->setStyleSheet(this->qssNotSelected);
            totalRightAV++;
            currentRightAV = totalRightAV;
            lstRightAVTime->append(getLeftRightTime(currentRightAV, "right"));
            btnSetLeft->setStyleSheet(this->qssNotSelected);
            totalLeftAV++;
            currentLeftAV = totalLeftAV;
            lstLeftAVTime->append(getLeftRightTime(currentLeftAV, "left"));
            btnBothAV->setStyleSheet(this->qssNotSelected);
            btnAVLeft->setEnabled(true);
            btnAVRight->setEnabled(true);
        }
        else {
            rightPressed = true;
            leftPressed = true;
            btnSetRight->setStyleSheet(this->qssSelected);
            btnSetLeft->setStyleSheet(this->qssSelected);
            btnBothAV->setStyleSheet(this->qssSelected);
        }
    }

    void StopWatch::btnSelAVClicked(){
        //TODO
    }

    /**
     * @brief StopWatch::btnAVClicked
     */
    void StopWatch::btnAVClicked(){
        currentAV = 1;
        btnPrevAV->setEnabled(false);
        if(currentAV == totalAV)
            btnNextAV->setEnabled(false);
        else
            btnNextAV->setEnabled(true);
        QString str;
        str.append(QString("%1").arg(currentAV));
        btnSelAV->setText("AV " + str);

        if(!windowMinimized){
            int t = lstAVTime->at(currentAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
        avSelected = true;
        leftSelected = false;
        rightSelected = false;
        btnAV->setStyleSheet(this->qssSelected);
        btnAVLeft->setStyleSheet(this->qssNotSelected);
        btnAVRight->setStyleSheet(this->qssNotSelected);
    }

    /**
     * @brief StopWatch::btnAVLeftClicked
     */
    void StopWatch::btnAVLeftClicked(){
        currentLeftAV = 1;
        btnPrevAV->setEnabled(false);
        if(currentLeftAV == totalLeftAV)
            btnNextAV->setEnabled(false);
        else
            btnNextAV->setEnabled(true);
        QString str;
        str.append(QString("%1").arg(currentLeftAV));
        btnSelAV->setText("L_AV " + str);

        if(!windowMinimized){
            int t = lstLeftAVTime->at(currentLeftAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
        avSelected = false;
        leftSelected = true;
        rightSelected = false;
        btnAV->setStyleSheet(this->qssNotSelected);
        btnAVLeft->setStyleSheet(this->qssSelected);
        btnAVRight->setStyleSheet(this->qssNotSelected);
    }

    /**
     * @brief StopWatch::btnAVRightClicked
     */
    void StopWatch::btnAVRightClicked(){
        currentRightAV = 1;
        btnPrevAV->setEnabled(false);
        if(currentRightAV == totalRightAV)
            btnNextAV->setEnabled(false);
        else
            btnNextAV->setEnabled(true);
        QString str;
        str.append(QString("%1").arg(currentRightAV));
        btnSelAV->setText("R_AV " + str);

        if(!windowMinimized){
            int t = lstRightAVTime->at(currentRightAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
        avSelected = false;
        leftSelected = false;
        rightSelected = true;
        btnAV->setStyleSheet(this->qssNotSelected);
        btnAVLeft->setStyleSheet(this->qssNotSelected);
        btnAVRight->setStyleSheet(this->qssSelected);
    }

    /**
     * @brief increases the time of the selected AV by one
     */
    void StopWatch::btnPlusClicked(){
        if(avSelected){
           int o = lstAVTime->at(currentAV -1) +1;
           lstAVTime->replace(currentAV -1, o);

           int t = lstAVTime->at(currentAV -1);

           unsigned int m = (t/ 60);
           unsigned int s = (t - 60*m);
           const QString diff = QString("%1:%2")
           .arg(m, 2, 10, QChar('0'))
           .arg(s, 2, 10, QChar('0'));
           avTime->setText(diff);
        }
        else if(leftSelected){
            int o = lstLeftAVTime->at(currentLeftAV -1) +1;
            lstLeftAVTime->replace(currentLeftAV -1, o);

            int t = lstLeftAVTime->at(currentLeftAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
        else {
            int o = lstRightAVTime->at(currentRightAV -1) +1;
            lstRightAVTime->replace(currentRightAV -1, o);

            int t = lstRightAVTime->at(currentRightAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
    }

    /**
     * @brief decreases the time of the selected AV by one
     */
    void StopWatch::btnMinusClicked(){
        if(avSelected){
           int o = lstAVTime->at(currentAV -1) -1;
           lstAVTime->replace(currentAV -1, o);

           int t = lstAVTime->at(currentAV -1);

           unsigned int m = (t/ 60);
           unsigned int s = (t - 60*m);
           const QString diff = QString("%1:%2")
           .arg(m, 2, 10, QChar('0'))
           .arg(s, 2, 10, QChar('0'));
           avTime->setText(diff);
        }
        else if(leftSelected){
            int o = lstLeftAVTime->at(currentLeftAV -1) -1;
            lstLeftAVTime->replace(currentLeftAV -1, o);

            int t = lstLeftAVTime->at(currentLeftAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
        else {
            int o = lstRightAVTime->at(currentRightAV -1) -1;
            lstRightAVTime->replace(currentRightAV -1, o);

            int t = lstRightAVTime->at(currentRightAV -1);

            unsigned int m = (t/ 60);
            unsigned int s = (t - 60*m);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            avTime->setText(diff);
        }
    }

    /**
     * @brief StopWatch::btnNextAVClicked
     */
    void StopWatch::btnNextAVClicked(){
        if(avSelected){
            currentAV++;
            QString str;
            str.append(QString("%1").arg(currentAV));
            btnSelAV->setText("AV " + str);
            btnPrevAV->setEnabled(true);
            if(currentAV  == totalAV)
                btnNextAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstAVTime->at(currentAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
        else if(leftSelected){
            currentLeftAV++;
            QString str;
            str.append(QString("%1").arg(currentLeftAV));
            btnSelAV->setText("L_AV " + str);
            btnPrevAV->setEnabled(true);
            if(currentLeftAV  == totalLeftAV)
                btnNextAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstLeftAVTime->at(currentLeftAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
        else {
            currentRightAV++;
            QString str;
            str.append(QString("%1").arg(currentRightAV));
            btnSelAV->setText("R_AV " + str);
            btnPrevAV->setEnabled(true);
            if(currentRightAV  == totalRightAV)
                btnNextAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstRightAVTime->at(currentRightAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
    }

    /**
     * @brief StopWatch::btnPrevAVClicked
     */
    void StopWatch::btnPrevAVClicked(){
        if(avSelected){
            currentAV--;
            QString str;
            str.append(QString("%1").arg(currentAV));
            btnSelAV->setText("AV " + str);
            btnNextAV->setEnabled(true);
            if(currentAV == 1)
                btnPrevAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstAVTime->at(currentAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
        else if(leftSelected){
            currentLeftAV--;
            QString str;
            str.append(QString("%1").arg(currentLeftAV));
            btnSelAV->setText("L_AV " + str);
            btnNextAV->setEnabled(true);
            if(currentLeftAV == 1)
                btnPrevAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstLeftAVTime->at(currentLeftAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
        else {
            currentRightAV--;
            QString str;
            str.append(QString("%1").arg(currentRightAV));
            btnSelAV->setText("R_AV " + str);
            btnNextAV->setEnabled(true);
            if(currentRightAV == 1)
                btnPrevAV->setEnabled(false);

            if(!windowMinimized){
                int t = lstRightAVTime->at(currentRightAV -1);

                unsigned int m = (t/ 60);
                unsigned int s = (t - 60*m);
                const QString diff = QString("%1:%2")
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
                avTime->setText(diff);
            }
        }
    }

    /**
     * @brief logic of the Stopwatch, updates stopwatch time
     */
    void StopWatch::timerEvent(QTimerEvent *){
        if(running){
            sessionTime = startTime.msecsTo(QDateTime::currentDateTime());
            qint64 time = totalTime + sessionTime;
            unsigned int h = time / 1000 / 60 / 60;
            unsigned int m = (time / 1000 / 60) - (h * 60);
            unsigned int s = (time / 1000) - ((m + (h * 60))* 60);
            const QString diff = QString("%1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));
            timer->setText(diff);
            if(counter != s){
                updateAVs();
                if(!windowMinimized)
                    graphView->updateGraph(lstAV, lstLeftAVs, lstRightAVs);
                //getButtonView();
            }
            counter = s;
        }
    }

    /**
     * @brief updates the lists of the AVs
     */
    void StopWatch::updateAVs(){
        if(stopped){
           lstAV->append("true");
           lstLeftAVs->append("false");
           lstRightAVs->append("false");
        }
        if(avPressed){
            lstAV->append("true");
            avPressed = false;
        }
        else
            lstAV->append("false");

        if(leftPressed)
            lstLeftAVs->append("true");
        else
            lstLeftAVs->append("false");
        if(rightPressed)
            lstRightAVs->append("true");
        else
            lstRightAVs->append("false");
    }

    /**
     * @brief calculates the time of the given AV
     * @param currentAV, the AV of which the time is to be returned
     * @return time of currentAV
     */
    int StopWatch::getTime(int currentAV){
        int avCount = 0;
        int secs = 0;
        for(int i = 1; i < lstAV->count(); ++i){
           QString s = lstAV->at(i);
           if(avCount == (currentAV -1)){
               if(s == "true"){
                  avCount++;
               }
               else
                   secs++;

           }
           else {
              if(s == "true")
                  avCount++;
           }
        }
        return secs +1;
    }

    /**
     * @brief calculates the time of the given AV
     * @param currentAV, the AV of which the time is to be returned
     * @param leftright, "left" if currentAV is a left AV, "right" if currentAV is a right AVs
     * @return time of currentAV
     */
    int StopWatch::getLeftRightTime(int currentAV, QString leftright){
        int avCount = 0;
        int secs = 0;
        if(leftright == "left"){
            for(int i = 1; i < lstLeftAVs->count() -1; ++i){
                QString s = lstLeftAVs->at(i);
                if(avCount == (currentAV -1)){
                    if(s == "true" && lstLeftAVs->at(i +1) == "false"){
                        avCount++;
                    }
                    else if(s == "true")
                        secs++;
                }
                else if(s == "true" && lstLeftAVs->at(i +1) == "false")
                    avCount++;
            }
        }
        else {
            for(int i = 1; i < lstRightAVs->count() -1; ++i){
                QString s = lstRightAVs->at(i);
                if(avCount == (currentAV -1)){
                    if(s == "true" && lstRightAVs->at(i +1) == "false"){
                        avCount++;
                    }
                    else if(s == "true")
                        secs++;
                }
                else if(s == "true" && lstRightAVs->at(i +1) == "false")
                    avCount++;
            }
        }
        return secs +1;
    }

    /**
     * @brief updates the button view, adds new buttons if necessary, otherwise, resizes existing buttons
     */
    void StopWatch::getButtonView(){
        btnView->btnPlus->setEnabled(true);
        btnView->btnMinus->setEnabled(true);

        int currentAV = 0;
        for(int i = 0; i < lstLeftAVs->count(); ++i){
            if(btnView->leftButtonLayout->itemAt(i) == 0){
                if(lstLeftAVs->at(i) == "false"){
                    btnView->leftButtonLayout->addItem(new QSpacerItem(100, 60));
                }
                else {
                    if(i > 0 && lstLeftAVs->at(i -1) == "false"){
                        currentAV++;
                        QString btn = "L ";
                        int time = getLeftRightTime(currentAV, "left");
                        btn.append(QString("%1: %2s").arg(currentAV).arg(time));
                        leftAVButtons->append((new SelectableValueButton(currentAV, time)));
                        leftAVButtons->at(currentAV -1)->setFixedSize(time*100, 60);
                        leftAVButtons->at(currentAV -1)->setText(btn);
                        btnView->leftButtonLayout->addWidget(leftAVButtons->at(currentAV -1));
                    }
                }
            }
        }

        currentAV = 0;
        for(int i = 0; i < lstRightAVs->count(); ++i){
            if(btnView->rightButtonLayout->itemAt(i) == 0){
                if(lstRightAVs->at(i) == "false"){
                    btnView->rightButtonLayout->addItem(new QSpacerItem(100, 60));
                }
                else {
                    if(i > 0 && lstRightAVs->at(i -1) == "false"){
                        currentAV++;
                        QString btn = "R ";
                        int time = getLeftRightTime(currentAV, "right");
                        btn.append(QString("%1: %2s").arg(currentAV).arg(time));
                        rightAVButtons->append((new SelectableValueButton(currentAV, time)));
                        rightAVButtons->at(currentAV -1)->setFixedSize(time*100, 60);
                        rightAVButtons->at(currentAV -1)->setText(btn);
                        btnView->rightButtonLayout->addWidget(rightAVButtons->at(currentAV -1));
                    }
                }
            }
        }

        for(int i = 1; i <= totalAV; ++i){
            if(btnView->avButtonLayout->itemAt(i) == 0){
                QString btn = "Av_";
                int time = getTime(i);
                btn.append(QString("%1: %2s").arg(i).arg(time));
                avButtons->append(new SelectableValueButton(i, time));
                avButtons->at(i -1)->setFixedSize(time*100,60);
                avButtons->at(i -1)->setText(btn);
                btnView->avButtonLayout->addWidget(avButtons->at(i -1));
            }
        }
    }

    /**
     * @brief creates and shows layout of the minimized view
     */
    void StopWatch::btnMinimizeClicked(){
        windowMinimized = true;

        mini = new QWidget();
        minimizedLayout = new QHBoxLayout();

        minimizedLayout->addWidget(btnMaximize);
        minimizedLayout->addItem(new QSpacerItem(70, 45));
        minimizedLayout->addWidget(btnAVLeft);
        minimizedLayout->addWidget(btnAVRight);
        minimizedLayout->addWidget(btnAV);
        minimizedLayout->addItem(new QSpacerItem(70, 45));
        minimizedLayout->addWidget(btnPrevAV);
        minimizedLayout->addWidget(btnSelAV);
        minimizedLayout->addWidget(btnNextAV);
        minimizedLayout->addWidget(timer);
        minimizedLayout->addWidget(btnStartPause);

        minimizedLayout->setAlignment(timer, Qt::AlignRight);
        minimizedLayout->setAlignment(btnStartPause, Qt::AlignRight);

        minimizedLayout->addWidget(btnMinus);
        minimizedLayout->addWidget(btnPlus);
        minimizedLayout->addWidget(avTime);
        minimizedLayout->addWidget(btnSetLeft);
        minimizedLayout->addWidget(btnSetRight);
        minimizedLayout->addWidget(btnSetAv);
        minimizedLayout->addWidget(btnStopReset);
        minimizedLayout->addWidget(btnBothAV);
        minimizedLayout->addWidget(graphView);
        minimizedLayout->addWidget(timerTitle);
        minimizedLayout->addWidget(btnMinimize);

        btnMaximize->setVisible(true);
        btnMinus->setVisible(false);
        btnPlus->setVisible(false);
        avTime->setVisible(false);
        btnSetLeft->setVisible(false);
        btnSetRight->setVisible(false);
        btnSetAv->setVisible(false);
        btnStopReset->setVisible(false);
        btnBothAV->setVisible(false);
        graphView->setVisible(false);
        timerTitle->setVisible(false);
        btnMinimize->setVisible(false);

        mini->setLayout(minimizedLayout);
        this->setCentralWidget(mini);
        this->setMaximumHeight(65);
    }

    /**
     * @brief creates and shows layout of the maximized view
     */
    void StopWatch::btnMaximizeClicked(){
        windowMinimized = false;

        main = new QWidget();
        mainLayout = new QHBoxLayout();
        mainTimerLayout = new QVBoxLayout();
        timerBtnLayout = new QVBoxLayout();
        mainAVLayout = new QVBoxLayout();
        avSelLayout = new QHBoxLayout();
        avTimeLayout = new QHBoxLayout();
        avLeftRightLayout = new QHBoxLayout();
        avSetLayout = new QVBoxLayout();
        timerBtnLayout2 = new QHBoxLayout();

        avLeftRightLayout->addWidget(btnMinimize);
        avLeftRightLayout->addWidget(btnMaximize);

        avLeftRightLayout->addWidget(btnAVLeft);
        avLeftRightLayout->addWidget(btnAVRight);
        avLeftRightLayout->addWidget(btnAV);
        avSelLayout->addWidget(btnPrevAV);
        avSelLayout->addWidget(btnSelAV);
        avSelLayout->addWidget(btnNextAV);
        avTimeLayout->addWidget(btnMinus);
        avTimeLayout->addWidget(avTime);
        avTimeLayout->addWidget(btnPlus);
        mainAVLayout->addLayout(avLeftRightLayout);
        mainAVLayout->addLayout(avSelLayout);
        mainAVLayout->addLayout(avTimeLayout);

        avSetLayout->addWidget(btnSetLeft);
        avSetLayout->addWidget(btnSetRight);
        avSetLayout->addWidget(btnSetAv);

        timerBtnLayout->addWidget(btnStartPause);
        timerBtnLayout->addWidget(btnStopReset);

        timerBtnLayout2->addWidget(btnBothAV);
        timerBtnLayout2->addLayout(timerBtnLayout);
        mainTimerLayout->addLayout(timerBtnLayout2);
        mainTimerLayout->addWidget(timerTitle);
        mainTimerLayout->addWidget(timer);
        mainTimerLayout->setAlignment(timer, Qt::AlignCenter);

        btnMaximize->setVisible(false);
        btnMinus->setVisible(true);
        btnPlus->setVisible(true);
        avTime->setVisible(true);
        btnSetLeft->setVisible(true);
        btnSetRight->setVisible(true);
        btnSetAv->setVisible(true);
        btnStopReset->setVisible(true);
        btnBothAV->setVisible(true);
        graphView->setVisible(true);
        timerTitle->setVisible(true);
        btnMinimize->setVisible(true);

        mainLayout->addLayout(mainAVLayout);
        mainLayout->addWidget(graphView);
        mainLayout->addLayout(avSetLayout);
        mainLayout->addLayout(mainTimerLayout);

        main->setLayout(mainLayout);
        this->setCentralWidget(main);
        this->setMaximumHeight(175);
    }
