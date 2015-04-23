#ifndef TIMERVIEWCONTROLLER_H
#define TIMERVIEWCONTROLLER_H

#include <QWidget>
#include <QTime>
#include <QList>
#include "../../enum.h"
#include "../interfaces/iworkprocesscontroller.h"
#include "minimizedtimerview.h"
#include "maximizedtimerview.h"
#include "ganttTimerview.h"

/**
 * @brief The TimerViewController class provides functionality to manage the recording,
 * selection and display of the workprocesses.
 */
class TimerViewController : public QWidget, IWorkProcessController
{
    Q_OBJECT
    Q_INTERFACES(IWorkProcessController)
public:
    /**
     * @brief TimerViewController Creates a new TimerViewController object with the given parent.
     * @param parent The parent of the object.
     */
    explicit TimerViewController(QWidget *parent = 0);

signals:
    void selectNextWorkProcess();
    void selectPreviousWorkProcess();
    void workProcessTypeChanged(AVType type);
    void workProcessDurationChanged(QTime duration);
    void createWorkProcess(QHash<QString, QVariant> values);
    void resetWorkProcesses();

    /**
     * @brief showGantView Can be emitted to signal that the GANTT view should be displayed.
     */
    void showGantView();

    /**
     * @brief hideGantView Can be emitted to signal that the GANTT view should be closed.
     */
    void hideGantView();

    /**
     * @brief changingWorkProcess Can be emitted to signal that a differernt workprocess is selected.
     */
    void changingWorkProcess();

public slots:
    void setSelectedWorkProcess(QHash<QString, QVariant> values);
    void setHasPreviousWorkProcess(bool hasPrevious);
    void setHasNextWorkProcess(bool hasNext);
    void setSelectedWorkProcessType(AVType type);
    void initializedWorkProcesses(QList<QHash<QString, QVariant>> values);

    /**
     * @brief closeTimerView Stops the timer and closes the GANTT view if necessary.
     */
    void closeTimerView();

    /**
     * @brief gantViewShown Disables the maximize button.
     */
    void gantViewShown();

    /**
     * @brief gantViewHidden Enables the maximize button.
     */
    void gantViewHidden();

protected:
    void timerEvent(QTimerEvent *);

private slots:
    void setSelectedWorkprocessNone();

    void minimizeView();
    void maximizeView();
    void startTimer();
    void pauseTimer();
    void stopTimer();
    void resetTimer();
    void setTime(const QTime &time);
    void setWorkProcessType(AVType type, const QString &prefix);

    void createLeftWorkProcessRequested();
    void createRightWorkProcessRequested();
    void createBasicWorkProcessRequested();

    void selectPreviousWorkProcessClicked();
    void selectNextWorkProcessClicked();
    void changingWorkProcessTypeClicked(AVType type);

    void changeLeft(bool b);
    void changeRight(bool b);

private:
    bool isLeftSet;
    bool isRightSet;
    bool isBasicSet;

    bool isGantShown;

    int timerID;

    QTime startTimeBasic;
    QTime startTimeLeft;
    QTime startTimeRight;
    QTime currentTime;

    TimerState timerState;
    TimerDisplayState displayState;
    MaximizedTimerView *maxTimerView;
    MinimizedTimerView *minTimerView;

    const QStringList TYPE_PREFIXE = QStringList()<<"L"<<"R"<<"AV";

    void syncTimerStates(TimerState state);
    void syncCurrentTime(const QTime &currentTime);

};

#endif // TIMERVIEWCONTROLLER_H

