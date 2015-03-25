#include "controller.h"

Controller::Controller(QObject *parent, QApplication *app) :
    QObject(parent),
    application(app),
    analyst_ID(0),
    recording_ID(0),
    factory_ID(0),
    workplace_ID(0),
    workcondition_ID(0),
    workprocess_ID(0),
    workprocess_Type(AVType::BASIC),
    activity_ID(0),
    appliedforce_ID(0),
    loadhandling_ID(0),
    bodyPosture_ID(0),
    employee_ID(0),
    bodyMeasurement_ID(0),
    selectedEmployee_ID(0),
    shift_ID(0),
    rotationGroup_ID(0),
    rotationGroupTask_ID(0)

{
    //Initialisation of the database
    QFileInfo databaseFileInfo = QFileInfo(StandardPaths::databasePath());
    QString databaseOriginPath = StandardPaths::originDatabasePath();
    QString databasePath = databaseFileInfo.absoluteFilePath();

    //Copy database from the readOnly location to the writeable location,
    //if the database does not exsist yet.
    if ( !databaseFileInfo.exists() ){
       bool copySuccess = QFile::copy( databaseOriginPath, databasePath );
       if ( !copySuccess ){
           QString errorMessage = QString("Could not copy database from \n %1 to \n %2").arg(databaseOriginPath).arg(databasePath);
           ErrorReporter::reportError(errorMessage);
           emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
           databasePath.clear();
       }
       else{
            if(!QFile::setPermissions(databasePath,QFile::WriteOwner | QFile::ReadOwner)){
                QString errorMessage = QString("Could not set read/write permissions on %1").arg(databasePath);
                ErrorReporter::reportError(errorMessage);
                emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
            }
       }
    }
    dbHandler = new DBHandler(databasePath);

    //Register all tables on the dbHandler
    QList<QString> tblNames = DBConstants::LIST_TABLE_NAMES;
    for(int i = 0; i < tblNames.size(); ++i)
        dbHandler->registerTable(tblNames.at(i));
}

Controller::~Controller(){
    Settings::saveSettings(StandardPaths::configFile());
}

void Controller::initialize(){
    //Initialize the data that is available by default
    initializeAnalysts();
    initializeProducts();
    initializeTansportations();
    initializeEquipments();
    initializeEmployees();
    initializeLines();
    initializeWorkplaces();
    initializeRotationGroupTasks();
}

//PRIVATE SLOTS

//Analyst
void Controller::initializeAnalysts(){
    emit clearAnalysts();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_ANALYST, QString(""));
    for(int i = 0; i < rows.size(); ++i)
        emit createdAnalyst(rows.at(i));
}

void Controller::createAnalyst(QHash<QString, QVariant> values){
    QString empName = values.value(DBConstants::COL_EMPLOYER_NAME).toString();
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_EMPLOYER_NAME).arg(empName);
    QHash<QString, QVariant> valuesEmployer = QHash<QString, QVariant>();
    valuesEmployer.insert(DBConstants::COL_EMPLOYER_NAME, empName);
    int emp_ID = dbHandler->save(DBConstants::TBL_EMPLOYER, DBConstants::HASH_EMPLOYER_TYPES, valuesEmployer, filter, DBConstants::COL_EMPLOYER_ID);

    values.remove(DBConstants::COL_EMPLOYER_NAME);
    values.insert(DBConstants::COL_ANALYST_EMPLOYER_ID, emp_ID);
    dbHandler->insert(DBConstants::TBL_ANALYST, DBConstants::HASH_ANALYST_TYPES, values, DBConstants::COL_ANALYST_ID);
    emit showMessage(tr("Created analyst"));
    emit createdAnalyst(values);
}

void Controller::deleteAnalyst(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ANALYST_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_ANALYST, filter);
    emit showMessage(tr("Deleted analyst"));
    emit removedAnalyst(id);
}

void Controller::selectAnalyst(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ANALYST_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_ANALYST, filter);
    analyst_ID = id;
    emit showMessage(tr("Hello  ") + dbHandler->select(DBConstants::TBL_ANALYST, QString("")).
                         at(id -1).value(DBConstants::COL_ANALYST_FIRSTNAME).toString() + "! ",
                         NotificationMessage::WELCOME, NotificationMessage::LONG);
    emit selectedAnalyst(values);
    filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_ANALYST_ID).arg(analyst_ID);
    QHash<QString, QVariant> recValues = dbHandler->selectFirst(DBConstants::TBL_RECORDING, filter);
    int recID = 0;
    if(recValues.isEmpty()){
        recValues.insert(DBConstants::COL_RECORDING_ANALYST_ID, analyst_ID);
        recID = dbHandler->insert(DBConstants::TBL_RECORDING, DBConstants::HASH_RECORDING_TYPES, recValues, DBConstants::COL_RECORDING_ID);
    }
    else
        recID = recValues.value(DBConstants::COL_RECORDING_ID).toInt();
    setRecording(recID);
}


//MainMenuView
void Controller::createBlankRecording(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_NAME, tr("Autogenerated workplace"));
    workplace_ID = dbHandler->insert(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, DBConstants::COL_WORKPLACE_ID);
    emit createdWorkplace(values);
    values.clear();
    values.insert(DBConstants::COL_ACTIVITY_DESCRIPTION, tr("Autogenerated activity"));
    values.insert(DBConstants::COL_ACTIVITY_WORKPLACE_ID, workplace_ID);
    activity_ID = dbHandler->insert(DBConstants::TBL_ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, values, DBConstants::COL_ACTIVITY_ID);

    QList<ViewType> prevViews = QList<ViewType>();
    prevViews.append(ViewType::WORKPLACE_VIEW);
    prevViews.append(ViewType::ACTIVITY_VIEW);

    selectWorkplace(workplace_ID);
    selectActivity(activity_ID);
    emit showView(ViewType::DOCUMENTATION_VIEW, &prevViews);
}


//BranchOfIndustry
void Controller::setBranchOfIndustry(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BRANCH_OF_INDUSTRY_ID).arg(id);
    QHash<QString, QVariant> boiValues = dbHandler->selectFirst(DBConstants::TBL_BRANCH_OF_INDUSTRY, filter);
    if(!boiValues.isEmpty())
        emit settedBranchOfIndustry(boiValues);
}

void Controller::saveBranchOfIndustry(QHash<QString, QVariant> values){
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).arg(values.value(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).toString());
    dbHandler->save(DBConstants::TBL_BRANCH_OF_INDUSTRY, DBConstants::HASH_BRANCH_OF_INDUSTRY_TYPES, values, filter, DBConstants::COL_BRANCH_OF_INDUSTRY_ID);
}

//Corperation
void Controller::setCorperation(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_CORPORATION_ID).arg(id);
    QHash<QString, QVariant> corpValues = dbHandler->selectFirst(DBConstants::TBL_CORPORATION, filter);
    if(!corpValues.isEmpty()){
        emit settedCorperation(corpValues);
        int boiID = corpValues.value(DBConstants::COL_CORPORATION_BRANCH_OF_INDUSTRY_ID).toInt();
        if(boiID > 0)
            setBranchOfIndustry(boiID);
    }
}

void Controller::saveCorperation(QHash<QString, QVariant> values){
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).arg(values.value(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME).toString());
    QHash<QString, QVariant> boiValues = dbHandler->selectFirst(DBConstants::TBL_BRANCH_OF_INDUSTRY, filter);
    values.insert(DBConstants::COL_CORPORATION_BRANCH_OF_INDUSTRY_ID, boiValues.value(DBConstants::COL_BRANCH_OF_INDUSTRY_ID));
    values.remove(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME);
    filter = QString("%1 = '%2'").arg(DBConstants::COL_CORPORATION_NAME).arg(values.value(DBConstants::COL_CORPORATION_NAME).toString());
    dbHandler->save(DBConstants::TBL_CORPORATION, DBConstants::HASH_CORPORATION_TYPES, values, filter, DBConstants::COL_CORPORATION_ID);
}

//Factory
void Controller::setFactory(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_FACTORY_ID).arg(id);
    QHash<QString, QVariant> factoryValues = dbHandler->selectFirst(DBConstants::TBL_FACTORY, filter);
    if(!factoryValues.isEmpty()){
        factory_ID = id;
        emit settedFactory(factoryValues);
        int corpID = factoryValues.value(DBConstants::COL_FACTORY_CORPORATION_ID).toInt();
        if(corpID > 0)
            setCorperation(corpID);
    }

}

void Controller::saveFactory(QHash<QString, QVariant> values){
    QString filter = QString("%3 = '%4'").arg(DBConstants::COL_CORPORATION_NAME).arg(values.value(DBConstants::COL_CORPORATION_NAME).toString());
    QHash<QString, QVariant> corpValues = dbHandler->selectFirst(DBConstants::TBL_CORPORATION, filter);
    if(!corpValues.isEmpty())
        values.insert(DBConstants::COL_FACTORY_CORPORATION_ID, corpValues.value(DBConstants::COL_CORPORATION_ID));
    values.remove(DBConstants::COL_CORPORATION_NAME);
    filter = QString("%1 = '%2' AND %3 = '%4'").arg(DBConstants::COL_FACTORY_NAME).arg(values.value(DBConstants::COL_FACTORY_NAME).toString()).arg(DBConstants::COL_FACTORY_STREET).arg(values.value(DBConstants::COL_FACTORY_STREET).toString());
    dbHandler->save(DBConstants::TBL_FACTORY, DBConstants::HASH_FACTORY_TYPES, values, filter, DBConstants::COL_FACTORY_ID);
}

//Recording
void Controller::setRecording(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_ID).arg(id);
    QHash<QString, QVariant> recordValues = dbHandler->selectFirst(DBConstants::TBL_RECORDING, filter);
    if(!recordValues.isEmpty()){
        recording_ID = id;
        emit settedRecording(recordValues);
        int factoryID = recordValues.value(DBConstants::COL_RECORDING_FACTORY_ID).toInt();
        if(factoryID > 0)
            setFactory(factoryID);
        filter = QString("%1 = %2").arg(DBConstants::COL_SHIFT_RECORDING_ID).arg(recording_ID);
        QHash<QString, QVariant> shiftValues = dbHandler->selectFirst(DBConstants::TBL_SHIFT, filter);
        int shift_ID = shiftValues.value(DBConstants::COL_SHIFT_ID).toInt();
        initializeShift(shift_ID);
    }
}

void Controller::saveRecording(QHash<QString, QVariant> values){
    QString filter = QString("%1 = '%2' AND %3 = '%4'").arg(DBConstants::COL_FACTORY_NAME).arg(values.value(DBConstants::COL_FACTORY_NAME).toString()).arg(DBConstants::COL_FACTORY_STREET).arg(values.value(DBConstants::COL_FACTORY_STREET).toString());
    QHash<QString, QVariant> factoryValues = dbHandler->selectFirst(DBConstants::TBL_FACTORY, filter);
    if(!factoryValues.isEmpty())
        values.insert(DBConstants::COL_RECORDING_FACTORY_ID, factoryValues.value(DBConstants::COL_FACTORY_ID));
    values.remove(DBConstants::COL_FACTORY_NAME);
    values.remove(DBConstants::COL_FACTORY_STREET);
    values.insert(DBConstants::COL_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_RECORDING_ANALYST_ID, analyst_ID);
    filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_ID).arg(recording_ID);
    dbHandler->save(DBConstants::TBL_RECORDING, DBConstants::HASH_RECORDING_TYPES, values, filter, DBConstants::COL_RECORDING_ID);
    emit showMessage(tr("Saved meta data"));
}

//WorkplaceView
void Controller::initializeWorkplaces(){
    emit clearWorkplaces();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_WORKPLACE, QString(""));
    for(int i = 0; i < rows.count(); ++i)
        emit createdWorkplace(rows.at(i));
}

void Controller::createWorkplace(QHash<QString, QVariant> values){
    int wp_ID = dbHandler->insert(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, DBConstants::COL_WORKPLACE_ID);
    values.insert(DBConstants::COL_WORKPLACE_ID, wp_ID);
    emit createdWorkplace(values);
    saveRecordingObservesWorkplace(wp_ID);
    emit showMessage(tr("Created new workplace"));
}

void Controller::createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues){
    int workplace_ID = dbHandler->insert(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values,DBConstants::COL_WORKPLACE_ID);
    values.insert(DBConstants::COL_WORKPLACE_ID, workplace_ID);
    emit createdWorkplace(values);
    for(int i = 0; i < activityValues.size(); ++i){
        QHash<QString, QVariant> curValues = activityValues.at(i);
        if(curValues.contains(DBConstants::COL_PRODUCT_NAME)){
            QString filter = QString("%1 = '%2'").arg(DBConstants::COL_PRODUCT_NAME).arg(curValues.value(DBConstants::COL_PRODUCT_NAME).toString());
            QHash<QString, QVariant> productValues = dbHandler->selectFirst(DBConstants::TBL_PRODUCT, filter);
            if(!productValues.isEmpty()){
                curValues.insert(DBConstants::COL_ACTIVITY_PRODUCT_ID, productValues.value(DBConstants::COL_PRODUCT_ID));
            }
            curValues.remove(DBConstants::COL_PRODUCT_NAME);
        }
        curValues.insert(DBConstants::COL_ACTIVITY_WORKPLACE_ID, workplace_ID);
        dbHandler->insert(DBConstants::TBL_ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, curValues, DBConstants::COL_ACTIVITY_ID);
    }
}

void Controller::deleteWorkplace(int id){
    QString tbl = DBConstants::TBL_WORKPLACE;
    dbHandler->remove(tbl, QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(QString::number(id)));

    deleteRecordingOberservesWorkplace(id);

    QList<QHash<QString, QVariant>> values = dbHandler->select(DBConstants::TBL_ACTIVITY, QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_WORKPLACE_ID).arg(id));
    for(int i = 0; i < values.count(); ++i)
        deleteActivity(values.at(i).value(DBConstants::COL_ACTIVITY_ID).toInt(), false);

    dbHandler->remove(DBConstants::TBL_COMMENT, QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(id));

    emit showMessage(tr("Deleted workplace"));

    emit removedWorkplace(id);
}

void Controller::selectWorkplace(int id){
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_WORKPLACE, QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(id));
    workplace_ID = id;
    emit selectedWorkplace(values);
    selectedEmployee_ID = values.value(DBConstants::COL_WORKPLACE_EMPLOYEE_ID).toInt();
    emit employeeSelected(selectedEmployee_ID);
    values = dbHandler->selectFirst(DBConstants::TBL_LINE, QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(values.value(DBConstants::COL_WORKPLACE_LINE_ID).toInt()));
    emit selectedLine(values);
    values = dbHandler->selectFirst(DBConstants::TBL_COMMENT, QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(workplace_ID));
    emit selectedComment(values);
    initializeActivities(id);
}

void Controller::saveWorkplace(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(workplace_ID);
    values.insert(DBConstants::COL_WORKPLACE_ID, workplace_ID);
    values.insert(DBConstants::COL_WORKPLACE_EMPLOYEE_ID, selectedEmployee_ID);
    dbHandler->update(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter);
    emit updatedWorkplace(values);
}

//Comment
void Controller::saveComment(QHash<QString, QVariant> values){
    values.insert(DBConstants::COL_COMMENT_WORKPLACE_ID, workplace_ID);
    QString filter = QString("%1 = %2").arg(DBConstants::COL_COMMENT_WORKPLACE_ID).arg(workplace_ID);
    dbHandler->save(DBConstants::TBL_COMMENT, DBConstants::HASH_COMMENT_TYPES, values, filter, DBConstants::COL_COMMENT_ID);
    emit updatedComment(values);
}

//Line
void Controller::initializeLines(){
    emit clearLines();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_LINE, QString(""));
    for(int i = 0; i < rows.count(); ++i)
        emit createdLine(rows.at(i));
}


void Controller::createLine(QHash<QString, QVariant> values){
    values.insert(DBConstants::COL_LINE_FACTORY_ID, factory_ID);
    int line_ID = dbHandler->insert(DBConstants::TBL_LINE, DBConstants::HASH_LINE_TYPES, values, DBConstants::COL_LINE_ID);
    values.insert(DBConstants::COL_LINE_ID, line_ID);
    saveRecordingObservesLine(line_ID);
    emit createdLine(values);
    emit showMessage(tr("Created new line"));
}

void Controller::editLine(int id){
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_LINE, QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(id));
    emit editLine(values);
}

void Controller::saveLine(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(values.value(DBConstants::COL_LINE_ID).toInt());
    dbHandler->update(DBConstants::TBL_LINE, DBConstants::HASH_LINE_TYPES, values, filter);
    emit updatedLine(values);
}

void Controller::deleteLine(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_LINE, filter);
    deleteRecordingObservesLine(id);
    emit removedLine(id);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_LINE_ID, 0);
    filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_LINE_ID).arg(id);
    dbHandler->update(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter);
    emit showMessage(tr("Deleted line"));
}

void Controller::selectLine(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_LINE_ID).arg(id);
    QHash<QString, QVariant> lineValues = dbHandler->selectFirst(DBConstants::TBL_LINE, filter);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORKPLACE_LINE_ID, id);
    filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(workplace_ID);
    dbHandler->update(DBConstants::TBL_WORKPLACE, DBConstants::HASH_WORKPLACE_TYPES, values, filter);
    selectedLine(lineValues);
}

//Product
void Controller::initializeProducts(){
    emit clearProducts();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_PRODUCT, QString(""));
    for(int i = 0; i < rows.count(); ++i)
        emit createdProduct(rows.at(i));
}

void Controller::createProduct(QHash<QString, QVariant> values){
    int prod_ID = dbHandler->insert(DBConstants::TBL_PRODUCT, DBConstants::HASH_PRODUCT_TYPES, values, DBConstants::COL_PRODUCT_ID);
    values.insert(DBConstants::COL_PRODUCT_ID, prod_ID);
    emit createdProduct(values);
    emit showMessage(tr("Created new product"));
}

void Controller::saveProduct(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_PRODUCT_ID).arg(values.value(DBConstants::COL_PRODUCT_ID).toInt());
    dbHandler->update(DBConstants::TBL_PRODUCT, DBConstants::HASH_PRODUCT_TYPES, values, filter);
    emit updatedProduct(values);
}


void Controller::deleteProduct(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_PRODUCT_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_PRODUCT, filter);
    emit removedProduct(id);
    filter = QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_PRODUCT_ID).arg(id);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ACTIVITY_PRODUCT_ID, 0);
    dbHandler->update(DBConstants::TBL_ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, values, filter);
    emit showMessage(tr("Deleted product"));
}

//Equipment
void Controller::initializeEquipments(){
    emit clearEquipments();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_EQUIPMENT, QString(""));
    for(int i = 0; i < rows.count(); ++i)
        emit createdEquipment(rows.at(i));
}

void Controller::createEquipment(QHash<QString, QVariant> values){
    int eq_ID = dbHandler->insert(DBConstants::TBL_EQUIPMENT, DBConstants::HASH_EQUIPMENT_TYPES, values, DBConstants::COL_EQUIPMENT_ID);
    values.insert(DBConstants::COL_EQUIPMENT_ID, eq_ID);
    emit createdEquipment(values);
    emit showMessage(tr("Created new equipment"));
}

void Controller::saveEquipment(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EQUIPMENT_ID).arg(values.value(DBConstants::COL_EQUIPMENT_ID).toString());
    dbHandler->update(DBConstants::TBL_EQUIPMENT, DBConstants::HASH_EQUIPMENT_TYPES, values, filter);
    emit updatedEquipment(values);
}

void Controller::deleteEquipment(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EQUIPMENT_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_EQUIPMENT, filter);
    emit removedEquipment(id);
    emit showMessage(tr("Deleted equipment"));
}

//Activity
void Controller::initializeActivities(int workplace_ID){
    emit clearActivities();
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_WORKPLACE_ID).arg(workplace_ID);
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_ACTIVITY, filter);
    for(int i = 0; i < rows.count(); ++i)
        emit createdActivity(rows.at(i));
}

void Controller::createActivity(QHash<QString, QVariant> values){
   values.insert(DBConstants::COL_ACTIVITY_WORKPLACE_ID, workplace_ID);
   int ac_ID = dbHandler->insert(DBConstants::TBL_ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, values, DBConstants::COL_ACTIVITY_ID);
   values.insert(DBConstants::COL_ACTIVITY_ID, ac_ID);
   emit createdActivity(values);
   emit showMessage(tr("Created new activity"));
}

void Controller::saveActivity(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_ID).arg(values.value(DBConstants::COL_ACTIVITY_ID).toInt());
    values.insert(DBConstants::COL_ACTIVITY_WORKPLACE_ID, workplace_ID);
    dbHandler->update(DBConstants::TBL_ACTIVITY, DBConstants::HASH_ACTIVITY_TYPES, values, filter);
    emit updatedActivity(values);
}

void Controller::deleteActivity(int id, bool showMsg){
    dbHandler->remove(DBConstants::TBL_ACTIVITY, QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_ID).arg(id));
    deleteWorkProcesses(id);
    emit removedActivity(id);
    if(showMsg)
        emit showMessage(tr("Deleted activity"));
}

void Controller::selectActivity(int id){
    activity_ID = id;
    initilizeWorkProcesses();
}

void Controller::editActivity(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ACTIVITY_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_ACTIVITY, filter);
    emit editActivity(values);
}


//Transportation
void Controller::initializeTansportations(){
    emit clearTransportations();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_TRANSPORTATION, QString(""));
    for(int i = 0; i < rows.count(); ++i)
        emit createdTransportation(rows.at(i));
}

void Controller::createTransportation(QHash<QString, QVariant> values){
    int trans_ID = dbHandler->insert(DBConstants::TBL_TRANSPORTATION, DBConstants::HASH_TRANSPORTATION_TYPES, values, DBConstants::COL_TRANSPORTATION_ID);
    values.insert(DBConstants::COL_TRANSPORTATION_ID, trans_ID);
    emit createdTransportation(values);
    emit showMessage(tr("Created new transportation"));
}

void Controller::saveTransportation(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_TRANSPORTATION_ID).arg(values.value(DBConstants::COL_TRANSPORTATION_ID).toString());
    dbHandler->update(DBConstants::TBL_TRANSPORTATION, DBConstants::HASH_TRANSPORTATION_TYPES, values, filter);
    emit updatedTransportation(values);
}

void Controller::deleteTransportation(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_TRANSPORTATION_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_TRANSPORTATION, filter);
    emit removedTransportation(id);
    emit showMessage(tr("Deleted transportation"));
}

//LoadHandling
void Controller::saveLoadHandling(QHash<QString, QVariant> values){
    QString filter = QString("%1 = '%2'").arg(DBConstants::COL_LOAD_HANDLING_TYPE_NAME).arg(values.value(DBConstants::COL_LOAD_HANDLING_TYPE_NAME).toString());
    QHash<QString, QVariant> loadType = dbHandler->selectFirst(DBConstants::TBL_LOAD_HANDLING_TYPE, filter);
    if(loadType.isEmpty()){
        loadType.insert(DBConstants::COL_LOAD_HANDLING_TYPE_NAME, values.value(DBConstants::COL_LOAD_HANDLING_TYPE_NAME).toString());
        int lt_ID = dbHandler->insert(DBConstants::TBL_LOAD_HANDLING_TYPE, DBConstants::HASH_LOAD_HANDLING_TYPE_TYPES, loadType, DBConstants::COL_LOAD_HANDLING_TYPE_ID);
        loadType.insert(DBConstants::COL_LOAD_HANDLING_TYPE_ID, lt_ID);
    }
    values.insert(DBConstants::COL_LOAD_HANDLING_LOAD_HANDLING_TYPE_ID, loadType.value(DBConstants::COL_LOAD_HANDLING_TYPE_ID));
    values.remove(DBConstants::COL_LOAD_HANDLING_TYPE_NAME);

    filter = QString("%1 = '%2'").arg(DBConstants::COL_TYPE_OF_GRASPING_NAME).arg(values.value(DBConstants::COL_TYPE_OF_GRASPING_NAME).toString());
    QHash<QString, QVariant> graspType = dbHandler->selectFirst(DBConstants::TBL_TYPE_OF_GRASPING, filter);
    if(graspType.isEmpty()){
        graspType.insert(DBConstants::COL_TYPE_OF_GRASPING_NAME, values.value(DBConstants::COL_TYPE_OF_GRASPING_NAME).toString());
        int gt_ID = dbHandler->insert(DBConstants::TBL_TYPE_OF_GRASPING, DBConstants::HASH_TYPE_OF_GRASPING_TYPES, graspType, DBConstants::COL_TYPE_OF_GRASPING_ID);
        graspType.insert(DBConstants::COL_TYPE_OF_GRASPING_ID, gt_ID);
    }
    values.insert(DBConstants::COL_LOAD_HANDLING_TYPE_OF_GRASPING, graspType.value(DBConstants::COL_TYPE_OF_GRASPING_ID));
    values.remove(DBConstants::COL_TYPE_OF_GRASPING_NAME);

    filter = QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(loadhandling_ID);
    int l_ID = dbHandler->save(DBConstants::TBL_LOAD_HANDLING, DBConstants::HASH_LOAD_HANDLING_TYPES, values, filter, DBConstants::COL_LOAD_HANDLING_ID);
    if(l_ID > 0)
        loadhandling_ID = l_ID;
    values.insert(DBConstants::COL_LOAD_HANDLING_ID, loadhandling_ID);
    emit setLoadHandling(values);
    saveWorkProcess(QHash<QString, QVariant>());
}

//BodyPosture
void Controller::saveBodyPosture(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(bodyPosture_ID);
    int bp_ID = dbHandler->save(DBConstants::TBL_BODY_POSTURE, DBConstants::HASH_BODY_POSTURE_TYPES, values, filter, DBConstants::COL_BODY_POSTURE_ID);
    if(bp_ID > 0)
        bodyPosture_ID = bp_ID;
    values.insert(DBConstants::COL_BODY_POSTURE_ID, bodyPosture_ID);
    saveWorkProcess(QHash<QString, QVariant>());
}

//AppliedForce
void Controller::saveAppliedForce(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(appliedforce_ID);
    int af_ID = dbHandler->save(DBConstants::TBL_APPLIED_FORCE, DBConstants::HASH_APPLIED_FORCE_TYPES, values, filter, DBConstants::COL_APPLIED_FORCE_ID);
    if(af_ID > 0)
        appliedforce_ID = af_ID;
    values.insert(DBConstants::COL_APPLIED_FORCE_ID, appliedforce_ID);
    emit setAppliedForce(values);
    saveWorkProcess(QHash<QString, QVariant>());
}

//WorkProcess
void Controller::saveWorkProcess(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_ID).arg(workprocess_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type);
    values.insert(DBConstants::COL_WORK_PROCESS_ID, workprocess_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID, activity_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_TYPE, workprocess_Type);
    values.insert(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID, appliedforce_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_CONDITION_ID, workcondition_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID, loadhandling_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_POSTURE_ID, bodyPosture_ID);
    dbHandler->update(DBConstants::TBL_WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, filter);
    emit setWorkProcess(values);
}

//ExecutionCondition
void Controller::saveExecutionCondition(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(workcondition_ID);
    int wc_ID = dbHandler->save(DBConstants::TBL_WORK_CONDITION, DBConstants::HASH_WORK_CONDITION_TYPES, values, filter, DBConstants::COL_WORK_CONDITION_ID);
    if(wc_ID > 0)
        workcondition_ID = wc_ID;
    values.insert(DBConstants::COL_WORK_CONDITION_ID, workcondition_ID);
    emit setExecutionCondition(values);
    saveWorkProcess(QHash<QString, QVariant>());
}

//Employee
void Controller::initializeEmployees(){
    QList<QHash<QString, QVariant>> values = dbHandler->select(DBConstants::TBL_EMPLOYEE, QString(""));
    for(int i = 0; i < values.count(); ++i)
        emit createdEmployee(values.at(i));
}

void Controller::createEmployee(QHash<QString, QVariant> values){
    QHash<QString, QVariant> bmValues = QHash<QString, QVariant>();
    int bmID = dbHandler->insert(DBConstants::TBL_BODY_MEASUREMENT, DBConstants::HASH_BODY_MEASUREMENT_TYPES, bmValues, DBConstants::COL_BODY_MEASUREMENT_ID);
    values.insert(DBConstants::COL_EMPLOYEE_BODY_MEASUREMENT_ID, bmID);
    int id = dbHandler->insert(DBConstants::TBL_EMPLOYEE, DBConstants::HASH_EMPLOYEE_TYPES, values, DBConstants::COL_EMPLOYEE_ID);
    values.insert(DBConstants::COL_EMPLOYEE_ID, id);
    emit createdEmployee(values);
    emit showMessage(tr("Created new employee"));
}

void Controller::createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues){
    int bmID = dbHandler->insert(DBConstants::TBL_BODY_MEASUREMENT, DBConstants::HASH_BODY_MEASUREMENT_TYPES, bodyMeasurementValues, DBConstants::COL_BODY_MEASUREMENT_ID);
    values.insert(DBConstants::COL_EMPLOYEE_BODY_MEASUREMENT_ID, bmID);
    int empID = dbHandler->insert(DBConstants::TBL_EMPLOYEE, DBConstants::HASH_EMPLOYEE_TYPES, values, DBConstants::COL_EMPLOYEE_ID);
    values.insert(DBConstants::COL_EMPLOYEE_ID, empID);
    emit createdEmployee(values);
}

void Controller::deleteEmployee(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYEE_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_EMPLOYEE, filter);
    dbHandler->remove(DBConstants::TBL_EMPLOYEE, filter);
    emit removedEmployee(id);
    filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYEE_BODY_MEASUREMENT_ID).arg(values.value(DBConstants::COL_EMPLOYEE_BODY_MEASUREMENT_ID).toInt());
    dbHandler->remove(DBConstants::TBL_BODY_MEASUREMENT, filter);
    emit showMessage(tr("Deleted employee"));
}

void Controller::selectEmployee(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYEE_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_EMPLOYEE, filter);
    employee_ID = id;
    bodyMeasurement_ID = values.value(DBConstants::COL_EMPLOYEE_BODY_MEASUREMENT_ID).toInt();
    emit selectedEmployee(values);
    filter = QString("%1 = %2").arg(DBConstants::COL_BODY_MEASUREMENT_ID).arg(bodyMeasurement_ID);
    values = dbHandler->selectFirst(DBConstants::TBL_BODY_MEASUREMENT, filter);
    emit selectedBodyMeasurement(values);
}

void Controller::saveEmployee(QHash<QString, QVariant> values){
    values.insert(DBConstants::COL_EMPLOYEE_ID, employee_ID);
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYEE_ID, employee_ID).arg(employee_ID);
    dbHandler->save(DBConstants::TBL_EMPLOYEE, DBConstants::HASH_EMPLOYEE_TYPES, values, filter, DBConstants::COL_EMPLOYEE_ID);
    emit updatedEmployee(values);
}

void Controller::setSelectedEmployee(int id){
    selectedEmployee_ID = id;
}

void Controller::resetEmployeeSelection(){
    emit employeeSelected(selectedEmployee_ID);
}

//BodyMeasurement
void Controller::saveBodyMeasurement(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BODY_MEASUREMENT_ID).arg(bodyMeasurement_ID);
    dbHandler->save(DBConstants::TBL_BODY_MEASUREMENT, DBConstants::HASH_BODY_MEASUREMENT_TYPES, values, filter, DBConstants::COL_BODY_MEASUREMENT_ID);
}


//WorkProcessControll
void Controller::initilizeWorkProcesses(bool selectFirst){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID);
    QList<QHash<QString, QVariant>> values = dbHandler->select(DBConstants::TBL_WORK_PROCESS, filter);
    emit initiliazedWorkProcesses(values);
    if(selectFirst)
        selectWorkProcess(1, AVType::BASIC);
}

void Controller::createWorkprocess(QHash<QString, QVariant> values){
    AVType type = (AVType) values.value(DBConstants::COL_WORK_PROCESS_TYPE).toInt();
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(type);

    int id = dbHandler->getNextID(DBConstants::TBL_WORK_PROCESS, DBConstants::COL_WORK_PROCESS_ID, filter);
    values.insert(DBConstants::COL_WORK_PROCESS_ID, id);
    values.insert(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID, activity_ID);
    values.insert(DBConstants::COL_WORK_PROCESS_TYPE, type);
    dbHandler->insert(DBConstants::TBL_WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, DBConstants::COL_WORK_PROCESS_ID);
    if(type == workprocess_Type && id == workprocess_ID + 1 )
        emit setHasNextWorkProcess(true);
    emit createdWorkProcess(values);
    if(type == workprocess_Type && id == 1){
        selectWorkProcess(1, type);
    }
}

void Controller::createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocesses){
    if(workplaceName != "" && activityName != ""){
        QString absErrorMessage = QString(tr("Could not create workprocess list because \n the %1 \"%2\" %3 is missing."));
        QString filter = QString("%1 = '%2'").arg(DBConstants::COL_WORKPLACE_NAME).arg(workplaceName);
        int wp_ID = dbHandler->selectFirst(DBConstants::TBL_WORKPLACE, filter).value(DBConstants::COL_WORKPLACE_ID).toInt();
        if(wp_ID > 0){
            filter = QString("%1 = %2 AND %3 = '%4'").arg(DBConstants::COL_ACTIVITY_WORKPLACE_ID).arg(wp_ID).arg(DBConstants::COL_ACTIVITY_DESCRIPTION).arg(activityName);
            int ac_ID = dbHandler->selectFirst(DBConstants::TBL_ACTIVITY, filter).value(DBConstants::COL_ACTIVITY_ID).toInt();
            if(ac_ID > 0){
                filter = QString("%1 = %2").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(ac_ID);

                if(!dbHandler->isSelectEmpty(DBConstants::TBL_WORK_PROCESS, filter)){
                    QString errorMessage = QString("The activity \"%1\" in workplace \"%2\" is not empty.").arg(activityName).arg(workplaceName);
                    ErrorReporter::reportError(errorMessage);
                    emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
                    return;
                }

                for(int i = 0; i < workprocesses.size(); ++i){
                    QHash<QString, QVariant> values = workprocesses.at(i);
                    filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(ac_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(AVType::BASIC);
                    int id = dbHandler->getNextID(DBConstants::TBL_WORK_PROCESS, DBConstants::COL_WORK_PROCESS_ID, filter);
                    values.insert(DBConstants::COL_WORK_PROCESS_TYPE, AVType::BASIC);
                    values.insert(DBConstants::COL_WORK_PROCESS_ID, id);
                    values.insert(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID, ac_ID);
                    dbHandler->insert(DBConstants::TBL_WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, DBConstants::COL_WORK_PROCESS_ID);
                }
            } else {
                QString addition = QString("with workplace \"%1\"").arg(workplaceName);
                QString errorMessage = absErrorMessage.arg(tr("activity")).arg(activityName).arg(addition);
                ErrorReporter::reportError(errorMessage);
                emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
            }

        } else {
            QString errorMessage = absErrorMessage.arg(tr("workplace")).arg(workplaceName).arg("");
            ErrorReporter::reportError(errorMessage);
            emit showMessage(errorMessage, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
        }

    }
}


void Controller::selectNextWorkProcess(){
    selectWorkProcess(workprocess_ID + 1, workprocess_Type);

}

void Controller::selectPreviousWorkProcess(){
    selectWorkProcess(workprocess_ID - 1, workprocess_Type);
}

void Controller::workProcessTypeChanged(AVType type){
    selectWorkProcess(1, type);

}

void Controller::resetWorkProcesses(){
    deleteWorkProcesses(activity_ID);
    initilizeWorkProcesses();
}

void Controller::workProcessDurationChanged(QTime time){
    QString tbl = DBConstants::TBL_WORK_PROCESS;
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 >= %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type).arg(DBConstants::COL_WORK_PROCESS_ID).arg(workprocess_ID);
    QList<QHash<QString, QVariant>> rows = dbHandler->select(tbl, filter);
    if(!rows.isEmpty())
        {
            QHash<QString, QVariant> row = rows.at(0);
            filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type).arg(DBConstants::COL_WORK_PROCESS_ID);
            QTime begin = row.value(DBConstants::COL_WORK_PROCESS_BEGIN).toTime();
            QTime end = row.value(DBConstants::COL_WORK_PROCESS_END).toTime();
            int diff = QTime(0, 0).addSecs(begin.secsTo(end)).secsTo(time);
            row.insert(DBConstants::COL_WORK_PROCESS_END, end.addSecs(diff));
            dbHandler->update(tbl, DBConstants::HASH_WORK_PROCESS_TYPES, row, filter.arg(workprocess_ID));
            for(int i = 1; i < rows.count(); ++i)
                {
                    row = rows.at(i);
                    begin = row.value(DBConstants::COL_WORK_PROCESS_BEGIN).toTime();
                    end = row.value(DBConstants::COL_WORK_PROCESS_END).toTime();
                    row.insert(DBConstants::COL_WORK_PROCESS_BEGIN, begin.addSecs(diff));
                    row.insert(DBConstants::COL_WORK_PROCESS_END, end.addSecs(diff));
                    dbHandler->update(tbl, DBConstants::HASH_WORK_PROCESS_TYPES, row, filter.arg(row.value(DBConstants::COL_WORK_PROCESS_ID).toInt()));
                }
            initilizeWorkProcesses(false);
        }
}


void Controller::selectWorkProcess(int id , AVType type){
    QString absFilter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(type).arg(DBConstants::COL_WORK_PROCESS_ID);
    QString filter = absFilter.arg(id);

    QString tbl = DBConstants::TBL_WORK_PROCESS;
    QHash<QString, QVariant> row = dbHandler->selectFirst(tbl, filter);
    bodyPosture_ID = row.value(DBConstants::COL_WORK_PROCESS_POSTURE_ID).toInt();
    emit setBodyPosture(dbHandler->selectFirst(DBConstants::TBL_BODY_POSTURE, QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(bodyPosture_ID)));
    appliedforce_ID = row.value(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID).toInt();
    emit setAppliedForce(dbHandler->selectFirst(DBConstants::TBL_APPLIED_FORCE, QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(appliedforce_ID)));
    loadhandling_ID = row.value(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID).toInt();
    QHash<QString, QVariant> lhValues = dbHandler->selectFirst(DBConstants::TBL_LOAD_HANDLING, QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(loadhandling_ID));
    QHash<QString, QVariant> lhtValues = dbHandler->selectFirst(DBConstants::TBL_LOAD_HANDLING_TYPE, QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_TYPE_ID).arg(lhValues.value(DBConstants::COL_LOAD_HANDLING_LOAD_HANDLING_TYPE_ID).toString()));
    lhValues.insert(DBConstants::COL_LOAD_HANDLING_TYPE_NAME, lhtValues.value(DBConstants::COL_LOAD_HANDLING_TYPE_NAME));
    QHash<QString, QVariant> togValues = dbHandler->selectFirst(DBConstants::TBL_TYPE_OF_GRASPING, QString("%1 = %2").arg(DBConstants::COL_TYPE_OF_GRASPING_ID).arg(lhValues.value(DBConstants::COL_LOAD_HANDLING_TYPE_OF_GRASPING).toString()));
    lhValues.insert(DBConstants::COL_TYPE_OF_GRASPING_NAME, togValues.value(DBConstants::COL_TYPE_OF_GRASPING_NAME));
    emit setLoadHandling(lhValues);
    workcondition_ID = row.value(DBConstants::COL_WORK_PROCESS_CONDITION_ID).toInt();
    emit setExecutionCondition(dbHandler->selectFirst(DBConstants::TBL_WORK_CONDITION, QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(workcondition_ID)));
    emit setWorkProcess(row);

    workprocess_ID = id;
    workprocess_Type = type;
    emit setSelectedWorkProcessType(type);
    emit setSelectedWorkProcess(row);
    bool hasPrevious = !dbHandler->isSelectEmpty(tbl, absFilter.arg(id - 1));
    bool hasNext = !dbHandler->isSelectEmpty(tbl, absFilter.arg(id + 1));
    emit setHasPreviousWorkProcess(hasPrevious);
    emit setHasNextWorkProcess(hasNext);
}

//Gantt
void Controller::saveWorkProcessFrequence(int frequence){
    QString filter = QString("%1 = %2 AND %3 = %4 AND %5 = %6").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID).arg(DBConstants::COL_WORK_PROCESS_TYPE).arg(workprocess_Type).arg(DBConstants::COL_WORK_PROCESS_ID).arg(workprocess_ID);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_WORK_PROCESS_FREQUENCY, frequence);
    dbHandler->update(DBConstants::TBL_WORK_PROCESS, DBConstants::HASH_WORK_PROCESS_TYPES, values, filter);

}

//Connection
void Controller::initializeFTPConnections(IFTPConnections *widget){
    widget->clearFTPConnections();
    int defaultConnection_ID = 0;
    QList<QHash<QString, QVariant>> values = dbHandler->select(DBConstants::TBL_CONNECTION, QString("%1 = %2").arg(DBConstants::COL_CONNECTION_ANALYST_ID).arg(analyst_ID));
    for(int i = 0; i < values.count(); ++i){
        QHash<QString, QVariant> row = values.at(i);
        widget->addFTPConnection(row);
        if(row.value(DBConstants::COL_CONNECTION_DEFAULT).toBool())
            defaultConnection_ID = row.value(DBConstants::COL_CONNECTION_ID).toInt();
    }
    widget->selectedFTPConnection(defaultConnection_ID);
}

void Controller::selectFTPConnection(IFTPConnections *widget, int id){
    QHash<QString, QVariant> row = dbHandler->selectFirst(DBConstants::TBL_CONNECTION, QString("%1 = %2").arg(DBConstants::COL_CONNECTION_ID).arg(id));
    if(!row.isEmpty()){
        widget->setFTPConnection(row);
    }
}

void Controller::createFTPConnection(IFTPConnections *widget)
{
    QHash<QString, QVariant> values = widget->getFTPConnection();
    values.insert(DBConstants::COL_CONNECTION_ANALYST_ID, analyst_ID);
    dbHandler->insert(DBConstants::TBL_CONNECTION, DBConstants::HASH_CONNECTION_TYPES, values, DBConstants::COL_CONNECTION_ID);
}

void Controller::editFTPConnection(IFTPConnections *widget, int id)
{
    QHash<QString, QVariant> values = widget->getFTPConnection();
    values.insert(DBConstants::COL_CONNECTION_ANALYST_ID, analyst_ID);
    dbHandler->update(DBConstants::TBL_CONNECTION, DBConstants::HASH_CONNECTION_TYPES, values, QString("%1 = %2").arg(DBConstants::COL_CONNECTION_ID).arg(id));
}

//ImportData
void Controller::importData(IImportData *widget){
    emit showMessage(tr("Start parsing"));
    importDataWidget = widget;
    if(widget->getImportMode().compare("XML") == 0){
        XMLParser *xmlParser = new XMLParser(this);
        connect(xmlParser, SIGNAL(createTransportation(QHash<QString,QVariant>)), this, SLOT(createTransportation(QHash<QString, QVariant>)));
        connect(xmlParser, SIGNAL(createEmployee(QHash<QString,QVariant>,QHash<QString,QVariant>)), this, SLOT(createEmployee(QHash<QString,QVariant>,QHash<QString,QVariant>)));
        connect(xmlParser, SIGNAL(createEquipment(QHash<QString,QVariant>)), this, SLOT(createEquipment(QHash<QString,QVariant>)));
        connect(xmlParser, SIGNAL(createProduct(QHash<QString,QVariant>)), this, SLOT(createProduct(QHash<QString,QVariant>)));
        connect(xmlParser, SIGNAL(createWorkplace(QHash<QString,QVariant>,QList<QHash<QString,QVariant> >)), this, SLOT(createWorkplace(QHash<QString,QVariant>,QList<QHash<QString,QVariant> >)));
        connect(xmlParser, SIGNAL(createWorkprocessList(QString,QString,QList<QHash<QString,QVariant> >)), this, SLOT(createWorkprocessList(QString,QString,QList<QHash<QString,QVariant> >)));
        parser = qobject_cast<IImportDataParser*>(xmlParser);
        downloadDir = StandardPaths::xmlDirectoryPath();
    }
    else {
        parser = 0;
        downloadDir = "";
    }


    QDir downloadDirectory = QDir(downloadDir);
    if(!downloadDirectory.exists())
        downloadDirectory.mkpath(downloadDir);

    if(parser){
        FtpHandler *ftpHandler = new FtpHandler();
        connect(ftpHandler, SIGNAL(error(QString)), this, SLOT(importDataDownloadError(QString)));
        connect(ftpHandler, SIGNAL(finished(QString)), this, SLOT(importDataDownloadFinished(QString)));
        QHash<QString, QVariant> conValues = widget->getFTPConnection();
        ftpHandler->setUser(conValues.value(DBConstants::COL_CONNECTION_USERNAME).toString(), conValues.value(DBConstants::COL_CONNECTION_PASSWORD).toString());
        ftpHandler->setPort(conValues.value(DBConstants::COL_CONNECTION_PORT).toInt());
        ftpHandler->setServer(conValues.value(DBConstants::COL_CONNECTION_SERVER_ADDRESS).toString());

        countFileDownload = 0;
        if(parser->getFileMode() == IImportDataParser::FileMode::MultiFile){
            if(widget->importTransportations()){
                ftpHandler->downloadFile(parser->getTransportationFilename(), downloadDir);
                countFileDownload++;
            }
            if(widget->importEquipments()){
                ftpHandler->downloadFile(parser->getEquipmentFilename(), downloadDir);
                countFileDownload++;
            }
            if(widget->importProducts()){
                ftpHandler->downloadFile(parser->getProductFilename(), downloadDir);
                countFileDownload++;
            }
            if(widget->importEmployees()){
                ftpHandler->downloadFile(parser->getEmployeeFilename(), downloadDir);
                countFileDownload++;
            }
            if(widget->importWorkplaces()){
                ftpHandler->downloadFile(parser->getWorkplaceFilename(), downloadDir);
                countFileDownload++;
            }
            if(widget->importWorkprocessLists()){
                ftpHandler->downloadFile(parser->getWorkprocessListFilename(), downloadDir);
                countFileDownload++;
            }
        }
        else {
            ftpHandler->downloadFile(parser->getSingleFilename(), downloadDir);
            countFileDownload++;
        }
    }
}

void Controller::importDataDownloadFinished(const QString ){
    countFileDownload--;
    if(countFileDownload != 0)
        return;

    QString path = QString("%1/%2").arg(downloadDir);
    if(parser != 0){
        if(importDataWidget->importTransportations())
            parser->parseTransportations(path.arg(parser->getTransportationFilename()));
        if(importDataWidget->importEquipments())
            parser->parseEquipments(path.arg(parser->getEquipmentFilename()));
        if(importDataWidget->importProducts())
            parser->parseProducts(path.arg(parser->getProductFilename()));
        if(importDataWidget->importEmployees())
            parser->parseEmployees(path.arg(parser->getEmployeeFilename()));
        if(importDataWidget->importWorkplaces())
            parser->parseWorkplaces(path.arg(parser->getWorkplaceFilename()));
        if(importDataWidget->importWorkprocessLists())
            parser->parseWorkprocessLists(path.arg(parser->getWorkprocessListFilename()));
    }
}

void Controller::importDataDownloadError(const QString &error){
    emit showMessage(error, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
}

//SendData
void Controller::sendData(ISendData *widget){
    FtpHandler *ftpHandler = new FtpHandler();
    connect(ftpHandler, SIGNAL(started()), this, SLOT(sendDataUploadStarted()));
    connect(ftpHandler, SIGNAL(finished(QString)), this, SLOT(sendDataUploadFinished(QString)));
    connect(ftpHandler, SIGNAL(error(QString)), this, SLOT(sendDataUploadError(QString)));
    QHash<QString, QVariant> conValues = widget->getFTPConnection();
    ftpHandler->setUser(conValues.value(DBConstants::COL_CONNECTION_USERNAME).toString(), conValues.value(DBConstants::COL_CONNECTION_PASSWORD).toString());
    ftpHandler->setPort(conValues.value(DBConstants::COL_CONNECTION_PORT).toInt());
    ftpHandler->setServer(conValues.value(DBConstants::COL_CONNECTION_SERVER_ADDRESS).toString());
    ftpHandler->uploadFile(StandardPaths::databasePath());
}

void Controller::sendDataUploadStarted(){
    emit showMessage(tr("Started Upload"), NotificationMessage::INFORMATION, NotificationMessage::MIDDLE);
}

void Controller::sendDataUploadFinished(const QString filename){
    emit showMessage(QString(tr("Finished Upload: ")).append(filename));
}

void Controller::sendDataUploadError(const QString &error){
    emit showMessage(error, NotificationMessage::ERROR, NotificationMessage::PERSISTENT);
}

//Shift
void Controller::initializeShift(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_SHIFT_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_SHIFT, filter);
    if(!values.isEmpty()){
        shift_ID = values.value(DBConstants::COL_SHIFT_ID).toInt();
        filter = QString ("%1 = %2").arg(DBConstants::COL_EMPLOYEE_WORKS_SHIFT_SHIFT_ID).arg(shift_ID);
        selectedEmployee_ID = dbHandler->selectFirst(DBConstants::TBL_EMPLOYEE_WORKS_SHIFT, filter).value(DBConstants::COL_EMPLOYEE_WORKS_SHIFT_EMPLOYEE_ID).toInt();
        emit employeeSelected(selectedEmployee_ID);
        emit selectedShift(values);
        initializeRotationGroup(values.value(DBConstants::COL_SHIFT_ROTATION_GROUP_ID).toInt());
    }
}

void Controller::saveShift(QHash<QString, QVariant> values){
    QHash<QString, QVariant> ewsValues = QHash<QString, QVariant>();
    ewsValues.insert(DBConstants::COL_EMPLOYEE_WORKS_SHIFT_EMPLOYEE_ID, selectedEmployee_ID);
    QString filter = QString("%1 = %2").arg(DBConstants::COL_EMPLOYEE_WORKS_SHIFT_SHIFT_ID).arg(shift_ID);
    dbHandler->update(DBConstants::TBL_EMPLOYEE_WORKS_SHIFT, DBConstants::HASH_EMPLOYEE_WORKS_SHIFT_TYPES, ewsValues, filter, DBConstants::COL_EMPLOYEE_WORKS_SHIFT_EMPLOYEE_ID);
    filter = QString("%1 = %2").arg(DBConstants::COL_SHIFT_ID).arg(shift_ID);
    values.insert(DBConstants::COL_SHIFT_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_SHIFT_ROTATION_GROUP_ID, rotationGroup_ID);
    values.insert(DBConstants::COL_SHIFT_ID, shift_ID);
    dbHandler->save(DBConstants::TBL_SHIFT, DBConstants::HASH_SHIFT_TYPES, values, filter, DBConstants::COL_SHIFT_ID);
    emit selectedShift(values);
}

//RotationGroup
void Controller::initializeRotationGroup(int id){
    rotationGroup_ID = id;
    emit clearRotationGroup();
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(id);
    QList<QHash<QString, QVariant>> rgesValues = dbHandler->select(DBConstants::TBL_ROTATION_GROUP, filter);
    for(int i = 0; i < rgesValues.size(); ++i){
        QHash<QString, QVariant> rgeValues = rgesValues.at(i);
        int entry_ID = rgeValues.value(DBConstants::COL_ROTATION_GROUP_ENTRY_ID).toInt();
        bool isTask = rgeValues.value(DBConstants::COL_ROTATION_GROUP_IS_TASK).toBool();
        QHash<QString, QVariant> additionalValues;
        QString tblName = isTask ? DBConstants::TBL_ROTATION_GROUP_TASK : DBConstants::TBL_BREAK;
        QString colIDName = isTask ? DBConstants::COL_ROTATION_GROUP_TASK_ID : DBConstants::COL_BREAK_ID;
        filter = QString("%1 = %2").arg(colIDName).arg(entry_ID);
        additionalValues = dbHandler->selectFirst(tblName, filter);
        foreach(QString key , additionalValues.keys())
            rgeValues.insert(key, additionalValues.value(key));
        if(isTask)
            emit addRotationGroupEntry(rgeValues);
        else
            emit addRotationGroupBreakEntry(rgeValues);
    }

}

void Controller::createRotationGroupEntry(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID);
    int order = dbHandler->getNextID(DBConstants::TBL_ROTATION_GROUP, DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, filter);
    values.insert(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, order);
    values.insert(DBConstants::COL_ROTATION_GROUP_IS_TASK, true);
    values.insert(DBConstants::COL_ROTATION_GROUP_ID, rotationGroup_ID);
    int success = dbHandler->insert(DBConstants::TBL_ROTATION_GROUP, DBConstants::HASH_ROTATION_GROUP_TYPES, values, DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
    if(success > 0) {
        filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ID).arg(values.value(DBConstants::COL_ROTATION_GROUP_ENTRY_ID).toString());
        QHash<QString, QVariant> additionalValues = dbHandler->selectFirst(DBConstants::TBL_ROTATION_GROUP_TASK, filter);
        values.insert(DBConstants::COL_ROTATION_GROUP_TASK_NAME, additionalValues.value(DBConstants::COL_ROTATION_GROUP_TASK_NAME));
        values.insert(DBConstants::COL_ROTATION_GROUP_TASK_DURATION, additionalValues.value(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_DURATION));
        emit addRotationGroupEntry(values);
        emit showMessage(tr("Added rotation group task to calendar"));
    }
}

void Controller::createRotationGroupBreakEntry(QHash<QString, QVariant> values){
    int duration = values.value(DBConstants::COL_BREAK_DURATION).toInt();
    QString filter = QString("%1 = %2").arg(DBConstants::COL_BREAK_DURATION).arg(duration);
    QHash<QString, QVariant> breakValues = QHash<QString, QVariant>();
    breakValues.insert(DBConstants::COL_BREAK_DURATION, duration);
    values.remove(DBConstants::COL_BREAK_DURATION);
    int break_ID = dbHandler->save(DBConstants::TBL_BREAK, DBConstants::HASH_BREAK_TYPES, breakValues, filter, DBConstants::COL_BREAK_ID);
    if(break_ID > 0) {
        values.insert(DBConstants::COL_ROTATION_GROUP_ENTRY_ID, break_ID);
        filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID);
        int order = dbHandler->getNextID(DBConstants::TBL_ROTATION_GROUP, DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, filter);
        values.insert(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, order);
        values.insert(DBConstants::COL_ROTATION_GROUP_IS_TASK, false);
        values.insert(DBConstants::COL_ROTATION_GROUP_ID, rotationGroup_ID);
        int success = dbHandler->insert(DBConstants::TBL_ROTATION_GROUP, DBConstants::HASH_ROTATION_GROUP_TYPES, values, DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
        if(success > 0) {
            values.insert(DBConstants::COL_BREAK_DURATION, duration);
            emit addRotationGroupBreakEntry(values);
            emit showMessage(tr("Added break to calendar"));
        }
    }
}

void Controller::removeRotationGroupEntry(int order){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID).arg(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER).arg(order);
    if(dbHandler->remove(DBConstants::TBL_ROTATION_GROUP, filter)){
        emit showMessage(tr("Removed entry form calendar"));
        filter = QString("%1 = %2 AND %3 > %4").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID).arg(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER).arg(order);
        QList<QHash<QString, QVariant>> rgesValues = dbHandler->select(DBConstants::TBL_ROTATION_GROUP, filter);
        QString absFilter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID).arg(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
        for(int i = 0; i < rgesValues.size(); ++i){
            QHash<QString, QVariant> rgeValues = rgesValues.at(i);
            int order = rgeValues.value(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER).toInt();
            rgeValues.insert(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, order - 1);
            dbHandler->update(DBConstants::TBL_ROTATION_GROUP, DBConstants::HASH_ROTATION_GROUP_TYPES, rgeValues, absFilter.arg(order), DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
        }
        initializeRotationGroup(rotationGroup_ID);
    }
}

void Controller::moveRotationGroupEntryUp(int order){
    swapRotationGroupEntries(order, order-1);
    initializeRotationGroup(rotationGroup_ID);
}

void Controller::moveRotationGroupEntryDown(int order){
    swapRotationGroupEntries(order, order+1);
    initializeRotationGroup(rotationGroup_ID);
}


//RotationGroupTask
void Controller::initializeRotationGroupTasks(){
    emit clearRotationGroupTasks();
    QList<QHash<QString, QVariant>> rows = dbHandler->select(DBConstants::TBL_ROTATION_GROUP_TASK, QString(""));
    for(int i = 0; i < rows.size(); ++i)
        emit createdRotationGroupTask(rows.value(i));
}

void Controller::createRotationGroupTask(QHash<QString, QVariant> values){
    dbHandler->insert(DBConstants::TBL_ROTATION_GROUP_TASK, DBConstants::HASH_ROTATION_GROUP_TASK_TYPES, values, DBConstants::COL_ROTATION_GROUP_TASK_ID);
    emit showMessage(tr("Created rotation group task"));
    emit createdRotationGroupTask(values);
}

void Controller::deleteRotationGroupTask(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ID).arg(id);
    dbHandler->remove(DBConstants::TBL_ROTATION_GROUP_TASK, filter);
    QList<QHash<QString, QVariant>> rgteRows = dbHandler->select(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID).arg(id));
    rotationGroupTask_ID = id;
    for(int i = 0; i < rgteRows.size(); ++i){
        deleteRotationGroupTaskEntry(rgteRows.at(i).value(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_ID).toInt(), false);
    }
    emit showMessage(tr("Deleted rotation group task"));
    emit removedRotationGroupTask(id);
}

void Controller::selectRotationGroupTask(int id){
    rotationGroupTask_ID = id;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ID).arg(id);
    QHash<QString, QVariant> values = dbHandler->selectFirst(DBConstants::TBL_ROTATION_GROUP_TASK, filter);
    emit selectedRotationGroupTask(values);
    initializeRotationGroupTaskEntries(id);
}

void Controller::saveRotationGroupTask(QHash<QString, QVariant> values){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ID).arg(rotationGroupTask_ID);
    values.insert(DBConstants::COL_ROTATION_GROUP_TASK_ID, rotationGroupTask_ID);
    dbHandler->save(DBConstants::TBL_ROTATION_GROUP_TASK, DBConstants::HASH_ROTATION_GROUP_TASK_TYPES, values, filter, DBConstants::COL_ROTATION_GROUP_TASK_ID);
    emit showMessage(tr("Saved rotation group task"));
    emit updatedRotationGroupTask(values);
    updateRotationGroupEntry(values.value(DBConstants::COL_ROTATION_GROUP_TASK_ID).toInt());
}


//RotationGroupTaskEntry
void Controller::initializeRotationGroupTaskEntries(int id){
    emit clearRotationGroupTaskEntries();
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID).arg(id);
    QList<QHash<QString, QVariant>> rgtesValues = dbHandler->select(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, filter);
    for(int i = 0; i < rgtesValues.size(); ++i){
        QHash<QString, QVariant> rgteValues = rgtesValues.at(i);
        rgteValues.insert(DBConstants::COL_WORKPLACE_NAME, getWorkplaceNameByID(rgteValues.value(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_WORKPLACE_ID).toInt()));
        emit createdRotationGroupTaskEntry(rgteValues);
    }
    updateRotationGroupTaskDuration();

}

void Controller::createRotationGroupTaskEntry(QHash<QString, QVariant> values){
    values.insert(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID, rotationGroupTask_ID);
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID).arg(rotationGroupTask_ID);
    int rgte_ID = dbHandler->getNextID(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_ID, filter);
    values.insert(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_ID, rgte_ID);
    dbHandler->insert(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, DBConstants::HASH_ROTATION_GROUP_TASK_ENTRY_TYPES, values, DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_ID);
    values.insert(DBConstants::COL_WORKPLACE_NAME, getWorkplaceNameByID(values.value(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_WORKPLACE_ID).toInt()));
    emit createdRotationGroupTaskEntry(values);
    emit showMessage(tr("Created rotation group task entry"));
    updateRotationGroupTaskDuration();
}

void Controller::deleteRotationGroupTaskEntry(int id, bool showMsg){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_ID).arg(id).arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID).arg(rotationGroupTask_ID);
    dbHandler->remove(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, filter);
    emit removedRotationGroupTaskEntry(id);
    if(showMsg)
        emit showMessage(tr("Deleted rotation group task entry"));
    updateRotationGroupTaskDuration();
}

//Database Factory Reset
void Controller::resetDatabaseFactory()
{
    QString emptyFilter = QString("");
    QList<QString> tblNames = DBConstants::LIST_TABLE_NAMES;
    for(int i = 0; i < tblNames.size(); ++i)
        dbHandler->remove(tblNames.at(i), emptyFilter);
    emit clearAll();
    emit showMessage(tr("Restored Factory Settings"));
    emit showView(ViewType::ANALYST_SELECTION_VIEW);
}

//Database selected reset
void Controller::resetSelectedEntries(ISelectedDatabaseReset *widget){
    QString emptyFilter = QString("");
    if(widget->headDataSelected()){
        factory_ID = 0;
        dbHandler->remove(DBConstants::TBL_BRANCH_OF_INDUSTRY, emptyFilter);
        dbHandler->remove(DBConstants::TBL_CORPORATION, emptyFilter);
        dbHandler->remove(DBConstants::TBL_EMPLOYER, emptyFilter);
        dbHandler->remove(DBConstants::TBL_FACTORY, emptyFilter);
    }
    if(widget->workplacesSelected()){
        recording_ID = 1;
        workplace_ID = 0;
        workcondition_ID = 0;
        activity_ID = 0;
        appliedforce_ID = 0;
        loadhandling_ID = 0;
        workprocess_Type = AVType::BASIC;
        workprocess_ID = 0;
        dbHandler->remove(DBConstants::TBL_ACTIVITY, emptyFilter);
        dbHandler->remove(DBConstants::TBL_APPLIED_FORCE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_BODY_POSTURE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_COMMENT, emptyFilter);
        dbHandler->remove(DBConstants::TBL_LINE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_LOAD_HANDLING, emptyFilter);
        dbHandler->remove(DBConstants::TBL_RECORDING, emptyFilter);
        dbHandler->remove(DBConstants::TBL_RECORDING_OB_LINE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_RECORDING_OB_WORKPLACE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_WORKPLACE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_WORK_CONDITION, emptyFilter);
        dbHandler->remove(DBConstants::TBL_WORK_PROCESS, emptyFilter);
        emit clearWorkplaces();
    }
    if(widget->equipmentSelected()){
        dbHandler->remove(DBConstants::TBL_EQUIPMENT, emptyFilter);
        emit clearEquipments();
    }
    if(widget->productsSelected()){
        dbHandler->remove(DBConstants::TBL_PRODUCT, emptyFilter);
        emit clearProducts();
    }
    if(widget->transportationSelected()){
        dbHandler->remove(DBConstants::TBL_TRANSPORTATION, emptyFilter);
        emit clearTransportations();
    }
    if(widget->employeeSelected()){
        employee_ID = 1;
        bodyMeasurement_ID = 1;
        dbHandler->remove(DBConstants::TBL_EMPLOYEE, emptyFilter);
        dbHandler->remove(DBConstants::TBL_EMPLOYEE_WORKS_SHIFT, emptyFilter);
        dbHandler->remove(DBConstants::TBL_BODY_MEASUREMENT, emptyFilter);
        emit clearEmployees();
    }
    if(widget->shiftDataSelected()){
        dbHandler->remove(DBConstants::TBL_SHIFT, emptyFilter);
        dbHandler->remove(DBConstants::TBL_BREAK, emptyFilter);
        dbHandler->remove(DBConstants::TBL_ROTATION_GROUP, emptyFilter);
        dbHandler->remove(DBConstants::TBL_ROTATION_GROUP_TASK, emptyFilter);
        dbHandler->remove(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, emptyFilter);
        emit clearRotationGroup();
        emit clearRotationGroupTaskEntries();
        emit clearRotationGroupTasks();
    }
    if(widget->ftpConnectionSelected()){
        dbHandler->remove(DBConstants::TBL_CONNECTION, emptyFilter);
    }

    emit showMessage(tr("Reset successful"));
}



// Changing of the application theme/stylesheet
void Controller::changeTheme(){
    if(Settings::value(Settings::SETTING_THEME) == Settings::THEME_GREEN){
        application->setStyleSheet(stringFromResource(":/assets/stylesheetGreen.qss"));
    }
    else {
        application->setStyleSheet(stringFromResource(":/assets/stylesheet.qss"));
    }

    emit showMessage(tr("Theme changed"));
}

//PRIVATE METHODS
void Controller::updateRotationGroupTaskDuration(){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_TASK_ID).arg(rotationGroupTask_ID);
    QList<QHash<QString, QVariant>> rgtesValues = dbHandler->select(DBConstants::TBL_ROTATION_GROUP_TASK_ENTRY, filter);
    int duration = 0;
    for(int i = 0; i < rgtesValues.size(); ++i){
        duration += rgtesValues.at(i).value(DBConstants::COL_ROTATION_GROUP_TASK_ENTRY_DURATION).toInt();
    }
    emit updatedRotationGroupTaskDuration(duration);
}

QString Controller::getWorkplaceNameByID(int id){
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORKPLACE_ID).arg(id);
    return dbHandler->selectFirst(DBConstants::TBL_WORKPLACE, filter).value(DBConstants::COL_WORKPLACE_NAME).toString();
}

void Controller::swapRotationGroupEntries(int order1, int order2){
    QString absFilter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_ROTATION_GROUP_ID).arg(rotationGroup_ID).arg(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
    QHash<QString, QVariant> values1 = dbHandler->selectFirst(DBConstants::TBL_ROTATION_GROUP, absFilter.arg(order1));
    dbHandler->remove(DBConstants::TBL_ROTATION_GROUP, absFilter.arg(order1));
    QHash<QString, QVariant> values2 = dbHandler->selectFirst(DBConstants::TBL_ROTATION_GROUP, absFilter.arg(order2));
    values2.insert(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, order1);
    dbHandler->update(DBConstants::TBL_ROTATION_GROUP, DBConstants::HASH_ROTATION_GROUP_TYPES, values2, absFilter.arg(order2), DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
    values1.insert(DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER, order2);
    dbHandler->insert(DBConstants::TBL_ROTATION_GROUP, DBConstants::HASH_ROTATION_GROUP_TYPES, values1, DBConstants::COL_ROTATION_GROUP_ORDER_NUMBER);
}

void Controller::updateRotationGroupEntry(int entry_ID){
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_ROTATION_GROUP_IS_TASK).arg(1).arg(DBConstants::COL_ROTATION_GROUP_ENTRY_ID).arg(entry_ID);
    QList<QHash<QString, QVariant>> rgesValues = dbHandler->select(DBConstants::TBL_ROTATION_GROUP, filter);
    for(int i = 0; i < rgesValues.size(); ++i){
        QHash<QString, QVariant> rgeValues = rgesValues.at(i);
        filter = QString("%1 = %2").arg(DBConstants::COL_ROTATION_GROUP_TASK_ID).arg(entry_ID);
        QHash<QString, QVariant> rgtValues = dbHandler->selectFirst(DBConstants::TBL_ROTATION_GROUP_TASK, filter);
        rgeValues.insert(DBConstants::COL_ROTATION_GROUP_TASK_DURATION, rgtValues.value(DBConstants::COL_ROTATION_GROUP_TASK_DURATION));
        rgeValues.insert(DBConstants::COL_ROTATION_GROUP_TASK_NAME, rgtValues.value(DBConstants::COL_ROTATION_GROUP_TASK_NAME));
        emit updatedRotationGroupEntry(rgeValues);
    }
}


QString Controller::stringFromResource(const QString &resName)
{
    QFile file(resName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream ts(&file);
    return ts.readAll();
}

void Controller::saveRecordingObservesLine(int lineID)
{
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_RECORDING_OB_LINE_RECORDING_ID).arg(QString::number(recording_ID)).arg(DBConstants::COL_RECORDING_OB_LINE_LINE_ID).arg(QString::number(lineID));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_RECORDING_OB_LINE_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_RECORDING_OB_LINE_LINE_ID, lineID);
    dbHandler->save(DBConstants::TBL_RECORDING_OB_LINE, DBConstants::HASH_RECORDING_OB_LINE_TYPES, values, filter);
}

void Controller::deleteRecordingObservesLine(int lineID)
{
    QString filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_OB_LINE_LINE_ID).arg(QString::number(lineID));
    dbHandler->remove(DBConstants::TBL_RECORDING_OB_LINE, filter);
}

void Controller::saveRecordingObservesWorkplace(int workplaceID)
{
    QString filter = QString("%1 = %2 AND %3 = %4").arg(DBConstants::COL_RECORDING_OB_WORKPLACE_RECORDING_ID).arg(QString::number(recording_ID)).arg(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID).arg(QString::number(workplaceID));

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_RECORDING_OB_WORKPLACE_RECORDING_ID, recording_ID);
    values.insert(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID, workplaceID);
    dbHandler->save(DBConstants::TBL_RECORDING_OB_WORKPLACE, DBConstants::HASH_RECORDING_OB_WORKPLACE_TYPES, values, filter);
}

void Controller::deleteRecordingOberservesWorkplace(int wpID)
{
    QString filter = QString("%1 = %2").arg(DBConstants::COL_RECORDING_OB_WORKPLACE_WORKPLACE_ID).arg(QString::number(wpID));
    dbHandler->remove(DBConstants::TBL_RECORDING_OB_WORKPLACE, filter);
}


void Controller::deleteWorkProcesses(int activity_ID)
{
    QString tbl = DBConstants::TBL_WORK_PROCESS;
    QString filter = QString("%1 = %2").arg(DBConstants::COL_WORK_PROCESS_ACTIVITY_ID).arg(activity_ID);
    QList<QHash<QString, QVariant>> values = dbHandler->select(tbl, filter);
    for(int i = 0; i < values.count(); ++i){
        QHash<QString, QVariant> row = values.at(i);
        dbHandler->remove(DBConstants::TBL_BODY_POSTURE, QString("%1 = %2").arg(DBConstants::COL_BODY_POSTURE_ID).arg(row.value(DBConstants::COL_WORK_PROCESS_POSTURE_ID).toInt()));
        dbHandler->remove(DBConstants::TBL_APPLIED_FORCE, QString("%1 = %2").arg(DBConstants::COL_APPLIED_FORCE_ID).arg(row.value(DBConstants::COL_WORK_PROCESS_APPLIED_FORCE_ID).toInt()));
        dbHandler->remove(DBConstants::TBL_LOAD_HANDLING, QString("%1 = %2").arg(DBConstants::COL_LOAD_HANDLING_ID).arg(row.value(DBConstants::COL_WORK_PROCESS_LOAD_HANDLING_ID).toInt()));
        dbHandler->remove(DBConstants::TBL_WORK_CONDITION, QString("%1 = %2").arg(DBConstants::COL_WORK_CONDITION_ID).arg(row.value(DBConstants::COL_WORK_PROCESS_CONDITION_ID).toInt()));
    }
    dbHandler->remove(tbl, filter);
}

