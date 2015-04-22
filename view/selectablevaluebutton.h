#ifndef SelectableValueButton_H
#define SelectableValueButton_H

#include <QPushButton>
#include <QWidget>
#include <QVariant>

/**
 * @brief The SelectableValueButton class provides functionality for a button that can be either
 * selected or deselcted and shows differently depending on the selection state.
 */
class SelectableValueButton : public QPushButton
{
    Q_OBJECT
public:

    /**
     * @brief SelectableValueButton Creates a new SelectableValueButton object with the given ID and value.
     * @param id The ID of the button.
     * @param value The value of the button.
     * @param parent The parent widget.
     */
    explicit SelectableValueButton(int id, const QVariant &value, QWidget *parent = 0);

    /**
     * @brief isCheckable A selectable value button is always checkable.
     * @return True, as the button is always checkable.
     */
    bool isCheckable() const {
        return true;
    }

    /**
     * @brief getID Returns the ID of the button.
     * @return The ID of the button,
     */
    int getID() const;

    /**
     * @brief setID Sets the ID of the button to the given one.
     * @param id The new ID.
     */
    void setID(int id);

    /**
     * @brief setSelected Sets the button selected or deselectedd
     * @param isSelected True, iff the button should be set selected.
     */
    void setSelected(bool isSelected);

    /**
     * @brief isSelected Returns true, iff the button is currently selected.
     * @return True, iff the button is selected, false otherwise.
     */
    bool isSelected() const;

    /**
     * @brief getValue Returns the currennt value of the button.
     * @return The value of the button.
     */
    QVariant getValue() const;

    /**
     * @brief setValue Sets the value of the button to the given one.
     * @param value The new value of the button.
     */
    void setValue(const QVariant &value);

signals:
    /**
     * @brief clickedWithID A signal, that is emitted, when the button is clicked.
     * @param id The ID of the clicked button.
     */
    void clickedWithID(int id);

private slots:
    void btnClicked();

private:
    int id;
    QVariant value;
    bool selected;
};

#endif // SelectableValueButton_H
