#include "textcontrol.h"
#include <QGridLayout>

TextControl::TextControl(QWidget *parent) : QWidget(parent),
    btnTextValues(QVector<QString>()),
    currentSelectedBtnID(0),
    txtBxValue(new TextLineEdit()),
    lblText(new QLabel()),
    btnList(new QVector<SelectableValueButton*>()),
    btnLineLayout(new QHBoxLayout)
{ 
    txtBxValue->setObjectName("notEditableTextBox");
    txtBxValue->setAlignment(Qt::AlignCenter);
    txtBxValue->setEnabled(false);
    txtBxValue->setMinimumSize(300, 40);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(lblText, 0, 0, 1, 1, Qt::AlignLeft);
    mainLayout->addWidget(txtBxValue, 0, 1, 1, 1, Qt::AlignCenter);
    mainLayout->addLayout(btnLineLayout, 1, 0, 1, 2, 0);

    this->setLayout(mainLayout);
    this->setMinimumSize(600, 150);
    this->setMaximumHeight(200);
}

TextControl::~TextControl()
{

}

//PUBLIC SLOTS
void TextControl::setValue(const QString &text){
    bool found = false;
    for(int i = 0; i < btnTextValues.length(); ++i){
        if(btnTextValues.at(i).compare(text) == 0){
            btnTextHasClicked(i);
            found = true;
            break;
        }
    }
    if(!found){
        txtBxValue->setText("");
        btnList->at(currentSelectedBtnID)->setSelected(false);
    }
}

//PUBLIC METHODS
void TextControl::setValues(bool showText, const QVector<QString> &btnTexts, const QVector<QString> &btnTextValues, const QString &iconSetPath){
    this->btnTextValues = btnTextValues;

    for(int i = 0; i < btnList->length(); i++){
        btnLineLayout->removeWidget(btnList->at(i));
        delete btnList->at(i);
    }
    btnList->clear();

    int width = this->width() / btnTextValues.length();

    for(int i = 0; i < btnTextValues.length(); i++){
        SelectableValueButton *currentBtn = new SelectableValueButton(i, i, this);
        if(showText)
            currentBtn->setText(btnTexts.at(i));
        try{
            QString s = iconSetPath;
            currentBtn->setIcon(QIcon(s.append(btnTextValues.at(i)).append(".png")));
            currentBtn->setIconSize(QSize(50,50));
            currentBtn->setMinimumHeight(60);
        }catch(...){}
        btnList->append(currentBtn);
        connect(currentBtn, SIGNAL(clickedWithID(int)), this, SLOT(btnTextHasClicked(int)));
        btnLineLayout->addWidget(currentBtn);
        currentBtn->setMinimumWidth(width);
    }
    currentSelectedBtnID = 0;
}

//PRIVATE SLOTS
void TextControl::btnTextHasClicked(int id){
    txtBxValue->setText(btnTextValues.at(id));
    btnList->at(currentSelectedBtnID)->setSelected(false);
    btnList->at(id)->setSelected(true);
    if(id != currentSelectedBtnID)
        emit valueChanged(txtBxValue->text());
    currentSelectedBtnID = id;
}

//GETTER / SETTER
QString TextControl::getTextValue() const{
    return txtBxValue->text();
}

QString TextControl::getText() const{
    return lblText->text();
}

void TextControl::setText(const QString &text){
    this->lblText->setText(text);
}

void TextControl::setTextHint(const QString &text){
    txtBxValue->setPlaceholderText(text);
}

