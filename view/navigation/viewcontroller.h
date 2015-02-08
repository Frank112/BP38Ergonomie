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

signals:
    void update(ViewType type);
    void save(ViewType type);

public slots:

private slots:
    void btnBackClicked();
    void btnForwardClicked();
    void goToView(ViewType type);
    void backToView(ViewType type);

    void showPopUp(PopUpType type);
    void closePopUp();

    void btnFeedbackClicked();
private:
    QStackedWidget *content;
    QStack<ViewType> *previousViews;
    QHash<ViewType, int> *viewTypeToIndex;
    QHash<ViewType, NavigateableWidget*> *viewTypeToWidget;
    QHash<PopUpType, AbstractPopUpWidget*> *popUpTypeToWidget;
    PopUpType currentPopUp;

    QPushButton *btnBack;
    QPushButton *btnForward;
    QPushButton *btnFeedback;
    QLabel *lblBackTitle;
    QLabel *lblForwardTitle;
    QLabel *lblTitle;
    QWidget *internalNavigation;
    QList<QAbstractButton*> *additionalNavigation;
    QHBoxLayout *middleNavigationLayout;
    QHBoxLayout *additionalNavigationLayout;


    void adaptNavigationBar(ViewType type);
};

#endif // VIEWCONTROLLER_H
