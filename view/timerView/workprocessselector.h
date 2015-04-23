#ifndef WORKPROCESSSELECTOR_H
#define WORKPROCESSSELECTOR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>


/**
 * @brief The WorkProcessSelector class provides functionality to display and select a workprocess.
 */
class WorkProcessSelector : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief WorkProcessSelector Creates a new WorkProcessSelector object with the given parent.
     * @param parent The parent of the object.
     */
    explicit WorkProcessSelector(QWidget *parent = 0);
    ~WorkProcessSelector();

signals:
    /**
     * @brief nextAV Can be emitted to signal that the next workprocess should be selected.
     */
    void nextAV();

    /**
     * @brief previousAV Can be emitted to signal that the previous workprocess should be selected.
     */
    void previousAV();

public slots:
    /**
     * @brief setSelectedAV Sets the selected workprocess to the given one.
     * @param avNum The number of the workprocess to select.
     */
    void setSelectedAV(int avNum);

    /**
     * @brief setAVPrefix Sets the prefix of the selected workprocess to the given one.
     * @param pref The prefix to set.
     */
    void setAVPrefix(const QString &pref);

    /**
     * @brief setSelectedAVNone Marks the selected workprocess as empty.
     */
    void setSelectedAVNone();

    /**
     * @brief setHasPreviousAV Enables or Disables the previous button depending on the given value.
     * @param hasPrevious True, the selected workprocess has a previous workprocess, otherwise false.
     */
    void setHasPreviousAV(bool hasPrevious);

    /**
     * @brief setHasNextAV Enables or Disables the next button depending on the given value.
     * @param hasNext True, the selected workprocess has a next workprocess, otherwise false.
     */
    void setHasNextAV(bool hasNext);

private:
    QPushButton *btnRight;
    QPushButton *btnLeft;
    QLabel *lblSelectedAV;

    QString prefix;
};

#endif // WORKPROCESSSELECTOR_H
