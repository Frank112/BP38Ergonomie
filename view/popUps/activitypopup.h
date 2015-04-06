#ifndef ACTIVITYPOPUP_H
#define ACTIVITYPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include "../textlineedit.h"
#include "../numberlineedit.h"
#include "../interfaces/iproductlist.h"
#include "../interfaces/iactivity.h"
#include "../../databaseHandler/dbconstants.h"


/**
 * @brief The ActivityPopUp class provides functionality to edit an activity with a form
 * displayed in a popup.
 *
 * ActivityPopUp inherits AbstractPopUpWidget and implements IProductList and IActivity.
 *
 * Pressing confirm button of the popup emits the saveActivity() signal to indicate the
 * entered data should be saved.
 *
 * @author Marius Gassen
 */
class ActivityPopUp : public AbstractPopUpWidget, IProductList, IActivity
{
    Q_OBJECT
    Q_INTERFACES(IProductList)
    Q_INTERFACES(IActivity)
public:
    /**
     * @brief ActivityPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit ActivityPopUp(QWidget *parent = 0);
    ~ActivityPopUp();

signals:
    void saveActivity(QHash<QString, QVariant> values);

    void createProduct(QHash<QString, QVariant> values);
    void deleteProduct(int id);
    void selectedProduct(int id);

public slots:
    void setActivity(QHash<QString, QVariant> values);

    void addProduct(QHash<QString, QVariant> values);
    void updateProduct(QHash<QString, QVariant> values);
    void removeProduct(int id);
    void clearProducts();

private slots:
    void selectedProductChanged(int id);
    void deselectedProduct(int id);

    void onConfirm();
    void onClose();

private:
    const QList<QStringList> productItemScheme = QList<QStringList>() << (QStringList() << tr("product number"));

    int id;
    int selectedProductID;

    QVBoxLayout *productListLayout;
    QWidget *productListContent;
    QScrollArea *scProducts;

    QLabel *lblActivityDescription;
    QLabel *lblActivityRepetitions;
    QLabel *lblChooseProduct;
    TextLineEdit *txtBxActivityDescription;
    NumberLineEdit *numBxActivityRepetitions;

};

#endif // ACTIVITYPOPUP_H
