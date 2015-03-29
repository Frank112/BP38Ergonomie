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
 * Furthermore a constantly visible navigation bar, containing the current view's navigation options, is displayed to get
 * input for the actual navigation.
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
     * @brief showStartView Displays the view with the given Types::ViewType. This type is pushed onto the stack views,
     * the content is set to this widget, the type is pushed onto the stack of seen widgets and the navigation bar is
     * adapted based on the views navigation.
     *
     * @param type The type of the view to be shown.
     *
     * <b>Note:</b> The view has to be registered with registerView(NavigateableWidget *widget, Types::ViewType type);
     *
     * @see NavigateableWidget::getBackViewType()
     * @see NavigateableWidget::getForwardViewType()
     * @see NavigateableWidget::getAdditionalNavigation()
     * @see NavigateableWidget::getInternalNavigation()
     *
     */
    void showStartView(Types::ViewType type);

    /**
     * @brief registerView Registers a NavigateableWidget with a corresponding Types::ViewType at the ViewController.
     *
     * This means in particular the view is inserted into a <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> that
     * matches the view's Types::ViewType with it's index in a <a href="http://doc.qt.io/qt-4.8/qstackedwidget.html">QStackedWidget</a>.
     *
     * Furthermore the view is inserted into a <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> that matches the
     * view's Types::ViewType with the actual NavigateableWidget.
     *
     * The <span>NavigateableWidget</span>'s signals NavigateableWidget::showView(Types::ViewType), NavigateableWidget::showPopUp(Types::PopUpType)
     * and NavigateableWidget::showMessage(const QString &message, NotificationMessage::MessageType msgType, NotificationMessage::MessageDisplayType msgDisplayType)
     * are connected to the <span>ViewController</span>'s slots to process those signals.
     *
     * <b>Note:</b> If the widget has already been registered or is 0, it is <i>not</i> registered as described above.
     *
     * @param widget The view to be registered.
     * @param type The corresponding type to be registered with the view.
     */
    void registerView(NavigateableWidget *widget, Types::ViewType type);

    /**
     * @brief registerPopUp Registers a AbstractPopUpWidget with a corresponding Types::PopUpType at the ViewController.
     *
     * This means in particular the popup is inserted into a <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> that
     * matches the view's Types::ViewType with the actual AbstractPopUpWidget.
     *
     * <b>Note:</b> The popup is initially hidden, as it has only been registered.
     *
     * The <span>AbstractPopUpWidget</span>'s signals AbstractPopUpWidget::closePopUp(), and
     * AbstractPopUpWidget::showMessage(const QString &message, NotificationMessage::MessageType msgType, NotificationMessage::MessageDisplayType msgDisplayType)
     * are connected to the <span>ViewController</span>'s slots to process those signals.
     *
     * @param popUp The popup to be registered.
     * @param type The corresponding type to be registered with the popup.
     */
    void registerPopUp(AbstractPopUpWidget *popUp, Types::PopUpType type);

    /**
     * @brief showView Displays the view with the given Types::ViewType. The View Types::ViewType specified in
     * <i>prevTypes</i> are pushed onto the stack of seen widgets, to simulate a navigation through those widgets, iff
     * the provided list does not equal 0.
     *
     * The </span>ViewController</span>'scontent is set to this widget, the type itself is pushed onto the stack of seen widgets and the navigation bar is
     * adapted based on the views navigation.
     *
     * The previous view's TitledWidget::onLeaving() slot is called, as well as the new view's TitledWidget::onEnter() slot.
     *
     * @param type The type of the widget to display.
     * @param prevTypes A list of types that should be simulated as shown beforehand.
     */
    void showView(Types::ViewType type, QList<Types::ViewType> *prevTypes = 0);

public slots:
    /**
     * @brief closePopUp Hides the currently shown popup.
     *
     * @see NotificationWidget::closePopUp()
     */
    void closePopUp();

private slots:
    void btnBackClicked();
    void btnForwardClicked();

    /**
     * @brief goToView test est est
     * @param type
     * @param prevTypes
     */
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
