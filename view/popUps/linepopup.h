#ifndef LINEPOPUP_H
#define LINEPOPUP_H
#include "../navigation/abstractpopupwidget.h"
#include "../textlineedit.h"
#include "../numberlineedit.h"
#include "../textedit.h"
#include "../interfaces/iline.h"

/**
 * @brief The LinePopUp class provides functionality to edit a line with a form
 * displayed in a popup.
 *
 * LinePopUp inherits AbstractPopUpWidget and implements ILine.
 *
 * Pressing confirm button of the popup emits the saveLine() signal to indicate the
 * entered data should be saved.
 *
 * @author Marius Gassen
 */
class LinePopUp : public AbstractPopUpWidget, ILine
{
    Q_OBJECT
    Q_INTERFACES(ILine)
public:
    /**
     * @brief LinePopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit LinePopUp(QWidget *parent = 0);

signals:
    void saveLine(QHash<QString, QVariant> values);

public slots:
    void setLine(QHash<QString, QVariant> values);

private slots:
    void onConfirm();

private:
    int id;
    TextLineEdit *txtBxName;
    NumberLineEdit *numBxWorkplaceCount;
    TextEdit *txtBxDescription;

};

#endif // LINEPOPUP_H
