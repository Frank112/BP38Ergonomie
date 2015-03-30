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
     * @brief initialize Initializes the controller by syncing it with the database for all values that are available instantly.
     */
    void initialize();

signals:
    /**
     * @brief showMessage A signal that is emitted to indicate that a NotificationMessage has been shown.
     * @param message The message requested to be displayed.
     * @param msgType The message type of the message to be displayed.
     * @param msgDisplayType The message display type of the message to be displayed.
     */
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::ACCEPT, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);

    /**
     * @brief showView A signal that is emitted to indicate that the view with the Types::ViewType <i>type</i> has been shown
     * and a <a href="http://doc.qt.io/qt-5/qlist.html">QList</a> of <span>Types::ViewType</span>s that has been simulated before.
     *
     * <b>Note:</b> The simulation is required if the <i>back</i> semantic should behave, as if the views in the list
     * has been stepped through, even if they were not really displayed <i>before</i>.
     *
     * <b>Note:</b> The previous views are listed in the order of simulation.
     *
     * @param view The view type of the widget that is requested to be shown.
     * @param previousViews The list of view types representing the previous views to be simulated.
     */
    void showView(Types::ViewType view, QList<Types::ViewType> *previousViews = 0);

    /**
     * @brief clearAll A signal that is emitted to indicate that all exisiting entries have been deleted.
     */
    void clearAll();

    /**
     * @brief clearAnalysts A signal that is emitted to indicate that all existing analysts have been deleted.
     */
    void clearAnalysts();

    /**
     * @brief createdAnalyst A signal that is emitted to indicate that a new analyst has been created as specified
     * in <i>values</i>.
     *
     * <b>Note:</b> The corporation name is provided with the values.
     *
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief selectedAnalyst A signal that is emitted to indicate that the analyst specified in <i>values</i>
     * has been selected.
     *
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedAnalyst(QHash<QString, QVariant> values);

    /**
     * @brief removedAnalyst A signal that is emitted to indicate that the analyst with <i>id</> has been removed.
     * @param id The id of the analyst removed.
     */
    void removedAnalyst(int id);

    /**
     * @brief selectedBranchOfIndustry A signal that is emitted to indicate that the Branch of Industry specified in
     * <i>values</i> has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedBranchOfIndustry(QHash<QString, QVariant> values);

    /**
     * @brief selectedCorperation A signal that is emitted to indicate that the Corporation specified in
     * <i>values</i> has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedCorperation(QHash<QString, QVariant> values);

    /**
     * @brief selectedFactory A signal that is emitted to indicate that the Factory specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedFactory(QHash<QString, QVariant> values);

    /**
     * @brief selectedRecording A signal that is emitted to indicate that the recording specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedRecording(QHash<QString, QVariant> values);

    /**
     * @brief clearWorkplaces A signal that is emitted to indicate that all existing workplaces have been deleted.
     */
    void clearWorkplaces();

    /**
     * @brief createdWorkplace A signal that is emitted to indicate that a new workplace has been created as
     * specified in <i>values</i>
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief selectedWorkplace A signal that is emitted to indicate that the workplace specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief updatedWorkplace A signal that is emitted to indicate that the workplaces specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief removedWorkplace A signal that is emitted to indicate that the workplace with <i>id</i> has been removed
     * @param id The id of the workplace removed.
     */
    void removedWorkplace(int id);

    /**
     * @brief selectedComment A signal that is emitted to indicate that the comment specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedComment(QHash<QString, QVariant> values);

    /**
     * @brief updatedComment A signal that is emitted to indicate that the comment specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedComment(QHash<QString, QVariant> values);

    /**
     * @brief createdLine A signal that is emitted to indicate that a new line specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdLine(QHash<QString, QVariant> values);

    /**
     * @brief updatedLine A signal that is emitted to indicate that the line specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedLine(QHash<QString, QVariant> values);

    /**
     * @brief editLine A signal that is emitted to indictate that the line specified in <i>values</i>
     * has been edited.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void editLine(QHash<QString, QVariant> values);

    /**
     * @brief removedLine A signal that is emitted to indicate that the line with <i>id</i> has been removed.
     * @param id The id of the line removed.
     */
    void removedLine(int id);

    /**
     * @brief selectedLine A signal that is emitted to indicate that the line specified in <i>values</i> has been
     * selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedLine(QHash<QString, QVariant> values);

    /**
     * @brief clearLines A signal that is emitted to indicate that all exisiting lines have been deleted.
     */
    void clearLines();

    /**
     * @brief clearEmployees A signal that is emitted to indicate that all exisiting employees have been deleted.
     */
    void clearEmployees();

    /**
     * @brief createdEmployee A signal that is emitted to indicate that a new employee specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdEmployee(QHash<QString, QVariant> values);

    /**
     * @brief selectedEmployee A signal that is emitted to indicate that the employee specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedEmployee(QHash<QString, QVariant> values);

    /**
     * @brief updatedEmployee A signal that is emitted to indicate that the employee specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedEmployee(QHash<QString, QVariant> values);

    /**
     * @brief removedEmployee A signal that is emitted to indicate that the employee with <i>id</i> has been removed.
     * @param id The id of the employee removed.
     */
    void removedEmployee(int id);

    /**
     * @brief employeeSelected A signal that is emitted to indicate that the employee specified in <i>values</i>
     * has been selected.
     * @param id The id of the employee to be selected.
     */
    void employeeSelected(int id);

    /**
     * @brief selectedBodyMeasurement A signal that is emitted to indicate that the body measurment specified in
     * <i>values</i> has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedBodyMeasurement(QHash<QString, QVariant> values);

    /**
     * @brief clearProducts A signal that is emitted to indicate that all existing products have been deleted.
     */
    void clearProducts();

    /**
     * @brief createdProduct A signal that is emitted to indicate that a new product specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdProduct(QHash<QString, QVariant> values);

    /**
     * @brief updatedProduct A signal that is emitted to indicate that the product specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedProduct(QHash<QString, QVariant> values);

    /**
     * @brief removedProduct A signal that is emitted to indicate that the product with <i>id</i> has been removed.
     * @param id The id of the product removed.
     */
    void removedProduct(int id);

    /**
     * @brief clearActivities A signal that is emitted to indicate that all exisiting activities have been deleted.
     */
    void clearActivities();

    /**
     * @brief createdActivity A signal that is emitted to indicate that a new activity specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdActivity(QHash<QString, QVariant> values);

    /**
     * @brief updatedActivity A signal that is emitted to indicate that the activity specified in <i>values
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedActivity(QHash<QString, QVariant> values);

    /**
     * @brief removedActivity A signal that is emitted to indicate that the activity with <i>id</i> has been removed.
     * @param id The id of the activity removed.
     */
    void removedActivity(int id);

    /**
     * @brief editActivity A signal that is emitted to indicate that the activity specified in <i>values</i>
     * should be edited.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void editActivity(QHash<QString, QVariant> values);

    /**
     * @brief clearEquipments A signal that is emitted to indicate that all existing equipments have been deleted.
     */
    void clearEquipments();

    /**
     * @brief createdEquipment A signal that is emitted to indicate that a new equipment specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdEquipment(QHash<QString, QVariant> values);

    /**
     * @brief updatedEquipment A signal that is emitted to indicate that the equipment specified in <i>values
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedEquipment(QHash<QString, QVariant> values);

    /**
     * @brief removedEquipment A signal that is emitted to indicate that the activity with <i>id</i> has been removed.
     * @param id The id of the equipment removed.
     */
    void removedEquipment(int id);

    /**
     * @brief clearTransportations A signal that is emitted to indicate that all existing equipments have been deleted.
     */
    void clearTransportations();

    /**
     * @brief createdTransportation A signal that is emitted to indicate that a new transportation specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdTransportation(QHash<QString, QVariant> values);

    /**
     * @brief updatedTransportation A signal that is emitted to indicate that the transportation specified in <i>values
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedTransportation(QHash<QString, QVariant> values);

    /**
     * @brief removedTransportation A signal that is emitted to indicate that the transportation with <i>id</i> has been removed.
     * @param id The id of the transportation removed.
     */
    void removedTransportation(int id);

    /**
     * @brief setLoadHandling A signal that is emitted to indicate that the load handling specified in <i>values</i>
     * has been set.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setLoadHandling(QHash<QString, QVariant> values);

    /**
     * @brief setBodyPosture A signal that is emitted to indicate that the body posture specified in <i>values</i>
     * has been set.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setBodyPosture(QHash<QString, QVariant> values);

    /**
     * @brief setAppliedForce A signal that is emitted to indicate that the applied force specified in <i>values</i>
     * has been set.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setAppliedForce(QHash<QString, QVariant> values);

    /**
     * @brief setWorkProcess A signal that is emitted to indicate that the work process specified in <i>values</i>
     * has been set.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setExecutionCondition A signal that is emitted to indicate that the execution condition specified in <i>values</i>
     * has been set.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void setExecutionCondition(QHash<QString, QVariant> values);

    /**
     * @brief createdWorkProcess A signal that is emitted to indicate that a work process specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedWorkProcess A signal that is emitted to indicate that the work process specified in <i>values</i>
     * has been selected.
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
     * @param type The type the workprocess has been set to.
     */
    void setSelectedWorkProcessType(AVType type);

    /**
     * @brief initializedWorkProcesses A signal that is emitted to indicate the work processes have ben initialized with a
     * <a href="http://doc.qt.io/qt-5/qlist.html">QList</a> of <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a>.
     * Each element of the list represents a work process.
     * @param values A list of hashmaps of values with each the column name and the corresponding value to this column.
     */
    void initializedWorkProcesses(QList<QHash<QString, QVariant>> values);

    /**
     * @brief selectedShift A signal that is emitted to indicate that the shift specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedShift(QHash<QString, QVariant> values);

    /**
     * @brief clearRotationGroup A signal that is emitted to indicate that all existing rotation groups have been deleted.
     */
    void clearRotationGroup();

    /**
     * @brief addRotationGroupEntry A signal that is emitted to indicate that a rotation group entry  specified in <i>values</i>
     * has been added.
     *
     * <b>Note:</b> The Rotation group task name and its duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupEntry A signal that is emitted to indicate that the rotation group entry specified in <i>values
     * has been updated.
     *
     * <b>Note:</b> The Rotation group task name and its duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief addRotationGroupBreakEntry A signal that is emitted to indicate that a new rotation group break entry
     * specified in <i>values</i> has been added.
     *
     * <b>Note:</b> The entry's duration is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void addRotationGroupBreakEntry(QHash<QString, QVariant> values);

    /**
     * @brief clearRotationGroupTasks A signal that is emitted to indicate that all existing rotation group tasks
     * have been deleted.
     */
    void clearRotationGroupTasks();

    /**
     * @brief createdRotationGroupTask A signal that is emitted to indicate that a new rotation group task specified in <i>values</i>
     * has been created.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTask A signal that is emitted to indicate that the rotation group task specified in <i>values</i>
     * has been updated.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void updatedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTask A signal that is emitted to indicate that the rotation group task with <i>id</i>
     * has been removed.
     * @param id The id of the rotation group task removed.
     */
    void removedRotationGroupTask(int id);

    /**
     * @brief selectedRotationGroupTask A signal that is emitted to indicate that the rotation group specified in <i>values</i>
     * has been selected.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void selectedRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief updatedRotationGroupTaskDuration A signal that is emitted to indicate that the currently selected rotation
     * group task has been updated with the provided <i>duration</i>.
     * @param duration The duration the rotation group task has been updated to.
     */
    void updatedRotationGroupTaskDuration(int duration);

    /**
     * @brief clearRotationGroupTaskEntries A signal that is emitted to indicate that all existing rotation group task
     * entries have been deleted.
     */
    void clearRotationGroupTaskEntries();

    /**
     * @brief createdRotationGroupTaskEntry A signal that is emitted to indicate that a new rotation group task entry
     * specified in <i>values</i> has been created.
     *
     * <b>Note:</b> The work place name is provided with the values.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     */
    void createdRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief removedRotationGroupTaskEntry A signal that is emitted to indicate that the rotation group task entry with
     * <i>id</id> has been removed.
     * @param id The id of the rotation group task entry removed.
     */
    void removedRotationGroupTaskEntry(int id);

public slots:
    /**
     * @brief createAnalyst Creates a new analyst in the database with the given <i>values</i>.
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

    /**
     * @brief createBlankRecording Creates a new autogenerated recording in the database and simulates the normal
     * behaviour of creating a recording in the views.
     *
     * An autogenerated workplace and activity are created.
     *
     * @see showView();
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createBlankRecording();

    /**
     * @brief setBranchOfIndustry Sets the branch of industry values with <i>id</i> from the database.
     * @param id The id of the branch of industry to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setBranchOfIndustry(int id);

    /**
     * @brief saveBranchOfIndustry Saves the branch of industry in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBranchOfIndustry(QHash<QString, QVariant> values);

    /**
     * @brief setCorporation Sets the corporation with <i>id</i> from the database.
     * @param id The id of the corporatoin to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setCorporation(int id);

    /**
     * @brief saveCorperation Saves the corporation in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveCorperation(QHash<QString, QVariant> values);

    /**
     * @brief setFactory Sets the factory with <i>id</i> from the database.
     * @param id The id of the factory to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setFactory(int id);

    /**
     * @brief saveFactory Saves the factory in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveFactory(QHash<QString, QVariant> values);

    /**
     * @brief setRecording Sets the recording with <i>id</i> from the database.
     * @param id The id of the recording to be set.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void setRecording(int id);

    /**
     * @brief saveRecording Saves the recording in the database with the given <i>values</i> .
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveRecording(QHash<QString, QVariant> values);

    /**
     * @brief createWorkplace Creates a new workplace in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief createWorkplace Creates a new workplace in the database with the given <i>values</i> and the
     * activities given in <i>activityValues</i>.
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
     * @brief saveWorkplace Saves the workplace in the database with the given <i>values</i> .
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkplace(QHash<QString, QVariant> values);

    /**
     * @brief saveComment Saves the comment in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveComment(QHash<QString, QVariant> values);

    /**
     * @brief createLine Creates a new line in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createLine(QHash<QString, QVariant> values);

    /**
     * @brief editLine Edits the Line with the given <i>id</i> in the database.
     * @param id The id of the line to be edited.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void editLine(int id);

    /**
     * @brief saveLine Saves the line in the database with the given <i>values</i>.
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

    /**
     * @brief createProduct Creates a new product in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createProduct(QHash<QString, QVariant> values);

    /**
     * @brief saveProduct Saves the product in the database with the given <i>values</i>.
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

    /**
     * @brief createActivity Creates a new activity in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createActivity(QHash<QString, QVariant> values);

    /**
     * @brief saveActivity Saves the activity in the database with the <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveActivity(QHash<QString, QVariant> values);

    /**
     * @brief deleteActivity Deletes the activity with <i>id</i> from the database. If showMsg is true, a message
     * indicating the deletion is requested.
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

    /**
     * @brief createEquipment Creates a new equipment in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createEquipment(QHash<QString, QVariant> values);

    /**
     * @brief saveEquipment Save the equipment in the database with the given <i>values</i> .
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

    /**
     * @brief createTransportation Creates a new transportation in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createTransportation(QHash<QString, QVariant> values);

    /**
     * @brief saveTransportation Saves the transportation in the database with the given <i>values</i>.
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

    /**
     * @brief saveLoadHandling Saves the load handling in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveLoadHandling(QHash<QString, QVariant> values);

    /**
     * @brief saveBodyPosture Saves the body posture in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBodyPosture(QHash<QString, QVariant> values);

    /**
     * @brief saveAppliedForce Saves the applied force in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveAppliedForce(QHash<QString, QVariant> values);

    /**
     * @brief saveWorkProcess Saves the work process in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkProcess(QHash<QString, QVariant> values);

    /**
     * @brief saveExecutionCondition Saves the execution condition in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveExecutionCondition(QHash<QString, QVariant> values);

    /**
     * @brief createWorkprocess Creates a new workplace in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createWorkprocess(QHash<QString, QVariant> values);

    /**
     * @brief selectNextWorkProcess Selects the next work process, this means the work process with the
     * current work process' id + 1 and the current workprocess' type.
     */
    void selectNextWorkProcess();

    /**
     * @brief selectPreviousWorkProcess Selects the previous work process, this means the work process with the
     * current work process' id - 1 and the current workprocess' type.
     */
    void selectPreviousWorkProcess();

    /**
     * @brief workProcessTypeChanged Selects the first work process with the specified <i>AVType</i>
     * @param type The type of which the first process should be selected.
     */
    void workProcessTypeChanged(AVType type);

    /**
     * @brief resetWorkProcesses Resets all existing workprocesses in the database for the currently selected
     * activity.
     */
    void resetWorkProcesses();

    /**
     * @brief workProcessDurationChanged The currently selected work process' time is set to the provided
     * <i>time</i>.
     *
     * The begin and end times of the following work processes of the same type are adapted depending on
     * whether the duration of the selected work process in- or decreased. The adaption is the difference
     * between the old and the new duration of the selected process.
     *
     * <b>Note:</b> The work processes of AVTypes different from the currently selected are not affected.
     * @param time The new time of the work process.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void workProcessDurationChanged(QTime time);

    /**
     * @brief selectWorkProcess Selects the work process identified by <i>id</i> and <i>type</i> in the database.
     * @param id The id of the work process to be selected.
     * @param type The type of the work process to be selected.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectWorkProcess(int id, AVType type);

    /**
     * @brief saveWorkProcessFrequence Saves the given frequence for the selected work process in the database.
     * @param frequence The new frequence of the work process.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveWorkProcessFrequence(int frequence);

    /**
     * @brief createEmployee Creates a new employee in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createEmployee(QHash<QString, QVariant> values);

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
     * @brief saveEmployee Saves the employee in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveEmployee(QHash<QString, QVariant> values);

    /**
     * @brief setSelectedEmployee Sets the currently selected employee to the one with <i>id</i> in the database.
     * @param id The new selectedEmployee id.
     */
    void setSelectedEmployee(int id);

    /**
     * @brief resetEmployeeSelection Emits the selectedEmployee() signal with the currently selected employee's ID.
     */
    void resetEmployeeSelection();

    /**
     * @brief saveBodyMeasurement Saves the body measurement in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveBodyMeasurement(QHash<QString, QVariant> values);

    /**
     * @brief initializeFTPConnections Initializes the widget which shows all FTP connections for the selected analyst.
     * @param widget A widget which implements the IFTPConnections interface.
     */
    void initializeFTPConnections(IFTPConnections *widget);

    /**
     * @brief createFTPConnection Creates a new FTP connection in the database with the values
     * provided by <i>widget</i>.
     * @param widget The widget implementing IFTPConnections, the values for the connection should be taken from.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createFTPConnection(IFTPConnections *widget);

    /**
     * @brief editFTPConnection Saves an FTP connection in the database with <i>id</i>.
     * The values to be saved are provided by <i>widget</i>.
     * @param widget The widget implementing IFTPConnections, the data for the connection should be taken from.
     * @param id The id of the connection to be updated.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void editFTPConnection(IFTPConnections *widget, int id);

    /**
     * @brief selectFTPConnection Selects the FTP connection with <i>id</i> from the database.
     * The connection is set on <i>widget</i>
     * @param widget The widget implementing IFTPConnections, the FTP connection should be set on.
     * @param id The id of the FTP connection.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void selectFTPConnection(IFTPConnections *widget, int id);

    /**
     * @brief saveShift Saves a shift in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveShift(QHash<QString, QVariant> values);

    /**
     * @brief createRotationGroupEntry Creates a new rotation group entry as specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupEntry(QHash<QString, QVariant> values);

    /**
     * @brief createRotationGroupBreakEntry Creates a new rotation group break entry as specified in <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupBreakEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupEntry Removes a rotation group entry with the given <i>order</i>.
     * This causes all rotation group entries with order numbers greater than <i>order</i> are
     * decreased by one.
     *
     * @param order The current order number of the rotation group entry to be deleted.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteRotationGroupEntry(int order);

    /**
     * @brief moveRotationGroupEntryUp Decreases the order number of the rotatation group entry with the
     * given <i>order</i>. Therefore the order number is swapped with the entry that has the order number
     * <i>order - 1</i>.
     * @param order The current order number of the rotation group entry to move up.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void moveRotationGroupEntryUp(int order);

    /**
     * @brief moveRotationGroupEntryDown Increases the order number of the rotatation group entry with the
     * given <i>order</i>. Therefore the order number is swapped with the entry that has the order number
     * <i>order + 1</i>.
     * @param order The current order number of the rotation group entry to move down.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void moveRotationGroupEntryDown(int order);

    /**
     * @brief createRotationGroupTask Creates a new rotation group task in the database with the given <i>values</i>.
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
     * @brief saveRotationGroupTask Saves the rotation group task in the database with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void saveRotationGroupTask(QHash<QString, QVariant> values);

    /**
     * @brief createRotationGroupTaskEntry Creates a new rotation group task entry in the database
     * with the given <i>values</i>.
     * @param values A hashmap of values with each the column name and the corresponding value to this column.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void createRotationGroupTaskEntry(QHash<QString, QVariant> values);

    /**
     * @brief deleteRotationGroupTaskEntry Deletes the Rotation group task entry with <i>id</i> from the database.
     * @param id The id of the rotation group task entry to be deleted.
     * @param showMsg Indicates whether a message indicating the deletion of the entry should be shown.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void deleteRotationGroupTaskEntry(int id, bool showMsg = true);

    /**
     * @brief resetDatabaseFactory Resets all entries in the database to their default values.
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void resetDatabaseFactory();

    /**
     * @brief resetSelectedEntries Resets the selected entries of <i>widget</i> in the database to their default values.
     * @param widget A widget representing the selected entries which implements ISelectedDatabaseReset.
     *
     * @see ISelectedDatabaseReset
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void resetSelectedEntries(ISelectedDatabaseReset *widget);

    /**
     * @brief changeTheme Sets the stylesheet of the application according to the settings.
     *
     * @see Settings
     *
     * <b>Note:</b> If an error occurs when accessing the database, showMessage() is emitted with
     * NotificationMessage::MessageType::ERROR.
     */
    void changeTheme();

private slots:

    void importData(IImportData *widget);
    void importDataDownloadFinished(const QString);
    void importDataDownloadError(const QString &error);

    void sendData(ISendData *widget);
    void sendDataUploadStarted();
    void sendDataUploadFinished(const QString filename);
    void sendDataUploadError(const QString &error);

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

    void initializeAnalysts();
    void initializeProducts();
    void initializeTransportations();
    void initializeEquipments();
    void initializeEmployees();
    void initializeLines();
    void initializeWorkplaces();
    void initializeActivities(int workplace_ID);
    void initializeShift(int id);
    void initializeWorkProcesses(bool selectFirst = true);
    void initializeRotationGroup(int id);
    void initializeRotationGroupTasks();
    void initializeRotationGroupTaskEntries(int id);

    void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocesses);
    void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues);

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
