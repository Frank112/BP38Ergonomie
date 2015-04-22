#ifndef DATELINEEDIT_H
#define DATELINEEDIT_H

#include "textlineedit.h"
#include <QDate>
#include <QRegularExpression>

/**
 * @brief The DateLineEdit class provides functionality for displaying and editing a date.
 */
class DateLineEdit : public TextLineEdit
{
    Q_OBJECT
public:

    /**
     * @brief DateLineEdit creates a new DateLineEdit object with the given parent.
     * @param parent The parent of the object.
     */
    explicit DateLineEdit(QWidget *parent = 0);

    /**
     * @brief getDate Returns the date currently displayed in the line edit.
     * @return The currently displayed date.
     */
    QDate getDate() const;

    /**
     * @brief setDate Sets the date to be displayed.
     * @param date The date to set.
     */
    void setDate(const QDate &date);

signals:

    /**
     * @brief dateChanged Can me emitted to signalize that the date has changed.
     */
    void dateChanged();

public slots:

    /**
     * @brief increaseDay Increases the displayed date by 1.
     */
    void increaseDay();

    /**
     * @brief increaseMonth Increases the displayed month by 1.
     */
    void increaseMonth();

    /**
     * @brief increaseYear Increases the displayed year by 1.
     */
    void increaseYear();

    /**
     * @brief decreaseDay Decreases the displayed day by 1.
     */
    void decreaseDay();

    /**
     * @brief decreaseMonth Decreases the displayed month by 1.
     */
    void decreaseMonth();

    /**
     * @brief decreaseYear Decreases the displayed year by 1.
     */
    void decreaseYear();

private slots:
    void updateText();
    void updateDate();

private:
    static const QRegularExpression regEx;

    QDate currentDate;

};

#endif // DATELINEEDIT_H
