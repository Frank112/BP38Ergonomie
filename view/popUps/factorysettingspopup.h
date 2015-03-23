#ifndef FACTORYSETTINGSPOPUP_H
#define FACTORYSETTINGSPOPUP_H

#include "../navigation/abstractpopupwidget.h"

class FactorySettingsPopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    explicit FactorySettingsPopUp(QWidget *parent = 0);
    ~FactorySettingsPopUp();

private slots:
    void onConfirm();
};

#endif // FACTORYSETTINGSPOPUP_H
