#ifndef PRODUCTVIEW_H
#define PRODUCTVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHash>
#include <QList>
#include <QScrollArea>
#include "../numberlineedit.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/iproductlist.h"

/**
 * @brief The ProductView class provides functionality to display and document product data.
 *
 * ProductView inherits SimpleNavigateableWidget and implements IProductList.
 *
 * @author Frank Loeffler
 */
class ProductView : public SimpleNavigateableWidget, IProductList
{
    Q_OBJECT
    Q_INTERFACES(IProductList)
public:
    /**
     * @brief ProductView Creates a new ProductView object with the given parent.
     * @param parent The parent of the object.
     */
    explicit ProductView(QWidget *parent = 0);
    ~ProductView();

signals:
    void createProduct(QHash<QString, QVariant> values);
    void deleteProduct(int id);

public slots:
    void addProduct(QHash<QString, QVariant> values);
    void updateProduct(QHash<QString, QVariant> values);
    void removeProduct(int id);
    void clearProducts();

private slots:
    void btnAddClicked();

private:
    const QList<QStringList> productItemScheme = QList<QStringList>() << (QStringList() << tr("product number")) << (QStringList()<< tr("total percentage"));

    QScrollArea *scProducts;
    QLabel *lblAddProduct;
    QLabel *lblName;
    QLabel *lblNumber;
    QLabel *lblTotalPercentage;

    TextLineEdit *txtBxName;
    TextLineEdit *txtBxNumber;
    NumberLineEdit *numBxTotalPercentage;

    QPushButton *btnAdd;

    QVBoxLayout *productListLayout;
};

#endif // PRODUCTVIEW_H
