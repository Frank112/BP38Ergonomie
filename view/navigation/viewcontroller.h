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
#include <QVBoxLayout>
#include "../separator.h"
#include "../../standardpaths.h"
#include "../../settings.h"
#include "../../control/controller.h"
#include "../generalViews/mainmenu.h"
#include "../generalViews/metadataview.h"
#include "../generalViews/errorlogview.h"
#include "../workplaceView/activityview.h"
#include "../workplaceView/commentview.h"
#include "../workplaceView/lineview.h"
#include "../workplaceView/workplacelistview.h"
#include "../workplaceView/workplaceview.h"
#include "../documentationView/documentationview.h"
#include "../generalViews/analystselectionview.h"
#include "../timerView/ganttimerview.h"
#include "../rotationGroupView/shiftview.h"
#include "../rotationGroupView/shiftcalendar.h"
#include "../rotationGroupView/rotationgrouptaskview.h"
#include "../rotationGroupView/rotationgrouptasklistview.h"
#include "../ressourceManagementView/equipmentview.h"
#include "../ressourceManagementView/transportationview.h"
#include "../ressourceManagementView/productview.h"
#include "../ressourceManagementView/ressourcemanagementview.h"
#include "../ressourceManagementView/bodymeasurementview.h"
#include "../ressourceManagementView/employeeview.h"
#include "../ressourceManagementView/employeelistview.h"
#include "../generalViews/settingsview.h"
#include "../popUps/equipmentpopup.h"
#include "../popUps/transporationpopup.h"
#include "../popUps/senddatabasepopup.h"
#include "../popUps/analystpopup.h"
#include "../popUps/createproductpopup.h"
#include "../popUps/activitypopup.h"
#include "../popUps/languagepopup.h"
#include "../popUps/themepopup.h"
#include "../popUps/workplacepopup.h"
#include "../popUps/importdatapopup.h"
#include "../interfaces/iftpconnections.h"
#include "../popUps/resetpopup.h"
#include "../popUps/employeepopup.h"
#include "../popUps/factorysettingspopup.h"
#include "../popUps/linepopup.h"
#include "../popUps/camerapopup.h"
#include "../documentationView/appliedforceview.h"
#include "../documentationView/loadhandlingview.h"
#include "../documentationView/executionconditionview.h"
#include "../documentationView/workprocessmetadataview.h"
#include "../documentationView/bodyPostureView/bodypostureview.h"

class ViewController : public NotificationWidget
{
    Q_OBJECT
public:
    explicit ViewController(QWidget *parent = 0);
    ~ViewController();

    void showStartView(ViewType type);

    void registerView(NavigateableWidget *widget, ViewType type);

    void registerPopUp(AbstractPopUpWidget *popUp, PopUpType type);

    void showView(ViewType type, QList<ViewType> *prevTypes = 0);

public slots:
    void closePopUp();

private slots:
    void btnBackClicked();
    void btnForwardClicked();

    void goToView(ViewType type, QList<ViewType> *prevTypes = 0);
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

    AnalystSelectionView *analystSelectionView;
    MainMenu *mainMenuView;
    MetaDataView *metaDataView;
    WorkplaceListView *workplaceListView;
    WorkplaceView *workplaceView;
    LineView *lineView;
    ActivityView *activityView;
    CommentView *commentView;
    RessourceManagementView *ressourceManagementView;
    ProductView *productView;
    EquipmentView *equipmentView;
    TransportationView *transportationView;
    EmployeeView *employeeView;
    EmployeeListView *employeeListView;
    BodyMeasurementView *bodyMeasurementView;
    ShiftView *shiftView;
    ShiftCalendar *shiftCalendarView;
    RotationGroupTaskView *rotationGroupTaskView;
    RotationGroupTaskListView *rotationGroupTaskListView;
    SettingsView *settingsView;
    ErrorLogView *errorLogView;

    DocumentationView *documentationView;
    WorkProcessMetaDataView *workProcessMetaDataView;
    AppliedForceView *appliedForceView;
    BodyPostureView *bodyPostureView;
    LoadHandlingView *loadHandlingView;
    ExecutionConditionView *executionConditionView;
    GantTimerView *gantTimerView;

    TimerViewController *timerViewController;

    EquipmentPopUp *equipmentPopUp;
    TransporationPopUp *transportationPopUp;
    SendDatabasePopUp *sendDatabasePopUp;
    AnalystPopUp *analystPopUp;
    CreateProductPopUp *createProductPopUp;
    ActivityPopUp *activityPopUp;
    LanguagePopUp *languagePopUp;
    ThemePopUp *themePopUp;
    WorkplacePopUp *workplacePopUp;
    ImportDataPopUp *importDataPopUp;
    ResetPopUp *resetPopUp;
    EmployeePopUp *employeePopUp;
    FactorySettingsPopUp *factorySettingsPopUp;
    LinePopUp *linePopUp;
    CameraPopUp *cameraPopUp;


    void adaptNavigationBar(ViewType type);
};

#endif // VIEWCONTROLLER_H
