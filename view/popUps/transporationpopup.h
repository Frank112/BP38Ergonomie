#ifndef TRANSPORATIONPOPUP_H
#define TRANSPORATIONPOPUP_H

#include "../navigation/abstractpopupwidget.h"
#include "../numberlineedit.h"
#include "../optionselectioncontrol.h"
#include "../interfaces/itransportation.h"

/**
 * @brief The TransporationPopUp class provides functionality to create a new transportation with a form
 * displayed in a popup.
 *
 * TransportationPopUp inherits AbstractPopUpWidget and implements ITransportation.
 *
 * Pressing confirm button of the popup emits the saveTransportation() signal to indicate the
 * entered data should be saved and a new transportation is created.
 *
 * @author Frank Loeffler
 */
class TransporationPopUp : public AbstractPopUpWidget, ITransportation
{
    Q_OBJECT
    Q_INTERFACES(ITransportation)
public:
    /**
     * @brief TransporationPopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit TransporationPopUp(QWidget *parent = 0);
    ~TransporationPopUp();

signals:
    void saveTransportation(QHash<QString, QVariant> values);

public slots:
    void setTransportation(QHash<QString, QVariant>){}

private slots:
    void onConfirm();
    void onClose();

private:
    TextLineEdit *txtBxName;
    NumberLineEdit *numBxWeight;
    NumberLineEdit *numBxMaxLoad;
    OptionSelectionControl *oscFixedRoller;
    OptionSelectionControl *oscBrakes;

    const QStringList YES_NO_TEXTS = QStringList()<<tr("yes")<<tr("no");
    const QVector<QVariant> YES_NO_VALUE = QVector<QVariant>()<<true<<false;
};

#endif // TRANSPORATIONPOPUP_H
