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
     * @brief showMessage A signal that is emitted to indicate that a NotificationMessage should be shown.
     * @param message The message requested to be displayed.
     * @param msgType The message type of the message to be displayed.
     * @param msgDisplayType The message display type of the message to be displayed.
     */
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::ACCEPT, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

    /**
     * @brief showView A signal that is emitted to indicate that the view with the Types::ViewType::ViewType <i>type</i> should be shown
     * @param view The view type of the widget that is requested to be shown.
     * @param previousViews The list of view types representing the previous Views of the now to be shown view.
     */
    void showView(Types::ViewType view, QList<Types::ViewType> *previousViews = 0);

    /**
     * @brief clearAll A signal that is emitted to indicate that all exisiting entries should be deleted.
     */
    void clearAll();

    //Analyst
    /**
     * @brief clearAnalysts A signal that is emitted to indicate that all existing analysts should be deleted.
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
     * @brief updatedAnalyst A signal that is emitted to indicate that the analyst identified in <i>values</i>
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief removedAnalyst A signal that is emitted to indicate that the analyst with <i>id</> should be removed.
     * @param id The id of the analyst to be removed.
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
     * @brief selectedCorperation A signal that is emitted to indicate that the Corporation was selected in the
     * Controller with the data in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedCorperation(QHash<QString, QVariant> values);

    //Factory
    /**
     * @brief selectedFactory A signal that is emitted to indicate that the Factory was selected in the Controller
     * with the data in in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedFactory(QHash<QString, QVariant> values);

    //Recording
    /**
     * @brief selectedRecording A signal that is emitted to indicate that the Recording was selected in the Controller
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
     * @param id The id of the workplace to be removed.
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
     * @param id The id of the line to be removed
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
     * @param id The id of the employee to be removed.
     */
    void removedEmployee(int id);

    //EmployeeSelectList
    /**
     * @brief employeeSelected A signal that is emitted to indicate that the employee identified in <i>values</i> should
     * be selected.
     * @param id The id of the employee to be selected.
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
     * @param id The id of the product to be removed.
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
     * @param id The id of the activity to be removed.
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
     * @brief clearEquipments A signal that is emitted to indicate that all existing equipments should be deleted.
     */
    void clearEquipments();

    /**
     * @brief createdEquipment A signal that is emitted to indicate that a new equipment should be created as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdEquipment(QHash<QString, QVariant> values);

    /**
     * @brief updatedEquipment A signal that is emitted to indicate that the equipment identified in <i>values
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedEquipment(QHash<QString, QVariant> values);

    /**
     * @brief removedEquipment A signal that is emitted to indicate that the activity with <i>id</i> should be removed.
     * @param id The id of the equipment to be removed.
     */
    void removedEquipment(int id);

    //Transportation
    /**
     * @brief clearTransportations A signal that is emitted to indicate that all existing equipments should be deleted.
     */
    void clearTransportations();

    /**
     * @brief createdTransportation A signal that is emitted to indicate that a new transportation should be created as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdTransportation(QHash<QString, QVariant> values);

    /**
     * @brief updatedTransportation A signal that is emitted to indicate that the transportation identified in <i>values
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedTransportation(QHash<QString, QVariant> values);

    /**
     * @brief removedTransportation A signal that is emitted to indicate that the transportation with <i>id</i> should be removed.
     * @param id The id of the transportation to be removed.
     */
    void removedTransportation(int id);

    //LoadHandling
    /**
     * @brief setLoadHandling A signal that is emitted to indicate that the load handling should be set as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    /**
     * @brief setBodyPosture A signal that is emitted to indicate that the body posture should be set as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    /**
     * @brief setAppliedForce A signal that is emitted to indicate that the applied force should be set as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    /**
     * @brief setWorkProcess A signal that is emitted to indicate that the work process should be set as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    /**
     * @brief setExecutionCondition A signal that is emitted to indicate that the execution condition should be set as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    /**
     * @brief createdWorkProcess A signal that is emitted to indicate that a work process should be created as
     * specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedWorkProcess A signal that is emitted to indicate that the work process specified in <i>values</i>
     * should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setSelectedWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setHasPreviousWorkProcess A signal that is emitted to indicate if the currently selected
     * workprocess has a previous work process or not.
     * @param hasPrevious true, iff the work process should have a previous process, false otherwise.
     */
    void setHasPreviousWorkProcess(bool hasPrevious);

    /**
     * @brief setHasNextWorkProcess A signal that is emitted to indicate if the currently selected
     * workprocess has a next work process or not.
     * @param hasNext true, iff the work process should have a next process, false otherwise.
     */
    void setHasNextWorkProcess(bool hasNext);

    /**
     * @brief setSelectedWorkProcessType A signal that is emitted to indicate the AVType of the currently
     * selected work process.
     * @param type The type the workprocess should be set to.
     */
    void setSelectedWorkProcessType(AVType type);

    /**
     * @brief initiliazedWorkProcesses A signal that is emitted to initialize the work process with a
     * <a href="http://doc.qt.io/qt-5/qlist.html">QList</a> of <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a>.
     * Each element of the list represents a work process.
     * @param values A list of hashmaps of values with each the column name and the corresponding value to this column.
     */
    void initiliazedWorkProcesses(QList<QHash<QString, QVariant>> values);

    //Shift
    /**
     * @brief selectedShift A signal that is emitted to indicate that the shift identified in <i>values</i>
     * should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedShift(QHash<QString, QVariant> values);

    //RotationGroup
    /**
     * @brief clearRotationGroup A signal that is emitted to indicate that all existing rotation groups should be deleted.
     */
    void clearRotationGroup();

    /**
     * @brief addRotationGroupEntry A signal that is emitted to indicate that a rotation group entry should be added.
     *
     * <b>Note:</b> The Rotation group task name and its duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupEntry A signal that is emitted to indicate that the rotation group entry identified in <i>values
     * should be updated.
     *
     * <b>Note:</b> The Rotation group task name and its duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief addRotationGroupBreakEntry A signal that is emitted to indicate that a new rotation group break entry
     * should be added.
     *
     * <b>Note:</b> The break's duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupBreakEntry(QHash<QString, QVariant> values);

    //RotationGroupTask
    /**
     * @brief clearRotationGroupTasks A signal that is emitted to indicate that all existing rotation group tasks should
     * be deleted.
     */
    void clearRotationGroupTasks();

    /**
     * @brief createdRotationGroupTask A signal that is emitted to indicate that a new rotation group task should
     * be created as specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTask A signal that is emitted to indicate that the rotation group task identified in <i>values</i>
     * should be updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTask A signal that is emitted to indicate that the rotation group task with <i>id</i>
     * should be removed.
     * @param id The id of the rotation group task to be removed.
     */
    void removedRotationGroupTask(int id);

    /**
     * @brief selectedRotationGroupTask A signal that is emitted to indicate that the rotation group identified in <i>values</i>
     * should be selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTaskDuration A signal that is emitted to indicate that the currently selected rotation
     * group task should be updated with the provided <i>duration</i>.
     * @param duration The duration the rotatoin group task should be updated to.
     */
    void updatedRotationGroupTaskDuration(int duration);

    //RotationGroupTaskEntry
    /**
     * @brief clearRotationGroupTaskEntries A signal that is emitted to indicate that all existing rotation group task
     * entries should be deleted.
     */
    void clearRotationGroupTaskEntries();

    /**
     * @brief createdRotationGroupTaskEntry A signal that is emitted to indicate that a new rotation group task entry
     * should be created as specified in <i>values</i>.
     *
     * <b>Note:</b> The work place name is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTaskEntry A signal that is emitted to indicate that the rotation group task entry with
     * <i>id</id> should be removed.
     * @param id The id of the rotation group task entry to be removed.
     */
    void removedRotationGroupTaskEntry(int id);

public slots:
    //Analyst
    /**
     * @brief initializeAnalysts Initialize all existing analysts from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeAnalysts();

    /**
     * @brief createAnalyst Creates a new analyst with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR. An analyst might still be created.
     */
    void createAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief deleteAnalyst Deletes the analayst with <i>id</i> from the database.
     * @param id The id of the analyst to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteAnalyst(int id);

    /**
     * @brief selectAnalyst Selects the analyst with <i>id</i> in the database.
     * @param id The id of the analyst to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectAnalyst(int id);

    //MainMenuView
    /**
     * @brief createBlankRecording Creates a new autogenerated recording in the database and simulates the normal
     * behaviour of creating a recording in the views.
     *
     * An autogenerated workplace and activity are created.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createBlankRecording();

    //BranchOfIndustry
    /**
     * @brief setBranchOfIndustry Sets the branch of industry values with <i>id</i> from the database.
     * @param id The id of the branch of industry to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setBranchOfIndustry(int id);

    /**
     * @brief saveBranchOfIndustry Saves the branch of industry entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBranchOfIndustry(QHash<QString, QVariant> values);

    //Corperation
    /**
     * @brief setCorperation Sets the corporation with <i>id</i> from the database.
     * @param id The id of the corporatoin to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setCorperation(int id);

    /**
     * @brief saveCorperation Saves the corporation entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveCorperation(QHash<QString, QVariant> values);

    //Factory
    /**
     * @brief setFactory Sets the factory with <i>id</i> from the database.
     * @param id The id of the factory to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setFactory(int id);

    /**
     * @brief saveFactory Saves the factory entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveFactory(QHash<QString, QVariant> values);

    //Recording
    /**
     * @brief setRecording Sets the recording with <i>id</i> from the database.
     * @param id The id of the recording to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setRecording(int id);

    /**
     * @brief saveRecording Saves the recoring entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveRecording(QHash<QString, QVariant> values);

    //Workplace
    /**
     * @brief initializeWorkplaces Initializes all existing workplaces from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeWorkplaces();

    /**
     * @brief createWorkplace Creates a new workplace with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief createWorkplace Creates a new workplace with the entries given in <i>values</i> and the activities given in
     * <i>activityValues</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     * @param activityValues A list of hashmaps of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues);

    /**
     * @brief deleteWorkplace Deletes the workplace with <i>id</i> from the database.
     * @param id The id of the workplace to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteWorkplace(int id);

    /**
     * @brief selectWorkplace Selects the workplace with <i>id</i> in the database.
     * @param id The id of the workplace to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectWorkplace(int id);

    /**
     * @brief saveWorkplace Saves the workplace entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkplace(QHash<QString, QVariant> values);

    //Comment
    /**
     * @brief saveComment Saves the comment entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveComment(QHash<QString, QVariant> values);

    //Line
    /**
     * @brief initializeLines Initializes all existing lines from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeLines();

    /**
     * @brief createLine Creates a new line with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createLine(QHash<QString, QVariant> values);

    /**
     * @brief editLine Edits the Line with the given <i>id</i>.
     * @param id The id of the line to be edited.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void editLine(int id);

    /**
     * @brief saveLine Saves the line entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveLine(QHash<QString, QVariant> values);

    /**
     * @brief deleteLine Deletes the line with the <i>id</i> from the database.
     * @param id The id of the line to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteLine(int id);

    /**
     * @brief selectLine Selects the line with the <i>id</i> in the database.
     * @param id The id of the Line to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectLine(int id);

    //Product
    /**
     * @brief initializeProducts Initializes all existing products from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeProducts();

    /**
     * @brief createProduct Creates a new product with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createProduct(QHash<QString, QVariant> values);

    /**
     * @brief saveProduct Saves the product entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveProduct(QHash<QString, QVariant> values);

    /**
     * @brief deleteProduct Deletes the product with the <i>id</i> from the database.
     * @param id The id of the product to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteProduct(int id);

    //Activity
    /**
     * @brief initializeActivities Initializes all existing activities from the database belonging to the workplace
     * with <i>workplace_ID</i>.
     * @param workplace_ID The id of the workplace, whose activites are initialized.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeActivities(int workplace_ID);

    /**
     * @brief createActivity Creates a new activity with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createActivity(QHash<QString, QVariant> values);

    /**
     * @brief saveActivity Saves the activity entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveActivity(QHash<QString, QVariant> values);

    /**
     * @brief deleteActivity Deletes the activity with <i>id</i> from the database. If showMsg is true, a message
     * indicating the deletion should be shown.
     * @param id The id of the activity to be deleted.
     * @param showMsg Indicates whether a message indicating the deletion of the activity should be shown.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteActivity(int id, bool showMsg = true);

    /**
     * @brief selectActivity Selects the activity with <i>id</i> in the database.
     * @param id The id of the activity to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectActivity(int id);

    /**
     * @brief editActivity Edits the activity with <i>id</i> in the database.
     * @param id The id of the activity to be edited.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void editActivity(int id);

    //Equipment
    /**
     * @brief initializeEquipments Initializes all existing equipments from the database
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeEquipments();

    /**
     * @brief createEquipment Creates a new equipment with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createEquipment(QHash<QString, QVariant> values);

    /**
     * @brief saveEquipment Save the equipment entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveEquipment(QHash<QString, QVariant> values);

    /**
     * @brief deleteEquipment Deletes the equipment with <i>id</i> from the database.
     * @param id The id of the equipment to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteEquipment(int id);

    //Transportation
    /**
     * @brief initializeTansportations Initializes all exising transporations from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeTansportations();

    /**
     * @brief createTransportation Creates a new transportation with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createTransportation(QHash<QString, QVariant> values);

    /**
     * @brief saveTransportation Saves the transportation entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveTransportation(QHash<QString, QVariant> values);

    /**
     * @brief deleteTransportation Deletes the transportation with <i>id</i> from the database.
     * @param id The id of the transportation to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteTransportation(int id);

    //LoadHandling
    /**
     * @brief saveLoadHandling Saves the load handling entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    /**
     * @brief saveBodyPosture Saves the body posture entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    /**
     * @brief saveAppliedForce Saves the applied force entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    /**
     * @brief saveWorkProcess Saves the work process entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    /**
     * @brief saveExecutionCondition Saves the execution condition entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    /**
     * @brief initilizeWorkProcesses Initializes all existing work processes from the database and selects the first basic
     * work process if selectFirst is true. Otherwise no work process is selected.
     * @param selectFirst Indicates whether the first basic work process should be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initilizeWorkProcesses(bool selectFirst = true);

    /**
     * @brief createWorkprocess Creates a new workplace with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkprocess(QHash<QString, QVariant> values);

    /**
     * @brief createWorkprocessList
     * @param workplaceName
     * @param activityName
     * @param workprocesses
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocesses);

    /**
     * @brief selectNextWorkProcess Selects the workprocess with the current workprocess id +1 and the current workprocess
     * type.
     */
    void selectNextWorkProcess();

    /**
     * @brief selectPreviousWorkProcess Selects the workprocess with the current workprocess id -1 and the current workProcess
     * type
     */
    void selectPreviousWorkProcess();

    /**
     * @brief workProcessTypeChanged Selects the first workprocess with work process type <i>type</i>.
     * @param type The type of the workprocess to be selected.
     */
    void workProcessTypeChanged(AVType type);

    /**
     * @brief resetWorkProcesses Resets all existing workprocesses in the database.
     */
    void resetWorkProcesses();

    /**
     * @brief workProcessDurationChanged
     * @param time
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void workProcessDurationChanged(QTime time);

    /**
     * @brief selectWorkProcess
     * @param id
     * @param type
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectWorkProcess(int id, AVType type);

    //Gantt
    /**
     * @brief saveWorkProcessFrequence
     * @param frequence
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkProcessFrequence(int frequence);

    //Employee
    /**
     * @brief initializeEmployees Initializes all employees from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeEmployees();

    /**
     * @brief createEmployee Creates a new employee with the entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createEmployee(QHash<QString, QVariant> values);

    /**
     * @brief createEmployee
     * @param values
     * @param bodyMeasurementValues
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues);

    /**
     * @brief deleteEmployee Deletes the employee with <i>id</i> from the database.
     * @param id The id of the employee to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteEmployee(int id);

    /**
     * @brief selectEmployee Selects the employee with <i>id</i> in the database.
     * @param id The id of the employee to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectEmployee(int id);

    /**
     * @brief saveEmployee Saves the employee entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveEmployee(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedEmployee Sets the selectedEmployee_ID to id.
     * @param id The new selectedEmployee id.
     */
    void setSelectedEmployee(int id);

    /**
     * @brief resetEmployeeSelection Emits the selectedEmployee signal with the current selectedEmployee_ID.
     */
    void resetEmployeeSelection();

    //BodyMeasurement
    /**
     * @brief saveBodyMeasurement Saves the body measurement entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBodyMeasurement(QHash<QString, QVariant> values);

    //Connection
    /**
     * @brief initializeFTPConnections
     * @param widget
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeFTPConnections(IFTPConnections *widget);

    /**
     * @brief createFTPConnection
     * @param widget
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createFTPConnection(IFTPConnections *widget);

    /**
     * @brief editFTPConnection
     * @param widget
     * @param id
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void editFTPConnection(IFTPConnections *widget, int id);

    /**
     * @brief selectFTPConnection
     * @param widget
     * @param id
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectFTPConnection(IFTPConnections *widget, int id);

    //ImportData
    /**
     * @brief importData
     * @param widget
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
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
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
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
     * @brief initializeShift Initializes the shift with <i>id</i> from the database.
     * @param id The id of the shift to be initialized.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeShift(int id);

    /**
     * @brief saveShift
     * @param values
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveShift(QHash<QString, QVariant> values);

    //RotationGroup
    /**
     * @brief initializeRotationGroup
     * @param id
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeRotationGroup(int id);

    /**
     * @brief createRotationGroupEntry
     * @param values
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief createRotationGroupBreakEntry
     * @param values
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupBreakEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupEntry
     * @param order
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteRotationGroupEntry(int order);

    /**
     * @brief moveRotationGroupEntryUp
     * @param order
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void moveRotationGroupEntryUp(int order);

    /**
     * @brief moveRotationGroupEntryDown
     * @param order
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void moveRotationGroupEntryDown(int order);

    //RotationGroupTask
    /**
     * @brief initializeRotationGroupTasks Initializes all existing rotation group tasks from the database.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeRotationGroupTasks();

    /**
     * @brief createRotationGroupTask Creates a new rotation group task with the entries given in <i>values</i>
     * in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupTask Deletes the rotation group task with <i>id</i> from the database.
     * @param id The id of the rotation group task to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteRotationGroupTask(int id);

    /**
     * @brief selectRotationGroupTask Selects the rotation group task with <i>id</i> in the database.
     * @param id The id of the rotation group task to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectRotationGroupTask(int id);

    /**
     * @brief saveRotationGroupTask Saves the rotation group task entries given in <i>values</i> in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveRotationGroupTask(QHash<QString, QVariant> values);

    //RotationGroupTaskEntry
    /**
     * @brief initializeRotationGroupTaskEntries
     * @param id
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void initializeRotationGroupTaskEntries(int id);

    /**
     * @brief createRotationGroupTaskEntry Creates a new rotation group task entry with the entries given in <i>values</i>
     * in the database.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupTaskEntry
     * @param id
     * @param showMsg
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteRotationGroupTaskEntry(int id, bool showMsg = true);

    //Reset
    /**
     * @brief resetDatabaseFactory Resets all entries in the database to their default values.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void resetDatabaseFactory();

    /**
     * @brief resetSelectedEntries Resets the selected entries of <i>widget</i> in the database to their default values.
     * @param widget DatabaseReset widget representing the selected entries.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void resetSelectedEntries(ISelectedDatabaseReset *widget);

    //Theme
    /**
     * @brief changeTheme Sets the stylesheet of the application according to the settings.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
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
