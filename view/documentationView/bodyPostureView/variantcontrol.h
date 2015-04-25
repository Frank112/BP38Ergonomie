#ifndef VARIANTCONTROL_H
#define VARIANTCONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../../selectablevaluebutton.h"
#include "../../valuecontrol.h"
#include "variantspecification.h"

/**
 * @brief The VariantControl class represents different variants with
 * one or more subvariants with a ValueControl where the actual value of
 * the control gets setted.
 *
 * Example: Trunk (VariantControl) with Tilt (Variant) and
 * 1 Value Control for the trunk tilt (Subvariant)
 *
 */
class VariantControl : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates a new VariantControl with no Variant entries and
     * no name.
     *
     * @param parent
     *          The parent widget of this new object.
     */
    explicit VariantControl(QWidget *parent = 0);
    ~VariantControl();

    /**
     * @brief Adds a new variant with the given name to the control.
     *
     * @param name
     *          The name of the variant
     * @return
     *          The identifier of the new created variant (unique).
     */
    int addVariant(const QString &name);

    /**
     * @brief Adds a new sub variant with the given ValueControl to
     * the variant with the given identifier.
     *
     * @param variantID
     *          The identifier of the variant to add the sub variant.
     * @param vc
     *          The reference to the ValueControl object of the sub variant.
     * @return
     *          The identifier of the new sub variant (unique with the corresponding id)
     */
    int addSubVariant(int variantID, ValueControl *vc);

    /**
     * @brief Sets the VariantSpecification of the variant control if needed.
     *
     * @param varSpeci
     *          The reference to the VariantSpecification object.
     */
    void setSpecification(VariantSpecification *varSpeci);

    /**
     * @brief setSelectedSpecification
     * @param type
     */
    void setSelectedSpecification(AVType type);


    /**
     * @brief Returns the name of this control
     *
     * @return
     *          The name of the control
     */
    QString getName() const;

    /**
     * @brief Returns the setted value of the ValueControl with the
     * given sub varaint identifier in the variant with the given variant
     * identifier.
     *
     * @param variantID
     *          The identifier of the variant.
     * @param subVariantID
     *          The identifier of the subvariant in the variant
     * @return
     *          The value for the given sub variant in the given variant or
     *          0 iff the sub variant or variant does not exsist.
     */
    int getValue(int variantID, int subVariantID) const;

signals:
    /**
     * @brief Is emitted iff a variant specification is set and indicates that
     * the value with the given specification identifier has changed to the given
     * value in the currently shown variant.
     *
     * @param type
     *          The specification identifier which is currently selected.
     * @param value
     *          The new value of the ValueControl.
     */
    void valueChanged(int type, const QVariant &value);

    /**
     * @brief Is emitted indicates when the value of the currently
     * shown variant has changed to the given value.
     *
     * @param value
     *          The new value of the ValueControl.
     */
    void valueChanged(const QVariant &value);

    /**
     * @brief Is emitted when the content of the variant with the given
     * name should be selected and shown.
     *
     * @param name
     *          The name of the variant.
     */
    void requestShowContent(const QString &name);

public slots:
    /**
     * @brief Hides the current content of the variant control except the
     * label with the name of the control.
     */
    void hideContent();

    /**
     * @brief Shows the whole content of the control.
     */
    void showContent();

    /**
     * @brief Sets the displayed name of this control to the given name.
     *
     * @param name
     *          The name of the control.
     */
    void setName(const QString &name);

    /**
     * @brief Sets a IconButton as the control representation instead of
     * showing the name of the control.
     *
     * @param objectName
     *          The object name of the IconButton.
     * @param size
     *          The size of the IconButton.
     */
    void setButtonIcon(const QString &objectName, const QSize &size);

    /**
     * @brief Sets the variant with the given identifier as the selected variant.
     * If there is no match with the given identifier nothing happens.
     *
     * @param variantID
     *          The identifier of the variant to select.
     */
    void setSelectedVariant(int variantID);

    /**
     * @brief If the control name matches the given name than this
     * control show his content, otherwise it hides his content.
     *
     * @see showContent()
     * @see hideContent()
     *
     * @param name
     *          The name of the control that should be shown.
     */
    void setExclusiveDisplayByName(const QString &name);

private slots:
    void btnVariantClicked(int id);
    void vcValueChanged(const QVariant &value);
    void btnNameClicked();
private:
    QString name;
    QVBoxLayout *variantsLayout;
    QVBoxLayout *valueControlLayout;
    QWidget *mainContent;

    QPushButton *btnName;

    VariantSpecification *varSpeci;
    bool hasSpeci;

    SelectableValueButton *svBtnCurrentSel;
    QVector<QVector<ValueControl*>*> *valueControls;
    QVector<SelectableValueButton*> *variantBtns;

    bool shown;
};

#endif // VARIANTCONTROL_H
