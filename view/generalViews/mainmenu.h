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
    /**
     * @brief btnSettingsClicked Emits a signal to open the settings view.
     */
    void btnSettingsClicked();

    /**
     * @brief btnMetaDataViewClicked Emits a signal to open the metadata view.
     */
    void btnMetaDataViewClicked();

    /**
     * @brief btnWorkplaceListClicked Emits a signal to open the workplace list view.
     */
    void btnWorkplaceListClicked();

    /**
     * @brief btnRessourceManagementClicked Emits a signal to open the ressource management view.
     */
    void btnRessourceManagementClicked();

    /**
     * @brief btnShiftClicked Emits a signal to open the shift view.
     */
    void btnShiftClicked();

    /**
     * @brief btnNewRecordingClicked Emits a signal to create a new blank recording.
     */
    void btnNewRecordingClicked();

    /**
     * @brief btnSendDatabaseClicked Emits a signal to open the send data popup.
     */
    void btnSendDatabaseClicked();

    /**
     * @brief btnImportClicked Emits a signal to open the import data popup.
     */
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
