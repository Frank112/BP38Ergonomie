#ifndef MINIMIZEDTIMERVIEW_H
#define MINIMIZEDTIMERVIEW_H

#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QTime>
#include "workprocesstypepicker.h"
#include "workprocessselector.h"
#include "../../enum.h"

/**
 * @brief The MinimizedTimerView class provides functionality to set the minimal
 * settings of a workprocess recording.
 *
 * @author Markus Danz
 */
class MinimizedTimerView : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MinimizedTimerView creates a new MinimizedTimerView object with the given state and parent.
     * @param state The timer state of the the object.
     * @param parent The parent of the object.
     */
    explicit MinimizedTimerView(TimerState state = TimerState::IDLE, QWidget *parent = 0);
    ~MinimizedTimerView();

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
    void setSelectedAV(int id);

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
     * @brief setWorkProcessType Sets the given prefix on the wpSelector and the given type on the wpTypePicker.
     * @param type The type to set.
     * @param prefix The prefix to set.
     */
    void setWorkProcessType(AVType type, const QString &prefix);

private slots:

    void btnPlayPausedClicked();

private:
    TimerState state;

    QLabel *lblTime;

    QPushButton *btnMaximized;
    QPushButton *btnPlayPaused;

    WorkProcessSelector *wpSelector;

    WorkProcessTypePicker *wpTypePicker;
};

#endif // MINIMIZEDTIMERVIEW_H
