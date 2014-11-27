#ifndef ANGLECONTROL_H
#define ANGLECONTROL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QString>
#include "owncon.h"
#include "variantcon.h"
#include "variant.h"
#include "variantspecification.h"

class AngleControl : public QWidget
{
    Q_OBJECT
public:
    explicit AngleControl(QString* descVarConText, Variant* variant, VariantSpecification* varSpeci, QWidget *parent = 0);
    void addVariant(Variant* variant);
    void selectVariant(int id);

signals:

public slots:

private slots:
    void selectedVariantChanged(int id);


private:
    VariantCon *variantCon;
    QVector<OwnCon*> *ownCons;
    QVector<QWidget*> *ownConSeperator;
    QHBoxLayout *mainLayout;
    QVBoxLayout *subVariantsLayout;

};

#endif // ANGLECONTROL_H
