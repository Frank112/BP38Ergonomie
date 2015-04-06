#ifndef IMPORTDATAPOPUP_H
#define IMPORTDATAPOPUP_H

#include "../view/navigation/abstractpopupwidget.h"
#include "../view/interfaces/iimportdata.h"
#include "../ftpconnectionswidget.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The ImportDataPopUp class provides functionality to import data with a form
 * displayed in a popup.
 *
 * ImportDataPopUp inherits AbstractPopUpWidget and implements IImportData.
 *
 * Pressing confirm button of the popup emits the importData() signal to indicate that the
 * selected data should be imported.
 *
 * @author Frank Loeffler
 */
class ImportDataPopUp : public AbstractPopUpWidget, public IImportData
{
    Q_OBJECT
    Q_INTERFACES(IImportData)
public:
    /**
     * @brief ImportDataPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit ImportDataPopUp(QWidget *parent = 0);
    ~ImportDataPopUp();

    QHash<QString, QVariant> getFTPConnection() const;
    void setFTPConnection(QHash<QString, QVariant> values);

    QString getImportMode() const;
    bool importTransportations() const;
    bool importEquipments() const;
    bool importProducts() const;
    bool importEmployees() const;
    bool importWorkplaces() const;
    bool importWorkprocessLists() const;

signals:
    void initializeFTPConnections(IFTPConnections *widget);
    void createFTPConnection(IFTPConnections *widget);
    void editFTPConnection(IFTPConnections *widget, int id);
    void selectFTPConnection(IFTPConnections *widget, int id);
    void importData(IImportData *widget);

public slots:
    void addFTPConnection(QHash<QString, QVariant> values);
    void selectedFTPConnection(int id);
    void clearFTPConnections();

    void onEnter();

private slots:
    void selectedConnectionChanged(int id);
    void onConfirm();

private:
    FTPConnectionsWidget *ftpConnectionWidget;
    QComboBox *cmbxImportMethod;
    QCheckBox *chBxTransportation;
    QCheckBox *chBxEquipment;
    QCheckBox *chBxProduct;
    QCheckBox *chBxEmployee;
    QCheckBox *chBxWorkplace;
    QCheckBox *chBxWorkProcesses;
};

#endif // IMPORTDATAPOPUP_H
