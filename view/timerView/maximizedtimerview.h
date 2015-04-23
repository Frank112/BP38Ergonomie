#ifndef MAXIMIZEDTIMERVIEW_H
#define MAXIMIZEDTIMERVIEW_H

#include <QWidget>
#include <QTime>
#include "enum.h"
#include "workprocessselector.h"
#include "../optionselectioncontrol.h"
#include "graphtimelineview.h"
#include "timepicker.h"
#include "../selectablevaluebutton.h"
#include "workprocesstypepicker.h"

/**
 * @brief The MaximizedTimerView class provides functionality to controll the
 * stopwatch and set workprocesses.
 *
 * @author Markus Danz
 */
class MaximizedTimerView : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MaximizedTimerView creates a new MaximizedTimerView object with the given state and parent.
     * @param state The timer state of the object.
     * @param parent The parent of the object.
     */
    explicit MaximizedTimerView(TimerState state = TimerState::IDLE, QWidget *parent = 0);
    ~MaximizedTimerView();

    /**
     * @brief getDuration Returns the time of the time picker.
     * @return The time of the time picker.
     */
    QTime getDuration() const;

    /**
     * @brief getWorkprocessType Returns the currently selected workprocess type.
     * @return The currently selected workprocess type.
     */
    AVType getWorkprocessType() const;

    /**
     * @brief getState Returns the current timer state of the object.
     * @return The current timer state.
     */
    TimerState getState() const;

    /**
     * @brief getTime Returns the current time of the objects stopwatch.
     * @return The current time of the objects stopwatch.
     */
    QTime getTime() const;

signals:
    /**
     * @brief nextWorkProcess Can be emitted to signal that the next workprocess should be selected.
     */
    void nextWorkProcess();

    /**
     * @brief previousWorkProcess Can be emitted to signal that the previous workprocess should be selected.
     */
    void previousWorkProcess();

    /**
     * @brief workProcessTypeChanged Can be emitted to signal that the selected workprocess type should be changed to the given type.
     * @param type The type to set as new selected type.
     */
    void workProcessTypeChanged(AVType type);

    /**
     * @brief minimize Can be emitted to signal that the minimized timer view should be displayed.
     */
    void minimize();

    /**
     * @brief maximize Can be emitted to signal that the maximized timer view should be displayed.
     */
    void maximize();

    /**
     * @brief play Can be emitted to signal that the stopwatch should be running.
     */
    void play();

    /**
     * @brief pause Can be emitted to signal that the stopwatch should be paused.
     */
    void pause();

    /**
     * @brief stop Can be emitted to signal that the stopwatch should be stopped.
     */
    void stop();

    /**
     * @brief reset Can be emitted to signal that the stopwatch and all workprocesses should be reset.
     */
    void reset();

    /**
     * @brief leftSet Can be emitted to signal that a left workprocess should be set.
     */
    void leftSet();

    /**
     * @brief rightSet Can be emitted to signal that a right workprocess should be set.
     */
    void rightSet();

    /**
     * @brief avSet Can be emitted to signal that a basic workprocess should be set.
     */
    void avSet();

    /**
     * @brief durationChanged Can be emitted to signal that the duration of the selected
     * workprocess should be changed to the given duration.
     * @param duration The duration to set.
     */
    void durationChanged(const QTime &duration);

    /**
     * @brief leftChanged Can be emitted to signal that the left workprocess button was clicked.
     * @param b True, iff the button is now selected, otherwise false.
     */
    void leftChanged(bool b);

    /**
     * @brief rightChanged Can be emitted to signal that the right workprocess button was clicked.
     * @param b True, iff the button is now selected, otherwise false.
     */
    void rightChanged(bool b);

public slots:
    /**
     * @brief setState Sets the objects timer state to the given state and enables the buttons accordingly.
     * @param state The state to set.
     */
    void setState(TimerState state);

    /**
     * @brief setTime Sets the time of the stopwatch to the given time.
     * @param time The time to set.
     */
    void setTime(const QTime &time);

    /**
     * @brief setSelectedAV Sets the selected workprocess to the one with the given id.
     * @param id The id of the workprocess to select.
     */
    void setSelectedAV(int id, const QTime &duration);

    /**
     * @brief setWorkProcessType Sets the given prefix on the wpSelector and the given type on the wpTypePicker.
     * @param type The type to set.
     * @param prefix The prefix to set.
     */
    void setWorkProcessType(AVType type, const QString &prefix);

    /**
     * @brief setSelectedAVNone Sets the selected workprocess to none.
     */
    void setSelectedAVNone();

    /**
     * @brief setHasPreviousAV Sets the has previous workprocess on the wpSelector.
     * @param hasPrevious The boolean to set.
     */
    void setHasPreviousAV(bool hasPrevious);

    /**
     * @brief setHasNextAV Sets the has next workprocess on the wpSelector.
     * @param hasNext The boolean to set.
     */
    void setHasNextAV(bool hasNext);

    /**
     * @brief leftStarted Starts a new left workprocess on the graph at the given starttime.
     * @param startTime The start time of the new workprocess.
     */
    void leftStarted(const QTime &startTime);

    /**
     * @brief leftEnded Ends the last left workprocess on the graph at the given endtime.
     * @param endTime The end time of the workprocess.
     */
    void leftEnded(const QTime &endTime);

    /**
     * @brief rightStarted Starts a new right workprocess on the graph at the given starttime.
     * @param startTime The start time of the new workprocess.
     */
    void rightStarted(const QTime &startTime);

    /**
     * @brief rightEnded Ends the last right workprocess on the graph at the given endtime.
     * @param endTime The end time of the workprocess.
     */
    void rightEnded(const QTime &endTime);

    /**
     * @brief basicStarted Starts a new basic workprocess on the graph at the given starttime.
     * @param startTime The start time of the new workprocess.
     */
    void basicStarted(const QTime &startTime);

    /**
     * @brief basicEnded Ends the last basic workprocess on the graph at the given endtime.
     * @param endTime The end time of the workprocess.
     */
    void basicEnded(const QTime &endTime);

    /**
     * @brief initialize Initializes the graph with the given workprocesses.
     * @param leftWPs The left workprocesses to initialize.
     * @param rightWPs The right workprocesses to initialize.
     * @param basicWPs The basic workprocesses to initialize.
     */
    void initialize(QVector<QVariant> *leftWPs, QVector<QVariant> *rightWPs, QVector<QVariant> *basicWPs);

    /**
     * @brief updateGraphTimeLine Updates the graph.
     * @param currentTime The current time of the stopwatch.
     */
    void updateGraphTimeLine(const QTime &currentTime);

    /**
     * @brief leaveTimer Stops the stopwatch, if it is not already stopped.
     */
    void leaveTimer();

    /**
     * @brief disableMaximize Disables the maximize button.
     */
    void disableMaximize();

    /**
     * @brief enableMaximize Enables the maximize button.
     */
    void enableMaximize();

private slots:
    void btnPlayPausedClicked();
    void btnStopResetClicked();
    void emitBothSet();

    void btnLeftClicked();
    void btnRightClicked();
    void btnBothClicked();
    void btnAVClicked();

private:
    TimerState state;

    QLabel *lblTime;

    QPushButton *btnMinimized;
    QPushButton *btnMaximized;
    QPushButton *btnPlayPaused;
    QPushButton *btnStopReset;

    SelectableValueButton *btnSetLeft;
    SelectableValueButton *btnSetRight;
    SelectableValueButton *btnSetBoth;
    QPushButton *btnSetAV;

    TimePicker *timePicker;
    WorkProcessSelector *wpSelector;

    WorkProcessTypePicker *wpTypePicker;

    GraphTimelineView *graphTimer;
};

#endif // MAXIMIZEDTIMERVIEW_H
