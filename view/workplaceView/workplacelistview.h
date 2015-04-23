#ifndef WORKPLACELISTVIEW_H
#define WORKPLACELISTVIEW_H

#include "../detailedlistitem.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/IWorkplaceList.h"
#include "../databaseHandler/dbconstants.h"
#include <QPushButton>
#include <QScrollArea>

/**
 * @brief The WorkplaceListView class provides functionality to create a new workplace and display
 * all existing workplaces in a list.
 *
 * WorkplaceListView inherits SimpleNavigateableWidget and implements IWorkplaceList.
 *
 * @author Marius Gassen
 */
class WorkplaceListView : public SimpleNavigateableWidget, IWorkplaceList
{
    Q_OBJECT
    Q_INTERFACES(IWorkplaceList)
public:
    /**
     * @brief WorkplaceListView Creates a new WorkplaceListView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit WorkplaceListView(QWidget *parent = 0);

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:   
    void createWorkplace(QHash<QString, QVariant> values);
    void deleteWorkplace(int id);
    void selectWorkplace(int id);

public slots:
    void addWorkplace(QHash<QString, QVariant> values);
    void updateWorkplace(QHash<QString, QVariant> values);
    void removeWorkplace(int id);
    void clearWorkplaces();

private slots:
    void btnPlusClicked();
    void dliWorkplaceClicked(int id);

private:
    const QList<QStringList> workplaceCaptions = QList<QStringList>() << (QStringList() << tr("Description") << tr("Code"));
    QPushButton *btnPlus;
    QVBoxLayout *listContentLayout;
    QScrollArea *scWorkplaces;
};

#endif // WORKPLACELISTVIEW_H
