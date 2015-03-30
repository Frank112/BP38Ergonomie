#ifndef TST_CONTROLLERTEST
#define TST_CONTROLLERTEST

#include <QObject>
#include <QtTest>
#include "../control/controller.h"

class ControllerTest : public QObject {
    Q_OBJECT

public:
    ControllerTest();

private Q_SLOTS:
    void initTestCase();

    void createAnalystSuccessfulTest();
    void createAnalystFailedTest();

    void deleteAnalystSuccessfulTest();
    void deleteAnalystFailedTest();

    void selectAnalystSuccessfulTest();
    void selectAnalystFailedTest();

    void createBlankRecording();

    void setBranchOfIndustrySuccessfulTest();
    void setBranchOfIndustryFailedTest();

    void saveBranchOfIndustrySuccessfulTest();
    void saveBranchOfIndustryFailedTest();

    void setCorperationSuccessfulTest();
    void setCorperationFailedTest();

    void saveCorperationSuccessfulTest();
    void saveCorperationFailedTest();

    void setFactorySuccessfulTest();
    void setFactoryFailedTest();

    void saveFactorySuccessfulTest();
    void saveFactoryFailedTest();

    void setRecordingSuccessfulTest();
    void setRecordingFailedTest();

    void saveRecordingSuccessfulTest();
    void saveRecordingFailedTest();

    void createWorkplaceSuccessfulTest();
    void createWorkplaceFailedTest();

    void deleteWorkplaceSuccessfulTest();
    void deleteWorkplaceFailedTest();

    void selectWorkplaceSuccessfulTest();
    void selectWorkplaceFailedTest();

    void saveWorkplaceSuccessfulTest();
    void saveWorkplaceFailedTest();

    void saveCommentSuccessfulTest();
    void saveCommentFailedTest();

    void createLineSuccessfulTest();
    void createLineFailedTest();

    void editLineSuccessfulTest();
    void editLineFailedTest();

    void saveLineSuccessfulTest();
    void saveLineFailedTest();

    void deleteLineSuccessfulTest();
    void deleteLineFailedTest();

    void selectLineSuccessfulTest();
    void selectLineFailedTest();

    void createProductSuccessfulTest();
    void createProductFailedTest();

    void saveProductSuccessfulTest();
    void saveProductFailedTest();

    void deleteProductSuccessfulTest();
    void deleteProductFailedTest();

    void createActivitySuccessfulTest();
    void createActivityFailedTest();

    void deleteActivitySuccessfulTest();
    void deleteActivityFailedTest();

    void selectActivitySuccessfulTest();
    void selectActivityFailedTest();

    void saveActivitySuccessfulTest();
    void saveActivityFailedTest();

    void editActivitySuccessfulTest();
    void editActivityFailedTest();

    void createEquipmentSuccessfulTest();
    void createEquipmentFailedTest();

    void saveEquipmentSuccessfulTest();
    void saveEquipmentFailedTest();

    void deleteEquipmentSuccessfulTest();
    void deleteEquipmentFailedTest();

    void createTransportationSuccessfulTest();
    void createTransportationFailedTest();

    void saveTransportationSuccessfulTest();
    void saveTransportationFailedTest();

    void deleteTransportationSuccessfulTest();
    void deleteTransportationFailedTest();

    void saveLoadHandlingSuccessfulTest();
    void saveLoadHandlingFailedTest();

    void saveBodyPostureSuccessfulTest();
    void saveBodyPostureFailedTest();

    void saveAppliedForceSuccessfulTest();
    void saveAppliedForceFailedTest();

    void saveExecutionConditionSuccessfulTest();
    void saveExecutionConditionFailedTest();

    void saveWorkprocessSuccessfulTest();
    void saveWorkprocessFailedTest();

    void createWorkprocessSuccessfulTest();
    void createWorkprocessFailedTest();

    void createWorkprocessListSuccessfulTest();
    void createWorkprocessListFailedTest();

    void selectNextWorkprocessSuccessfulTest();

    void selectPreviousWorkprocessSuccessfulTest();

    void workprocessTypeChangedTest();

    void resetWorkprocessesTest();

    void workprocessDurationChangedSuccessfulTest();
    void workprocessDurationChangedFailedTest();

    void selectWorkprocessSuccessfulTest();
    void selectWorkprocessFailedTest();

    void saveWorkprocessFrequenceSuccessfulTest();
    void saveWorkprocessFrequenceFailedTest();

    void createEmployeeSuccessfulTest();
    void createEmployeeFailedTest();

    void createEmployeeBodyMeasurementSuccessfulTest();
    void createEmployeeBodyMeasurementFailedTest();

    void deleteEmployeeSuccessfulTest();
    void deleteEmployeeFailedTest();

    void selectEmployeeSuccessfulTest();
    void selectEmployeeFailedTest();

    void saveEmployeeSuccessfulTest();
    void saveEmployeeFailedTest();

    void setSelectedEmployeeSuccessfulTest();
    void setSelectedEmployeeFailedTest();

    void resetEmployeeSelectionTest();

    void saveBodyMeasurementSuccessfulTest();
    void saveBodyMeasurementFailedTest();

    void saveShiftSuccessfulTest();
    void saveShiftFailedTest();

    void createRotationGroupEntrySuccessfulTest();
    void createRotationGroupEntryFailedTest();

    void createRotationGroupBreakEntrySuccessfulTest();
    void createRotationGroupBreakEntryFailedTest();

    void deleteRotationGroupEntrySuccessfulTest();
    void deleteRotationGroupEntryFailedTest();

    void moveRotationGroupEntryUpSuccessfulTest();
    void moveRotationGroupEntryUpFailedTest();

    void moveRotationGroupEntryDownSuccessfulTest();
    void moveRotationGroupEntryDownFailedTest();

    void createRotationGroupTaskSuccessfulTest();
    void createRotationGroupTaskFailedTest();

    void deleteRotationGroupTaskSuccessfulTest();
    void deleteRotationGroupTaskFailedTest();

    void selectRotationGroupTaskSuccessfulTest();
    void selectRotationGroupTaskFailedTest();

    void saveRotationGroupTaskSuccessfulTest();
    void saveRotationGroupTaskFailedTest();

    void createRotationGroupTaskEntrySuccessfulTest();
    void createRotationGroupTaskEntryFailedTest();

    void deleteRotationGroupTaskEntrySuccessfulTest();
    void deleteRotationGroupTaskEntryFailedTest();

    void resetDatabaseFactoryTest();

    void cleanupTestCase();

private:
    Controller *c;
};

#endif // TST_CONTROLLERTEST

