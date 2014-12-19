#include "variantcon.h"
#include <QLabel>

VariantCon::VariantCon(QWidget *parent) :
    QWidget(parent)
{
    this->currentSelBtnID = 0;

    mainLayout = new QVBoxLayout;
    varLayout = new QVBoxLayout;
    varSpeciLayout = new QVBoxLayout;

    mainLayout->addLayout(varLayout);
    mainLayout->addSpacerItem(new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    mainLayout->addLayout(varSpeciLayout);
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    variantBtns = new QVector<SelectableValueButton*>();
    varSpeciBtns = new QVector<SelectableValueButton*>();
    variants = new QVector<Variant*>();

    currentSelVarSpeciBtnID = 0;
    this->setLayout(mainLayout);
}


void VariantCon::variantBtnPressed(int id){
    variantBtns->at(id)->setSelected(true);
    if(currentSelBtnID != id)
        variantBtns->at(currentSelBtnID)->setSelected(false);
    this->currentSelBtnID = id;
    emit selectedVariantChanged(id);
}

void VariantCon::variantSpeciBtnPressed(int id){
    varSpeciBtns->at(id)->setSelected(true);
    if(currentSelVarSpeciBtnID != id)
        varSpeciBtns->at(currentSelVarSpeciBtnID)->setSelected(false);
    currentSelVarSpeciBtnID = id;
}

void VariantCon::setVariantSpecification(VariantSpecification* varSpeci){
    if(varSpeci != NULL){
        this->varSpeci = varSpeci;
        QVector<QString*>* vs = varSpeci->getSpecificationDesc();
        for(int i = 0; i < vs->size(); i++){
            SelectableValueButton *newBtn = new SelectableValueButton(i,0, this);
            newBtn->setMinimumSize(150, 40);
            newBtn->setText((* vs->at(i)));
            connect(newBtn, SIGNAL(clickedWithID(int)), this, SLOT(variantSpeciBtnPressed(int)));
            varSpeciBtns->append(newBtn);
            varSpeciLayout->addWidget(newBtn, 0, Qt::AlignTop);
        }
        variantSpeciBtnPressed(0);
    }
}


void VariantCon::addVariant(Variant* variant){
    variants->append(variant);
    SelectableValueButton *newBtn = new SelectableValueButton(variantBtns->length(), 0, this);
    newBtn->setMinimumSize(150, 40);
    newBtn->setText((*variant->getDescription()));
    connect(newBtn, SIGNAL(clickedWithID(int)), this, SLOT(variantBtnPressed(int)));
    variantBtns->append(newBtn);
    varLayout->addWidget(newBtn, 0, Qt::AlignTop);
    variantBtnPressed(0);
}

Variant* VariantCon::getVariantByID(int id) const{
    if(id > -1 && id < variants->length())
        return variants->at(id);
    return NULL;
}

void VariantCon::selectID(int id){
    variantBtnPressed(id);
}

void VariantCon::selectSpecification(int id){
    variantSpeciBtnPressed(id);
}
