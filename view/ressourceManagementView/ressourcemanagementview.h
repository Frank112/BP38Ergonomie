#ifndef RESSOURCEMANAGEMENTVIEW_H
#define RESSOURCEMANAGEMENTVIEW_H

#include <QWidget>
#include "../iconbutton.h"
#include "../navigation/simplenavigateablewidget.h"

/**
 * @brief The RessourceManagementView class provides functionality to display and open ressource entries.
 *
 * RessourceManagementView inherits SimpleNavigateableWidget.
 *
 * @author Markus Danz
 */
class RessourceManagementView : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    /**
     * @brief RessourceManagementView Creates a new RessourceManagementView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit RessourceManagementView(QWidget *parent = 0);

private slots:
    void btnEquipmentClicked();
    void btnProductClicked();
    void btnTransportationClicked();
    void btnEmployeeClicked();
    
private:
    IconButton *btnEquipmentView;
    IconButton *btnProductView;
    IconButton *btnTransportationView;
    IconButton *btnEmployeeView;


};

#endif // RESSOURCEMANAGEMENTVIEW_H
