#ifndef FACTORYSETTINGSPOPUP_H
#define FACTORYSETTINGSPOPUP_H

#include "../navigation/abstractpopupwidget.h"

/**
 * @brief The FactorySettingsPopUp class provides functionality to confirm a factory reset.
 *
 * FactorySettingsPopUp inherits AbstractPopUpWidget.
 *
 * @author Markus Danz
 */
class FactorySettingsPopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    /**
     * @brief FactorySettingsPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit FactorySettingsPopUp(QWidget *parent = 0);
    ~FactorySettingsPopUp();

private slots:
    void onConfirm();
};

#endif // FACTORYSETTINGSPOPUP_H
