#ifndef TEXTCONTROL_H
#define TEXTCONTROL_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "selectablevaluebutton.h"
#include "textlineedit.h"

/**
 * @brief The TextControl class provides functionality for single selection between multiple texts.
 * Although to show icons to illustrade the text values and differences between the shown text and
 * the value of text that is shown in the text line above.
 *
 * @author Frank Loeffler
 *
 */
class TextControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief TextControl Creates a new object with the given <i>parent</i>
     * @param parent The parent object of the new object
     */
    explicit TextControl(QWidget *parent = 0);
    ~TextControl();

    /**
     * @brief setValues Sets the values of the control
     * @param showText Indicates whether the text values should be shown on the buttons
     * @param btnTexts The predefinied texts for the buttons, there will be shown as many buttons as the length of the vector
     * @param btnTextValues The predefinied text values for a button, if a button gets selected this is the text that will be shown in the QLineEdit
     * @param iconSetPath The path to the icons, the names of the icons have to be the texts in btnTexts and the filetype png
     */
    void setValues(bool showText, const QVector<QString> &btnTexts, const QVector<QString> &btnTextValues, const QString &iconSetPath);

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
     * @brief getTextValue Returns the selected text value of the control
     * @return The current selected text value of the control, iff nothing is selected
     * the empty string.
     */
    QString getTextValue() const;

signals:
    /**
     * @brief valueChanged Signals that the selected text value of the control has changed.
     * @param text The current selected text value of the control
     */
    void valueChanged(const QString &text);

public slots:
    /**
     * @brief setValue Sets the selected value of the text control on the given text.
     *
     * <b>Note:</b> The given text has to be equal with the text value you want to select.
     * @param text The text value to be selected, iff the text value does not exsits than nothing is selected.
     */
    void setValue(const QString &text);

private slots:
    void btnTextHasClicked(int id);

private:
    QVector<QString> btnTextValues;
    int currentSelectedBtnID;

    TextLineEdit *txtBxValue;
    QLabel *lblText;
    QVector<SelectableValueButton*> *btnList;
    QHBoxLayout *btnLineLayout;

};

#endif // TEXTCONTROL_H
