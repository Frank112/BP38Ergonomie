#ifndef ANALYSTPOPUP_H
#define ANALYSTPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../interfaces/ianalyst.h"
#include "../../databaseHandler/dbconstants.h"
#include "../textlineedit.h"

/**
 * @brief The AnalystPopUp class provides functionality to create a new analyst with a form
 * displayed in a popup.
 *
 * AnalystPopUp inherits AbstractPopUpWidget and implements IAnalyst.
 *
 * Pressing confirm button of the popup emits the saveAnalyst() signal to indicate the
 * entered data should be saved and a new analyst is created.
 *
 * @author Markus Danz
 */
class AnalystPopUp : public AbstractPopUpWidget, IAnalyst
{
    Q_OBJECT
    Q_INTERFACES(IAnalyst)
public:
    /**
     * @brief AnalystPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit AnalystPopUp(QWidget *parent = 0);
    ~AnalystPopUp();

signals:
    void saveAnalyst(QHash<QString, QVariant> values);

public slots:
    void onEnter();
    void setAnalyst(QHash<QString, QVariant>){}

private slots:
    void onConfirm();

private:
    TextLineEdit *txtBxAnalystLastName;
    TextLineEdit *txtBxAnalystFirstName;
    TextLineEdit *txtBxAnalystEmployer;
    TextLineEdit *txtBxAnalystExperience;

};

#endif // ANALYSTPOPUP_H
