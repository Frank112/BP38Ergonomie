#ifndef OPTIONSELECTIONCONTROL_H
#define OPTIONSELECTIONCONTROL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QStringList>
#include <QVariant>
#include "selectablevaluebutton.h"

/**
 * @brief The OptionSelectionControl class represents a list of options as buttons.
 * Each of these buttons has a string representation, which gets actually showed and
 * a concrete value of the abstract type QVariant as the value of the text representation.
 * Maximum one option/button can be selected at any time.
 *
 * @author Frank Loeffler
 */
class OptionSelectionControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new object with no options to select and no selected value.
     *
     * @param parent
     *          The parent widget of this object.
     */
    explicit OptionSelectionControl(QWidget *parent = 0);

    /**
     * @brief Returns the currently selected value.
     * If nothing is selected this method returns the empty QVariant.
     *
     * @return
     *          The value of the current selected option.
     */
    QVariant getSelectedValue() const;

    /**
     * @brief Returns the currently selected text.
     * If nothing is selected this method returns the empty string.
     *
     * @return
     *          The text of the currently selected option.
     */
    QString getSelectedTexts() const;

    /**
     * @brief Returns the currently selected button id, where each button id
     * is unique.
     * If nothing is selected this method returns -1.
     *
     * @return
     *          The id of the currently selected button/option.
     */
    int getSelectedID() const;

signals:
    /**
     * @brief Is emitted when ever the selection of any option has been
     * changed.
     *
     * @param id
     *          The id of the currently selected button/option.
     */
    void selectionChanged(int id);

public slots:
    /**
     * @brief Sets the option/button with the given id as the selected option.
     * If there are no matches, than nothing changes.
     *
     * @param id
     *         The id of the button/option to select.
     */
    void setSelectedValue(int id);

    /**
     * @brief Sets the option as selected, where the given text equals case sensetive
     * the text of the option, which is shown on the button.
     * If there are multiple matches always the first match gets selected.
     * If there are no matches, than nothing changes.
     *
     * @param text
     *          The text of the option, which should be selected.
     */
    void setSelectedValue(const QString &text);

    /**
     * @brief Sets the option as selected, where the given value equals
     * the value of the option.
     * If there are multiple matches always the first match gets selected.
     * If there are no matches, than nothing changes.
     *
     * @param value
     *          The value of the option, which should be selected.
     */
    void setSelectedByValue(int value);

    /**
     * @brief Sets the options of this control with the given texts and
     * the given values to the text representation.
     *
     * <b>Note :</b> The list of texts and values have to be the same size and
     * the corresponding value to a text has to be at the same position in the list.
     *
     * @param texts
     *          The list of text values
     * @param values
     *          The list of values for the text values.
     */
    void setValues(const QStringList &texts, const QVector<QVariant> &values);

    /**
     * @brief Sets the options of this control with the given text as the text
     * representation of the value and the text as the value of the option.
     *
     * @see setValues(const QStringList &texts, const QVector<QVariant> &values)
     *
     * @param texts
     *          The list of text values.
     */
    void setValues(const QStringList &texts);

private:
    SelectableValueButton *currentSelectedBtn;

    QVector<SelectableValueButton*> btnOptions;
    QHBoxLayout *mainLayout;

    void clear();

};

#endif // OPTIONSELECTIONCONTROL_H
