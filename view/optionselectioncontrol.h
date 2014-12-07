#ifndef OPTIONSELECTIONCONTROL_H
#define OPTIONSELECTIONCONTROL_H

#include <QWidget>
#include <QHBoxLayout>
#include "selectablevaluebutton.h"

class OptionSelectionControl : public QWidget
{
    Q_OBJECT
public:
    explicit OptionSelectionControl(QVector<QString*> *options, QWidget *parent = 0);

    QString getSelectedValue();
    int getSelectedID();

signals:
    void selectionChanged(int id);

public slots:
    void setSelectedValue(int id);

private:
    int currentSelectedBtnID;

    QVector<SelectableValueButton*> *btnOptions;
    QHBoxLayout *mainLayout;

};

#endif // OPTIONSELECTIONCONTROL_H
