#ifndef THEMEPOPUP_H
#define THEMEPOPUP_H

#include <QList>
#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"
#include "../navigation/abstractpopupwidget.h"
#include "../detailedlistitem.h"

class ThemePopUp : public AbstractPopUpWidget
{
    Q_OBJECT
public:
    explicit ThemePopUp(QWidget *parent = 0);
    ~ThemePopUp();

signals:
    void themeChanged();
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
