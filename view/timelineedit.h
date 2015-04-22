#ifndef TIMELINEEDIT_H
#define TIMELINEEDIT_H
#include <QTime>
#include <QRegularExpression>
#include "../enum.h"
#include "textlineedit.h"

/**
 * @brief The TimeLineEdit class provides functionality for displaying and editing a time.
 */
class TimeLineEdit : public TextLineEdit
{
    Q_OBJECT
public:

    /**
     * @brief TimeLineEdit Creates a new TimeLineEdit object with the given type
     * @param parent
     * @param type The type of the time to be displayed
     * @see TimeLineType
     */
    explicit TimeLineEdit(QWidget *parent = 0, TimeLineType type = TimeLineType::MINUTE_SECOND);

    /**
     * @brief getTime Returns the currently displayed time.
     * @return The currently displayed time.
     */
    QTime getTime() const;

    /**
     * @brief setTime Sets the displayed time to a new one.
     * @param time The new time.
     */
    void setTime(const QTime &time);

signals:

    /**
     * @brief dayIncreased A signal that is emitted, when the day is increased, hence the
     * hour goes beyond 0.
     */
    void dayIncreased();

    /**
     * @brief dayDecreased A signal that is emitted when the day is decreased, hence
     * the hour exceeds 24.
     */
    void dayDecreased();

    /**
     * @brief timeChanged A signal that is emitted, when the time changed.
     */
    void timeChanged();

public slots:
    /**
     * @brief increaseHour Increases the hour displayed.
     */
    void increaseHour();

    /**
     * @brief decreaseHour Decreases the hour displayed.
     */
    void decreaseHour();

    /**
     * @brief increaseMinute Increases the miunte displayed.
     */
    void increaseMinute();

    /**
     * @brief decreaseMinute Decreases the minute displayed.
     */
    void decreaseMinute();

private slots:
    void updateText();
    void updateTime();

private:

    static const QRegularExpression regExMS;
    static const QRegularExpression regExHM;
    static const QRegularExpression regExHMS;

    QTime currentTime;
    TimeLineType type;
};

#endif // TIMELINEEDIT_H
