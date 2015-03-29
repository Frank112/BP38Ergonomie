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

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0, QApplication *app = 0);
    ~Controller();

    void initialize();

signals:
    void showMessage(QString message, NotificationMessage::MessageType msgType = NotificationMessage::ACCEPT, NotificationMessage::MessageDisplayType msgDisplayType = NotificationMessage::MIDDLE);
    void showView(Types::ViewType view, QList<Types::ViewType> *previousViews = 0);

    void clearAll();

    //Analyst
    void clearAnalysts();
    void createdAnalyst(QHash<QString, QVariant> values);
    void selectedAnalyst(QHash<QString, QVariant> values);
    void updatedAnalyst(QHash<QString, QVariant> values);
    void removedAnalyst(int id);

    //Branch of Industry
    void settedBranchOfIndustry(QHash<QString, QVariant> values);

    //Corperation
    void settedCorperation(QHash<QString, QVariant> values);

    //Factory
    void settedFactory(QHash<QString, QVariant> values);

    //Recording
    void settedRecording(QHash<QString, QVariant> values);

    //Workplace
    void clearWorkplaces();
    void createdWorkplace(QHash<QString, QVariant> values);
    void selectedWorkplace(QHash<QString, QVariant> values);
    void updatedWorkplace(QHash<QString, QVariant> values);
    void removedWorkplace(int id);

    //Workplace comment
    void selectedComment(QHash<QString, QVariant> values);
    void updatedComment(QHash<QString, QVariant> values);

    //Line
    void createdLine(QHash<QString, QVariant> values);
    void updatedLine(QHash<QString, QVariant> values);
    void editLine(QHash<QString, QVariant> values);
    void removedLine(int id);
    void selectedLine(QHash<QString, QVariant> values);
    void clearLines();

    //Employee
    void clearEmployees();
    void createdEmployee(QHash<QString, QVariant> values);
    void selectedEmployee(QHash<QString, QVariant> values);
    void updatedEmployee(QHash<QString, QVariant> values);
    void removedEmployee(int id);

    //EmployeeSelectList
    void employeeSelected(int id);

    //BodyMeasurement
    void selectedBodyMeasurement(QHash<QString, QVariant> values);

    //Product
    void clearProducts();
    void createdProduct(QHash<QString, QVariant> values);
    void updatedProduct(QHash<QString, QVariant> values);
    void removedProduct(int id);

    //Activity
    void clearActivities();
    void createdActivity(QHash<QString, QVariant> values);
    void updatedActivity(QHash<QString, QVariant> values);
    void removedActivity(int id);
    void editActivity(QHash<QString, QVariant> values);

    //Equipment
    void clearEquipments();
    void createdEquipment(QHash<QString, QVariant> values);
    void updatedEquipment(QHash<QString, QVariant> values);
    void removedEquipment(int id);

    //Transportation
    void clearTransportations();
    void createdTransportation(QHash<QString, QVariant> values);
    void updatedTransportation(QHash<QString, QVariant> values);
    void removedTransportation(int id);

    //LoadHandling
    void setLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    void setBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    void setAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    void setWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    void setExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    void createdWorkProcess(QHash<QString, QVariant> values);
    void setSelectedWorkProcess(QHash<QString, QVariant> values);
    void setHasPreviousWorkProcess(bool hasPrevious);
    void setHasNextWorkProcess(bool hasNext);
    void setSelectedWorkProcessType(AVType type);
    void initiliazedWorkProcesses(QList<QHash<QString, QVariant>> values);
    void resettedWorkProcesses();

    //Shift
    void selectedShift(QHash<QString, QVariant> values);

    //RotationGroup
    void clearRotationGroup();
    void addRotationGroupEntry(QHash<QString, QVariant> values);
    void updatedRotationGroupEntry(QHash<QString, QVariant> values);
    void addRotationGroupBreakEntry(QHash<QString, QVariant> values);

    //RotationGroupTask
    void clearRotationGroupTasks();
    void createdRotationGroupTask(QHash<QString, QVariant> values);
    void updatedRotationGroupTask(QHash<QString, QVariant> values);
    void removedRotationGroupTask(int id);
    void selectedRotationGroupTask(QHash<QString, QVariant> values);
    void updatedRotationGroupTaskDuration(int duration);

    //RotationGroupTaskEntry
    void clearRotationGroupTaskEntries();
    void createdRotationGroupTaskEntry(QHash<QString, QVariant> values);
    void removedRotationGroupTaskEntry(int id);

public slots:
    //Analyst
    void initializeAnalysts();
    void createAnalyst(QHash<QString, QVariant> values);
    void deleteAnalyst(int id);
    void selectAnalyst(int id);

    //MainMenuView
    void createBlankRecording();

    //BranchOfIndustry
    void setBranchOfIndustry(int id);
    void saveBranchOfIndustry(QHash<QString, QVariant> values);

    //Corperation
    void setCorperation(int id);
    void saveCorperation(QHash<QString, QVariant> values);

    //Factory
    void setFactory(int id);
    void saveFactory(QHash<QString, QVariant> values);

    //Recording
    void setRecording(int id);
    void saveRecording(QHash<QString, QVariant> values);

    //Workplace
    void initializeWorkplaces();
    void createWorkplace(QHash<QString, QVariant> values);
    void createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues);
    void deleteWorkplace(int id);
    void selectWorkplace(int id);
    void saveWorkplace(QHash<QString, QVariant> values);

    //Comment
    void saveComment(QHash<QString, QVariant> values);

    //Line
    void initializeLines();
    void createLine(QHash<QString, QVariant> values);
    void editLine(int id);
    void saveLine(QHash<QString, QVariant> values);
    void deleteLine(int id);
    void selectLine(int id);

    //Product
    void initializeProducts();
    void createProduct(QHash<QString, QVariant> values);
    void saveProduct(QHash<QString, QVariant> values);
    void deleteProduct(int id);

    //Activity
    void initializeActivities(int workplace_ID);
    void createActivity(QHash<QString, QVariant> values);
    void saveActivity(QHash<QString, QVariant> values);
    void deleteActivity(int id, bool showMsg = true);
    void selectActivity(int id);
    void editActivity(int id);

    //Equipment
    void initializeEquipments();
    void createEquipment(QHash<QString, QVariant> values);
    void saveEquipment(QHash<QString, QVariant> values);
    void deleteEquipment(int id);

    //Transportation
    void initializeTansportations();
    void createTransportation(QHash<QString, QVariant> values);
    void saveTransportation(QHash<QString, QVariant> values);
    void deleteTransportation(int id);

    //LoadHandling
    void saveLoadHandling(QHash<QString, QVariant> values);

    //BodyPosture
    void saveBodyPosture(QHash<QString, QVariant> values);

    //AppliedForce
    void saveAppliedForce(QHash<QString, QVariant> values);

    //WorkProcess
    void saveWorkProcess(QHash<QString, QVariant> values);

    //ExecutionCondition
    void saveExecutionCondition(QHash<QString, QVariant> values);

    //WorkProcessControll
    void initilizeWorkProcesses(bool selectFirst = true);
    void createWorkprocess(QHash<QString, QVariant> values);
    void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocesses);
    void selectNextWorkProcess();
    void selectPreviousWorkProcess();
    void workProcessTypeChanged(AVType type);
    void resetWorkProcesses();
    void workProcessDurationChanged(QTime time);
    void selectWorkProcess(int id, AVType type);

    //Gantt
    void saveWorkProcessFrequence(int frequence);

    //Employee
    void initializeEmployees();
    void createEmployee(QHash<QString, QVariant> values);
    void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues);
    void deleteEmployee(int id);
    void selectEmployee(int id);
    void saveEmployee(QHash<QString, QVariant> values);
    void setSelectedEmployee(int id);
    void resetEmployeeSelection();

    //BodyMeasurement
    void saveBodyMeasurement(QHash<QString, QVariant> values);

    //Connection
    void initializeFTPConnections(IFTPConnections *widget);
    void createFTPConnection(IFTPConnections *widget);
    void editFTPConnection(IFTPConnections *widget, int id);
    void selectFTPConnection(IFTPConnections *widget, int id);

    //ImportData
    void importData(IImportData *widget);
    void importDataDownloadFinished(const QString);
    void importDataDownloadError(const QString &error);

    //SendData
    void sendData(ISendData *widget);
    void sendDataUploadStarted();
    void sendDataUploadFinished(const QString filename);
    void sendDataUploadError(const QString &error);

    //Shift
    void initializeShift(int id);
    void saveShift(QHash<QString, QVariant> values);

    //RotationGroup
    void initializeRotationGroup(int id);
    void createRotationGroupEntry(QHash<QString, QVariant> values);
    void createRotationGroupBreakEntry(QHash<QString, QVariant> values);
    void deleteRotationGroupEntry(int order);
    void moveRotationGroupEntryUp(int order);
    void moveRotationGroupEntryDown(int order);

    //RotationGroupTask
    void initializeRotationGroupTasks();
    void createRotationGroupTask(QHash<QString, QVariant> values);
    void deleteRotationGroupTask(int id);
    void selectRotationGroupTask(int id);
    void saveRotationGroupTask(QHash<QString, QVariant> values);

    //RotationGroupTaskEntry
    void initializeRotationGroupTaskEntries(int id);
    void createRotationGroupTaskEntry(QHash<QString, QVariant> values);
    void deleteRotationGroupTaskEntry(int id, bool showMsg = true);

    //Reset
    void resetDatabaseFactory();
    void resetSelectedEntries(ISelectedDatabaseReset *widget);

    //Theme
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
