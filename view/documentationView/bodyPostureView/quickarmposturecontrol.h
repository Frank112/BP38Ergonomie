#ifndef QUICKARMPOSTURECONTROL_H
#define QUICKARMPOSTURECONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QVariant>
#include "selectablevaluebutton.h"
#include <QString>

/**
 * @brief The QuickArmPostureControl class provides functionality to quickly change arm positions, for each arm individually.
 * It does this by implementing a Vertical set of Buttons.
 *
 * @author Johannes Pfannmueller
 */
class QuickArmPostureControl : public QWidget
{ Q_OBJECT
public:
    /**
     * @brief QuickArmPostureControl Creates a new QuickArmPostureControl.
     * @param parent Parent widget which holds the QuickArmPostureControl or if 0 then a standalone window.
     */
    explicit QuickArmPostureControl(QWidget *parent=0);
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
     * @brief getSelectedSpecification Retruns the current selected Specification ID of the Arm Specification as an Integer.
     * @return the current selected Specification ID of the Arm Specification as an Integer.
     */
    int getSelectedSpecification() const;

signals:
    /**
     * @brief selectionChanged indicates that a Selection has Changed by providing the id of the newly selected Button and the id
     *  of the selected specification
     * @param id the id of the newly selected Button
     * @param sel the id of the specification
     */
    void selectionChanged(int id, int sel);
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
     * @param differ The String Values displayed on the Buttons do differentiate between left and right.
     * @param labelThe String Value which functions as a Headline for the Control.
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


#endif // QUICKARMPOSTURECONTROL_H
