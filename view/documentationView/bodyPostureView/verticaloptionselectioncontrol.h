#ifndef VERTICALOPTIONSELECTIONCONTROL_H
#define VERTICALOPTIONSELECTIONCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QVariant>
#include "selectablevaluebutton.h"
#include <QString>

/**
 * @brief The VerticalOptionSelectionControl class provides functionality to quickly chage between different Bodypostures.
 * It does this by implementing a Vertical set of Buttons.
 *
 * @author Johannes Pfannmueller
 */
class VerticalOptionSelectionControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief VerticalOptionSelectionControl Creates a new VerticalOptionSelectionControl
     * @param parent Parent widget which holds the QuickArmPostureControl or if 0 then a standalone window.
     */
    explicit VerticalOptionSelectionControl(QWidget *parent=0);


    /**
     * @brief getSelectedValue Returns the current selected Value of the control as a QVariant.
     * @return The current selected value as QVariant.
     */
    QVariant getSelectedValue() const;
    /**
     * @brief getSelectedTexts Returns the current selected Value of the control as a String.
     * @return the current selected Value of the cvontrol as a String.
     */
    QString getSelectedTexts() const;
    /**
     * @brief getSelectedID Returns the current selected Button ID of the Control as an Integer.
     * @return the current selected Button ID of the Cotrol as an Integer.
     */
    int getSelectedID() const;

signals:
    void selectionChanged(int id);

public slots:
    /**
     * @brief setSelectedValue selects a Button.
     * @param id the ID of the Button.
     */
    void setSelectedValue(int id);
    /**
     * @brief setValues Creates the Buttons and sets the String Values displayed on them.
     * @param texts The String Values which should be displayed on the Buttons.
     * @param label The String Value which functions as a Headline for the Control.
     */
    void setValues(const QStringList &texts, const QString &label);

private:
    SelectableValueButton *currentSelectedBtn;

    QVector<SelectableValueButton*> btnOptions;
    QVBoxLayout *mainLayout;

    void clear();
    int id;

};

#endif // VERTICALOPTIONSELECTIONCONTROL_H
