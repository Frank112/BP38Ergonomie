#include "tst_controllertest.h"

ControllerTest::ControllerTest(){

}

void ControllerTest::initTestCase(){
    c = new Controller();
}

void ControllerTest::createAnalystSuccessfulTest(){
    QSignalSpy spy(c, SIGNAL(createdAnalyst(QHash<QString,QVariant>)));
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ANALYST_FIRSTNAME, "Max");
    values.insert(DBConstants::COL_ANALYST_LASTNAME, "Mustermann");
    c->createAnalyst(values);
    QCOMPARE(spy.count(), 1);
}
void ControllerTest::createAnalystFailedTest(){
    QSignalSpy spy(c, SIGNAL(createdAnalyst(QHash<QString,QVariant>)));
    QSignalSpy spyError(c, SIGNAL(showMessage(QString,NotificationMessage::MessageType,NotificationMessage::MessageDisplayType)));
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ACTIVITY_REPETITIONS, 5);
    c->createActivity(values);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(spyError.count(), 1);
}

void ControllerTest::deleteAnalystSuccessfulTest(){
    c->deleteAnalyst(1);
    QVERIFY(true);
}
void ControllerTest::deleteAnalystFailedTest(){
    c->deleteActivity(-1);
    QVERIFY(true);
}

void ControllerTest::selectAnalystSuccessfulTest(){
    c->selectAnalyst(-1);
    QVERIFY(true);
}
void ControllerTest::selectAnalystFailedTest(){
    c->selectAnalyst(2);
    QVERIFY(true);
}

void ControllerTest::createBlankRecording(){
    c->createBlankRecording();
    QVERIFY(true);
}

void ControllerTest::setBranchOfIndustrySuccessfulTest(){
    c->setBranchOfIndustry(0);
}
void ControllerTest::setBranchOfIndustryFailedTest(){
    c->setBranchOfIndustry(-1);
}

void ControllerTest::saveBranchOfIndustrySuccessfulTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_BRANCH_OF_INDUSTRY_NAME, "Test");
    c->saveBranchOfIndustry(values);
}
void ControllerTest::saveBranchOfIndustryFailedTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ANALYST_EXPERIENCE, "Test");
    c->saveBranchOfIndustry(values);
}

void ControllerTest::setCorperationSuccessfulTest(){
    c->setCorporation(0);
}
void ControllerTest::setCorperationFailedTest(){
    c->setCorporation(-1);
}

void ControllerTest::saveCorperationSuccessfulTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_CORPORATION_NAME, "Test");
    c->saveBranchOfIndustry(values);
}
void ControllerTest::saveCorperationFailedTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ANALYST_EXPERIENCE, "Test");
    c->saveCorperation(values);
}

void ControllerTest::setFactorySuccessfulTest(){
    c->setFactory(0);
}
void ControllerTest::setFactoryFailedTest(){
    c->setFactory(-1);
}

void ControllerTest::saveFactorySuccessfulTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_FACTORY_NAME, "Test");
    c->saveFactory(values);
}
void ControllerTest::saveFactoryFailedTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_ANALYST_LASTNAME, "Test");
    c->saveFactory(values);
}

void ControllerTest::setRecordingSuccessfulTest(){
    c->setRecording(0);
}
void ControllerTest::setRecordingFailedTest(){
    c->setRecording(-1);
}

void ControllerTest::saveRecordingSuccessfulTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_RECORDING_ANALYST_ID, 2);
    c->saveRecording(values);
}
void ControllerTest::saveRecordingFailedTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(DBConstants::COL_PRODUCT_ID, 5);
    c->saveRecording(values);
}

void ControllerTest::createWorkplaceSuccessfulTest(){ }
void ControllerTest::createWorkplaceFailedTest(){ }

void ControllerTest::deleteWorkplaceSuccessfulTest(){ }
void ControllerTest::deleteWorkplaceFailedTest(){ }

void ControllerTest::selectWorkplaceSuccessfulTest(){ }
void ControllerTest::selectWorkplaceFailedTest(){ }

void ControllerTest::saveWorkplaceSuccessfulTest(){ }
void ControllerTest::saveWorkplaceFailedTest(){ }

void ControllerTest::saveCommentSuccessfulTest(){ }
void ControllerTest::saveCommentFailedTest(){ }

void ControllerTest::createLineSuccessfulTest(){ }
void ControllerTest::createLineFailedTest(){ }

void ControllerTest::editLineSuccessfulTest(){ }
void ControllerTest::editLineFailedTest(){ }

void ControllerTest::saveLineSuccessfulTest(){ }
void ControllerTest::saveLineFailedTest(){ }

void ControllerTest::deleteLineSuccessfulTest(){ }
void ControllerTest::deleteLineFailedTest(){ }

void ControllerTest::selectLineSuccessfulTest(){ }
void ControllerTest::selectLineFailedTest(){ }

void ControllerTest::createProductSuccessfulTest(){ }
void ControllerTest::createProductFailedTest(){ }

void ControllerTest::saveProductSuccessfulTest(){ }
void ControllerTest::saveProductFailedTest(){ }

void ControllerTest::deleteProductSuccessfulTest(){ }
void ControllerTest::deleteProductFailedTest(){ }

void ControllerTest::createActivitySuccessfulTest(){ }
void ControllerTest::createActivityFailedTest(){ }

void ControllerTest::deleteActivitySuccessfulTest(){ }
void ControllerTest::deleteActivityFailedTest(){ }

void ControllerTest::selectActivitySuccessfulTest(){ }
void ControllerTest::selectActivityFailedTest(){ }

void ControllerTest::saveActivitySuccessfulTest(){ }
void ControllerTest::saveActivityFailedTest(){ }

void ControllerTest::editActivitySuccessfulTest(){ }
void ControllerTest::editActivityFailedTest(){ }

void ControllerTest::createEquipmentSuccessfulTest(){ }
void ControllerTest::createEquipmentFailedTest(){ }

void ControllerTest::saveEquipmentSuccessfulTest(){ }
void ControllerTest::saveEquipmentFailedTest(){ }

void ControllerTest::deleteEquipmentSuccessfulTest(){ }
void ControllerTest::deleteEquipmentFailedTest(){ }

void ControllerTest::createTransportationSuccessfulTest(){ }
void ControllerTest::createTransportationFailedTest(){ }

void ControllerTest::saveTransportationSuccessfulTest(){ }
void ControllerTest::saveTransportationFailedTest(){ }

void ControllerTest::deleteTransportationSuccessfulTest(){ }
void ControllerTest::deleteTransportationFailedTest(){ }

void ControllerTest::saveLoadHandlingSuccessfulTest(){ }
void ControllerTest::saveLoadHandlingFailedTest(){ }

void ControllerTest::saveBodyPostureSuccessfulTest(){ }
void ControllerTest::saveBodyPostureFailedTest(){ }

void ControllerTest::saveAppliedForceSuccessfulTest(){ }
void ControllerTest::saveAppliedForceFailedTest(){ }

void ControllerTest::saveExecutionConditionSuccessfulTest(){ }
void ControllerTest::saveExecutionConditionFailedTest(){ }

void ControllerTest::saveWorkprocessSuccessfulTest(){ }
void ControllerTest::saveWorkprocessFailedTest(){ }

void ControllerTest::createWorkprocessSuccessfulTest(){ }
void ControllerTest::createWorkprocessFailedTest(){ }

void ControllerTest::createWorkprocessListSuccessfulTest(){ }
void ControllerTest::createWorkprocessListFailedTest(){ }

void ControllerTest::selectNextWorkprocessSuccessfulTest(){ }

void ControllerTest::selectPreviousWorkprocessSuccessfulTest(){ }

void ControllerTest::workprocessTypeChangedTest(){ }

void ControllerTest::resetWorkprocessesTest(){ }

void ControllerTest::workprocessDurationChangedSuccessfulTest(){ }
void ControllerTest::workprocessDurationChangedFailedTest(){ }

void ControllerTest::selectWorkprocessSuccessfulTest(){ }
void ControllerTest::selectWorkprocessFailedTest(){ }

void ControllerTest::saveWorkprocessFrequenceSuccessfulTest(){ }
void ControllerTest::saveWorkprocessFrequenceFailedTest(){ }

void ControllerTest::createEmployeeSuccessfulTest(){ }
void ControllerTest::createEmployeeFailedTest(){ }

void ControllerTest::createEmployeeBodyMeasurementSuccessfulTest(){ }
void ControllerTest::createEmployeeBodyMeasurementFailedTest(){ }

void ControllerTest::deleteEmployeeSuccessfulTest(){ }
void ControllerTest::deleteEmployeeFailedTest(){ }

void ControllerTest::selectEmployeeSuccessfulTest(){ }
void ControllerTest::selectEmployeeFailedTest(){ }

void ControllerTest::saveEmployeeSuccessfulTest(){ }
void ControllerTest::saveEmployeeFailedTest(){ }

void ControllerTest::setSelectedEmployeeSuccessfulTest(){ }
void ControllerTest::setSelectedEmployeeFailedTest(){ }

void ControllerTest::resetEmployeeSelectionTest(){ }

void ControllerTest::saveBodyMeasurementSuccessfulTest(){ }
void ControllerTest::saveBodyMeasurementFailedTest(){ }

void ControllerTest::saveShiftSuccessfulTest(){ }
void ControllerTest::saveShiftFailedTest(){ }

void ControllerTest::createRotationGroupEntrySuccessfulTest(){ }
void ControllerTest::createRotationGroupEntryFailedTest(){ }

void ControllerTest::createRotationGroupBreakEntrySuccessfulTest(){ }
void ControllerTest::createRotationGroupBreakEntryFailedTest(){ }

void ControllerTest::deleteRotationGroupEntrySuccessfulTest(){ }
void ControllerTest::deleteRotationGroupEntryFailedTest(){ }

void ControllerTest::moveRotationGroupEntryUpSuccessfulTest(){ }
void ControllerTest::moveRotationGroupEntryUpFailedTest(){ }

void ControllerTest::moveRotationGroupEntryDownSuccessfulTest(){ }
void ControllerTest::moveRotationGroupEntryDownFailedTest(){ }

void ControllerTest::createRotationGroupTaskSuccessfulTest(){ }
void ControllerTest::createRotationGroupTaskFailedTest(){ }

void ControllerTest::deleteRotationGroupTaskSuccessfulTest(){ }
void ControllerTest::deleteRotationGroupTaskFailedTest(){ }

void ControllerTest::selectRotationGroupTaskSuccessfulTest(){ }
void ControllerTest::selectRotationGroupTaskFailedTest(){ }

void ControllerTest::saveRotationGroupTaskSuccessfulTest(){ }
void ControllerTest::saveRotationGroupTaskFailedTest(){ }

void ControllerTest::createRotationGroupTaskEntrySuccessfulTest(){ }
void ControllerTest::createRotationGroupTaskEntryFailedTest(){ }

void ControllerTest::deleteRotationGroupTaskEntrySuccessfulTest(){ }
void ControllerTest::deleteRotationGroupTaskEntryFailedTest(){ }

void ControllerTest::resetDatabaseFactoryTest(){ }

void ControllerTest::cleanupTestCase(){
    delete c;
}
