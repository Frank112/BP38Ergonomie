#ifndef WORKPROCESSBUTTON_H
#define WORKPROCESSBUTTON_H

#include "../selectablevaluebutton.h"
#include <QTime>

/**
 * @brief The WorkProcessButton class provides functionality of a button representing a workprocess.
 */
class WorkProcessButton : public SelectableValueButton
{
    Q_OBJECT
public:
    /**
     * @brief WorkProcessButton Creates a new WorkProcessButton object with the given parameters.
     * @param id The id of the object.
     * @param value The value of the object.
     * @param start The start time of the workprocess.
     * @param end The end time of the workprocess.
     * @param parent The parent of the object.
     */
    explicit WorkProcessButton(int id, int value, const QTime &start, const QTime &end, QWidget *parent = 0);
    ~WorkProcessButton();

    /**
     * @brief getEndTime Returns the end time of the workprocess belonging to the WorkProcessButton.
     * @return The end time of the workprocess.
     */
    QTime getEndTime() const;

    /**
     * @brief getStartTime Returns the start time of the workprocess belonging to the WorkProcessButton.
     * @return The start time of the workprocess.
     */
    QTime getStartTime() const;

signals:
    /**
     * @brief clickedWithIDValue Can be emitted to signal that the WorkProcessButton with the given id and value was clicked.
     * @param id The id of the object.
     * @param value The value of the object.
     */
    void clickedWithIDValue(int id, int value);


public slots:
    /**
     * @brief setEndTime Sets the end time to the given time.
     * @param end The time to set.
     */
    void setEndTime(const QTime &end);

    /**
     * @brief setStartTime Sets the start time to the given time.
     * @param start The time to set.
     */
    void setStartTime(const QTime &start);

private slots:
    void btnClicked();

private:
    QTime start;
    QTime end;

};

#endif // WORKPROCESSBUTTON_H
