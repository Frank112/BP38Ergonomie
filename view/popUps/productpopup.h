#ifndef PRODUCTPOPUP_H
#define PRODUCTPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../textlineedit.h"
#include "../numberlineedit.h"
#include "../interfaces/iproduct.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The ProductPopUp class provides functionality to create a new product with a form
 * displayed in a popup.
 *
 * ProductPopUp inherits AbstractPopUpWidget and implements IProduct.
 *
 * Pressing confirm button of the popup emits the saveProduct() signal to indicate the
 * entered data should be saved and a new product is created.
 *
 * @author Marius Gassen
 */
class ProductPopUp : public AbstractPopUpWidget, IProduct
{
    Q_OBJECT
    Q_INTERFACES(IProduct)
public:
    /**
     * @brief ProductPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit ProductPopUp(QWidget *parent = 0);
    ~ProductPopUp();

signals:
    void saveProduct(QHash<QString, QVariant> values);

public slots:
    void setProduct(QHash<QString, QVariant>){}

private slots:
    void onConfirm();
    void onClose();

private:
    TextLineEdit *txtBxName;
    TextLineEdit *txtBxNumber;
    NumberLineEdit *numBxTotalPercentage;

};

#endif // PRODUCTPOPUP_H
