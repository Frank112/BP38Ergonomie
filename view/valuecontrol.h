#ifndef ValueControl_H
#define ValueControl_H

#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QVector>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include "selectablevaluebutton.h"
#include "../enum.h"

/**
 * @brief The ValueControl class provides functionality for a integer value selection within given bounds with a slider.
 * Also to have predefinied values with the possiblity to illustraed these values with a icon and the posibility
 * to directly enter a value or to increase/decrease the value directly by 1.
 *
 * @author Frank Loeffler
 *
 */
class ValueControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief ValueControl Creates a new Value Control
     * @param controlType Type of the value Control, remember you can not change the type
     * @param parent Parent widget which holds the value control or if 0 then a standalone window
     */
    explicit ValueControl(QWidget *parent = 0);

    /**
     * @brief setValues Sets the values of the control, is only appliable if the control type is VALUE_CONTROL
     * @param min Minimum value
     * @param max Maximum value
     * @param btnValues The predefinied values for the Buttons, there will be shown as many buttons as the length of the vector
     * @param iconSetPath The path to the icons, the names of the icons have to be the values in btnValues and the filetype png
     */
    void setValues(int min, int max, const QVector<int> &btnValues, const QString &iconSetPath);

    /**
     * @brief setText Sets the description label of the control
     * @param text the text to be set, note that the displayed text is: "text [unit]:" if and only if unit is set otherwise
     * it is: "text:"
     */
    void setText(const QString &text);

    /**
     * @brief getText returns the description text of the control
     * @return the text which was set with setText, not the actually displayed text in the control
     */
    QString getText() const;

    /**
     * @brief setTextHint Sets a text placeholder for the TextLineEdit, note only appliable if control type is TEXT_CONTROL
     * @param text The placeholder text
     */
    void setTextHint(const QString &text);

    /**
     * @brief setUnit The unit that will be displayed in the control description and on the buttons after the value, only appliable if control type is VALUE_CONTROL
     * @param unit the unit of the values
     */
    void setUnit(const QString &unit);

    /**
     * @brief getUnit returns the set unit
     * @return returns the unit if the unit was not set than the emtpy QString
     */
    QString getUnit() const;

    /**
     * @brief getValue Returns the current adjusted value of the control
     * @return The current adjusted value of the control
     */
    int getValue() const;

    /**
     * @brief getTextValue Returns the selected value of the control as a string.
     * @return The current selected value of the control as a string.
     */
    QString getTextValue() const;


signals:
    /**
     * @brief Is emitted when ever the selected value has changed.
     *
     * @param value
     *          The new value.
     */
    void valueChanged(int value);

    /**
     * @brief Is emitted when ever the selected value has changed.
     *
     * @param value
     *          The new value.
     */
    void valueChanged(QVariant value);

public slots:
    /**
     * @brief Sets the value of the control to the given value, iff
     * the value is within the bounds.
     *
     * @param value
     *          The value to set the control to.
     */
    void setValue(int value);

private slots:
    void txtBxValueHasChanged();
    void sldrValueHasChanged();
    void btnValueHasClicked(int id);
    void btnPlusClicked();
    void btnMinusClicked();

private:
    QVector<int> *btnRanges;
    QString unit;
    int currentSelectedBtnID;
    int min;
    int max;

    QLineEdit *txtBxValue;
    QSlider *sldrValue;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QLabel *lblText;
    QLabel *lblMin;
    QLabel *lblMax;
    QVector<SelectableValueButton*> *btnList;
    QHBoxLayout *btnLineLayout;

    void btnHighlight(int value);

};

#endif // ValueControl_H
