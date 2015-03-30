#ifndef TIMESPINNER_H
#define TIMESPINNER_H

#include <QWidget>
#include <QTime>
#include <QGridLayout>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "numberlineedit.h"
#include "timelineedit.h"

/**
 * @brief The TimeSpinner class provides functionality for displaying and selecting a <a href="http://doc.qt.io/qt-4.8/qtime.html">QTime</a>.
 *
 * An instance of TimeSpinner uses a TimeLineEdit for displaying a time and in this way provides funtionality to
 * manually enter the time via a keyboard.
 *
 * Furthermore buttons for increasing the hour and minute are displayed above the TimeLineEdit,
 * buttons for decreasing are displayed below respectively
 *
 * The TimeSpinner provides public methods to get and set the displayed time.
 *
 */
class TimeSpinner : public QWidget
{
    Q_OBJECT
public:
    explicit TimeSpinner(QWidget *parent = 0);

    /**
     * @brief getTime Gets the currently displayed time on the TimerSpinner.
     * @return The currently displayed time.
     */
    QTime getTime() const;

    /**
     * @brief setTime Sets the current time to a given time which is displayed on the TimeSpinner.
     * @param time The new time to be displayed.
     */
    void setTime(const QTime &time);

private:
    QGridLayout *spinnerLayout;

    TimeLineEdit *timeBxTime;

    QPushButton *btnHourInc;
    QPushButton *btnHourDec;
    QPushButton *btnMinuteInc;
    QPushButton *btnMinuteDec;

    QTime currentTime;

    void update();

};

#endif // TIMESPINNER_H
