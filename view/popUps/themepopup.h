#ifndef THEMEPOPUP_H
#define THEMEPOPUP_H

#include <QList>
#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"

/**
 * @brief The ThemePopUp class provides functionality to choose the theme of the application from a list of themes
 * displayed in a popup.
 *
 * ThemePopUp inherits AbstractPopUpWidget.
 *
 * @author Marius Gassen
 */
class ThemePopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    /**
     * @brief ThemePopUp Creates an AbstractPopUpWidget with a <i>parent</i>
     * @param parent The parent widget of the popup.
     */
    explicit ThemePopUp(QWidget *parent = 0);
    ~ThemePopUp();

signals:
    /**
     * @brief themeChanged A signal to indicate that the selected theme changed.
     */
    void themeChanged();

    /**
     * @brief themeSelected A signal to indicate that the theme with <i>id</i> is selected.
     * @param id The id of the theme selected.
     */
    void themeSelected(int id);

public slots:
    void onEnter();

private slots:
    void selectedThemeChanged(int id);
    void onConfirm();

private:
    DetailedListItem *blue;
    DetailedListItem *green;
    QList<DetailedListItem*> *themes;
};

#endif // THEMEPOPUP_H
