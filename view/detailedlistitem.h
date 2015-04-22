#ifndef DETAILEDLISTITEM_H
#define DETAILEDLISTITEM_H

#include <QAbstractButton>
#include <QGridLayout>
#include <QPushButton>
#include <QList>
#include <QCheckBox>
#include <QLabel>
#include <QIcon>

/**
 * @brief The DetailedListItem class provides functionality for objects serving as list items. A list item can contain a new,
 * an icon, different rows and columns with entries, a delete, add, edit and forward button as well as a checkbox.
 * The item itself can be clicked as well.
 *
 */
class DetailedListItem : public QAbstractButton
{
    Q_OBJECT
public:

    /**
     * @brief DetailedListItem Creates a new DetailedListItem object with elements depending on the parameters.
     * @param parent The parent widget.
     * @param objectName The object name of the icon in the stylesheet. The Icon shows the icon specified in the stylesheet.
     * @param name The name of the item. Will be displayed in the top line.
     * @param scheme The scheme of row and column entries. Each list entry is a new row, each stringlist contains the captions for one row.
     * @param isDeletable True, iff the item should have a delete button.
     * @param isCheckable True, iff the item should have a checkbox.
     * @param hasForwardButton True, iff the item should have a forward button.
     * @param canBeAdded True, iff the item should have an add button.
     * @param isEditable True, iff the item souhld have an edit button.
     */
    explicit DetailedListItem(QWidget *parent = 0, const QString &objectName = "btnIcon", const QString &name = "", const QList<QStringList> &scheme = QList<QStringList>(), bool isDeletable = false, bool isCheckable = false, bool hasForwardButton = false, bool canBeAdded = false, bool isEditable = false);

    /**
     * @brief getID The ID of the list item.
     * @return The item's ID.
     */
    int getID() const;

    /**
     * @brief setID Sets the ID to a new ID.
     * @param id The ID to set.
     */
    void setID(int id);

    /**
     * @brief getName Returns the displayed name of the item.
     * @return The name.
     */
    QString getName() const;

    /**
     * @brief isSelected Returns true, if the item is currently marked as selected.
     * @return True, iff the item is selected.
     */
    bool isSelected();

signals:
    /**
     * @brief A signal that is emitted, when the item's delete button is pressed.
     * @param id The item's ID.
     */
    void deleteItem(int id);

    /**
     * @brief addItem A signal that is emitted, when the item's add button is pressed.
     * @param id The item's ID.
     */
    void addItem(int id);

    /**
     * @brief editItem A signal that is emitted, when the item's edit button is pressed.
     * @param id The item's ID.
     */
    void editItem(int id);

    /**
     * @brief pressed A signal that is emitted, when the item itself is pressed.
     * @param id The item's ID.
     */
    void pressed(int id);

    /**
     * @brief selected A signal that is emitted, when the item's checkbox is checked.
     * @param id The item's ID.
     */
    void selected(int id);

    /**
     * @brief deselected A signal that is emitted, when the item's checkbox is unchecked.
     * @param id The item's ID.
     */
    void deselected(int id);

public slots:

    /**
     * @brief setValues Sets the values to the given ones. Each list entry of the list contains the entries
     * for one row. The list scheme has to match the item's scheme.
     * @param values The text values to set on the item.
     */
    void setValues(const QList<QStringList> &values);

    /**
     * @brief setName Sets the name of the item to the given text.
     * @param name The name to set on the item.
     */
    void setName(const QString &name);

    /**
     * @brief changeSelection Deselectes the item, iff it's not selected and vice versa.
     */
    void changeSelection();

    /**
     * @brief select Selects the item, iff its ID matches the given one.
     * @param id The ID to match for selecting.
     */
    void select(int id);

    /**
     * @brief selectExclusiveWithID Selects the item, iff the ID matches the given one,
     * deselects the item otherwise.
     * @param id The ID to match for selecting.
     */
    void selectExclusiveWithID(int id);

    /**
     * @brief deselect Deselects the item, iff the ID matches the given one.
     * @param id The ID to match for deselecting.
     */
    void deselect(int id);

    /**
     * @brief select Selects the item, iff it is not already selected.
     */
    void select();

    /**
     * @brief deselect Deselects the item, iff it is not already selected.
     */
    void deselect();

private slots:
    void itemPressed();
    void deleteItem();
    void addItem();
    void editItem();

protected:
    void paintEvent(QPaintEvent*);

private:
    int id;

    bool isCheckable;

    QGridLayout *layout;
    QPushButton *lblIcon;
    QIcon icon;
    QLabel *lblName;
    QPushButton *btnDelete;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QCheckBox *checkBox;
    QPushButton *btnForward;

    QList<QList<QLabel*>> listLblValues;
};

#endif // DETAILEDLISTITEM_H
