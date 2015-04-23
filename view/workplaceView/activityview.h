#ifndef ACTIVITYVIEW_H
#define ACTIVITYVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include "../textlineedit.h"
#include "../numberlineedit.h"
#include "../navigation/simplenavigateablewidget.h"
#include "../interfaces/iproductlist.h"
#include "../interfaces/iactivitylist.h"

/**
 * @brief The ActivityView class provides functionality to create and delete activities, as well
 * as products. To each activity one product can be assigned.
 */
class ActivityView : public SimpleNavigateableWidget, IProductList, IActivityList
{
    Q_OBJECT
    Q_INTERFACES(IProductList)
    Q_INTERFACES(IActivityList)
public:
    explicit ActivityView(QWidget *parent = 0);

signals:
    void createActivity(QHash<QString, QVariant> values);
    void deleteActivity(int id);
    void editActivity(int id);
    void selectActivity(int id);

    void createProduct(QHash<QString, QVariant> values);
    void deleteProduct(int id);

    /**
     * @brief selectedProduct A signal that is emitted, when a product has been selected.
     * @param id The ID of the selected product.
     */
    void selectedProduct(int id);

public slots:
    void addActivity(QHash<QString, QVariant> values);
    void updateActivity(QHash<QString, QVariant> values);
    void removeActivity(int id);
    void clearActivities();

    void addProduct(QHash<QString, QVariant> values);
    void updateProduct(QHash<QString, QVariant> values);
    void removeProduct(int id);
    void clearProducts();

private slots:
    void btnAddClicked();
    void btnProductsClicked();
    void dliActivityClicked(int id);
    void selectedProductChanged(int id);
    void deselectProduct(int id);

    void editActivityClicked(int id);

private:
    const QList<QStringList> productItemScheme = QList<QStringList>() << (QStringList() << tr("product number"));
    const QList<QStringList> activityItemScheme = QList<QStringList>() << (QStringList() << tr("repetitions"));

    int id;
    int selectedProductID;

    QVBoxLayout *mainLayout;
    QVBoxLayout *productListLayout;
    QVBoxLayout *activityListLayout;

    QWidget *productListContent;
    QWidget *activityListContent;
    QScrollArea *scProducts;
    QScrollArea *scActivities;

    QLabel *lblAddActivity;
    QLabel *lblActivityDescription;
    QLabel *lblActivityRepetitions;
    QLabel *lblChooseProduct;
    TextLineEdit *txtBxActivityDescription;
    NumberLineEdit *numBxActivityRepetitions;
    QPushButton *btnAdd;
    QPushButton *btnMoreProducts;
};

#endif // ACTIVITYVIEW_H
