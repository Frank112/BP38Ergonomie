#include "controller.h"
#include <QDebug>
#include <QTime>
Controller::Controller(QObject *parent) :
    QObject(parent),
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
    bodyMeasurementView(new BodyMeasurementView()),
    shiftView(new ShiftView()),
    shiftCalendarView(new ShiftCalendar()),
    rotationGroupView(new RotationGroupView()),
    rotationGroupListView(new RotationGroupListView()),
    settingsView(new SettingsView()),
    documentationView(new DocumentationView()),
    workProcessMetaDataView(new WorkProcessMetaDataView()),
    appliedForceView(new AppliedForceView()),
    bodyPostureView(new BodyPostureView()),
    loadHandlingView(new LoadHandlingView()),
    executionConditionView(new ExecutionConditionView()),
    gantTimerView(new GantTimerView()),
    timerViewController(new TimerViewController()),
    feedbackPopUp(new FeedbackPopUp()),
    equipmentPopUp(new EquipmentPopUp()),
    transportationPopUp(new TransporationPopUp()),
    sendDatabasePopUp(new SendDatabasePopUp())
{
    dbHandler = new DBHandler();

    analyst_ID = 0;
    recording_ID = 1;
    workplace_ID = 0;
    workcondition_ID = 0;
    factory_ID = 0;
    activity_ID = 0;
    appliedforce_ID = 0;
    loadhandling_ID = 0;
    workprocess_Type = AVType::BASIC;
    workprocess_ID = 0;

    documentationView->registerView(workProcessMetaDataView, ViewType::WORK_PROCESS_META_DATA_VIEW);
    documentationView->registerView(bodyPostureView, ViewType::BODY_POSTURE_VIEW);
    documentationView->registerView(loadHandlingView, ViewType::LOAD_HANDLING_VIEW);
    documentationView->registerView(appliedForceView, ViewType::APPLIED_FORCE_VIEW);
    documentationView->registerView(executionConditionView, ViewType::WORKING_CONDITION_VIEW);
    documentationView->registerView(gantTimerView, ViewType::GANT_VIEW);
    documentationView->setTimerViewController(timerViewController);


    viewCon = new ViewController();
    viewCon->registerView(analystSelectionView, ViewType::ANALYST_SELECTION_VIEW);
    viewCon->registerView(mainMenuView, ViewType::MAIN_MENU_VIEW);
    viewCon->registerView(metaDataView, ViewType::METADATA_VIEW);
    viewCon->registerView(workplaceListView, ViewType::WORKPLACELIST_VIEW);
    viewCon->registerView(settingsView, ViewType::SETTINGS_VIEW);
    viewCon->registerView(activityView, ViewType::ACTIVITY_VIEW);
    viewCon->registerView(commentView, ViewType::COMMENT_VIEW);
    viewCon->registerView(lineView, ViewType::LINE_VIEW);
    viewCon->registerView(workplaceView, ViewType::WORKPLACE_VIEW);
    viewCon->registerView(transportationView, ViewType::TRANSPORTATION_VIEW);
    viewCon->registerView(ressourceManagementView, ViewType::RESSOURCE_MANAGMENT_VIEW);
    viewCon->registerView(productView, ViewType::PRODUCT_VIEW);
    viewCon->registerView(equipmentView, ViewType::EQUIPMENT_VIEW);
    viewCon->registerView(shiftView, ViewType::SHIFT_VIEW);
    viewCon->registerView(shiftCalendarView, ViewType::SHIFT_CALENDAR_VIEW);
    viewCon->registerView(rotationGroupView, ViewType::ROTATION_GROUP_VIEW);
    viewCon->registerView(rotationGroupListView, ViewType::ROTATION_GROUP_LIST_VIEW);
    viewCon->registerView(employeeView, ViewType::EMPLOYEE_VIEW);
    viewCon->registerView(bodyMeasurementView, ViewType::BODY_MEASUREMENT_VIEW);
    viewCon->registerView(documentationView, ViewType::DOCUMENTATION_VIEW);

    viewCon->registerPopUp(feedbackPopUp, PopUpType::FEEDBACK_POPUP);
    viewCon->registerPopUp(equipmentPopUp, PopUpType::EQUIPMENT_POPUP);
    viewCon->registerPopUp(sendDatabasePopUp, PopUpType::DB_SEND_POPUP);
    viewCon->registerPopUp(transportationPopUp, PopUpType::TRANSPORTATION_POPUP);

    connect(viewCon, SIGNAL(update(ViewType)), this, SLOT(update(ViewType)));
    connect(viewCon, SIGNAL(save(ViewType)), this, SLOT(save(ViewType)));

    connect(analystSelectionView, SIGNAL(remove(int)), this, SLOT(removeAnalyst(int)));
    connect(analystSelectionView, SIGNAL(create()), this, SLOT(createAnalyst()));
    connect(analystSelectionView, SIGNAL(select(int)), this, SLOT(selectAnalyst(int)));

    connect(workplaceListView, SIGNAL(remove(int)), this, SLOT(deleteWorkplace(int)));
    connect(workplaceListView, SIGNAL(create()), this, SLOT(createWorkplace()));
    connect(workplaceListView, SIGNAL(selected(int)), this, SLOT(updateWorkplaceView(int)));

    connect(lineView, SIGNAL(saveLine()), this, SLOT(saveLine()));
    connect(lineView, SIGNAL(saveSelectedLine(int)), SLOT(saveSelectedLine(int)));
    connect(lineView, SIGNAL(deleteLine(int)), SLOT(deleteLine(int)));

    connect(productView, SIGNAL(saveProduct()), this, SLOT(createProduct()));
    connect(productView, SIGNAL(deleteProduct(int)), this, SLOT(deleteProduct(int)));

    connect(equipmentView, SIGNAL(saveEquipment()), this, SLOT(createEquipment()));
    connect(equipmentView, SIGNAL(deleteEquipment(int)), this, SLOT(deleteEquipment(int)));
    connect(equipmentPopUp, SIGNAL(confirm()), this, SLOT(createEquipmentPopUp()));

    connect(transportationView, SIGNAL(saveTransportation()), this, SLOT(createTransportation()));
    connect(transportationView, SIGNAL(deleteTransportation(int)), this, SLOT(deleteTransportation(int)));

    connect(activityView, SIGNAL(createActivity()), this, SLOT(createActivity()));
    connect(activityView, SIGNAL(selectActivity(int)), this, SLOT(selectActivity(int)));
    connect(activityView, SIGNAL(deleteActivity(int)), this, SLOT(deleteActivity(int)));

    connect(documentationView, SIGNAL(update(ViewType)), this, SLOT(update(ViewType)));
    connect(documentationView, SIGNAL(save(ViewType)), this, SLOT(save(ViewType)));

    connect(gantTimerView, SIGNAL(workProcessSelected(int,AVType)), this, SLOT(setSelectedWorkProcess(int, AVType)));

    connect(timerViewController, SIGNAL(createWorkProcess(AVType,QTime,QTime)), this, SLOT(createWorkprocess(AVType,QTime,QTime)));
    connect(timerViewController, SIGNAL(nextWorkProcess()), this, SLOT(selectNextWorkProcess()));
    connect(timerViewController, SIGNAL(previousWorkProcess()), this, SLOT(selectPreviousWorkProcess()));
    connect(timerViewController, SIGNAL(workProcessTypeChanged(AVType)), this, SLOT(workProcessTypeChanged(AVType)));
    connect(timerViewController, SIGNAL(resetWorkProcesses()), this, SLOT(resetWorkProcesses()));

    connect(settingsView, SIGNAL(resetDatabase()), this, SLOT(resetDatabase()));

    documentationView->showStartView(ViewType::BODY_POSTURE_VIEW);
    viewCon->showStartView(ViewType::ANALYST_SELECTION_VIEW);
}
//PRIVATE SLOTS

void Controller::update(ViewType type){
    switch(type){
    case ViewType::ANALYST_SELECTION_VIEW: updateAnalystSelectionView(); break;
    case ViewType::METADATA_VIEW: updateMetaDataView(); break;
    case ViewType::WORKPLACELIST_VIEW: updateWorkplacesView(); break;
    case ViewType::WORKPLACE_VIEW: updateWorkplaceView(); break;
    case ViewType::LINE_VIEW: updateLineView(); break;
    case ViewType::COMMENT_VIEW: updateComment(); break;
    case ViewType::ACTIVITY_VIEW: updateActivityView(); break;
    case ViewType::DOCUMENTATION_VIEW: updateDocumentationViewRessources(); break;
    case ViewType::EQUIPMENT_VIEW: updateEquipmentView(); break;
    case ViewType::TRANSPORTATION_VIEW: updateTransportationView(); break;
    case ViewType::PRODUCT_VIEW: updateProductView(); break;
    case ViewType::BODY_POSTURE_VIEW: updateBodyPostureView(); break;
    case ViewType::APPLIED_FORCE_VIEW: updateAppliedForceView(); break;
    case ViewType::LOAD_HANDLING_VIEW: updateLoadHandlingView(); break;
    case ViewType::WORKING_CONDITION_VIEW: updateExecutionConditionView(); break;
    case ViewType::WORK_PROCESS_META_DATA_VIEW: updateWorkProcessMetaDataView(); break;
    case ViewType::GANT_VIEW: updateGantView(); break;
    case ViewType::SETTINGS_VIEW: break;
    default: break;
    }
}

void Controller::save(ViewType type){
    switch(type){
    case ViewType::METADATA_VIEW: saveMetaDataView(); break;
    case ViewType::WORKPLACE_VIEW: saveWorkplaceView(); break;
    case ViewType::LINE_VIEW: updateLineView(); break;
    case ViewType::COMMENT_VIEW: saveComment(); break;
    case ViewType::DOCUMENTATION_VIEW: saveCurrentWorkProcess(); break;
    case ViewType::BODY_POSTURE_VIEW: saveBodyPostureView(); break;
    case ViewType::APPLIED_FORCE_VIEW: saveAppliedForceView(); break;
    case ViewType::LOAD_HANDLING_VIEW: saveLoadHandlingView(); break;
    case ViewType::WORKING_CONDITION_VIEW: saveExecutionConditionView(); break;
    case ViewType::WORK_PROCESS_META_DATA_VIEW: saveCurrentWorkProcess(); break;
    default: break;
    }
}


//AnalystSelectionView
void Controller::updateAnalystSelectionView(){
    analystSelectionView->clear();
    DB_TABLES tbl = DB_TABLES::ANALYST;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        analystSelectionView->add(record.value(DBConstants::COL_ANALYST_ID).toInt(),
                                  record.value(DBConstants::COL_ANALYST_LASTNAME).toString(),
                                  record.value(DBConstants::COL_ANALYST_FIRSTNAME).toString());
    }
}

void Controller::createAnalyst(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYER_NAME).arg(analystSelectionView->getAnalystEmployer());
    QHash<QString, QVariant> valuesEmployer = QHash<QString, QVariant>();
    valuesEmployer.insert(DBConstants::COL_EMPLOYER_NAME, analystSelectionView->getAnalystEmployer());
    int emp_ID = dbHandler->save(DB_TABLES::EMPLOYER, DBConstants::HASH_EMPLOYER_TYPES, valuesEmployer, filter, DBConstants::COL_EMPLOYER_ID);

    QHash<QString, QVariant> valuesAnalyst = QHash<QString, QVariant>();
    valuesAnalyst.insert(DBConstants::COL_ANALYST_LASTNAME, analystSelectionView->getAnalystLastName());
    valuesAnalyst.insert(DBConstants::COL_ANALYST_FIRSTNAME, analystSelectionView->getAnalystFirstName());
    valuesAnalyst.insert(DBConstants::COL_ANALYST_EMPLOYER_ID, emp_ID);
    valuesAnalyst.insert(DBConstants::COL_ANALYST_EXPERIENCE, analystSelectionView->getAnalystExperience());
    dbHandler->insert(DB_TABLES::ANALYST, DBConstants::HASH_ANALYST_TYPES, valuesAnalyst, DBConstants::COL_ANALYST_ID);
    updateAnalystSelectionView();
}

void Controller::removeAnalyst(int id){
    dbHandler->deleteAll(DB_TABLES::ANALYST, QString("%1 = %2").arg(DBConstants::COL_ANALYST_ID).arg(id));
    updateAnalystSelectionView();
}

void Controller::selectAnalyst(int id){
    analyst_ID = id;
}


//MetaDataView
void Controller::updateMetaDataView(){
    if(recording_ID <= 0){
        metaDataView->setRecordTime(QDateTime::currentDateTime(), QDateTime::currentDateTime());
    }
    else{
        dbHandler->select(DB_TABLES::RECORDING, QString("%1 = %2").arg(DBConstants::COL_RECORDING_ID).arg(QString::number(recording_ID)));
        QSqlRecord record = dbHandler->record(DB_TABLES::RECORDING, 0);
        metaDataView->setRecordTime(record.value(DBConstants::COL_RECORDING_START).toDateTime(),
                                record.value(DBConstants::COL_RECORDING_END).toDateTime());

        factory_ID = record.value(DBConstants::COL_RECORDING_FACTORY_ID).toInt();
        dbHandler->select(DB_TABLES::FACTORY, QString("%1 = %2").arg(DBConstants::COL_FACTORY_ID).arg(QString::number(factory_ID)));
        record = dbHandler->record(DB_TABLES::FACTORY, 0);
        metaDataView->setFactory(record.value(DBConstants::COL_FACTORY_NAME).toString(),
                            record.value(DBConstants::COL_FACTORY_STREET).toString(),
                            record.value(DBConstants::COL_FACTORY_ZIP).toInt(),
                            record.value(DBConstants::COL_FACTORY_CITY).toString(),
                            record.value(DBConstants::COL_FACTORY_COUNTRY).toString(),
                            record.value(DBConstants::COL_FACTORY_CONTACT_PERSON).toString(),
                            record.value(DBConstants::COL_FACTORY_HEADCOUNT).toInt());

        int corp_ID = record.value(DBConstants::COL_FACTORY_CORPORATION_ID).toInt();
        dbHandler->select(DB_TABLES::CORPORATION, QString("%1 = %2").arg(DBConstants::COL_CORPORATION_ID).arg(QString::number(corp_ID)));
        record = dbHandler->record(DB_TABLES::CORPORATION, 0);
        metaDataView->setCorporation(record.value(DBConstants::COL_CORPORATION_NAME).toString());

        int boi_ID = record.value(DBConstants::COL_CORPORATION_BRANCH_OF_INDUSTRY_ID).toInt();
        dbHandler->select(DB_TABLES::BRANCH_OF_INDUSTRY, QString("%1 = %2").arg(DBConstants::COL_BRANCH_OF_INDUSTRY_ID).arg(boi_ID));
        record = dbHandler->record(DB_TABLES::BRANCH_OF_INDUSTRY, 0);
        metaDataView->setBranchOfIndustry(record.value(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).toString(),
                                          record.value(DBConstants::COL_BRANCH_OF_INDUSTRY_DESCRIPTION).toString());
    }
}

void Controller::saveMetaDataView(){
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).arg(metaDataView->getBranchOfIndustryName());
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME, metaDataView->getBranchOfIndustryName());
    values.insert(DBConstants::COL_BRANCH_OF_INDUSTRY_DESCRIPTION, metaDataView->getBranchOfIndustryDescription());
    int boi_ID = dbHandler->save(DB_TABLES::BRANCH_OF_INDUSTRY, DBConstants::HASH_BRANCH_OF_INDUSTRY_TYPES, values, filter, DBConstants::COL_BRANCH_OF_INDUSTRY_ID);

    filter = QString("%1 = '%2'").arg(DBConstants::COL_CORPORATION_NAME).arg(metaDataView->getCorporationName());
    values.clear();
    values.insert(DBConstants::COL_CORPORATION_NAME, metaDataView->getCorporationName());
    values.insert(DBConstants::COL_CORPORATION_BRANCH_OF_INDUSTRY_ID, boi_ID);
    int corp_ID = dbHandler->save(DB_TABLES::CORPORATION, DBConstants::HASH_CORPORATION_TYPES, values, filter, DBConstants::COL_CORPORATION_ID);

    filter = QString("%1 = '%2' AND %3 = '%4'").arg(DBConstants::COL_FACTORY_NAME).arg(metaDataView->getFactoryName()).arg(DBConstants::COL_FACTORY_STREET).arg(metaDataView->getFactoryStreet());
    values.clear();
    values.insert(DBConstants::COL_FACTORY_NAME, metaDataView->getFactoryName());
    values.insert(DBConstants::COL_FACTORY_STREET, metaDataView->getFactoryStreet());
    values.insert(DBConstants::COL_FACTORY_ZIP, metaDataView->getFactoryZip());
    values.insert(DBConstants::COL_FACTORY_CITY, metaDataView->getFactoryCity());
    values.insert(DBConstants::COL_FACTORY_COUNTRY, metaDataView->getFactoryCountry());
    values.insert(DBConstants::COL_FACTORY_CONTACT_PERSON, metaDataView->getFactoryContact());
    values.insert(DBConstants::COL_FACTORY_HEADCOUNT, metaDataView->getFactoryEmployeeCount());
    values.insert(DBConstants::COL_FACTORY_CORPORATION_ID, corp_ID);
    factory_ID = dbHandler->save(DB_TABLES::FACTORY, DBConstants::HASH_FACTORY_TYPES, values, filter, DBConstants::COL_FACTORY_ID);


    filter = QString("");
    QString dtFormat = "dd.MM.yyyy hh:mm";
    values.clear();
    values.insert(DBConstants::COL_RECORDING_START, metaDataView->getRecordTimeBegin().toString(dtFormat));
    values.insert(DBConstants::COL_RECORDING_END, metaDataView->getRecordTimeEnd().toString(dtFormat));
    values.insert(DBConstants::COL_RECORDING_FACTORY_ID, factory_ID);
    values.insert(DBConstants::COL_RECORDING_ANALYST_ID, analyst_ID);
    recording_ID = dbHandler->save(DB_TABLES::RECORDING, DBConstants::HASH_RECORDING_TYPES, values, filter, DBConstants::COL_RECORDING_ID);
}

//WorkplacesView
void Controller::updateWorkplacesView(){
    workplaceListView->clear();
    DB_TABLES tbl = DB_TABLES::WORKPLACE;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        workplaceListView->addWorkplace(record.value(DBConstants::COL_WORKPLACE_ID).toInt(), record.value(DBConstants::COL_WORKPLACE_NAME).toString(), record.value(DBConstants::COL_WORKPLACE_DESCRIPTION).toString(), record.value(DBConstants::COL_WORKPLACE_CODE).toString());
    }
}

//WorkplaceView
void Controller::updateWorkplaceView(int id){
    workplace_ID = id;
    DB_TABLES tbl = DB_TABLES::WORKPLACE;
    dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(QString::number(id)));
    QSqlRecord record = dbHandler->record(tbl, 0);
    workplaceView->setWorkplaceMetaData(record.value(DBConstants::COL_WORKPLACE_NAME).toString(),
                                  record.value(DBConstants::COL_WORKPLACE_DESCRIPTION).toString(),
                                  record.value(DBConstants::COL_WORKPLACE_CODE).toString(),
                                  record.value(DBConstants::COL_WORKPLACE_PERCENTAGE_WOMAN).toInt());

    QTime basicTime = QTime(0, 0);
    basicTime = basicTime.addSecs(record.value(DBConstants::COL_WORKPLACE_BASIC_TIME).toInt());
    QTime setupTime = QTime(0, 0);
    setupTime = setupTime.addSecs(record.value(DBConstants::COL_WORKPLACE_SETUP_TIME).toInt());
    QTime restTime = QTime(0, 0);
    restTime = restTime.addSecs(record.value(DBConstants::COL_WORKPLACE_REST_TIME).toInt());
    QTime allowanceTime = QTime(0, 0);
    allowanceTime = allowanceTime.addSecs(record.value(DBConstants::COL_WORKPLACE_ALLOWANCE_TIME).toInt());
    QTime cycleTime = QTime(0, 0);
    cycleTime = cycleTime.addSecs(record.value(DBConstants::COL_WORKPLACE_CYCLE_TIME).toInt());

    workplaceView->setWorkplaceTimes(basicTime, setupTime, restTime, allowanceTime, cycleTime);

    tbl = DB_TABLES::LINE;
    if(dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(record.value(DBConstants::COL_WORKPLACE_LINE_ID).toString())) > 0){
        QSqlRecord line = dbHandler->record(tbl, 0);
        workplaceView->setLine(line.value(DBConstants::COL_LINE_NAME).toString(),
                                  line.value(DBConstants::COL_LINE_DESCRIPTION).toString());
    }
    else
        workplaceView->setLine("","");

    tbl = DB_TABLES::COMMENT;
    if(dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(workplace_ID)) > 0){
        QSqlRecord comment = dbHandler->record(tbl, 0);
        workplaceView->setComment(comment.value(DBConstants::COL_COMMENT_PROBLEM_NAME).toString(),
                                     comment.value(DBConstants::COL_COMMENT_MEASURE_NAME).toString());
    }
    else
        workplaceView->setComment("","");

}

void Controller::updateWorkplaceView(){
    updateWorkplaceView(workplace_ID);
}

int Controller::createWorkplace(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(QString::number(0));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    int id = dbHandler->save(DB_TABLES::WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter, DBConstants::COL_WORKPLACE_ID);
    updateWorkplaceView(id);
    saveRecordingObservesWorkplace(id);
    return id;
}

void Controller::saveWorkplaceView(){
   saveWorkplace(workplace_ID);
}

void Controller::deleteWorkplace(int id){
    DB_TABLES tbl = DB_TABLES::WORKPLACE;
    dbHandler->deleteAll(tbl, QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(QString::number(id)));
    updateWorkplacesView();
    deleteRecordingOberservesWorkplace(id);
}


//Line

void Controller::updateLineView(){
    lineView->clear();
    DB_TABLES tbl = DB_TABLES::LINE;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        lineView->addLine(record.value(DBConstants::COL_LINE_ID).toInt(), record.value(DBConstants::COL_LINE_NAME).toString());
    }

    dbHandler->select(DB_TABLES::WORKPLACE, QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(workplace_ID));
    lineView->setSelectedLine(dbHandler->record(DB_TABLES::WORKPLACE, 0).value(DBConstants::COL_WORKPLACE_LINE_ID).toInt());
}

int Controller::saveSelectedLine(int id){
    DB_TABLES tbl = DB_TABLES::WORKPLACE;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(workplace_ID);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_LINE_ID, id);
    return dbHandler->save(tbl, DBConstants::HASH_WORKPLACE_TYPES, values, filter, DBConstants::COL_WORKPLACE_ID);
}

int Controller::saveLine(){
    DB_TABLES tbl = DB_TABLES::LINE;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(QString::number(0));
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_LINE_NAME, lineView->getName());
    values.insert(DBConstants::COL_LINE_DESCRIPTION, lineView->getDescription());
    values.insert(DBConstants::COL_LINE_NUMBER_OF_WORKPLACES, lineView->getWorkplaceCount());
    values.insert(DBConstants::COL_LINE_FACTORY_ID, factory_ID);
    int lineID = dbHandler->save(tbl, DBConstants::HASH_LINE_TYPES, values, filter, DBConstants::COL_LINE_ID);
    saveRecordingObservesLine(lineID);
    updateLineView();
    return lineID;
}

void Controller::deleteLine(int id){
    deleteRecordingObservesLine(id);
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(QString::number(id));
    dbHandler->deleteAll(DB_TABLES::LINE, filter);
    filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_LINE_ID).arg(QString::number(id));
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_LINE_ID, 0);
    dbHandler->update(DB_TABLES::WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter);
    updateLineView();
}

//Product
void Controller::updateProductView(){
    productView->clear();
    DB_TABLES tbl = DB_TABLES::PRODUCT;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        productView->addProduct(record.value(DBConstants::COL_PRODUCT_ID).toInt(),
                            record.value(DBConstants::COL_PRODUCT_NAME).toString(),
                            record.value(DBConstants::COL_PRODUCT_NUMBER).toString(),
                            record.value(DBConstants::COL_PRODUCT_TOTAL_PERCENTAGE).toInt());
    }
}

void Controller::createProduct(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_PRODUCT_NAME, productView->getName());
    values.insert(DBConstants::COL_PRODUCT_NUMBER, productView->getNumber());
    values.insert(DBConstants::COL_PRODUCT_TOTAL_PERCENTAGE, productView->getTotalPercentage());
    dbHandler->insert(DB_TABLES::PRODUCT, DBConstants::HASH_PRODUCT_TYPES, values, DBConstants::COL_PRODUCT_ID);
    updateProductView();
}

void Controller::deleteProduct(int id){
    dbHandler->deleteAll(DB_TABLES::PRODUCT, QString("%1 = %2").arg(DBConstants::COL_PRODUCT_ID).arg(QString::number(id)));
    updateProductView();
}

//Equipment View
void Controller::updateEquipmentView(){
    equipmentView->clear();
    DB_TABLES tbl = DB_TABLES::EQUIPMENT;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        equipmentView->addEquipment(record.value(DBConstants::COL_EQUIPMENT_ID).toInt(),
                                    record.value(DBConstants::COL_EQUIPMENT_NAME).toString(),
                                    record.value(DBConstants::COL_EQUIPMENT_RECOIL_COUNT).toInt(),
                                    record.value(DBConstants::COL_EQUIPMENT_RECOIL_INTENSITY).toInt(),
                                    record.value(DBConstants::COL_EQUIPMENT_VIBRATION_COUNT).toInt(),
                                    record.value(DBConstants::COL_EQUIPMENT_VIBRATION_INTENSITY).toInt());
    }
}

void Controller::createEquipment(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_EQUIPMENT_NAME, equipmentView->getName());
    values.insert(DBConstants::COL_EQUIPMENT_RECOIL_COUNT, equipmentView->getRecoilCount());
    values.insert(DBConstants::COL_EQUIPMENT_RECOIL_INTENSITY, equipmentView->getRecoilIntensity());
    values.insert(DBConstants::COL_EQUIPMENT_VIBRATION_COUNT, equipmentView->getVibrationCount());
    values.insert(DBConstants::COL_EQUIPMENT_VIBRATION_INTENSITY, equipmentView->getVibrationIntensity());
    dbHandler->insert(DB_TABLES::EQUIPMENT, DBConstants::HASH_EQUIPMENT_TYPES, values, DBConstants::COL_EQUIPMENT_ID);
    updateEquipmentView();
}

void Controller::deleteEquipment(int id){
    dbHandler->deleteAll(DB_TABLES::EQUIPMENT, QString("%1 = %2").arg(DBConstants::COL_EQUIPMENT_ID).arg(id));
    updateEquipmentView();
}

void Controller::createEquipmentPopUp(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_EQUIPMENT_NAME, equipmentPopUp->getName());
    values.insert(DBConstants::COL_EQUIPMENT_RECOIL_COUNT, equipmentPopUp->getRecoilCount());
    values.insert(DBConstants::COL_EQUIPMENT_RECOIL_INTENSITY, equipmentPopUp->getRecoilIntensity());
    values.insert(DBConstants::COL_EQUIPMENT_VIBRATION_COUNT, equipmentPopUp->getVibrationCount());
    values.insert(DBConstants::COL_EQUIPMENT_VIBRATION_INTENSITY, equipmentPopUp->getVibrationIntensity());
    dbHandler->insert(DB_TABLES::EQUIPMENT, DBConstants::HASH_EQUIPMENT_TYPES, values, DBConstants::COL_EQUIPMENT_ID);
    viewCon->showMessage(tr("Created new Equipment"));
    viewCon->closePopUp();
}


//ActivityView
void Controller::updateActivityView(){
    activityView->clearProducts();
    DB_TABLES tbl = DB_TABLES::PRODUCT;
    dbHandler->select(tbl, QString(""));

    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        activityView->addProduct(record.value(DBConstants::COL_PRODUCT_ID).toInt(),
                                 record.value(DBConstants::COL_PRODUCT_NAME).toString(),
                                 record.value(DBConstants::COL_PRODUCT_NUMBER).toString());
    }
    updateActivityViewActivities();
}

void Controller::updateActivityViewActivities(){
    activityView->clearActivities();
    DB_TABLES tbl = DB_TABLES::ACTIVITY;
    dbHandler->select(tbl, QString(""));

    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        activityView->addActivity(record.value(DBConstants::COL_ACTIVITY_ID).toInt(),
                                  record.value(DBConstants::COL_ACTIVITY_DESCRIPTION).toString(),
                                  record.value(DBConstants::COL_ACTIVITY_REPETITIONS).toInt());
    }
}


void Controller::createActivity(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ACTIVITY_DESCRIPTION, activityView->getDescription());
    values.insert(DBConstants::COL_ACTIVITY_PRODUCT_ID, activityView->getSelectedProduct());
    values.insert(DBConstants::COL_ACTIVITY_REPETITIONS, activityView->getRepetitions());
    values.insert(DBConstants::COL_ACTIVITY_WORKPLACE_ID, workplace_ID);
    dbHandler->insert(DB_TABLES::ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, values, DBConstants::COL_ACTIVITY_ID);
    updateActivityViewActivities();
}

void Controller::deleteActivity(int id){
    dbHandler->deleteAll(DB_TABLES::ACTIVITY, QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_ID).arg(id));
    deleteWorkProcesses(id);
    updateActivityViewActivities();
}

void Controller::selectActivity(int id){
    activity_ID = id;
    workProcessTypeChanged(AVType::BASIC);
    updateGantView();
}

//CommentView
void Controller::updateComment(){
    DB_TABLES tbl = DB_TABLES::COMMENT;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(workplace_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    commentView->setComment(record.value(DBConstants::COL_COMMENT_PROBLEM_NAME).toString(),
                        record.value(DBConstants::COL_COMMENT_PROBLEM_DESCRIPTION).toString(),
                        record.value(DBConstants::COL_COMMENT_MEASURE_NAME).toString(),
                        record.value(DBConstants::COL_COMMENT_MEASURE_DESCRIPTION).toString(),
                        record.value(DBConstants::COL_COMMENT_WORKER_PERCEPTION).toString());
}

int Controller::saveComment(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(workplace_ID);

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_COMMENT_PROBLEM_NAME, commentView->getProblemName());
    values.insert(DBConstants::COL_COMMENT_PROBLEM_DESCRIPTION, commentView->getProblemDescription());
    values.insert(DBConstants::COL_COMMENT_MEASURE_NAME, commentView->getMeasureName());
    values.insert(DBConstants::COL_COMMENT_MEASURE_DESCRIPTION, commentView->getMeasureDescription());
    values.insert(DBConstants::COL_COMMENT_WORKER_PERCEPTION, commentView->getWorkerPerception());
    values.insert(DBConstants::COL_COMMENT_WORKPLACE_ID, workplace_ID);
    return dbHandler->save(DB_TABLES::COMMENT, DBConstants::HASH_COMMENT_TYPES, values, filter, DBConstants::COL_COMMENT_ID);
}

//TransportationView
void Controller::updateTransportationView(){
    transportationView->clear();
    DB_TABLES tbl = DB_TABLES::TRANSPORTATION;
    int count = dbHandler->select(tbl, QString(""));
    for(int i = 0; i < count; ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        transportationView->addTransportation(record.value(DBConstants::COL_TRANSPORTATION_ID).toInt(),
                                              record.value(DBConstants::COL_TRANSPORTATION_NAME).toString(),
                                              record.value(DBConstants::COL_TRANSPORTATION_EMPTY_WEIGHT).toInt(),
                                              record.value(DBConstants::COL_TRANSPORTATION_MAX_LOAD).toInt(),
                                              record.value(DBConstants::COL_TRANSPORTATION_FIXED_ROLLER).toBool(),
                                              record.value(DBConstants::COL_TRANSPORTATION_BRAKES).toBool());
    }
}

void Controller::createTransportation(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_TRANSPORTATION_NAME, transportationView->getName());
    values.insert(DBConstants::COL_TRANSPORTATION_EMPTY_WEIGHT, transportationView->getWeight());
    values.insert(DBConstants::COL_TRANSPORTATION_MAX_LOAD, transportationView->getMaxLoad());
    values.insert(DBConstants::COL_TRANSPORTATION_BRAKES, transportationView->hasBrakes());
    values.insert(DBConstants::COL_TRANSPORTATION_FIXED_ROLLER, transportationView->hasFixedRoller());
    dbHandler->insert(DB_TABLES::TRANSPORTATION, DBConstants::HASH_TRANSPORTATION_TYPES, values, DBConstants::COL_TRANSPORTATION_ID);
    updateTransportationView();
}

void Controller::deleteTransportation(int id){
    dbHandler->deleteAll(DB_TABLES::TRANSPORTATION, QString("%1 = %2").arg(DBConstants::COL_TRANSPORTATION_ID).arg(id));
    updateTransportationView();
}

//WORKPROCESS
int Controller::createWorkprocess(AVType type, const QTime &start, const QTime &end){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(type);

    int id = dbHandler->getNextID(DB_TABLES::WORK_PROCESS, DBConstants::COL_WORK_PROCESS_ID, filter);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORK_PROCESS_ID, id);
    values.insert(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID, activity_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_TYPE, type);
    values.insert(DBConstants::COL_WORK_PROCESS_BEGIN, start.toString());
    values.insert(DBConstants::COL_WORK_PROCESS_END, end.toString());
    dbHandler->insert(DB_TABLES::WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, DBConstants::COL_WORK_PROCESS_ID);
    gantTimerView->add(id, type, start, end);
    return id;
}


void Controller::setSelectedWorkProcess(int id , AVType type){
    saveCurrentWorkProcess();
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ID).arg(id).arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(type);

    DB_TABLES tbl = DB_TABLES::WORK_PROCESS;
    dbHandler->select(tbl, filter);
    if(dbHandler->rowCount(tbl) > 0){
        QSqlRecord record = dbHandler->record(tbl, 0);
        bodyPosture_ID = record.value(DBConstants::COL_WORK_PROCESS_POSTURE_ID).toInt();
        appliedforce_ID = record.value(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID).toInt();
        loadhandling_ID = record.value(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID).toInt();
        workcondition_ID = record.value(DBConstants::COL_WORK_PROCESS_CONDITION_ID).toInt();
        QTime duration = QTime(0,0).addSecs(record.value(DBConstants::COL_WORK_PROCESS_BEGIN).toTime().secsTo(record.value(DBConstants::COL_WORK_PROCESS_END).toTime()));
        workprocess_ID = id;
        workprocess_Type = type;
        timerViewController->setSelectedType(type);
        timerViewController->setSelectedAV(id, duration);
        updateBodyPostureView();
        updateAppliedForceView();
        updateLoadHandlingView();
        updateExecutionConditionView();
        updateWorkProcessMetaDataView();
        gantTimerView->setSelectedWorkProcess(id, type, record.value(DBConstants::COL_WORK_PROCESS_FREQUENCY).toInt());
        updateGantView();
    }
    else{
        timerViewController->setSelectedType(AVType::BASIC);
        timerViewController->setSelectedAV(0, QTime(0,0));
    }
}

void Controller::selectNextWorkProcess(){
    setSelectedWorkProcess(workprocess_ID + 1, workprocess_Type);
}

void Controller::selectPreviousWorkProcess(){
    setSelectedWorkProcess(workprocess_ID - 1, workprocess_Type);
}

void Controller::workProcessTypeChanged(AVType type){
    setSelectedWorkProcess(1, type);
}

void Controller::resetWorkProcesses(){
    deleteWorkProcesses(activity_ID);
    updateGantView();
}

void Controller::saveCurrentWorkProcess(){
    saveBodyPostureView();
    saveLoadHandlingView();
    saveAppliedForceView();
    saveExecutionConditionView();
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_ID).arg(workprocess_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type);

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORK_PROCESS_DESCRIPTION, workProcessMetaDataView->getDescription());
    values.insert(DBConstants::COL_WORK_PROCESS_FREQUENCY, gantTimerView->getFrequenz());
    values.insert(DBConstants::COL_WORK_PROCESS_MTM_CODE, workProcessMetaDataView->getMTMCode());
    values.insert(DBConstants::COL_WORK_PROCESS_WORKING_HEIGHT, workProcessMetaDataView->getWorkingHeight());
    values.insert(DBConstants::COL_WORK_PROCESS_DISTANCE, workProcessMetaDataView->getDistance());
    values.insert(DBConstants::COL_WORK_PROCESS_IMPULSE_COUNT, workProcessMetaDataView->getImpulseCount());
    values.insert(DBConstants::COL_WORK_PROCESS_IMPULSE_INTENSITY, workProcessMetaDataView->getImpulseIntensity());
    values.insert(DBConstants::COL_WORK_PROCESS_EQUIPMENT_ID, workProcessMetaDataView->getSelectedEquipment());
    values.insert(DBConstants::COL_WORK_PROCESS_POSTURE_ID, bodyPosture_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID, loadhandling_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID, appliedforce_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_CONDITION_ID, workcondition_ID);
    dbHandler->save(DB_TABLES::WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, filter);
}

void Controller::updateGantView(){
    gantTimerView->clear();
    QVector<QVariant> *leftWorkProcesses = new QVector<QVariant>();
    QVector<QVariant> *rightWorkProcesses = new QVector<QVariant>();
    QVector<QVariant> *basicWorkProcesses = new QVector<QVariant>();
    dbHandler->select(DB_TABLES::WORK_PROCESS, QString("%1 = %2").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID));
    for(int i = 0; i < dbHandler->rowCount(DB_TABLES::WORK_PROCESS); ++i){
        QSqlRecord record = dbHandler->record(DB_TABLES::WORK_PROCESS, i);
        int type = record.value(DBConstants::COL_WORK_PROCESS_TYPE).toInt();
        QVariant id = record.value(DBConstants::COL_WORK_PROCESS_ID);
        QVariant start = record.value(DBConstants::COL_WORK_PROCESS_BEGIN);
        QVariant end = record.value(DBConstants::COL_WORK_PROCESS_END);
        if(type == 1){
            leftWorkProcesses->append(id);
            leftWorkProcesses->append(start);
            leftWorkProcesses->append(end);
        }
        else if(type == 2){
            rightWorkProcesses->append(id);
            rightWorkProcesses->append(start);
            rightWorkProcesses->append(end);
        }
        else {
            basicWorkProcesses->append(id);
            basicWorkProcesses->append(start);
            basicWorkProcesses->append(end);
        }

    }
    gantTimerView->setWorkProcessLists(leftWorkProcesses, rightWorkProcesses, basicWorkProcesses);
    timerViewController->setWorkProcessLists(leftWorkProcesses, rightWorkProcesses, basicWorkProcesses);
}


// BodyPostureView
void Controller::updateBodyPostureView(){
    DB_TABLES tbl = DB_TABLES::BODY_POSTURE;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(bodyPosture_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    if(dbHandler->rowCount(tbl) == 0 && record.count() == 0){
        foreach(QString key, DBConstants::HASH_BODY_POSTURE_TYPES.keys())
            record.append(QSqlField(key, DBConstants::HASH_BODY_POSTURE_TYPES.value(key)));
    }
    bodyPostureView->setRecord(record);
}

void Controller::saveBodyPostureView(){
    DB_TABLES tbl = DB_TABLES::BODY_POSTURE;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(bodyPosture_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = bodyPostureView->getRecord();
    if(dbHandler->rowCount(tbl) == 0){
        int id = dbHandler->getNextID(tbl, DBConstants::COL_BODY_POSTURE_ID);
        record.setValue(DBConstants::COL_BODY_POSTURE_ID, id);
        dbHandler->insertRow(tbl, record);
        bodyPosture_ID = id;
    }
    else {
        dbHandler->updateRow(tbl, 0, record);
    }
    bodyPosture_ID = record.value(DBConstants::COL_BODY_POSTURE_ID).toInt();
}

// ExecutionConditionView
void Controller::updateExecutionConditionView(){
    DB_TABLES tbl = DB_TABLES::WORK_CONDITION;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(workcondition_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    executionConditionView->setArmSupports(record.value(DBConstants::COL_WORK_CONDITION_RIGHT_UPPER_ARM_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LEFT_UPPER_ARM_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_RIGHT_FOREARM_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LEFT_FOREARM_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_RIGHT_HAND_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LEFT_HAND_SUPPORTED).toInt());
    executionConditionView->setBodySupports(record.value(DBConstants::COL_WORK_CONDITION_HEAD_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_TRUNK_SUPPORT).toInt());
    executionConditionView->setLegSupports(record.value(DBConstants::COL_WORK_CONDITION_RIGHT_THIGH_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LEFT_THIGH_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_RIGHT_LOWER_LEG_SUPPORTED).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LEFT_LOWER_LEG_SUPPORTED).toInt());
    executionConditionView->setResultingConstraints((DBConstants::COL_WORK_CONDITION_GRIP_CONDITION).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_ACCESSIBILITY).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_GROUND).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_LIGHTING).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_CLIMATE).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_WIND).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_CLOTHING).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_ROOM_TO_MOVE).toInt());
    executionConditionView->setConditionAttributes((DBConstants::COL_WORK_CONDITION_PRECISION).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_VELOCITY).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_ACCELERATION).toInt(),
                        record.value(DBConstants::COL_WORK_CONDITION_VIBRATION).toInt());
}

void Controller::saveExecutionConditionView(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(workcondition_ID);

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORK_CONDITION_ACCELERATION, executionConditionView->getAcceleration());
    values.insert(DBConstants::COL_WORK_CONDITION_ACCESSIBILITY, executionConditionView->getAccessibility());
    values.insert(DBConstants::COL_WORK_CONDITION_CLIMATE, executionConditionView->getClimate());
    values.insert(DBConstants::COL_WORK_CONDITION_CLOTHING, executionConditionView->getClothing());
    values.insert(DBConstants::COL_WORK_CONDITION_GRIP_CONDITION, executionConditionView->getGraspingType());
    values.insert(DBConstants::COL_WORK_CONDITION_GROUND, executionConditionView->getGround());
    values.insert(DBConstants::COL_WORK_CONDITION_HEAD_SUPPORTED, executionConditionView->getHeadSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LEFT_FOREARM_SUPPORTED, executionConditionView->getLeftForearmSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LEFT_HAND_SUPPORTED, executionConditionView->getLeftHandSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LEFT_LOWER_LEG_SUPPORTED, executionConditionView->getLeftLowerLegSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LEFT_THIGH_SUPPORTED, executionConditionView->getLeftThighSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LEFT_UPPER_ARM_SUPPORTED, executionConditionView->getLeftUpperArmSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_LIGHTING, executionConditionView->getLighting());
    values.insert(DBConstants::COL_WORK_CONDITION_PRECISION, executionConditionView->getPrecision());
    values.insert(DBConstants::COL_WORK_CONDITION_RIGHT_FOREARM_SUPPORTED, executionConditionView->getRightForearmSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_RIGHT_HAND_SUPPORTED, executionConditionView->getRightHandSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_RIGHT_LOWER_LEG_SUPPORTED, executionConditionView->getRightLowerLegSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_RIGHT_THIGH_SUPPORTED, executionConditionView->getRightThighSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_RIGHT_UPPER_ARM_SUPPORTED, executionConditionView->getRightUpperArmSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_ROOM_TO_MOVE, executionConditionView->getRoomToMove());
    values.insert(DBConstants::COL_WORK_CONDITION_TRUNK_SUPPORT, executionConditionView->getTrunkSupport());
    values.insert(DBConstants::COL_WORK_CONDITION_VELOCITY, executionConditionView->getVelocity());
    values.insert(DBConstants::COL_WORK_CONDITION_VIBRATION, executionConditionView->getVibration());
    values.insert(DBConstants::COL_WORK_CONDITION_WIND, executionConditionView->getWind());
    values.insert(DBConstants::COL_WORK_CONDITION_ID, workcondition_ID);
    workcondition_ID = dbHandler->save(DB_TABLES::WORK_CONDITION, DBConstants::HASH_COMMENT_TYPES, values, filter, DBConstants::COL_WORK_CONDITION_ID);
}

// AppliedForceView
void Controller::updateAppliedForceView(){
    DB_TABLES tbl = DB_TABLES::APPLIED_FORCE;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(appliedforce_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    appliedForceView->setOrgan(record.value(DBConstants::COL_APPLIED_FORCE_ORGAN).toString());
    appliedForceView->setDirection(record.value(DBConstants::COL_APPLIED_FORCE_DIRECTION).toString());
    appliedForceView->setIntensity(record.value(DBConstants::COL_APPLIED_FORCE_INTENSITY).toInt());
}

void Controller::saveAppliedForceView(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(appliedforce_ID);

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_APPLIED_FORCE_ORGAN, appliedForceView->getOrgan());
    values.insert(DBConstants::COL_APPLIED_FORCE_DIRECTION, appliedForceView->getDirection());
    values.insert(DBConstants::COL_APPLIED_FORCE_INTENSITY, appliedForceView->getIntensity());
    values.insert(DBConstants::COL_APPLIED_FORCE_ID, appliedforce_ID);
    appliedforce_ID = dbHandler->save(DB_TABLES::APPLIED_FORCE, DBConstants::HASH_COMMENT_TYPES, values, filter, DBConstants::COL_APPLIED_FORCE_ID);
}

// LoadHandlingView
void Controller::updateLoadHandlingView(){
    DB_TABLES tbl = DB_TABLES::LOAD_HANDLING;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(loadhandling_ID);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    loadHandlingView->setGraspType(record.value(DBConstants::COL_LOAD_HANDLING_TYPE_OF_GRASPING).toString());
    loadHandlingView->setWeight(record.value(DBConstants::COL_LOAD_HANDLING_LOAD).toInt());
    loadHandlingView->setDistance(record.value(DBConstants::COL_LOAD_HANDLING_DISTANCE).toInt());
    int grasp_ID = record.value(DBConstants::COL_TYPE_OF_GRASPING_ID).toInt();
    int handlingType_ID = record.value(DBConstants::COL_LOAD_HANDLING_LOAD_HANDLING_TYPE_ID).toInt();
    int trans_ID = record.value(DBConstants::COL_LOAD_HANDLING_TRANSPORTATION_ID).toInt();

    tbl = DB_TABLES::LOAD_HANDLING_TYPE;
    dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_TYPE_ID).arg(handlingType_ID));
    record = dbHandler->record(tbl, 0);
    loadHandlingView->setHandlingType(record.value(DBConstants::COL_LOAD_HANDLING_TYPE_NAME).toString());

    tbl = DB_TABLES::TYPE_OF_GRASPING;
    dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_TYPE_OF_GRASPING_ID).arg(grasp_ID));
    record = dbHandler->record(tbl, 0);
    loadHandlingView->setGraspType(record.value(DBConstants::COL_TYPE_OF_GRASPING_NAME).toString());
    updateLoadHandlingTransportations();
    loadHandlingView->setSelectedTransportation(trans_ID);
}

void Controller::saveLoadHandlingView(){
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_TYPE_OF_GRASPING_NAME).arg(loadHandlingView->getGraspType());
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_TYPE_OF_GRASPING_NAME, loadHandlingView->getGraspType());
    int grasp_ID = dbHandler->save(DB_TABLES::TYPE_OF_GRASPING, DBConstants::HASH_TYPE_OF_GRASPING_TYPES, values, filter, DBConstants::COL_TYPE_OF_GRASPING_ID);

    filter = QString("%1 = '%2'").arg(DBConstants::COL_LOAD_HANDLING_TYPE_NAME).arg(loadHandlingView->getHandlingType());
    values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_LOAD_HANDLING_TYPE_NAME, loadHandlingView->getHandlingType());
    int loadHandlingType_ID = dbHandler->save(DB_TABLES::LOAD_HANDLING_TYPE, DBConstants::HASH_LOAD_HANDLING_TYPE_TYPES, values, filter, DBConstants::COL_LOAD_HANDLING_TYPE_ID);

    filter = QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(loadhandling_ID);
    values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_LOAD_HANDLING_TYPE_OF_GRASPING, grasp_ID);
    values.insert(DBConstants::COL_LOAD_HANDLING_LOAD_HANDLING_TYPE_ID, loadHandlingType_ID);
    values.insert(DBConstants::COL_LOAD_HANDLING_TRANSPORTATION_ID, loadHandlingView->getSelectedTransportation());
    values.insert(DBConstants::COL_LOAD_HANDLING_LOAD, loadHandlingView->getWeight());
    values.insert(DBConstants::COL_LOAD_HANDLING_DISTANCE, loadHandlingView->getDistance());
    loadhandling_ID = dbHandler->save(DB_TABLES::LOAD_HANDLING, DBConstants::HASH_LOAD_HANDLING_TYPES, values, filter, DBConstants::COL_LOAD_HANDLING_ID);
}

void Controller::updateLoadHandlingTransportations(){
    loadHandlingView->clearTransportation();
    DB_TABLES tbl = DB_TABLES::TRANSPORTATION;
    dbHandler->select(tbl, "");
    QSqlRecord record;
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        record = dbHandler->record(tbl, i);
        loadHandlingView->addTransportation(record.value(DBConstants::COL_TRANSPORTATION_ID).toInt(),
                                            record.value(DBConstants::COL_TRANSPORTATION_NAME).toString(),
                                            record.value(DBConstants::COL_TRANSPORTATION_EMPTY_WEIGHT).toInt(),
                                            record.value(DBConstants::COL_TRANSPORTATION_MAX_LOAD).toInt(),
                                            record.value(DBConstants::COL_TRANSPORTATION_BRAKES).toBool(),
                                            record.value(DBConstants::COL_TRANSPORTATION_FIXED_ROLLER).toBool());
    }
}

//WorkProcessMetaDataView
void Controller::updateWorkProcessMetaDataView(){
    DB_TABLES tbl = DB_TABLES::WORK_PROCESS;
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_POSTURE_ID).arg(workprocess_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type);
    dbHandler->select(tbl, filter);
    QSqlRecord record = dbHandler->record(tbl, 0);
    workProcessMetaDataView->setWorkProcessMetaData(record.value(DBConstants::COL_WORK_PROCESS_DESCRIPTION).toString(),
                                                    record.value(DBConstants::COL_WORK_PROCESS_MTM_CODE).toString(),
                                                    record.value(DBConstants::COL_WORK_PROCESS_WORKING_HEIGHT).toInt(),
                                                    record.value(DBConstants::COL_WORK_PROCESS_DISTANCE).toInt(),
                                                    record.value(DBConstants::COL_WORK_PROCESS_IMPULSE_INTENSITY).toInt(),
                                                    record.value(DBConstants::COL_WORK_PROCESS_IMPULSE_COUNT).toInt());
    updateWorkProcessMetaDataEquipment();
    workProcessMetaDataView->setSelectedEquipment(record.value(DBConstants::COL_WORK_PROCESS_EQUIPMENT_ID).toInt());
}

void Controller::updateWorkProcessMetaDataEquipment(){
    workProcessMetaDataView->clearEquipment();
    DB_TABLES tbl = DB_TABLES::EQUIPMENT;
    dbHandler->select(tbl, QString(""));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        workProcessMetaDataView->addEquipment(record.value(DBConstants::COL_EQUIPMENT_ID).toInt(),
                                              record.value(DBConstants::COL_EQUIPMENT_NAME).toString(),
                                              record.value(DBConstants::COL_EQUIPMENT_RECOIL_COUNT).toInt(),
                                              record.value(DBConstants::COL_EQUIPMENT_RECOIL_INTENSITY).toInt(),
                                              record.value(DBConstants::COL_EQUIPMENT_VIBRATION_COUNT).toInt(),
                                              record.value(DBConstants::COL_EQUIPMENT_VIBRATION_INTENSITY).toInt());
    }
}

// Documentation View Ressource Lists
void Controller::updateDocumentationViewRessources(){
    updateLoadHandlingTransportations();
    updateWorkProcessMetaDataEquipment();
}



void Controller::resetDatabase(){
    analyst_ID = 0;
    recording_ID = 1;
    workplace_ID = 0;
    workcondition_ID = 0;
    factory_ID = 0;
    activity_ID = 0;
    appliedforce_ID = 0;
    loadhandling_ID = 0;
    workprocess_Type = AVType::BASIC;
    workprocess_ID = 0;
    QString emptyFilter = QString("");
    dbHandler->deleteAll(DB_TABLES::ACTIVITY, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::ANALYST, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::APPLIED_FORCE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::BODY_POSTURE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::BRANCH_OF_INDUSTRY, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::BREAK, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::COMMENT, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::CORPORATION, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::EMPLOYEE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::EMPLOYEE_WORKS_SHIFT, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::EMPLOYER, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::EQUIPMENT, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::FACTORY, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::LINE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::LOAD_HANDLING, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::LOAD_HANDLING_TYPE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::PRODUCT, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::RECORDING, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::RECORDING_OBSERVES_LINE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::RECORDING_OBSERVES_WORKPLACE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::SHIFT, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::TRANSPORTATION, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::TYPE_OF_GRASPING, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::WORKPLACE, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::WORK_CONDITION, emptyFilter);
    dbHandler->deleteAll(DB_TABLES::WORK_PROCESS, emptyFilter);
}

//PRIVATE METHODS

void Controller::saveRecordingObservesLine(int lineID){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_RECORDING_OB_LINE_RECORDING_ID).arg(QString::number(recording_ID)).arg(DBConstants::COL_RECORDING_OB_LINE_LINE_ID).arg(QString::number(lineID));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_RECORDING_OB_LINE_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_RECORDING_OB_LINE_LINE_ID, lineID);
    dbHandler->save(DB_TABLES::RECORDING_OBSERVES_LINE, DBConstants::HASH_RECORDING_OB_LINE_TYPES, values, filter);
}

void Controller::deleteRecordingObservesLine(int lineID){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_OB_LINE_LINE_ID).arg(QString::number(lineID));
    dbHandler->deleteAll(DB_TABLES::RECORDING_OBSERVES_LINE, filter);
}

void Controller::saveRecordingObservesWorkplace(int workplaceID){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_RECORDING_OB_WORKPLACE_RECORDING_ID).arg(QString::number(recording_ID)).arg(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID).arg(QString::number(workplaceID));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_RECORDING_OB_WORKPLACE_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID, workplaceID);
    dbHandler->save(DB_TABLES::RECORDING_OBSERVES_WORKPLACE, DBConstants::HASH_RECORDING_OB_WORKPLACE_TYPES, values, filter);
}

void Controller::deleteRecordingOberservesWorkplace(int wpID){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID).arg(QString::number(wpID));
    dbHandler->deleteAll(DB_TABLES::RECORDING_OBSERVES_WORKPLACE, filter);
}

int Controller::saveWorkplace(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(QString::number(id));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_NAME, workplaceView->getName());
    values.insert(DBConstants::COL_WORKPLACE_DESCRIPTION, workplaceView->getDescription());
    values.insert(DBConstants::COL_WORKPLACE_CODE, workplaceView->getCode());
    values.insert(DBConstants::COL_WORKPLACE_PERCENTAGE_WOMAN, workplaceView->getWomanPercentage());
    values.insert(DBConstants::COL_WORKPLACE_BASIC_TIME, qTimeToSeconds(workplaceView->getBasicTime()));
    values.insert(DBConstants::COL_WORKPLACE_REST_TIME, qTimeToSeconds(workplaceView->getRestTime()));
    values.insert(DBConstants::COL_WORKPLACE_ALLOWANCE_TIME, qTimeToSeconds(workplaceView->getAllowanceTime()));
    values.insert(DBConstants::COL_WORKPLACE_SETUP_TIME, qTimeToSeconds(workplaceView->getSetupTime()));
    values.insert(DBConstants::COL_WORKPLACE_CYCLE_TIME, qTimeToSeconds(workplaceView->getCycleTime()));
    return dbHandler->save(DB_TABLES::WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter, DBConstants::COL_WORKPLACE_ID);
}

int Controller::qTimeToSeconds(const QTime &time){
    return time.hour() * 3600 + time.minute() * 60 + time.second();
}

void Controller::deleteWorkProcesses(int activity_ID){
    DB_TABLES tbl = DB_TABLES::WORK_PROCESS;
    dbHandler->select(tbl, QString("%1 = %2").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID));
    for(int i = 0; i < dbHandler->rowCount(tbl); ++i){
        QSqlRecord record = dbHandler->record(tbl, i);
        dbHandler->deleteAll(DB_TABLES::BODY_POSTURE, QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(record.value(DBConstants::COL_WORK_PROCESS_POSTURE_ID).toInt()));
        dbHandler->deleteAll(DB_TABLES::APPLIED_FORCE, QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(record.value(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID).toInt()));
        dbHandler->deleteAll(DB_TABLES::LOAD_HANDLING, QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(record.value(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID).toInt()));
        dbHandler->deleteAll(DB_TABLES::WORK_CONDITION, QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(record.value(DBConstants::COL_WORK_PROCESS_CONDITION_ID).toInt()));
        dbHandler->deleteRow(tbl, i);
    }
}



