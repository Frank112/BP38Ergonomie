#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <QtPlugin>

class IProduct {

public slots:

    /**
     * @brief setProduct Sets the product to be displayed specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void setProduct(QHash<QString, QVariant> values) = 0;

signals:

    /**
     * @brief saveProduct A signal that can be emitted to signal that a product with the given <i>values</i> should be saved.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    virtual void saveProduct(QHash<QString, QVariant> values) = 0;
};

#define IProduct_iid "IProduct"
Q_DECLARE_INTERFACE(IProduct, IProduct_iid)

#endif // IPRODUCT_H
