#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QStackedWidget>
#include "notificationwidget.h"
#include "navigateablewidget.h"
#include "abstractpopupwidget.h"
#include <QStack>
#include <QHash>
#include <QSet>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class ViewController : public NotificationWidget
{
    Q_OBJECT
public:
    explicit ViewController(QWidget *parent = 0);
    ~ViewController();

    void showStartView(ViewType type);

    void registerView(NavigateableWidget *widget, ViewType type);

    void registerPopUp(AbstractPopUpWidget *popUp, PopUpType type);

    void showView(ViewType type, const QList<ViewType> *prevTypes = 0);

public slots:
    void closePopUp();

private slots:
    void btnBackClicked();
    void btnForwardClicked();
    void goToView(ViewType type, const QList<ViewType> *prevTypes = 0);
    void backToView(ViewType type);

    void showPopUp(PopUpType type);

private:
    QStackedWidget *content;
    QStack<ViewType> *previousViews;
    QHash<ViewType, int> *viewTypeToIndex;
    QHash<ViewType, NavigateableWidget*> *viewTypeToWidget;
    QHash<PopUpType, AbstractPopUpWidget*> *popUpTypeToWidget;
    PopUpType currentPopUp;

    QPushButton *btnBack;
    QPushButton *btnForward;
    QLabel *lblBackTitle;
    QLabel *lblForwardTitle;
    QLabel *lblTitle;
    QWidget *internalNavigation;
    QList<QAbstractButton*> *additionalNavigation;
    QHBoxLayout *middleNavigationLayout;
    QHBoxLayout *additionalNavigationLayout;
    QSpacerItem *leftSpacer;
    QSpacerItem *rightSpacer;


    void adaptNavigationBar(ViewType type);
};

#endif // VIEWCONTROLLER_H
