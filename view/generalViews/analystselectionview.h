#ifndef ANALYSTSELECTIONVIEW_H
#define ANALYSTSELECTIONVIEW_H

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/ianalystlist.h"
#include "../textlineedit.h"
#include "../detailedlistitem.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The AnalystSelectionView class provides functionality to display and select analysts.
 *
 * AnalystSelectionView inherits SimpleNavigateableWidget and implements IAnalystList.
 *
 * @author Markus Danz
 */
class AnalystSelectionView : public SimpleNavigateableWidget, IAnalystList
{
    Q_OBJECT
    Q_INTERFACES(IAnalystList)

public:
    /**
     * @brief AnalystSelectionView Creates a new AnalystSelectionView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit AnalystSelectionView(QWidget *parent = 0);

    bool canGoBack() const{
        return false;
    }

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:
    void createAnalyst(QHash<QString, QVariant> values);
    void deleteAnalyst(int id);
    void selectAnalyst(int id);

public slots:
    void addAnalyst(QHash<QString, QVariant> values);
    void updateAnalyst(QHash<QString, QVariant> values);
    void removeAnalyst(int id);
    void clearAnalysts();

private slots:
    void dliPressed(int id);
    void btnCreateAnalystClicked();

private:
    QPushButton *btnCreateAnalyst;

    QVBoxLayout *listContentLayout;
    QScrollArea *scAnalysts;

};

#endif // ANALYSTSELECTIONVIEW_H
