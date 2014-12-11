#include "valuecontrol.h"
#include <QGuiApplication>
#include <QVBoxLayout>
#include "numberlineedit.h"
#include "selectablevaluebutton.h"

ValueControl::ValueControl(VariantControl controlType, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *txtEditLineLayout = new QHBoxLayout;
    QWidget* txtEdit = new QWidget(this);
    QHBoxLayout *txtEditLayout = new QHBoxLayout;
    btnLineLayout = new QHBoxLayout;

    this->btnValues = new QVector<SelectableValueButton*>();
    this->btnRanges = new QVector<int>();
    this->unit = QString("");
    this->conType = controlType;

    lblText = new QLabel(this);
    lblText->setText("");
    lblText->setMinimumWidth(300);




    if(controlType == VALUE_CONTROL){
        txtBxValue = new NumberLineEdit(this);
        txtBxValue->setAlignment(Qt::AlignCenter);
        txtBxValue->setFixedSize(100, 40);
        connect(txtBxValue, SIGNAL(editingFinished()), this, SLOT(txtBxValueHasChanged()));

        btnPlus = new QPushButton (this);
        btnPlus->setText("+");
        btnPlus->setFixedSize(txtBxValue->height(), txtBxValue->height());
        connect(btnPlus, SIGNAL(pressed()), this, SLOT(btnPlusClicked()));

        btnMinus = new QPushButton (this);
        btnMinus->setText("-");
        btnMinus->setFixedSize(txtBxValue->height(),txtBxValue->height());
        connect(btnMinus, SIGNAL(pressed()), this, SLOT(btnMinusClicked()));

        txtEditLayout->addWidget(btnMinus);
        txtEditLayout->addWidget(txtBxValue);
        txtEditLayout->addWidget(btnPlus);
        txtEdit->setLayout(txtEditLayout);
    }
    else{
        txtBxValue = new TextLineEdit(this);
        txtBxValue->setAlignment(Qt::AlignCenter);
        txtBxValue->setEnabled(false);
        txtBxValue->setMinimumSize(300, 40);
    }

    txtEditLineLayout->addWidget(lblText, 0, Qt::AlignLeft);
    txtEditLineLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
    if (controlType == VALUE_CONTROL)
        txtEditLineLayout->addWidget(txtEdit, 0, Qt::AlignCenter);
    else
        txtEditLineLayout->addWidget(txtBxValue, 0, Qt::AlignCenter);
    txtEditLineLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding, QSizePolicy::Expanding));
    mainLayout->addLayout(txtEditLineLayout);

    mainLayout->addLayout(btnLineLayout);

    if(controlType == VALUE_CONTROL){
        sldrValue = new QSlider(this);
        sldrValue->setOrientation(Qt::Horizontal);
        sldrValue->setMinimumSize(400, 45);
        sldrValue->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
        connect(sldrValue, SIGNAL(valueChanged(int)), this, SLOT(sldrValueHasChanged()));

        lblMin = new QLabel(this);
        lblMin->setFixedWidth(90);

        lblMax = new QLabel(this);
        lblMax->setFixedWidth(90);

        QHBoxLayout *sldrLineLayout = new QHBoxLayout;
        sldrLineLayout->addWidget(lblMin);
        sldrLineLayout->addWidget(sldrValue);
        sldrLineLayout->addWidget(lblMax);

        mainLayout->addLayout(sldrLineLayout);
    }

    this->setLayout(mainLayout);
    if(controlType == VALUE_CONTROL){
        this->setMinimumSize(600, 200);
        this->setMaximumHeight(250);
    }
    else {
        this->setMinimumSize(600, 150);
        this->setMaximumHeight(200);
    }
}

//Public slots
void ValueControl::setValue(int value){
    sldrValue->setValue(value);
}

//Public functions
void ValueControl::setValues(int min, int max, QVector<int>* btnValues, QString* iconSetPath){
    btnRanges = new QVector<int>();
    btnRanges->append(min);
    for(int i = 0; i < btnValues->length() - 1; ++i)
        btnRanges->append(btnValues->at(i) + (btnValues->at(i+1) - btnValues->at(i))/2);
    btnRanges->append(max+1);


    for(int i = 0; i < this->btnValues->length(); i++){
        btnLineLayout->removeWidget(this->btnValues->at(i));
        delete this->btnValues->at(i);
    }
    this->btnValues->clear();

    for(int i = 0; i < btnValues->length(); i++){
        SelectableValueButton *currentBtn = new SelectableValueButton(i, btnValues->at(i), this);
        currentBtn->setText((QString().number(btnValues->at(i))).append(unit));
        try{
            QString s = (*iconSetPath);
            s.append(QString::number(btnValues->at(i))+".png");
            currentBtn->setIcon(QIcon(s));
            currentBtn->setIconSize(QSize(50,50));
        }catch(...){}
        this->btnValues->append(currentBtn);
        connect(currentBtn, SIGNAL(pressedWithID(int)), this, SLOT(btnValueHasClicked(int)));
        btnLineLayout->addWidget(currentBtn);
        currentBtn->setMinimumSize(50, 60);
    }


    lblMin->setText(QString().number(min));
    lblMax->setText(QString().number(max));
    currentSelectedBtnID = 0;
    sldrValue->setRange(min, max);
    sldrValueHasChanged();
}

void ValueControl::setValues(QVector<QString *> *btnTexts, QVector<QString*> *btnTextValues, QString *iconSetPath){
    this->btnTextValues = btnTextValues;

    for(int i = 0; i < this->btnValues->length(); i++){
        btnLineLayout->removeWidget(this->btnValues->at(i));
        delete this->btnValues->at(i);
    }
    this->btnValues->clear();

    int width = this->width() / btnTexts->length();

    for(int i = 0; i < btnTexts->length(); i++){
        SelectableValueButton *currentBtn = new SelectableValueButton(i, i, this);
        currentBtn->setText((*btnTexts->at(i)));
        try{
            QString s = (*iconSetPath);
            currentBtn->setIcon(QIcon(s.append((*btnTexts->at(i))).append(".png")));
            currentBtn->setIconSize(QSize(50,50));
        }catch(...){}
        this->btnValues->append(currentBtn);
        connect(currentBtn, SIGNAL(pressedWithID(int)), this, SLOT(btnTextHasClicked(int)));
        btnLineLayout->addWidget(currentBtn);
        currentBtn->setMinimumSize(width, 60);
    }
    currentSelectedBtnID = 0;
}


// Private slots
void ValueControl::txtBxValueHasChanged(){
    sldrValue->setValue(txtBxValue->text().toInt());
    sldrValueHasChanged();
}

void ValueControl::sldrValueHasChanged(){
    txtBxValue->setText(QString().number(sldrValue->value()));
    btnHighlight(sldrValue->value());
    emit valueChanged(sldrValue->value());
}

void ValueControl::btnValueHasClicked(int id){
    SelectableValueButton *btn = this->btnValues->at(id);
    btnHighlight(btn->getValue());
    sldrValue->setValue(btn->getValue());
}

void ValueControl::btnTextHasClicked(int id){
    txtBxValue->setText((*btnTextValues->at(id)));
    btnValues->at(currentSelectedBtnID)->setSelected(false);
    btnValues->at(id)->setSelected(true);
    currentSelectedBtnID = id;
}

void ValueControl::btnPlusClicked(){
    sldrValue->setValue(sldrValue->value() + 1);
}

void ValueControl::btnMinusClicked(){
    sldrValue->setValue(sldrValue->value() - 1);
}


// Private functions
void ValueControl::btnHighlight(int value){
    this->btnValues->at(currentSelectedBtnID)->setSelected(false);
    for(int i = 1; i < btnRanges->length(); ++i){
        if(btnRanges->at(i) >= value){
            currentSelectedBtnID = i-1;
            break;
        }
    }
    this->btnValues->at(currentSelectedBtnID)->setSelected(true);

}


// Getter and Setter
void ValueControl::setText(QString text){
    if(unit != "")
        this->lblText->setText(text.append(" [").append(unit).append("]:"));
    else
        this->lblText->setText(text);
}

QString ValueControl::getTextValue() const{
    return txtBxValue->text();
}

int ValueControl::getValue() const{
    if(conType == VALUE_CONTROL)
        return sldrValue->value();
    return 0;
}

QString ValueControl::getText() const{
    return lblText->text();
}

void ValueControl::setTextHint(const QString &text){
    txtBxValue->setPlaceholderText(text);
}

VariantControl ValueControl::getControlType() const{
    return conType;
}

void ValueControl::setUnit(const QString &unit){
    if(unit != NULL)
        this->unit = unit;
}

QString ValueControl::getUnit() const{
    return unit;
}


