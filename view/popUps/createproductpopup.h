#ifndef CREATEPRODUCTPOPUP_H
#define CREATEPRODUCTPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../textlineedit.h"
#include "../numberlineedit.h"
#include "../interfaces/iproduct.h"
#include "../../databaseHandler/dbconstants.h"

/**
 * @brief The CreateProductPopUp class provides functionality to create a new product with a form
 * displayed in a popup.
 *
 * CreateProductPopUp inherits AbstractPopUpWidget and implements IProduct.
 *
 * Pressing confirm button of the popup emits the saveProduct() signal to indicate the
 * entered data should be saved and a new product is created.
 *
 * @author Marius Gassen
 */
class CreateProductPopUp : public AbstractPopUpWidget, IProduct
{
    Q_OBJECT
    Q_INTERFACES(IProduct)
public:
    /**
     * @brief CreateProductPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit CreateProductPopUp(QWidget *parent = 0);
    ~CreateProductPopUp();

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

#endif // CREATEPRODUCTPOPUP_H
