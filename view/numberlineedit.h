#ifndef NUMBERLINEEDIT_H
#define NUMBERLINEEDIT_H

#include "textlineedit.h"

/**
 * @brief The NumberLineEdit class provides functionality to display and edit numbers.
 */
class NumberLineEdit : public TextLineEdit
{
    Q_OBJECT
public:

    /**
     * @brief NumberLineEdit Creates a new NumberLineEdit with the given parent.
     * @param parent The parent widget.
     */
    explicit NumberLineEdit(QWidget *parent = 0);

    /**
     * @brief getValue Returns the currently displayed value.
     * @return The value currently displayed.
     */
    int getValue() const;

    /**
     * @brief setValue Sets the value to display.
     * @param value The new value
     */
    void setValue(int value);

signals:

public slots:

};

#endif // NUMBERLINEEDIT_H
