#ifndef TIMEPICKER_H
#define TIMEPICKER_H

#include <QWidget>
#include <QTime>
#include <QPushButton>
#include "../timelineedit.h"

/**
 * @brief The TimePicker class provides functionality to display and change time.
 */
class TimePicker : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief TimePicker Creates a new TimePicker object with the given parent.
     * @param parent The parent of the object.
     */
    explicit TimePicker(QWidget *parent = 0);
    ~TimePicker();

    /**
     * @brief getTime Returns the time currently displayed.
     * @return The time currently displayed.
     */
    QTime getTime() const;

    /**
     * @brief setTime Sets the time to be displayed.
     * @param time The time to set.
     */
    void setTime(const QTime &time);

signals:
    /**
     * @brief timeChanged Can be emitted to signal that the time in the time picker has changed.
     * @param time The new time of the time picker.
     */
    void timeChanged(const QTime &time);

private slots:
    void increaseTime();
    void decreaseTime();
    void emitTimeChanged();

private:
    TimeLineEdit *timeBxTime;
    QPushButton *btnIncreaseTime;
    QPushButton *btnDecreaseTime;

};

#endif // TIMEPICKER_H
