#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QHash>
#include <QApplication>
#include <QDir>
#include "../view/navigation/notificationmessage.h"
#include "../databaseHandler/dbhandler.h"
#include "../xmlHandler/xmlparser.h"
#include "../standardpaths.h"
#include "../enum.h"
#include "../view/interfaces/iimportdata.h"
#include "../view/interfaces/isenddata.h"
#include "../view/interfaces/iselecteddatabasereset.h"
#include "../ftpHandler/ftphandler.h"
#include "../errorreporter.h"
#include "../settings.h"
#include "../view/navigation/viewtype.h"

/**
 * @brief The Controller class provides functionality to manipulate the entities in
 * the database.
 *
 * It provides the information about the coherence of the tables, and thus
 * keeps the data displayed and the data stored in the database in <i>sync</i>.
 *
 * <b>Note:</b>
 *
 * @author Frank Loeffler
 */
class Controller : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Controller Constructs an object with a <i>parent</i>.
     * @param parent The <i>parent</i> of the object.
     * @param app The actual application, the controller is running in.
     *
     * @see <a href="http://doc.qt.io/qt-5/qapplication.html">QApplication</a>
     */
    explicit Controller(QObject *parent = 0, QApplication *app = 0);
    ~Controller();

    /**
     * @brief initialize All data availabe by default is being initialized.
     */
    void initialize();

signals:
    /**
     * @brief showMessage A signal that can be emitted to indicate that a NotificationMessage should be shown.
     * @param message The message requested to be displayed.
     * @param msgType The message type of the message to be displayed.
     * @param msgDisplayType The message display type of the message to be displayed.
     */
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::ACCEPT, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

    /**
     * @brief showView A signal that can be emitted to indicate that the view with the Types::ViewType::ViewType <i>type</i> should be shown
     * @param view The view type of the widget that is requested to be shown.
     * @param previousViews The list of view types representing the previous Views of the now to be shown view.
     */
    void showView(Types::ViewType view, QList<Types::ViewType> *previousViews = 0);

    /**
     * @brief clearAll A signal that can be emitted to indicate that all exisiting entries should be deleted.
     */
    void clearAll();

    //Analyst
    /**
     * @brief clearAnalysts A signal that can be emitted to indicate that all existing analysts should be deleted.
     */
    void clearAnalysts();

    /**
     * @brief createdAnalyst A signal that is emitted to indicate that a new analyst should be created as specified
     * in <i>values</i>.
     *
     * <b>Note:</b> The corporation name is provided with the values.
     *
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief selectedAnalyst A signal that is emitted to indicate that the analyst identified in <i>values</i>
     * should be selected.
     *
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief updatedAnalyst A signal that can be emitted to indicate that the analyst identified in <i>values</i>
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief removedAnalyst A signal that is emitted to indicate that the analyst with <i>id</> should be removed.
     * @param id The id of the analyst that is to be removed.
     */
    void removedAnalyst(int id);

    //Branch of Industry
    /**
     * @brief selectedBranchOfIndustry A signal that is emitted to indicate that the Branch of Industry was selected
     * in the Controller with the data in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedBranchOfIndustry(QHash<QString, QVariant> values);

    //Corperation
    /**
     * @brief selectedCorperation A signal that can be emitted to indicate that the Corporation was selected in the
     * Controller with the data in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedCorperation(QHash<QString, QVariant> values);

    //Factory
    /**
     * @brief selectedFactory A signal that can be emitted to indicate that the Factory was selected in the Controller
     * with the data in in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedFactory(QHash<QString, QVariant> values);

    //Recording
    /**
     * @brief selectedRecording A signal that can be emitted to indicate that the Recording was selected in the Controller
     * with the data in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedRecording(QHash<QString, QVariant> values);

    //Workplace
    /**
     * @brief clearWorkplaces A signal that is emitted to indicate that all existing workplaces should be deleted.
     */
    void clearWorkplaces();

    /**
     * @brief createdWorkplace A signal that is emitted to indicate that a new workplace should be created as
     * specified in <i>values</i>
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief selectedWorkplace A signal that is emitted to indicate that the workplace identified by <i>values</i>
     * should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief updatedWorkplace A signal that is emitted to indicate that the workplaces identified in <i>values</i>
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief removedWorkplace A signal that is emitted to indicate that the workplace with <i>id</i> should be removed
     * @param id The id of the workplace that is to be removed.
     */
    void removedWorkplace(int id);

    //Workplace comment
    /**
     * @brief selectedComment A signal that is emitted to indicate that the comment identified in <i>values</i>
     * should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedComment(QHash<QString, QVariant> values);

    /**
     * @brief updatedComment A signal that is emitted to indicate that the comment identified in <i>values</i>
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedComment(QHash<QString, QVariant> values);

    //Line
    /**
     * @brief createdLine A signal that is emitted to indicate that a new line should be created as specified in
     * <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdLine(QHash<QString, QVariant> values);

    /**
     * @brief updatedLine A signal that is emitted to indicate that the line identified in <i>values</i>
     * should be updated
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedLine(QHash<QString, QVariant> values);

    /**
     * @brief editLine A signal that is emitted to indictate that the line identified in <i>values</i>
     * should be edited.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void editLine(QHash<QString, QVariant> values);

    /**
     * @brief removedLine A signal that is emitted to indicate that the line with <i>id</i> should be removed
     * @param id The id of the line that is to be removed
     */
    void removedLine(int id);

    /**
     * @brief selectedLine A signal that is emitted to indicate that the line identified in <i>values</i> should be
     * selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedLine(QHash<QString, QVariant> values);

    /**
     * @brief clearLines A signal that is emitted to indicate that all exisiting lines should be deleted.
     */
    void clearLines();

    //Employee
    /**
     * @brief clearEmployees A signal that is emitted to indicate that all exisiting employees should be deleted.
     */
    void clearEmployees();

    /**
     * @brief createdEmployee A signal that is emitted to indicate that a new employee should be created as specified
     * in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdEmployee(QHash<QString, QVariant> values);

    /**
     * @brief selectedEmployee A signal that is emitted to indicate that the employee identified in <i>values</i> should
     * be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedEmployee(QHash<QString, QVariant> values);

    /**
     * @brief updatedEmployee A signal that is emitted to indicate that the employee identified in <i>values</i> should
     * be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedEmployee(QHash<QString, QVariant> values);

    /**
     * @brief removedEmployee A signal that is emitted to indicate that the employee with <i>id</i> should be removed.
     * @param id The id of the employee that is to be removed.
     */
    void removedEmployee(int id);

    //EmployeeSelectList
    /**
     * @brief employeeSelected A signal that is emitted to indicate that the employee identified in <i>values</i> should
     * be selected.
     * @param id The id of the employee that is to be selected.
     */
    void employeeSelected(int id);

    //BodyMeasurement
    /**
     * @brief selectedBodyMeasurement A signal that is emitted to indicate that the body measurment identified in
     * <i>values</i> should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedBodyMeasurement(QHash<QString, QVariant> values);

    //Product
    /**
     * @brief clearProducts A signal that is emitted to indicate that all existing products should be deleted.
     */
    void clearProducts();

    /**
     * @brief createdProduct A signal that is emitted to indicate that a new product should be created as specified
     * in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdProduct(QHash<QString, QVariant> values);

    /**
     * @brief updatedProduct A signal that is emitted to indicate that the product identified in <i>values</i> should
     * be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedProduct(QHash<QString, QVariant> values);

    /**
     * @brief removedProduct A signal that is emitted to indicate that the product with <i>id</i> should be removed.
     * @param id The id of the product that is to be removed.
     */
    void removedProduct(int id);

    //Activity
    /**
     * @brief clearActivities A signal that is emitted to indicate that all exisiting activities should be deleted.
     */
    void clearActivities();

    /**
     * @brief createdActivity A signal that is emitted to indicate that a new activity should be created as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdActivity(QHash<QString, QVariant> values);

    /**
     * @brief updatedActivity A signal that is emitted to indicate that the activity identified in <i>values
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedActivity(QHash<QString, QVariant> values);

    /**
     * @brief removedActivity A signal that is emitted to indicate that the activity with <i>id</i> should be removed.
     * @param id The id of the activity that is to be removed.
     */
    void removedActivity(int id);

    /**
     * @brief editActivity A signal that is emitted to indicate that the activity identified in <i>values</i>
     * should be edited.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void editActivity(QHash<QString, QVariant> values);

    //Equipment
    /**
     * @brief clearEquipments A signal that is emitted
     */
    void clearEquipments();

    /**
     * @brief createdEquipment
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdEquipment(QHash<QString, QVariant> values);

    /**
     * @brief updatedEquipment
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedEquipment(QHash<QString, QVariant> values);

    /**
     * @brief removedEquipment
     * @param id
     */
    void removedEquipment(int id);

    //Transportation
    /**
     * @brief clearTransportations
     */
    void clearTransportations();

    /**
     * @brief createdTransportation
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdTransportation(QHash<QString, QVariant> values);

    /**
     * @brief updatedTransportation
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedTransportation(QHash<QString, QVariant> values);

    /**
     * @brief removedTransportation
     * @param id
     */
    void removedTransportation(int id);

    //LoadHandling
    /**
     * @brief setLoadHandling
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    /**
     * @brief setBodyPosture
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    /**
     * @brief setAppliedForce
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    /**
     * @brief setWorkProcess
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    /**
     * @brief setExecutionCondition
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    /**
     * @brief createdWorkProcess
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedWorkProcess
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setSelectedWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setHasPreviousWorkProcess
     * @param hasPrevious
     */
    void setHasPreviousWorkProcess(bool hasPrevious);

    /**
     * @brief setHasNextWorkProcess
     * @param hasNext
     */
    void setHasNextWorkProcess(bool hasNext);

    /**
     * @brief setSelectedWorkProcessType
     * @param type
     */
    void setSelectedWorkProcessType(AVType type);

    /**
     * @brief initiliazedWorkProcesses
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void initiliazedWorkProcesses(QList<QHash<QString, QVariant>> values);

    /**
     * @brief reselectedWorkProcesses
     */
    void reselectedWorkProcesses();

    //Shift
    /**
     * @brief selectedShift
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedShift(QHash<QString, QVariant> values);

    //RotationGroup
    /**
     * @brief clearRotationGroup A signal that can be emitted to indicate that all existing rotation groups should be deleted
     */
    void clearRotationGroup();

    /**
     * @brief addRotationGroupEntry A signal that can be emitted to indicate that a rotation group entry should be added
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupEntry
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief addRotationGroupBreakEntry A signal that can be emitted to indicate that a new rotation group task break should
     * be added.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupBreakEntry(QHash<QString, QVariant> values);

    //RotationGroupTask
    /**
     * @brief clearRotationGroupTasks A signal that can be emitted to indicate that all existing rotation group tasks should
     * be deleted.
     */
    void clearRotationGroupTasks();

    /**
     * @brief createdRotationGroupTask A signal that can be emitted to indicate that a new rotation group task should be created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTask
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTask A signal that can be emitted to indicate that the rotation group task with <i>id</i>
     * should be removed.
     * @param id The id of the rotation group task that is to be removed
     */
    void removedRotationGroupTask(int id);

    /**
     * @brief selectedRotationGroupTask
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTaskDuration
     * @param duration
     */
    void updatedRotationGroupTaskDuration(int duration);

    //RotationGroupTaskEntry
    /**
     * @brief clearRotationGroupTaskEntries A signal that can be emitted to indicate that all existing rotation group task
     * entries should be deleted
     */
    void clearRotationGroupTaskEntries();

    /**
     * @brief createdRotationGroupTaskEntry A signal that can be emitted to indicate that a new rotation group task entry
     * should be created
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTaskEntry A signal that can be emitted to indicate that the rotation group task entry with
     * <i>id</id> should be removed
     * @param id The id of the rotation group task entry that is to be removed
     */
    void removedRotationGroupTaskEntry(int id);

public slots:
    //Analyst
    /**
     * @brief initializeAnalysts
     */
    void initializeAnalysts();

    /**
     * @brief createAnalyst
     * @param values
     */
    void createAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief deleteAnalyst
     * @param id
     */
    void deleteAnalyst(int id);

    /**
     * @brief selectAnalyst
     * @param id
     */
    void selectAnalyst(int id);

    //MainMenuView
    /**
     * @brief createBlankRecording
     */
    void createBlankRecording();

    //BranchOfIndustry
    /**
     * @brief setBranchOfIndustry
     * @param id
     */
    void setBranchOfIndustry(int id);

    /**
     * @brief saveBranchOfIndustry
     * @param values
     */
    void saveBranchOfIndustry(QHash<QString, QVariant> values);

    //Corperation
    /**
     * @brief setCorperation
     * @param id
     */
    void setCorperation(int id);

    /**
     * @brief saveCorperation
     * @param values
     */
    void saveCorperation(QHash<QString, QVariant> values);

    //Factory
    /**
     * @brief setFactory
     * @param id
     */
    void setFactory(int id);

    /**
     * @brief saveFactory
     * @param values
     */
    void saveFactory(QHash<QString, QVariant> values);

    //Recording
    /**
     * @brief setRecording
     * @param id
     */
    void setRecording(int id);

    /**
     * @brief saveRecording
     * @param values
     */
    void saveRecording(QHash<QString, QVariant> values);

    //Workplace
    /**
     * @brief initializeWorkplaces
     */
    void initializeWorkplaces();

    /**
     * @brief createWorkplace
     * @param values
     */
    void createWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief createWorkplace
     * @param values
     * @param activityValues
     */
    void createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues);

    /**
     * @brief deleteWorkplace
     * @param id
     */
    void deleteWorkplace(int id);

    /**
     * @brief selectWorkplace
     * @param id
     */
    void selectWorkplace(int id);

    /**
     * @brief saveWorkplace
     * @param values
     */
    void saveWorkplace(QHash<QString, QVariant> values);

    //Comment
    /**
     * @brief saveComment
     * @param values
     */
    void saveComment(QHash<QString, QVariant> values);

    //Line
    /**
     * @brief initializeLines
     */
    void initializeLines();

    /**
     * @brief createLine
     * @param values
     */
    void createLine(QHash<QString, QVariant> values);

    /**
     * @brief editLine
     * @param id
     */
    void editLine(int id);

    /**
     * @brief saveLine
     * @param values
     */
    void saveLine(QHash<QString, QVariant> values);

    /**
     * @brief deleteLine
     * @param id
     */
    void deleteLine(int id);

    /**
     * @brief selectLine
     * @param id
     */
    void selectLine(int id);

    //Product
    /**
     * @brief initializeProducts
     */
    void initializeProducts();

    /**
     * @brief createProduct
     * @param values
     */
    void createProduct(QHash<QString, QVariant> values);

    /**
     * @brief saveProduct
     * @param values
     */
    void saveProduct(QHash<QString, QVariant> values);

    /**
     * @brief deleteProduct
     * @param id
     */
    void deleteProduct(int id);

    //Activity
    /**
     * @brief initializeActivities
     * @param workplace_ID
     */
    void initializeActivities(int workplace_ID);

    /**
     * @brief createActivity
     * @param values
     */
    void createActivity(QHash<QString, QVariant> values);

    /**
     * @brief saveActivity
     * @param values
     */
    void saveActivity(QHash<QString, QVariant> values);

    /**
     * @brief deleteActivity
     * @param id
     * @param showMsg
     */
    void deleteActivity(int id, bool showMsg = true);

    /**
     * @brief selectActivity
     * @param id
     */
    void selectActivity(int id);

    /**
     * @brief editActivity
     * @param id
     */
    void editActivity(int id);

    //Equipment
    /**
     * @brief initializeEquipments
     */
    void initializeEquipments();

    /**
     * @brief createEquipment
     * @param values
     */
    void createEquipment(QHash<QString, QVariant> values);

    /**
     * @brief saveEquipment
     * @param values
     */
    void saveEquipment(QHash<QString, QVariant> values);

    /**
     * @brief deleteEquipment
     * @param id
     */
    void deleteEquipment(int id);

    //Transportation
    /**
     * @brief initializeTansportations
     */
    void initializeTansportations();

    /**
     * @brief createTransportation
     * @param values
     */
    void createTransportation(QHash<QString, QVariant> values);

    /**
     * @brief saveTransportation
     * @param values
     */
    void saveTransportation(QHash<QString, QVariant> values);

    /**
     * @brief deleteTransportation
     * @param id
     */
    void deleteTransportation(int id);

    //LoadHandling
    /**
     * @brief saveLoadHandling
     * @param values
     */
    void saveLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    /**
     * @brief saveBodyPosture
     * @param values
     */
    void saveBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    /**
     * @brief saveAppliedForce
     * @param values
     */
    void saveAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    /**
     * @brief saveWorkProcess
     * @param values
     */
    void saveWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    /**
     * @brief saveExecutionCondition
     * @param values
     */
    void saveExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    /**
     * @brief initilizeWorkProcesses
     * @param selectFirst
     */
    void initilizeWorkProcesses(bool selectFirst = true);

    /**
     * @brief createWorkprocess
     * @param values
     */
    void createWorkprocess(QHash<QString, QVariant> values);

    /**
     * @brief createWorkprocessList
     * @param workplaceName
     * @param activityName
     * @param workprocesses
     */
    void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocesses);

    /**
     * @brief selectNextWorkProcess
     */
    void selectNextWorkProcess();

    /**
     * @brief selectPreviousWorkProcess
     */
    void selectPreviousWorkProcess();

    /**
     * @brief workProcessTypeChanged
     * @param type
     */
    void workProcessTypeChanged(AVType type);

    /**
     * @brief resetWorkProcesses
     */
    void resetWorkProcesses();

    /**
     * @brief workProcessDurationChanged
     * @param time
     */
    void workProcessDurationChanged(QTime time);

    /**
     * @brief selectWorkProcess
     * @param id
     * @param type
     */
    void selectWorkProcess(int id, AVType type);

    //Gantt
    /**
     * @brief saveWorkProcessFrequence
     * @param frequence
     */
    void saveWorkProcessFrequence(int frequence);

    //Employee
    /**
     * @brief initializeEmployees
     */
    void initializeEmployees();

    /**
     * @brief createEmployee
     * @param values
     */
    void createEmployee(QHash<QString, QVariant> values);

    /**
     * @brief createEmployee
     * @param values
     * @param bodyMeasurementValues
     */
    void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues);

    /**
     * @brief deleteEmployee
     * @param id
     */
    void deleteEmployee(int id);

    /**
     * @brief selectEmployee
     * @param id
     */
    void selectEmployee(int id);

    /**
     * @brief saveEmployee
     * @param values
     */
    void saveEmployee(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedEmployee
     * @param id
     */
    void setSelectedEmployee(int id);

    /**
     * @brief resetEmployeeSelection
     */
    void resetEmployeeSelection();

    //BodyMeasurement
    /**
     * @brief saveBodyMeasurement
     * @param values
     */
    void saveBodyMeasurement(QHash<QString, QVariant> values);

    //Connection
    /**
     * @brief initializeFTPConnections
     * @param widget
     */
    void initializeFTPConnections(IFTPConnections *widget);

    /**
     * @brief createFTPConnection
     * @param widget
     */
    void createFTPConnection(IFTPConnections *widget);

    /**
     * @brief editFTPConnection
     * @param widget
     * @param id
     */
    void editFTPConnection(IFTPConnections *widget, int id);

    /**
     * @brief selectFTPConnection
     * @param widget
     * @param id
     */
    void selectFTPConnection(IFTPConnections *widget, int id);

    //ImportData
    /**
     * @brief importData
     * @param widget
     */
    void importData(IImportData *widget);

    /**
     * @brief importDataDownloadFinished
     */
    void importDataDownloadFinished(const QString);

    /**
     * @brief importDataDownloadError
     * @param error
     */
    void importDataDownloadError(const QString &error);

    //SendData
    /**
     * @brief sendData
     * @param widget
     */
    void sendData(ISendData *widget);

    /**
     * @brief sendDataUploadStarted
     */
    void sendDataUploadStarted();

    /**
     * @brief sendDataUploadFinished
     * @param filename
     */
    void sendDataUploadFinished(const QString filename);

    /**
     * @brief sendDataUploadError
     * @param error
     */
    void sendDataUploadError(const QString &error);

    //Shift
    /**
     * @brief initializeShift
     * @param id
     */
    void initializeShift(int id);

    /**
     * @brief saveShift
     * @param values
     */
    void saveShift(QHash<QString, QVariant> values);

    //RotationGroup
    /**
     * @brief initializeRotationGroup
     * @param id
     */
    void initializeRotationGroup(int id);

    /**
     * @brief createRotationGroupEntry
     * @param values
     */
    void createRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief createRotationGroupBreakEntry
     * @param values
     */
    void createRotationGroupBreakEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupEntry
     * @param order
     */
    void deleteRotationGroupEntry(int order);

    /**
     * @brief moveRotationGroupEntryUp
     * @param order
     */
    void moveRotationGroupEntryUp(int order);

    /**
     * @brief moveRotationGroupEntryDown
     * @param order
     */
    void moveRotationGroupEntryDown(int order);

    //RotationGroupTask
    /**
     * @brief initializeRotationGroupTasks
     */
    void initializeRotationGroupTasks();

    /**
     * @brief createRotationGroupTask
     * @param values
     */
    void createRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupTask
     * @param id
     */
    void deleteRotationGroupTask(int id);

    /**
     * @brief selectRotationGroupTask
     * @param id
     */
    void selectRotationGroupTask(int id);

    /**
     * @brief saveRotationGroupTask
     * @param values
     */
    void saveRotationGroupTask(QHash<QString, QVariant> values);

    //RotationGroupTaskEntry
    /**
     * @brief initializeRotationGroupTaskEntries
     * @param id
     */
    void initializeRotationGroupTaskEntries(int id);

    /**
     * @brief createRotationGroupTaskEntry
     * @param values
     */
    void createRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupTaskEntry
     * @param id
     * @param showMsg
     */
    void deleteRotationGroupTaskEntry(int id, bool showMsg = true);

    //Reset
    /**
     * @brief resetDatabaseFactory
     */
    void resetDatabaseFactory();

    /**
     * @brief resetSelectedEntries
     * @param widget
     */
    void resetSelectedEntries(ISelectedDatabaseReset *widget);

    //Theme
    /**
     * @brief changeTheme
     */
    void changeTheme();

private:
    QApplication *application;
    DBHandler *dbHandler;

    int analyst_ID;
    int recording_ID;
    int factory_ID;
    int workplace_ID;
    int workcondition_ID;
    int workprocess_ID;
    AVType workprocess_Type;
    int activity_ID;
    int appliedforce_ID;
    int loadhandling_ID;
    int bodyPosture_ID;
    int employee_ID;
    int bodyMeasurement_ID;
    int selectedEmployee_ID;
    int shift_ID;
    int rotationGroup_ID;
    int rotationGroupTask_ID;

    IImportData *importDataWidget;
    IImportDataParser *parser;
    QString downloadDir;
    int countFileDownload;

    void updateRotationGroupTaskDuration();
    QString getWorkplaceNameByID(int id);
    void swapRotationGroupEntries(int order1, int order2);
    void updateRotationGroupEntry(int entry_ID);
    void deleteRotationGroupEntries(int groupTask_ID);

    void saveRecordingObservesLine(int line_ID);
    void deleteRecordingObservesLine(int line_ID);

    void saveRecordingObservesWorkplace(int workplace_ID);
    void deleteRecordingOberservesWorkplace(int workplace_ID);

    void deleteWorkProcesses(int activity_ID);

    QString stringFromResource(const QString &resName);
};

#endif // CONTROLLER_H
