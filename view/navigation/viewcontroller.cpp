#include "viewcontroller.h"
#include <QDir>

ViewController::ViewController(QWidget *parent) : NotificationWidget(parent),
    content(new QStackedWidget()),
    previousViews(new QStack<ViewType>()),
    viewTypeToIndex(new QHash<ViewType, int>()),
    viewTypeToWidget(new QHash<ViewType, NavigateableWidget*>()),
    popUpTypeToWidget(new QHash<PopUpType, AbstractPopUpWidget*>()),
    btnBack(new QPushButton),
    btnForward(new QPushButton),
    lblBackTitle(new QLabel),
    lblForwardTitle(new QLabel),
    lblTitle(new QLabel),
    internalNavigation(0),
    additionalNavigation(0),
    middleNavigationLayout(new QHBoxLayout),
    additionalNavigationLayout(new QHBoxLayout),
    analystSelectionView(new AnalystSelectionView()),
    mainMenuView(new MainMenu()),
    metaDataView(new MetaDataView()),
    workplaceListView(new WorkplaceListView()),
    workplaceView(new WorkplaceView()),
    lineView(new LineView()),
    activityView(new ActivityView()),
    commentView(new CommentView()),
    ressourceManagementView(new RessourceManagementView()),
    productView(new ProductView()),
    equipmentView(new EquipmentView()),
    transportationView(new TransportationView()),
    employeeView(new EmployeeView()),
    employeeListView(new EmployeeListView()),
    bodyMeasurementView(new BodyMeasurementView()),
    shiftView(new ShiftView()),
    shiftCalendarView(new ShiftCalendar()),
    rotationGroupTaskView(new RotationGroupTaskView()),
    rotationGroupTaskListView(new RotationGroupTaskListView()),
    settingsView(new SettingsView()),
    errorLogView(new ErrorLogView()),
    documentationView(new DocumentationView()),
    workProcessMetaDataView(new WorkProcessMetaDataView()),
    appliedForceView(new AppliedForceView()),
    bodyPostureView(new BodyPostureView()),
    loadHandlingView(new LoadHandlingView()),
    executionConditionView(new ExecutionConditionView()),
    gantTimerView(new GantTimerView()),
    timerViewController(new TimerViewController()),
    equipmentPopUp(new EquipmentPopUp()),
    transportationPopUp(new TransporationPopUp()),
    sendDatabasePopUp(new SendDatabasePopUp()),
    analystPopUp(new AnalystPopUp()),
    createProductPopUp(new CreateProductPopUp()),
    activityPopUp(new ActivityPopUp()),
    languagePopUp(new LanguagePopUp()),
    themePopUp(new ThemePopUp()),
    workplacePopUp(new WorkplacePopUp()),
    importDataPopUp(new ImportDataPopUp()),
    resetPopUp(new ResetPopUp()),
    employeePopUp(new EmployeePopUp()),
    factorySettingsPopUp(new FactorySettingsPopUp()),
    linePopUp(new LinePopUp()),
    cameraPopUp(new CameraPopUp())
{
    btnBack->setObjectName("leftIcon");
    btnBack->setFixedSize(45, 45);
    connect(btnBack, SIGNAL(clicked()), this, SLOT(btnBackClicked()));

    btnForward->setObjectName("rightIcon");
    btnForward->setFixedSize(45, 45);
    connect(btnForward, SIGNAL(clicked()), this, SLOT(btnForwardClicked()));

    middleNavigationLayout->addWidget(lblTitle);

    leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    QHBoxLayout *navigationBarLayout = new QHBoxLayout;
    navigationBarLayout->addWidget(btnBack, 0, Qt::AlignLeft);
    navigationBarLayout->addWidget(lblBackTitle, 0, Qt::AlignLeft);
    navigationBarLayout->addSpacerItem(leftSpacer);
    navigationBarLayout->addSpacerItem(new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    navigationBarLayout->addLayout(middleNavigationLayout);
    navigationBarLayout->addSpacerItem(new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    navigationBarLayout->addSpacerItem(rightSpacer);
    navigationBarLayout->addLayout(additionalNavigationLayout);
    navigationBarLayout->addSpacerItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Fixed));
    navigationBarLayout->addWidget(lblForwardTitle, 0, Qt::AlignRight);
    navigationBarLayout->addWidget(btnForward, 0, Qt::AlignRight);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(navigationBarLayout);
    mainLayout->addWidget(new Separator(Qt::Horizontal, 3));
    mainLayout->addWidget(content);

    QWidget *mainContent = new QWidget();
    mainContent->setLayout(mainLayout);
    this->setMainWidget(mainContent);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    //Initialize Controller
    Controller *controller = new Controller(this);
    connect(controller, SIGNAL(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)), this, SLOT(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)));
    connect(controller, SIGNAL(showView(ViewType,QList<ViewType>*)), this, SLOT(goToView(ViewType,QList<ViewType>*)));

    //Connection of the Views
    //MainMenuView signals/slots
    connect(mainMenuView, SIGNAL(createBlankRecording()), controller, SLOT(createBlankRecording()));

    //AnalystSelectionView signals/slots
    connect(controller, SIGNAL(clearAll()), analystSelectionView, SLOT(clearAnalysts()));
    connect(controller, SIGNAL(clearAnalysts()), analystSelectionView, SLOT(clearAnalysts()));
    connect(controller, SIGNAL(createdAnalyst(QHash<QString,QVariant>)), analystSelectionView, SLOT(addAnalyst(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedAnalyst(int)), analystSelectionView, SLOT(removeAnalyst(int)));
    connect(analystSelectionView, SIGNAL(deleteAnalyst(int)), controller, SLOT(deleteAnalyst(int)));
    connect(analystSelectionView, SIGNAL(selectAnalyst(int)), controller, SLOT(selectAnalyst(int)));
    connect(controller, SIGNAL(updatedAnalyst(QHash<QString,QVariant>)), analystSelectionView, SLOT(updateAnalyst(QHash<QString,QVariant>)));

    //AnalystPopUp signals/slots
    connect(analystPopUp, SIGNAL(saveAnalyst(QHash<QString,QVariant>)), controller, SLOT(createAnalyst(QHash<QString,QVariant>)));

    //MetaDataView signals/slots
    connect(metaDataView, SIGNAL(saveBranchOfIndustry(QHash<QString,QVariant>)), controller, SLOT(saveBranchOfIndustry(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(settedBranchOfIndustry(QHash<QString,QVariant>)), metaDataView, SLOT(setBranchOfIndustry(QHash<QString,QVariant>)));
    connect(metaDataView, SIGNAL(saveCorperation(QHash<QString,QVariant>)), controller, SLOT(saveCorperation(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(settedCorperation(QHash<QString,QVariant>)), metaDataView, SLOT(setCorperation(QHash<QString,QVariant>)));
    connect(metaDataView, SIGNAL(saveFactory(QHash<QString,QVariant>)), controller, SLOT(saveFactory(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(settedFactory(QHash<QString,QVariant>)), metaDataView, SLOT(setFactory(QHash<QString,QVariant>)));
    connect(metaDataView, SIGNAL(saveRecording(QHash<QString,QVariant>)), controller, SLOT(saveRecording(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(settedRecording(QHash<QString,QVariant>)), metaDataView, SLOT(setRecording(QHash<QString,QVariant>)));

    //WorkplaceList View signal/slots
    connect(controller, SIGNAL(clearAll()), workplaceListView, SLOT(clearWorkplaces()));
    connect(controller, SIGNAL(clearWorkplaces()), workplaceListView, SLOT(clearWorkplaces()));
    connect(workplaceListView, SIGNAL(createWorkplace(QHash<QString,QVariant>)), controller, SLOT(createWorkplace(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdWorkplace(QHash<QString,QVariant>)), workplaceListView, SLOT(addWorkplace(QHash<QString,QVariant>)));
    connect(workplaceListView, SIGNAL(selectWorkplace(int)), controller, SLOT(selectWorkplace(int)));
    connect(controller, SIGNAL(selectedWorkplace(QHash<QString,QVariant>)), workplaceView, SLOT(setWorkplace(QHash<QString, QVariant>)));
    connect(workplaceListView, SIGNAL(deleteWorkplace(int)), controller, SLOT(deleteWorkplace(int)));
    connect(controller, SIGNAL(removedWorkplace(int)), workplaceListView, SLOT(removeWorkplace(int)));
    connect(controller, SIGNAL(updatedWorkplace(QHash<QString,QVariant>)), workplaceListView, SLOT(updateWorkplace(QHash<QString,QVariant>)));

    //Workplace View signal/slots
    connect(controller, SIGNAL(selectedComment(QHash<QString,QVariant>)), workplaceView, SLOT(setSavedComment(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedComment(QHash<QString,QVariant>)), workplaceView, SLOT(setSavedComment(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedLine(QHash<QString,QVariant>)), workplaceView, SLOT(setSavedLine(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedLine(QHash<QString,QVariant>)), workplaceView, SLOT(setSavedLine(QHash<QString,QVariant>)));
    connect(workplaceView, SIGNAL(saveWorkplace(QHash<QString,QVariant>)), controller, SLOT(saveWorkplace(QHash<QString,QVariant>)));

    //Comment View signal/slots
    connect(controller, SIGNAL(selectedComment(QHash<QString,QVariant>)), commentView, SLOT(setComment(QHash<QString,QVariant>)));
    connect(commentView, SIGNAL(saveComment(QHash<QString,QVariant>)), controller, SLOT(saveComment(QHash<QString,QVariant>)));

    //Employee View signal/slots
    connect(controller, SIGNAL(clearEmployees()), employeeListView, SLOT(clearEmployees()));
    connect(controller, SIGNAL(clearAll()), employeeListView, SLOT(clearEmployees()));
    connect(employeeListView, SIGNAL(deleteEmployee(int)), controller, SLOT(deleteEmployee(int)));
    connect(controller, SIGNAL(removedEmployee(int)), employeeListView, SLOT(removeEmployee(int)));
    connect(employeeListView, SIGNAL(createEmployee(QHash<QString,QVariant>)), controller, SLOT(createEmployee(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdEmployee(QHash<QString,QVariant>)), employeeListView, SLOT(addEmployee(QHash<QString,QVariant>)));
    connect(employeeListView, SIGNAL(selectEmployee(int)), controller, SLOT(selectEmployee(int)));
    connect(controller, SIGNAL(updatedEmployee(QHash<QString,QVariant>)), employeeListView, SLOT(updateEmployee(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedEmployee(QHash<QString,QVariant>)), employeeView, SLOT(setEmployee(QHash<QString,QVariant>)));
    connect(employeeView, SIGNAL(saveEmployee(QHash<QString,QVariant>)), controller, SLOT(saveEmployee(QHash<QString,QVariant>)));

    //BodyMeasurement View signal/slots
    connect(bodyMeasurementView, SIGNAL(saveBodyMeasurement(QHash<QString,QVariant>)), controller, SLOT(saveBodyMeasurement(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedBodyMeasurement(QHash<QString,QVariant>)), bodyMeasurementView, SLOT(setBodyMeasurement(QHash<QString,QVariant>)));

    //EmployeePopUp signal/slots
    connect(employeePopUp, SIGNAL(saveEmployeeSelected(int)), controller, SLOT(setSelectedEmployee(int)));
    connect(employeePopUp, SIGNAL(resetEmployeeSelection()), controller, SLOT(resetEmployeeSelection()));
    connect(controller, SIGNAL(employeeSelected(int)), employeePopUp, SLOT(setEmployeeSelected(int)));
    connect(controller, SIGNAL(clearAll()), employeePopUp, SLOT(clearEmployees()));
    connect(controller, SIGNAL(clearEmployees()), employeePopUp, SLOT(clearEmployees()));
    connect(controller, SIGNAL(updatedEmployee(QHash<QString,QVariant>)), employeePopUp, SLOT(updateEmployee(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdEmployee(QHash<QString,QVariant>)), employeePopUp, SLOT(addEmployee(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedEmployee(int)), employeePopUp, SLOT(removeEmployee(int)));

    //Line View signal/slots
    connect(controller, SIGNAL(clearAll()), lineView, SLOT(clearLines()));
    connect(controller, SIGNAL(clearLines()), lineView, SLOT(clearLines()));
    connect(lineView, SIGNAL(createLine(QHash<QString,QVariant>)), controller, SLOT(createLine(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdLine(QHash<QString,QVariant>)), lineView, SLOT(addLine(QHash<QString,QVariant>)));
    connect(lineView, SIGNAL(deleteLine(int)), controller, SLOT(deleteLine(int)));
    connect(controller, SIGNAL(removedLine(int)), lineView, SLOT(removeLine(int)));
    connect(lineView, SIGNAL(selectLine(int)), controller, SLOT(selectLine(int)));
    connect(controller, SIGNAL(selectedLine(QHash<QString,QVariant>)), lineView, SLOT(selectedLine(QHash<QString,QVariant>)));
    connect(lineView, SIGNAL(editLine(int)), controller, SLOT(editLine(int)));
    connect(controller, SIGNAL(updatedLine(QHash<QString,QVariant>)), lineView, SLOT(updateLine(QHash<QString,QVariant>)));

    //LinePopUp signal/slots
    connect(controller, SIGNAL(editLine(QHash<QString,QVariant>)), linePopUp, SLOT(setLine(QHash<QString, QVariant>)));
    connect(linePopUp, SIGNAL(saveLine(QHash<QString, QVariant>)), controller, SLOT(saveLine(QHash<QString,QVariant>)));

    //ProductView signal/slots
    connect(controller, SIGNAL(clearAll()), productView, SLOT(clearProducts()));
    connect(controller, SIGNAL(clearProducts()), productView, SLOT(clearProducts()));
    connect(productView, SIGNAL(createProduct(QHash<QString,QVariant>)), controller, SLOT(createProduct(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdProduct(QHash<QString,QVariant>)), productView, SLOT(addProduct(QHash<QString,QVariant>)));
    connect(productView, SIGNAL(deleteProduct(int)), controller, SLOT(deleteProduct(int)));
    connect(controller, SIGNAL(removedProduct(int)), productView, SLOT(removeProduct(int)));
    connect(controller, SIGNAL(updatedProduct(QHash<QString,QVariant>)), productView, SLOT(updateProduct(QHash<QString,QVariant>)));

    //CreateProductPopUp signal/slots
    connect(createProductPopUp, SIGNAL(saveProduct(QHash<QString, QVariant>)), controller, SLOT(createProduct(QHash<QString,QVariant>)));

    //ActivityPopUp signal/slots
    connect(controller, SIGNAL(clearAll()), activityPopUp, SLOT(clearProducts()));
    connect(controller, SIGNAL(clearProducts()), activityPopUp, SLOT(clearProducts()));
    connect(controller, SIGNAL(createdProduct(QHash<QString,QVariant>)), activityPopUp, SLOT(addProduct(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedProduct(int)), activityPopUp, SLOT(removeProduct(int)));
    connect(controller, SIGNAL(updatedProduct(QHash<QString,QVariant>)), activityPopUp, SLOT(updateProduct(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(editActivity(QHash<QString,QVariant>)), activityPopUp, SLOT(setActivity(QHash<QString,QVariant>)));
    connect(activityPopUp, SIGNAL(saveActivity(QHash<QString,QVariant>)), controller, SLOT(saveActivity(QHash<QString,QVariant>)));

    //ActivityView signal/slots
    connect(controller, SIGNAL(clearAll()), activityView, SLOT(clearProducts()));
    connect(controller, SIGNAL(clearProducts()), activityView, SLOT(clearProducts()));
    connect(controller, SIGNAL(createdProduct(QHash<QString,QVariant>)), activityView, SLOT(addProduct(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedProduct(int)), activityView, SLOT(removeProduct(int)));
    connect(controller, SIGNAL(updatedProduct(QHash<QString,QVariant>)), activityView, SLOT(updateProduct(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(clearAll()), activityView, SLOT(clearActivities()));
    connect(controller, SIGNAL(clearActivities()), activityView, SLOT(clearActivities()));
    connect(activityView, SIGNAL(createActivity(QHash<QString,QVariant>)), controller, SLOT(createActivity(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdActivity(QHash<QString,QVariant>)), activityView, SLOT(addActivity(QHash<QString,QVariant>)));
    connect(activityView, SIGNAL(deleteActivity(int)), controller, SLOT(deleteActivity(int)));
    connect(controller, SIGNAL(removedActivity(int)), activityView, SLOT(removeActivity(int)));
    connect(activityView, SIGNAL(editActivity(int)), controller, SLOT(editActivity(int)));
    connect(controller, SIGNAL(updatedActivity(QHash<QString,QVariant>)), activityView, SLOT(updateActivity(QHash<QString,QVariant>)));
    connect(activityView, SIGNAL(selectActivity(int)), controller, SLOT(selectActivity(int)));

    //Equipment View signals/slots
    connect(controller, SIGNAL(clearAll()), equipmentView, SLOT(clearEquipments()));
    connect(controller, SIGNAL(clearEquipments()), equipmentView, SLOT(clearEquipments()));
    connect(equipmentView, SIGNAL(createEquipment(QHash<QString,QVariant>)), controller, SLOT(createEquipment(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdEquipment(QHash<QString,QVariant>)), equipmentView, SLOT(addEquipment(QHash<QString,QVariant>)));
    connect(equipmentView, SIGNAL(deleteEquipment(int)), controller, SLOT(deleteEquipment(int)));
    connect(controller, SIGNAL(removedEquipment(int)), equipmentView, SLOT(removeEquipment(int)));
    connect(controller, SIGNAL(updatedEquipment(QHash<QString,QVariant>)), equipmentView, SLOT(updateEquipment(QHash<QString,QVariant>)));

    //EquipmentPopUp signals/slots
    connect(equipmentPopUp, SIGNAL(saveEquipment(QHash<QString,QVariant>)), controller, SLOT(createEquipment(QHash<QString,QVariant>)));

    //WorkProcessMetaData View signals/slots
    connect(controller, SIGNAL(clearAll()), workProcessMetaDataView, SLOT(clearEquipments()));
    connect(controller, SIGNAL(clearEquipments()), workProcessMetaDataView, SLOT(clearEquipments()));
    connect(controller, SIGNAL(createdEquipment(QHash<QString,QVariant>)), workProcessMetaDataView, SLOT(addEquipment(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedEquipment(QHash<QString,QVariant>)), workProcessMetaDataView, SLOT(updateEquipment(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedEquipment(int)), workProcessMetaDataView, SLOT(removeEquipment(int)));
    connect(workProcessMetaDataView, SIGNAL(saveWorkProcess(QHash<QString, QVariant>)), controller, SLOT(saveWorkProcess(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setWorkProcess(QHash<QString,QVariant>)), workProcessMetaDataView, SLOT(setWorkProcess(QHash<QString, QVariant>)));

    //TransportationView signals/slots
    connect(controller, SIGNAL(clearAll()), transportationView, SLOT(clearTransportations()));
    connect(controller, SIGNAL(clearTransportations()), transportationView, SLOT(clearTransportations()));
    connect(transportationView, SIGNAL(createTransportation(QHash<QString,QVariant>)), controller, SLOT(createTransportation(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdTransportation(QHash<QString,QVariant>)), transportationView, SLOT(addTransportation(QHash<QString,QVariant>)));
    connect(transportationView, SIGNAL(deleteTransportation(int)), controller, SLOT(deleteTransportation(int)));
    connect(controller, SIGNAL(removedTransportation(int)), transportationView, SLOT(removeTransportation(int)));
    connect(controller, SIGNAL(updatedTransportation(QHash<QString,QVariant>)), transportationView, SLOT(updateTransportation(QHash<QString,QVariant>)));

    //TransportationPopUp signals/slots
    connect(transportationPopUp, SIGNAL(saveTransportation(QHash<QString,QVariant>)), controller, SLOT(createTransportation(QHash<QString,QVariant>)));

    //LoadHandling View signals/slots
    connect(controller, SIGNAL(clearAll()), loadHandlingView, SLOT(clearTransportations()));
    connect(controller, SIGNAL(clearTransportations()), loadHandlingView, SLOT(clearTransportations()));
    connect(controller, SIGNAL(createdTransportation(QHash<QString,QVariant>)), loadHandlingView, SLOT(addTransportation(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedTransportation(int)), loadHandlingView, SLOT(removeTransportation(int)));
    connect(controller, SIGNAL(updatedTransportation(QHash<QString,QVariant>)), loadHandlingView, SLOT(updateTransportation(QHash<QString,QVariant>)));
    connect(loadHandlingView, SIGNAL(saveLoadHandling(QHash<QString,QVariant>)), controller, SLOT(saveLoadHandling(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setLoadHandling(QHash<QString,QVariant>)), loadHandlingView, SLOT(setLoadHandling(QHash<QString,QVariant>)));

    //AppliedForce View signals/slots
    connect(appliedForceView, SIGNAL(saveAppliedForce(QHash<QString, QVariant>)), controller, SLOT(saveAppliedForce(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setAppliedForce(QHash<QString,QVariant>)), appliedForceView, SLOT(setAppliedForce(QHash<QString, QVariant>)));

    //ExecutionCondition View signals/slots
    connect(executionConditionView, SIGNAL(saveExecutionCondition(QHash<QString, QVariant>)), controller, SLOT(saveExecutionCondition(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setExecutionCondition(QHash<QString,QVariant>)), executionConditionView, SLOT(setExecutionCondition(QHash<QString, QVariant>)));

    //BodyPosture View signals/slots
    connect(bodyPostureView, SIGNAL(saveBodyPosture(QHash<QString,QVariant>)), controller, SLOT(saveBodyPosture(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setBodyPosture(QHash<QString,QVariant>)), bodyPostureView, SLOT(setBodyPosture(QHash<QString,QVariant>)));

    //GanttTimer View signals/slots
    connect(gantTimerView, SIGNAL(selectWorkProcess(int, AVType)), controller, SLOT(selectWorkProcess(int, AVType)));
    connect(gantTimerView, SIGNAL(saveWorkProcessFrequence(int)), controller, SLOT(saveWorkProcessFrequence(int)));
    connect(controller, SIGNAL(initiliazedWorkProcesses(QList<QHash<QString,QVariant> >)), gantTimerView, SLOT(initiliazeWorkProcesses(QList<QHash<QString,QVariant> >)));
    connect(controller, SIGNAL(setSelectedWorkProcess(QHash<QString,QVariant>)), gantTimerView, SLOT(setSelectedWorkProcess(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdWorkProcess(QHash<QString, QVariant>)), gantTimerView, SLOT(addWorkProcess(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(resettedWorkProcesses()), gantTimerView, SLOT(resetWorkProcesses()));

    connect(gantTimerView, SIGNAL(entered()), timerViewController, SLOT(gantViewShown()));
    connect(gantTimerView, SIGNAL(left()), timerViewController, SLOT(gantViewHidden()));

    //WorkProcessControll
    connect(controller, SIGNAL(initiliazedWorkProcesses(QList<QHash<QString,QVariant> >)), timerViewController, SLOT(initiliazedWorkProcesses(QList<QHash<QString,QVariant> >)));
    connect(timerViewController, SIGNAL(createWorkProcess(QHash<QString,QVariant>)), controller, SLOT(createWorkprocess(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(setSelectedWorkProcess(QHash<QString,QVariant>)), timerViewController, SLOT(setSelectedWorkProcess(QHash<QString,QVariant>)));
    connect(timerViewController, SIGNAL(selectPreviousWorkProcess()), controller, SLOT(selectPreviousWorkProcess()));
    connect(controller, SIGNAL(setHasPreviousWorkProcess(bool)), timerViewController, SLOT(setHasPreviousWorkProcess(bool)));
    connect(controller, SIGNAL(setHasNextWorkProcess(bool)), timerViewController, SLOT(setHasNextWorkProcess(bool)));
    connect(timerViewController, SIGNAL(selectNextWorkProcess()), controller, SLOT(selectNextWorkProcess()));
    connect(controller, SIGNAL(setSelectedWorkProcessType(AVType)), timerViewController, SLOT(setSelectedWorkProcessType(AVType)));
    connect(timerViewController, SIGNAL(workProcessTypeChanged(AVType)), controller, SLOT(workProcessTypeChanged(AVType)));
    connect(timerViewController, SIGNAL(workProcessDurationChanged(QTime)), controller, SLOT(workProcessDurationChanged(QTime)));
    connect(timerViewController, SIGNAL(resetWorkProcesses()), controller, SLOT(resetWorkProcesses()));

    //SendDatabasePopUp signals/slots
    connect(sendDatabasePopUp, SIGNAL(initializeFTPConnections(IFTPConnections*)), controller, SLOT(initializeFTPConnections(IFTPConnections*)));
    connect(sendDatabasePopUp, SIGNAL(createFTPConnection(IFTPConnections*)), controller, SLOT(createFTPConnection(IFTPConnections*)));
    connect(sendDatabasePopUp, SIGNAL(editFTPConnection(IFTPConnections*,int)), controller, SLOT(editFTPConnection(IFTPConnections*,int)));
    connect(sendDatabasePopUp, SIGNAL(selectFTPConnection(IFTPConnections*,int)), controller, SLOT(selectFTPConnection(IFTPConnections*,int)));
    connect(sendDatabasePopUp, SIGNAL(sendData(ISendData*)), controller, SLOT(sendData(ISendData*)));

    //ImportDatabasePopUp signals/slots
    connect(importDataPopUp, SIGNAL(initializeFTPConnections(IFTPConnections*)), controller, SLOT(initializeFTPConnections(IFTPConnections*)));
    connect(importDataPopUp, SIGNAL(createFTPConnection(IFTPConnections*)), controller, SLOT(createFTPConnection(IFTPConnections*)));
    connect(importDataPopUp, SIGNAL(editFTPConnection(IFTPConnections*,int)), controller, SLOT(editFTPConnection(IFTPConnections*,int)));
    connect(importDataPopUp, SIGNAL(selectFTPConnection(IFTPConnections*,int)), controller, SLOT(selectFTPConnection(IFTPConnections*,int)));
    connect(importDataPopUp, SIGNAL(importData(IImportData*)), controller, SLOT(importData(IImportData*)));

    //ShiftView signals/slots
    connect(shiftView, SIGNAL(saveShift(QHash<QString,QVariant>)), controller, SLOT(saveShift(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedShift(QHash<QString,QVariant>)), shiftView, SLOT(setShift(QHash<QString,QVariant>)));

    //rotationGroupTaskListView signals/slots
    connect(controller, SIGNAL(clearAll()), rotationGroupTaskListView, SLOT(clearRotationGroupTasks()));
    connect(controller, SIGNAL(clearRotationGroupTasks()), rotationGroupTaskListView, SLOT(clearRotationGroupTasks()));
    connect(controller, SIGNAL(createdRotationGroupTask(QHash<QString,QVariant>)), rotationGroupTaskListView, SLOT(addRotationGroupTask(QHash<QString,QVariant>)));
    connect(rotationGroupTaskListView, SIGNAL(createRotationGroupTask(QHash<QString,QVariant>)), controller, SLOT(createRotationGroupTask(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedRotationGroupTask(int)), rotationGroupTaskListView, SLOT(removeRotationGroupTask(int)));
    connect(rotationGroupTaskListView, SIGNAL(deleteRotationGroupTask(int)), controller, SLOT(deleteRotationGroupTask(int)));
    connect(rotationGroupTaskListView, SIGNAL(selectRotationGroupTask(int)), controller, SLOT(selectRotationGroupTask(int)));
    connect(controller, SIGNAL(updatedRotationGroupTask(QHash<QString,QVariant>)), rotationGroupTaskListView, SLOT(updateRotationGroupTask(QHash<QString,QVariant>)));

    //rotationGroupTaskView signals/slots
    connect(controller, SIGNAL(clearAll()), rotationGroupTaskView, SLOT(clearRotationGroupTaskEntries()));
    connect(controller, SIGNAL(clearAll()), rotationGroupTaskView, SLOT(clearWorkplaces()));
    connect(controller, SIGNAL(clearWorkplaces()), rotationGroupTaskView, SLOT(clearWorkplaces()));
    connect(controller, SIGNAL(clearRotationGroupTaskEntries()), rotationGroupTaskView, SLOT(clearRotationGroupTaskEntries()));
    connect(controller, SIGNAL(createdWorkplace(QHash<QString,QVariant>)), rotationGroupTaskView, SLOT(addWorkplace(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedWorkplace(QHash<QString,QVariant>)), rotationGroupTaskView, SLOT(updateWorkplace(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedWorkplace(int)), rotationGroupTaskView, SLOT(removeWorkplace(int)));
    connect(rotationGroupTaskView, SIGNAL(createRotationGroupTaskEntry(QHash<QString,QVariant>)), controller, SLOT(createRotationGroupTaskEntry(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(createdRotationGroupTaskEntry(QHash<QString,QVariant>)), rotationGroupTaskView, SLOT(addRotationGroupTaskEntry(QHash<QString,QVariant>)));
    connect(rotationGroupTaskView, SIGNAL(deleteRotationGroupTaskEntry(int)), controller, SLOT(deleteRotationGroupTaskEntry(int)));
    connect(controller, SIGNAL(removedRotationGroupTaskEntry(int)), rotationGroupTaskView, SLOT(removeRotationGroupTaskEntry(int)));
    connect(rotationGroupTaskView, SIGNAL(saveRotationGroupTask(QHash<QString,QVariant>)), controller, SLOT(saveRotationGroupTask(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedRotationGroupTask(QHash<QString,QVariant>)), rotationGroupTaskView, SLOT(setRotationGroupTask(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedRotationGroupTaskDuration(int)), rotationGroupTaskView, SLOT(setRotationGroupTaskDuration(int)));

    //shiftCalendarView signals/slots
    connect(controller, SIGNAL(clearAll()), shiftCalendarView, SLOT(clearRotationGroup()));
    connect(controller, SIGNAL(clearAll()), shiftCalendarView, SLOT(clearRotationGroupTasks()));
    connect(controller, SIGNAL(clearRotationGroupTasks()), shiftCalendarView, SLOT(clearRotationGroupTasks()));
    connect(controller, SIGNAL(clearRotationGroup()), shiftCalendarView, SLOT(clearRotationGroup()));
    connect(controller, SIGNAL(createdRotationGroupTask(QHash<QString,QVariant>)), shiftCalendarView, SLOT(addRotationGroupTask(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedRotationGroupTask(QHash<QString,QVariant>)), shiftCalendarView, SLOT(updateRotationGroupTask(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(removedRotationGroupTask(int)), shiftCalendarView, SLOT(removeRotationGroupTask(int)));
    connect(controller, SIGNAL(addRotationGroupBreakEntry(QHash<QString,QVariant>)), shiftCalendarView, SLOT(addRotationGroupBreakEntry(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(addRotationGroupEntry(QHash<QString,QVariant>)), shiftCalendarView, SLOT(addRotationGroupEntry(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(updatedRotationGroupEntry(QHash<QString,QVariant>)), shiftCalendarView, SLOT(updateRotationGroupEntry(QHash<QString,QVariant>)));
    connect(controller, SIGNAL(selectedShift(QHash<QString,QVariant>)), shiftCalendarView, SLOT(setShift(QHash<QString,QVariant>)));
    connect(shiftCalendarView, SIGNAL(createRotationGroupBreakEntry(QHash<QString,QVariant>)), controller, SLOT(createRotationGroupBreakEntry(QHash<QString,QVariant>)));
    connect(shiftCalendarView, SIGNAL(createRotationGroupEntry(QHash<QString,QVariant>)), controller, SLOT(createRotationGroupEntry(QHash<QString,QVariant>)));
    connect(shiftCalendarView, SIGNAL(requestMoveEntryDown(int)), controller, SLOT(moveRotationGroupEntryDown(int)));
    connect(shiftCalendarView, SIGNAL(requestMoveEntryUp(int)), controller, SLOT(moveRotationGroupEntryUp(int)));
    connect(shiftCalendarView, SIGNAL(requestRemoveEntry(int)), controller, SLOT(removeRotationGroupEntry(int)));

    //WorkplacePopUp signals/slots
    connect(workplacePopUp, SIGNAL(saveWorkplace(QHash<QString, QVariant>)), controller, SLOT(createWorkplace(QHash<QString,QVariant>)));

    connect(languagePopUp, SIGNAL(languageChanged()), settingsView, SLOT(languageChanged()));
    connect(themePopUp, SIGNAL(themeChanged()), settingsView, SLOT(themeChanged()));
    connect(themePopUp, SIGNAL(themeChanged()), controller, SLOT(changeTheme()));
    connect(resetPopUp, SIGNAL(resetSelectedEntries(ISelectedDatabaseReset*)), controller, SLOT(resetSelectedEntries(ISelectedDatabaseReset*)));
    connect(factorySettingsPopUp, SIGNAL(confirm()), controller, SLOT(resetDatabaseFactory()));

    // Register Documentation Views
    documentationView->registerView(workProcessMetaDataView, ViewType::WORK_PROCESS_META_DATA_VIEW);
    documentationView->registerView(bodyPostureView, ViewType::BODY_POSTURE_VIEW);
    documentationView->registerView(loadHandlingView, ViewType::LOAD_HANDLING_VIEW);
    documentationView->registerView(appliedForceView, ViewType::APPLIED_FORCE_VIEW);
    documentationView->registerView(executionConditionView, ViewType::WORKING_CONDITION_VIEW);
    documentationView->registerView(gantTimerView, ViewType::GANT_VIEW);
    documentationView->setTimerViewController(timerViewController);

    // Register ViewContoller Views
    registerView(analystSelectionView, ViewType::ANALYST_SELECTION_VIEW);
    registerView(mainMenuView, ViewType::MAIN_MENU_VIEW);
    registerView(metaDataView, ViewType::METADATA_VIEW);
    registerView(workplaceListView, ViewType::WORKPLACELIST_VIEW);
    registerView(settingsView, ViewType::SETTINGS_VIEW);
    registerView(errorLogView, ViewType::ERROR_LOG_VIEW);
    registerView(activityView, ViewType::ACTIVITY_VIEW);
    registerView(commentView, ViewType::COMMENT_VIEW);
    registerView(lineView, ViewType::LINE_VIEW);
    registerView(workplaceView, ViewType::WORKPLACE_VIEW);
    registerView(transportationView, ViewType::TRANSPORTATION_VIEW);
    registerView(ressourceManagementView, ViewType::RESSOURCE_MANAGMENT_VIEW);
    registerView(productView, ViewType::PRODUCT_VIEW);
    registerView(equipmentView, ViewType::EQUIPMENT_VIEW);
    registerView(shiftView, ViewType::SHIFT_VIEW);
    registerView(shiftCalendarView, ViewType::SHIFT_CALENDAR_VIEW);
    registerView(rotationGroupTaskView, ViewType::ROTATION_GROUP_TASK_VIEW);
    registerView(rotationGroupTaskListView, ViewType::ROTATION_GROUP_TASK_LIST_VIEW);
    registerView(employeeView, ViewType::EMPLOYEE_VIEW);
    registerView(employeeListView, ViewType::EMPLOYEE_LIST_VIEW);
    registerView(bodyMeasurementView, ViewType::BODY_MEASUREMENT_VIEW);
    registerView(documentationView, ViewType::DOCUMENTATION_VIEW);

    // Register PopUps on ViewController
    registerPopUp(equipmentPopUp, PopUpType::EQUIPMENT_POPUP);
    registerPopUp(sendDatabasePopUp, PopUpType::DB_SEND_POPUP);
    registerPopUp(transportationPopUp, PopUpType::TRANSPORTATION_POPUP);
    registerPopUp(createProductPopUp, PopUpType::CREATE_PRODUCT_POPUP);
    registerPopUp(analystPopUp, PopUpType::ANALYST_POPUP);
    registerPopUp(activityPopUp, PopUpType::ACTIVITY_POPUP);
    registerPopUp(languagePopUp, PopUpType::LANGUAGE_POPUP);
    registerPopUp(themePopUp, PopUpType::THEME_POPUP);
    registerPopUp(workplacePopUp, PopUpType::WORKPLACE_POPUP);
    registerPopUp(importDataPopUp, PopUpType::IMPORT_DATA_POPUP);
    registerPopUp(resetPopUp, PopUpType::RESET_POPUP);
    registerPopUp(employeePopUp,PopUpType::EMPLOYEE_POPUP);
    registerPopUp(factorySettingsPopUp, PopUpType::FACTORYSETTINGS_POPUP);
    registerPopUp(linePopUp, PopUpType::LINE_POPUP);
    registerPopUp(cameraPopUp, PopUpType::CAMERA_POPUP);

    //Initialize data
    controller->initialize();

    //Set the start views
    documentationView->showStartView(ViewType::BODY_POSTURE_VIEW);
    showStartView(ViewType::ANALYST_SELECTION_VIEW);
}

ViewController::~ViewController()
{

}

//PUBLIC METHODS
void ViewController::showStartView(ViewType type){
    if(viewTypeToIndex->contains(type)){
        previousViews->push(type);
        content->setCurrentIndex(viewTypeToIndex->value(type));
        adaptNavigationBar(type);
        this->show();
    }
}

void ViewController::registerView(NavigateableWidget *widget, ViewType type){
    if(!viewTypeToIndex->contains(type) && widget != 0){
        viewTypeToIndex->insert(type, content->addWidget(widget));
        viewTypeToWidget->insert(type, widget);
        connect(widget, SIGNAL(showPopUp(PopUpType)), this, SLOT(showPopUp(PopUpType)));
        connect(widget, SIGNAL(showView(ViewType)), this, SLOT(goToView(ViewType)));
        connect(widget, SIGNAL(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)), this, SLOT(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)));
        NotificationWidget::resize(widget->sizeHint());
    }
}

void ViewController::registerPopUp(AbstractPopUpWidget *popUp, PopUpType type){
    if(!popUpTypeToWidget->contains(type) && popUp != 0){
        popUpTypeToWidget->insert(type, popUp);
        popUp->hide();
        connect(popUp, SIGNAL(closePopUp()), this, SLOT(closePopUp()));
        connect(popUp, SIGNAL(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)), this, SLOT(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)));
    }
}

void ViewController::showView(ViewType type, QList<ViewType> *prevTypes){
    goToView(type, prevTypes);
}

//PRIVATE SLOTS
void ViewController::btnBackClicked(){
    ViewType currentType = previousViews->top();
    NavigateableWidget *currentView = viewTypeToWidget->value(currentType);
    backToView(currentView->getBackViewType());
}

void ViewController::btnForwardClicked(){
    ViewType currentType = previousViews->top();
    NavigateableWidget *currentView = viewTypeToWidget->value(currentType);
    goToView(currentView->getForwardViewType());
}

void ViewController::goToView(ViewType type, QList<ViewType> *prevTypes){
    if(viewTypeToIndex->contains(type)){
        ViewType currentView = previousViews->top();
        viewTypeToWidget->value(currentView)->onLeaving();
        if(prevTypes != 0){
            for(int i = 0; i < prevTypes->count(); ++i)
                previousViews->push(prevTypes->at(i));
        }
        viewTypeToWidget->value(type)->onEnter();
        content->setCurrentIndex(viewTypeToIndex->value(type));
        previousViews->push(type);
        adaptNavigationBar(type);
    }
}

void ViewController::backToView(ViewType type){
    if((viewTypeToIndex->contains(type) && previousViews->contains(type)) || type == ViewType::UNKNOWN){
        viewTypeToWidget->value(previousViews->top())->onLeaving();
        if(type == ViewType::UNKNOWN){
            previousViews->pop();
        }
        else {
            while(previousViews->top() != type)
                previousViews->pop();
        }
        ViewType nextType = previousViews->top();
        viewTypeToWidget->value(nextType)->onEnter();
        content->setCurrentIndex(viewTypeToIndex->value(nextType));
        adaptNavigationBar(nextType);
    }
}

void ViewController::showPopUp(PopUpType type){
    if(popUpTypeToWidget->contains(type)){
        AbstractPopUpWidget *popUp = popUpTypeToWidget->value(type);
        popUp->onEnter();
        this->openPopUp(popUp);
        currentPopUp = type;
    }
}

void ViewController::closePopUp(){
    NotificationWidget::closePopUp();
}


//PRIVATE METHODS
void ViewController::adaptNavigationBar(ViewType type){
    NavigateableWidget *currentWidget = viewTypeToWidget->value(type);
    int leftWidth = 0;
    int rightWidth = 0;

    if(currentWidget->canGoBack()){
        btnBack->show();
        ViewType backType = currentWidget->getBackViewType();
        if(backType == UNKNOWN){
            backType = previousViews->at(previousViews->count() - 2);
        }
        if(Settings::value(Settings::SETTING_SHOW_NAVIGATION_TITLE).toBool())
            lblBackTitle->setText(viewTypeToWidget->value(backType)->getTitle());
        else
            lblBackTitle->setText("");
        lblBackTitle->adjustSize();
        leftWidth += btnBack->sizeHint().width();
        leftWidth += lblBackTitle->sizeHint().width();
    }
    else {
        btnBack->hide();
        lblBackTitle->setText("");
    }

    if(currentWidget->canGoForward() && viewTypeToWidget->contains(currentWidget->getForwardViewType())){
        btnForward->show();
        if(Settings::value(Settings::SETTING_SHOW_NAVIGATION_TITLE).toBool())
            lblForwardTitle->setText(viewTypeToWidget->value(currentWidget->getForwardViewType())->getTitle());
        else
            lblForwardTitle->setText("");
        lblForwardTitle->adjustSize();
        rightWidth += btnForward->sizeHint().width();
        rightWidth += lblForwardTitle->sizeHint().width();
    }
    else{
        btnForward->hide();
        lblForwardTitle->setText("");
    }

    if(additionalNavigation != 0){
        for(int i = 0; i < additionalNavigation->count(); ++i)
            additionalNavigation->at(i)->hide();
    }
    if(currentWidget->hasAdditionalNavigation()){
        additionalNavigation = currentWidget->getAdditionalNavigation();
        for(int i = 0; i < additionalNavigation->count(); ++i){
            QAbstractButton *btnAdditional = additionalNavigation->at(i);
            btnAdditional->show();
            additionalNavigationLayout->addWidget(btnAdditional, 0, Qt::AlignRight);
            btnAdditional->adjustSize();
            rightWidth += btnAdditional->sizeHint().width();
        }
    }
    else{
        additionalNavigation = 0;
    }

    if(internalNavigation != 0)
        internalNavigation->hide();
    if(currentWidget->hasInteralNavigation()){
        lblTitle->hide();
        internalNavigation = currentWidget->getInternalNavigation();
        internalNavigation->show();
        middleNavigationLayout->addWidget(internalNavigation, 0, Qt::AlignCenter);
    }
    else{
        lblTitle->setText(currentWidget->getTitle());
        lblTitle->show();
        internalNavigation = 0;
    }

    leftSpacer->changeSize(rightWidth, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    rightSpacer->changeSize(leftWidth, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    QWidget::update();
}


