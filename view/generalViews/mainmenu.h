#ifndef MAINMENU_H
#define MAINMENU_H

#include "../navigation/simplenavigateablewidget.h"
#include "../iconbutton.h"
#include <QPushButton>
#include <QWidget>
#include <QLabel>

/**
 * @brief The MainMenu class provides functionality to display and open main menu entries.
 *
 * MainMenu inherits SimpleNavigateableWidget.
 *
 * @author Marius Gassen
 */
class MainMenu : public SimpleNavigateableWidget
{
    Q_OBJECT
public:
    /**
     * @brief MainMenu Creates a new MainMenu object with the given parent.
     * @param btnparent The parent of the object.
     */
    explicit MainMenu(QWidget *btnparent = 0);

    bool canGoBack() const{
        return false;
    }

    bool hasAdditionalNavigation() const{
        return true;
    }

    QList<QAbstractButton*> * getAdditionalNavigation() const;

signals:
    /**
     * @brief createBlankRecording Can be emitted to signal that a new blank recording should be created.
     */
    void createBlankRecording();

private slots:
    void btnSettingsClicked();
    void btnMetaDataViewClicked();
    void btnWorkplaceListClicked();
    void btnRessourceManagementClicked();
    void btnShiftClicked();
    void btnNewRecordingClicked();
    void btnSendDatabaseClicked();
    void btnImportClicked();

private:
    QLabel *lblViewName;
    IconButton *btnMetaDataView;
    IconButton *btnWorkplaceList;
    IconButton *btnRessourceManagement;
    IconButton *btnShift;
    QPushButton *btnSettings;
    QPushButton *btnNewRecording;
    QPushButton *btnSendDatabase;
    QPushButton *btnImport;


};

#endif // MAINMENU_H
