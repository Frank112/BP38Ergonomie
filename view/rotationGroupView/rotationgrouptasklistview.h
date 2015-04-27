#ifndef ROTATIONGROUPTASKLISTVIEW_H
#define ROTATIONGROUPTASKLISTVIEW_H

#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/irotationgrouptasklist.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>

/**
 * @brief The RotationGroupTaskListView class provides functionality to create a new rotation group tasks
 * and display all existing tasks in a list.
 *
 * @author Marius Gassen
 */
class RotationGroupTaskListView : public SimpleNavigateableWidget, IRotationGroupTaskList
{
    Q_OBJECT
    Q_INTERFACES(IRotationGroupTaskList)
public:

    /**
     * @brief RotationGroupTaskListView Creates a new RotationGroupTaskListView object with its parent.
     * @param parent The parent widget.
     */
    explicit RotationGroupTaskListView(QWidget *parent = 0);

    bool hasAdditionalNavigation() const {
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:
    void createRotationGroupTask(QHash<QString, QVariant> values);
    void deleteRotationGroupTask(int id);
    void selectRotationGroupTask(int id);

public slots:
    void addRotationGroupTask(QHash<QString, QVariant> values);
    void updateRotationGroupTask(QHash<QString, QVariant> values);
    void removeRotationGroupTask(int id);
    void clearRotationGroupTasks();

private slots:
    void btnPlusClicked();
    void dliRotationGroupTaskClicked(int id);

private:
    const QList<QStringList> rotationGroupCaptions = QList<QStringList>() << (QStringList() << tr("Total Duration"));
    QPushButton *btnPlus;
    QVBoxLayout *listContentLayout;
    QScrollArea *scRotationGroups;
};

#endif // ROTATIONGROUPTASKLISTVIEW_H
