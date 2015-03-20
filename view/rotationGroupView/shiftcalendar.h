#ifndef SHIFTCALENDAR_H
#define SHIFTCALENDAR_H

#include <QTime>
#include <QScrollArea>
#include <QPainter>
#include <QPicture>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "../interfaces/irotationgroup.h"
#include "../interfaces/ishift.h"
#include "../interfaces/irotationgrouptasklist.h"
#include "../selectablevaluebutton.h"
#include "../numberlineedit.h"
#include "../textlineedit.h"
#include "../navigation/simplenavigateablewidget.h"

class ShiftCalendar : public SimpleNavigateableWidget, IRotationGroup, IShift, IRotationGroupTaskList
{
    Q_OBJECT
    Q_INTERFACES(IRotationGroupTaskList)
    Q_INTERFACES(IRotationGroup)
    Q_INTERFACES(IShift)

public:
    explicit ShiftCalendar(QWidget *parent = 0, const QTime &beginTime = QTime(6,0), const QTime &endTime = QTime(14, 0));
    ~ShiftCalendar();

    bool hasAdditionalNavigation() const {
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

    QString getBreakName() const;
    int getBreakDuration() const;

signals:
    void createRotationGroupTask(QHash<QString, QVariant> values);
    void deleteRotationGroupTask(int id);
    void selectRotationGroupTask(int id);

    void createRotationGroup(QHash<QString, QVariant> values);
    void deleteRotationGroup(int id);
    void createBreak(QHash<QString, QVariant> values);
    void deleteBreak(int id);

    void requestRemoveEntry(int id);
    void requestMoveEntryUp(int id);
    void requestMoveEntryDown(int id);

    void saveShift(QHash<QString, QVariant> values);

public slots:
    void addRotationGroupTask(QHash<QString, QVariant> values);
    void updateRotationGroupTask(QHash<QString, QVariant> values);
    void removeRotationGroupTask(int id);
    void clearRotationGroupTasks();

    void addRotationGroupEntry(QHash<QString, QVariant> values);
    void updateRotationGroupEntry(QHash<QString, QVariant> values);
    //void removeRotationGroupEntry(int id);
    void addBreakEntry(QHash<QString, QVariant> values);
    //void removeBreakEntry(int id);

    void removeEntry(int id);
    void moveEntryUp(int id);
    void moveEntryDown(int id);
    void clearCalendar();

    void setShift(QHash<QString, QVariant> values);

private slots:
    void btnAddBreakClicked();
    void btnRotationClicked();
    void setSelectedId(int id);

    void btnMoveUpClicked();
    void btnMoveDownClicked();
    void btnDeleteClicked();

private:
    static const int HOUR_HEIGHT = 160;

    QTime beginTime;
    QTime endTime;

    QPushButton *btnRotation;

    QLabel *lblAddRotationGroup;
    QWidget *rotationGroupListContent;
    QScrollArea *scRotationGroups;
    QVBoxLayout *rotationGroupListLayout;

    QLabel *lblAddBreak;
    QLabel *lblBreakDuration;
    NumberLineEdit *numBxBreakDuration;
    QPushButton *btnAddBreak;
    int currentId;

    QPainter painter;
    QPicture picCalendar;
    QLabel *lblCalendar;
    QScrollArea *scCalendar;
    QVBoxLayout *calendarEntryLayout;    
    QPushButton *btnMoveUp;
    QPushButton *btnMoveDown;
    QPushButton *btnDelete;

    void drawBackground();

    const QList<QStringList> rotationGroupCaptions = QList<QStringList>() << (QStringList() << tr("Duration"));

};

#endif // SHIFTCALENDAR_H
