#include "optionselectioncontrol.h"

OptionSelectionControl::OptionSelectionControl(QVector<QString*> *options, QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QHBoxLayout;
    btnOptions = new QVector<SelectableValueButton*>();

    for(int i=0; i < options->length(); ++i){
        SelectableValueButton *btn = new SelectableValueButton(i, i, this);
        btn->setText((*options->at(i)));
        btnOptions->append(btn);
        mainLayout->addWidget(btn);
        connect(btn, SIGNAL(pressedWithID(int)), this, SLOT(setSelectedValue(int)));
    }
    currentSelectedBtnID = 1;
    this->setLayout(mainLayout);
    setSelectedValue(0);
}

//Public slots
void OptionSelectionControl::setSelectedValue(int id){
    if(currentSelectedBtnID != id){
        btnOptions->at(currentSelectedBtnID)->setSelected(false);
        btnOptions->at(id)->setSelected(true);
        currentSelectedBtnID = id;
        emit selectionChanged(id);
    }
}

//Getter and setter
QString OptionSelectionControl::getSelectedValue(){
    return btnOptions->at(currentSelectedBtnID)->text();
}

int OptionSelectionControl::getSelectedID(){
    return currentSelectedBtnID;
}
