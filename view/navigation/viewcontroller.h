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
#include "../timerView/gantttimerview.h"
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
#include "../documentationView/appliedforceview.h"
#include "../documentationView/loadhandlingview.h"
#include "../documentationView/executionconditionview.h"
#include "../documentationView/workprocessmetadataview.h"
#include "../documentationView/bodyPostureView/bodypostureview.h"

/**
 * @brief The ViewController class provides functionality to manage the display of all views and popups.
 *
 * The ViewController inherits the NotificationWidget to be able to display elements on different layers, such as
 * views, popups and messages.
 *
 * The ViewController is the central element for interconnecting the various views, popups and the controller
 * using the <a href="http://doc.qt.io/qt-5/signalsandslots.html">Qt SIGNAL and SLOT</a> system. It is responsible
 * for the logically correct navigation between views. It holds a stack of <span>Types::ViewType</span>s, to which a type is pushed on,
 * whenever the corresponding view is being <i>forwarded to</i>. Additionally the topmost type is popped from the stack when the corresponding
 * view is left and the <i>previous</i> view is shown again. This behavior occurs iff the Types::ViewType returned by
 * NavigateableWidget::getBackViewType() or NavigateableWidget::getForwardViewType() equals Types::ViewType::UNKNOWN.
 * Otherwise, iff NavigateableWidget::getBackViewType() returns an explicit type, the stack is popped until the desired view is found.
 * If neither is the case, the view is not changed.
 *
 * Whenever a view is changed, the NavigateableWidget::onLeaving() slot of the old view and the NavigateableWidget::onEnter() slot
 * of the new view are called.
 *
 * The ViewController holds <i>exactly one</i> instance of every view and popup.
 *
 * <b>Note:</b> All views and popups have to be registered with registerView(NavigateableWidget *widget, Types::ViewType type)
 * and registerPopUp(AbstractPopUpWidget *popUp, Types::PopUpType type) respectively.
 *
 * @author Frank Loeffler
 */
class ViewController : public NotificationWidget
{
    Q_OBJECT
public:

    /**
     * @brief ViewController Constructs a widget with a <i>parent</i>.
     * @param parent The <i>parent</i> widget of the abstract widget.
     */
    explicit ViewController(QWidget *parent = 0);
    ~ViewController();

    /**
     * @brief showStartView A method that is called to display the provided view. The Types::ViewType of this view
     * is pushed onto the stack, the content is set to this widget and the navigation bar adapted to the view's
     * @param type
     */
    void showStartView(Types::ViewType type);

    /**
     * @brief registerView
     * @param widget
     * @param type
     */
    void registerView(NavigateableWidget *widget, Types::ViewType type);

    /**
     * @brief registerPopUp
     * @param popUp
     * @param type
     */
    void registerPopUp(AbstractPopUpWidget *popUp, Types::PopUpType type);

    /**
     * @brief showView
     * @param type
     * @param prevTypes
     */
    void showView(Types::ViewType type, QList<Types::ViewType> *prevTypes = 0);

public slots:
    /**
     * @brief closePopUp
     */
    void closePopUp();

private slots:
    void btnBackClicked();
    void btnForwardClicked();

    void goToView(Types::ViewType type, QList<Types::ViewType> *prevTypes = 0);

    void backToView(Types::ViewType type);

    void showPopUp(Types::PopUpType type);

private:
    QStackedWidget *content;
    QStack<Types::ViewType> *previousViews;
    QHash<Types::ViewType, int> *viewTypeToIndex;
    QHash<Types::ViewType, NavigateableWidget*> *viewTypeToWidget;
    QHash<Types::PopUpType, AbstractPopUpWidget*> *popUpTypeToWidget;
    Types::PopUpType currentPopUp;

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
    GanttTimerView *ganttTimerView;

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


    void adaptNavigationBar(Types::ViewType type);
};

#endif // VIEWCONTROLLER_H
