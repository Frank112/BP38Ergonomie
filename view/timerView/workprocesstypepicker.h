#ifndef WORKPROCESSTYPEPICKER_H
#define WORKPROCESSTYPEPICKER_H

#include <QWidget>
#include "../selectablevaluebutton.h"
#include "../../enum.h"

/**
 * @brief The WorkProcessTypePicker class provides functionality to select a workprocess type.
 */
class WorkProcessTypePicker : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief WorkProcessTypePicker Creates a new WorkProcessTypePicker object with the given parent.
     * @param parent The parent of the object.
     */
    explicit WorkProcessTypePicker(QWidget *parent = 0);
    ~WorkProcessTypePicker();

    /**
     * @brief getSelectedType Returns the currently selected workprocess type.
     * @return The currently selected workprocess type.
     */
    AVType getSelectedType() const;

signals:
    /**
     * @brief selectedTypeChanged Can be emitted to signal that the selected type changed.
     * @param type The new selected type.
     */
    void selectedTypeChanged(AVType type);

public slots:
    /**
     * @brief setSelectedType Sets the selected Type to the given type.
     * @param type The type to be set.
     */
    void setSelectedType(AVType type);

private slots:
    void btnAVTypeClicked(int id);

private:
    SelectableValueButton *btnLeft;
    SelectableValueButton *btnRight;
    SelectableValueButton *btnBasic;

    AVType selectedType;

    SelectableValueButton* getBtnByType(AVType type);
    void setSelectedType(AVType type, bool emitSignal);
};

#endif // WORKPROCESSTYPEPICKER_H
