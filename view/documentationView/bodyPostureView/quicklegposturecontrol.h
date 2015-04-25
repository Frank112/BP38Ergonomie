#ifndef QUICKLEGPOSTURECONTROL_H
#define QUICKLEGPOSTURECONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QVariant>
#include "selectablevaluebutton.h"
#include <QString>

/**
 * @brief The QuickLegPostureControl class provides functionality to quickly change Leg Positions.
 * It does this by implementing a Vertical set of Buttons.
 *
 * @author Johannes Pfannmueller
 */
class QuickLegPostureControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief QuickLegPostureControl Creates a new QuickLegPostureControl.
     * @param parent Parent widget which holds the QuickArmPostureControl or if 0 then a standalone window.
     */
    explicit QuickLegPostureControl(QWidget *parent=0);

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
    /**
     * @brief getSelectedSpecification Retruns the current selected Specification ID of the kneeling Setting.
     * @return the current selected Specification ID of the kneeling Setting as an Integer.
     */
    int getSelectedSpecification() const;

signals:
    /**
     * @brief selectionChanged indicates that a Selection has Changed by providing the id of the newly selected Button and the id
     *  of the selected specification
     * @param id the id of the newly selected Button
     * @param speci the id of the specification
     */
    void selectionChanged(int id, int speci);
    /**
     * @brief specificationChanged indicates that the specification has Changed by providing the id of the newly selected Specification
     * @param id the ID of the specification
     */
    void specificationChanged(int id);

public slots:
    /**
     * @brief setSelectedValue selects a Button.
     * @param id the ID of the Button.
     */
    void setSelectedValue(int id);
    /**
     * @brief setSelectedSpecification sets the Specification for the selected Value.
     * @param id the ID of the Specification Button.
     */
    void setSelectedSpecification(int id);
    /**
     * @brief setValues Creates the Buttons and sets the String Values displayed on them.
     * @param texts The String Values which should be displayed on the Buttons.
     * @param differ The String Values which differentiate between kneeling with the right or left knee or both knees.
     * @param label The String Value which functions as a Headline for the Control.
     */
    void setValues(const QStringList &texts, const QStringList &differ, const QString &label);

private:
    SelectableValueButton *currentSelectedBtn;
    SelectableValueButton *currentSpeciBtn;

    QVector<SelectableValueButton*> btnOptions;
    QVector<SelectableValueButton*> speciOptions;
    QVBoxLayout *mainLayout;

    void clear();

    int id;
    int idSpeci;
    int specification;

};

#endif // QUICKLEGPOSTURECONTROL_H
