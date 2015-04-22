#ifndef DATETIMESPINNER_H
#define DATETIMESPINNER_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDateTime>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "timelineedit.h"
#include "datelineedit.h"

/**
 * @brief The DateTimeSpinner class provides functionality to display and edit a date and a time, by either
 * focusing a DateLineEdit and a TimeLineEdit or via buttons above and below the boxes to increase and decrease
 * each value.
 */
class DateTimeSpinner : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief DateTimeSpinner Creates a new DateTimeSpinner object with a parent.
     * @param parent The parent widget.
     */
    explicit DateTimeSpinner(QWidget *parent = 0);

    /**
     * @brief getDateTime Returns the currently displayed date and time.
     * @return The currently displayed date and time.
     */
    QDateTime getDateTime() const;

    /**
     * @brief setDateTime Sets the displayed to the given one.
     * @param time The time to set.
     */
    void setDateTime(const QDateTime &time);

signals:
    /**
     * @brief dateTimechanged Can be emitted to signalize that the date or time have changed.
     */
    void dateTimechanged();

private:
    QGridLayout *spinnerLayout;

    DateLineEdit *dateBxDate;
    TimeLineEdit *timeBxTime;

    QPushButton *btnDayInc;
    QPushButton *btnDayDec;
    QPushButton *btnMonthInc;
    QPushButton *btnMonthDec;
    QPushButton *btnYearInc;
    QPushButton *btnYearDec;
    QPushButton *btnHourInc;
    QPushButton *btnHourDec;
    QPushButton *btnMinuteInc;
    QPushButton *btnMinuteDec;
};

#endif // DATETIMESPINNER_H
