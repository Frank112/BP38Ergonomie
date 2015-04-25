#ifndef VARIANTSPEZIFIKATION_H
#define VARIANTSPEZIFIKATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include "../../selectablevaluebutton.h"

/**
 * @brief The VariantSpecification class represents a single specification
 * in the VariantControl. This is a futher information like the the value
 * specifices.
 *
 * Example: Left, Right or Both are specifications.
 */
class VariantSpecification : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new VariantSpecification with no
     * entries.
     *
     * @param parent
     *          The parent widget of the new object.
     */
    explicit VariantSpecification(QWidget *parent = 0);

    /**
     * @brief Adds a new specification in the control with the given name and
     * the given unique identifier and optional a value.
     * If this is the first specification added than this is the selected specification.
     *
     * @param name
     *          The name that is shown of the specification
     * @param id
     *          The unique identifier of the specification
     * @param value
     *          The value of the specification (optional)
     */
    void addSpecification(const QString &name, int id, int value = 0);

    /**
     * @brief Returns the value of the specification with the given
     * identifier.
     *
     * @param id
     *          The identifier of the specification.
     * @return
     *          The value of the specification with the given identifier.
     */
    int getValue(int id);

    /**
     * @brief Returns the identifier of the currently selected specification.
     *
     * @return
     *          The identifier of the currently selected specification.
     */
    int getSelectedID() const;

signals:
    /**
     * @brief Is emitted when ever the selected specification changes.
     *
     * @param value
     *          The value of the new selected specification.
     */
    void selectedSpeciValueChanged(int value);

public slots:
    /**
     * @brief Sets the specification with the given identifier as
     * the selected specification.
     * If the identifier does not match any specification nothing happens.
     *
     * @param id
     *          The identifier of the specification that should be selected.
     */
    void setSelected(int id);

private slots:
    void btnSpeciClicked(int id);

private:
    QVBoxLayout *mainContent;
    QVector<SelectableValueButton*> speciBtns;
    SelectableValueButton *selCurBtn;

    SelectableValueButton* getSpeciBtnByID(int id);
};

#endif // VARIANTSPEZIFIKATION_H
