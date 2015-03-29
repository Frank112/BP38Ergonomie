/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../control/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[205];
    char stringdata[3611];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 11), // "showMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "message"
QT_MOC_LITERAL(4, 32, 32), // "NotificationMessage::MessageType"
QT_MOC_LITERAL(5, 65, 7), // "msgType"
QT_MOC_LITERAL(6, 73, 39), // "NotificationMessage::MessageD..."
QT_MOC_LITERAL(7, 113, 14), // "msgDisplayType"
QT_MOC_LITERAL(8, 128, 8), // "showView"
QT_MOC_LITERAL(9, 137, 15), // "Types::ViewType"
QT_MOC_LITERAL(10, 153, 4), // "view"
QT_MOC_LITERAL(11, 158, 23), // "QList<Types::ViewType>*"
QT_MOC_LITERAL(12, 182, 13), // "previousViews"
QT_MOC_LITERAL(13, 196, 8), // "clearAll"
QT_MOC_LITERAL(14, 205, 13), // "clearAnalysts"
QT_MOC_LITERAL(15, 219, 14), // "createdAnalyst"
QT_MOC_LITERAL(16, 234, 6), // "values"
QT_MOC_LITERAL(17, 241, 15), // "selectedAnalyst"
QT_MOC_LITERAL(18, 257, 14), // "updatedAnalyst"
QT_MOC_LITERAL(19, 272, 14), // "removedAnalyst"
QT_MOC_LITERAL(20, 287, 2), // "id"
QT_MOC_LITERAL(21, 290, 24), // "selectedBranchOfIndustry"
QT_MOC_LITERAL(22, 315, 19), // "selectedCorperation"
QT_MOC_LITERAL(23, 335, 15), // "selectedFactory"
QT_MOC_LITERAL(24, 351, 17), // "selectedRecording"
QT_MOC_LITERAL(25, 369, 15), // "clearWorkplaces"
QT_MOC_LITERAL(26, 385, 16), // "createdWorkplace"
QT_MOC_LITERAL(27, 402, 17), // "selectedWorkplace"
QT_MOC_LITERAL(28, 420, 16), // "updatedWorkplace"
QT_MOC_LITERAL(29, 437, 16), // "removedWorkplace"
QT_MOC_LITERAL(30, 454, 15), // "selectedComment"
QT_MOC_LITERAL(31, 470, 14), // "updatedComment"
QT_MOC_LITERAL(32, 485, 11), // "createdLine"
QT_MOC_LITERAL(33, 497, 11), // "updatedLine"
QT_MOC_LITERAL(34, 509, 8), // "editLine"
QT_MOC_LITERAL(35, 518, 11), // "removedLine"
QT_MOC_LITERAL(36, 530, 12), // "selectedLine"
QT_MOC_LITERAL(37, 543, 10), // "clearLines"
QT_MOC_LITERAL(38, 554, 14), // "clearEmployees"
QT_MOC_LITERAL(39, 569, 15), // "createdEmployee"
QT_MOC_LITERAL(40, 585, 16), // "selectedEmployee"
QT_MOC_LITERAL(41, 602, 15), // "updatedEmployee"
QT_MOC_LITERAL(42, 618, 15), // "removedEmployee"
QT_MOC_LITERAL(43, 634, 16), // "employeeSelected"
QT_MOC_LITERAL(44, 651, 23), // "selectedBodyMeasurement"
QT_MOC_LITERAL(45, 675, 13), // "clearProducts"
QT_MOC_LITERAL(46, 689, 14), // "createdProduct"
QT_MOC_LITERAL(47, 704, 14), // "updatedProduct"
QT_MOC_LITERAL(48, 719, 14), // "removedProduct"
QT_MOC_LITERAL(49, 734, 15), // "clearActivities"
QT_MOC_LITERAL(50, 750, 15), // "createdActivity"
QT_MOC_LITERAL(51, 766, 15), // "updatedActivity"
QT_MOC_LITERAL(52, 782, 15), // "removedActivity"
QT_MOC_LITERAL(53, 798, 12), // "editActivity"
QT_MOC_LITERAL(54, 811, 15), // "clearEquipments"
QT_MOC_LITERAL(55, 827, 16), // "createdEquipment"
QT_MOC_LITERAL(56, 844, 16), // "updatedEquipment"
QT_MOC_LITERAL(57, 861, 16), // "removedEquipment"
QT_MOC_LITERAL(58, 878, 20), // "clearTransportations"
QT_MOC_LITERAL(59, 899, 21), // "createdTransportation"
QT_MOC_LITERAL(60, 921, 21), // "updatedTransportation"
QT_MOC_LITERAL(61, 943, 21), // "removedTransportation"
QT_MOC_LITERAL(62, 965, 15), // "setLoadHandling"
QT_MOC_LITERAL(63, 981, 14), // "setBodyPosture"
QT_MOC_LITERAL(64, 996, 15), // "setAppliedForce"
QT_MOC_LITERAL(65, 1012, 14), // "setWorkProcess"
QT_MOC_LITERAL(66, 1027, 21), // "setExecutionCondition"
QT_MOC_LITERAL(67, 1049, 18), // "createdWorkProcess"
QT_MOC_LITERAL(68, 1068, 22), // "setSelectedWorkProcess"
QT_MOC_LITERAL(69, 1091, 25), // "setHasPreviousWorkProcess"
QT_MOC_LITERAL(70, 1117, 11), // "hasPrevious"
QT_MOC_LITERAL(71, 1129, 21), // "setHasNextWorkProcess"
QT_MOC_LITERAL(72, 1151, 7), // "hasNext"
QT_MOC_LITERAL(73, 1159, 26), // "setSelectedWorkProcessType"
QT_MOC_LITERAL(74, 1186, 6), // "AVType"
QT_MOC_LITERAL(75, 1193, 4), // "type"
QT_MOC_LITERAL(76, 1198, 24), // "initiliazedWorkProcesses"
QT_MOC_LITERAL(77, 1223, 31), // "QList<QHash<QString,QVariant> >"
QT_MOC_LITERAL(78, 1255, 13), // "selectedShift"
QT_MOC_LITERAL(79, 1269, 18), // "clearRotationGroup"
QT_MOC_LITERAL(80, 1288, 21), // "addRotationGroupEntry"
QT_MOC_LITERAL(81, 1310, 25), // "updatedRotationGroupEntry"
QT_MOC_LITERAL(82, 1336, 26), // "addRotationGroupBreakEntry"
QT_MOC_LITERAL(83, 1363, 23), // "clearRotationGroupTasks"
QT_MOC_LITERAL(84, 1387, 24), // "createdRotationGroupTask"
QT_MOC_LITERAL(85, 1412, 24), // "updatedRotationGroupTask"
QT_MOC_LITERAL(86, 1437, 24), // "removedRotationGroupTask"
QT_MOC_LITERAL(87, 1462, 25), // "selectedRotationGroupTask"
QT_MOC_LITERAL(88, 1488, 32), // "updatedRotationGroupTaskDuration"
QT_MOC_LITERAL(89, 1521, 8), // "duration"
QT_MOC_LITERAL(90, 1530, 29), // "clearRotationGroupTaskEntries"
QT_MOC_LITERAL(91, 1560, 29), // "createdRotationGroupTaskEntry"
QT_MOC_LITERAL(92, 1590, 29), // "removedRotationGroupTaskEntry"
QT_MOC_LITERAL(93, 1620, 18), // "initializeAnalysts"
QT_MOC_LITERAL(94, 1639, 13), // "createAnalyst"
QT_MOC_LITERAL(95, 1653, 13), // "deleteAnalyst"
QT_MOC_LITERAL(96, 1667, 13), // "selectAnalyst"
QT_MOC_LITERAL(97, 1681, 20), // "createBlankRecording"
QT_MOC_LITERAL(98, 1702, 19), // "setBranchOfIndustry"
QT_MOC_LITERAL(99, 1722, 20), // "saveBranchOfIndustry"
QT_MOC_LITERAL(100, 1743, 14), // "setCorperation"
QT_MOC_LITERAL(101, 1758, 15), // "saveCorperation"
QT_MOC_LITERAL(102, 1774, 10), // "setFactory"
QT_MOC_LITERAL(103, 1785, 11), // "saveFactory"
QT_MOC_LITERAL(104, 1797, 12), // "setRecording"
QT_MOC_LITERAL(105, 1810, 13), // "saveRecording"
QT_MOC_LITERAL(106, 1824, 20), // "initializeWorkplaces"
QT_MOC_LITERAL(107, 1845, 15), // "createWorkplace"
QT_MOC_LITERAL(108, 1861, 14), // "activityValues"
QT_MOC_LITERAL(109, 1876, 15), // "deleteWorkplace"
QT_MOC_LITERAL(110, 1892, 15), // "selectWorkplace"
QT_MOC_LITERAL(111, 1908, 13), // "saveWorkplace"
QT_MOC_LITERAL(112, 1922, 11), // "saveComment"
QT_MOC_LITERAL(113, 1934, 15), // "initializeLines"
QT_MOC_LITERAL(114, 1950, 10), // "createLine"
QT_MOC_LITERAL(115, 1961, 8), // "saveLine"
QT_MOC_LITERAL(116, 1970, 10), // "deleteLine"
QT_MOC_LITERAL(117, 1981, 10), // "selectLine"
QT_MOC_LITERAL(118, 1992, 18), // "initializeProducts"
QT_MOC_LITERAL(119, 2011, 13), // "createProduct"
QT_MOC_LITERAL(120, 2025, 11), // "saveProduct"
QT_MOC_LITERAL(121, 2037, 13), // "deleteProduct"
QT_MOC_LITERAL(122, 2051, 20), // "initializeActivities"
QT_MOC_LITERAL(123, 2072, 12), // "workplace_ID"
QT_MOC_LITERAL(124, 2085, 14), // "createActivity"
QT_MOC_LITERAL(125, 2100, 12), // "saveActivity"
QT_MOC_LITERAL(126, 2113, 14), // "deleteActivity"
QT_MOC_LITERAL(127, 2128, 7), // "showMsg"
QT_MOC_LITERAL(128, 2136, 14), // "selectActivity"
QT_MOC_LITERAL(129, 2151, 20), // "initializeEquipments"
QT_MOC_LITERAL(130, 2172, 15), // "createEquipment"
QT_MOC_LITERAL(131, 2188, 13), // "saveEquipment"
QT_MOC_LITERAL(132, 2202, 15), // "deleteEquipment"
QT_MOC_LITERAL(133, 2218, 24), // "initializeTansportations"
QT_MOC_LITERAL(134, 2243, 20), // "createTransportation"
QT_MOC_LITERAL(135, 2264, 18), // "saveTransportation"
QT_MOC_LITERAL(136, 2283, 20), // "deleteTransportation"
QT_MOC_LITERAL(137, 2304, 16), // "saveLoadHandling"
QT_MOC_LITERAL(138, 2321, 15), // "saveBodyPosture"
QT_MOC_LITERAL(139, 2337, 16), // "saveAppliedForce"
QT_MOC_LITERAL(140, 2354, 15), // "saveWorkProcess"
QT_MOC_LITERAL(141, 2370, 22), // "saveExecutionCondition"
QT_MOC_LITERAL(142, 2393, 22), // "initilizeWorkProcesses"
QT_MOC_LITERAL(143, 2416, 11), // "selectFirst"
QT_MOC_LITERAL(144, 2428, 17), // "createWorkprocess"
QT_MOC_LITERAL(145, 2446, 21), // "createWorkprocessList"
QT_MOC_LITERAL(146, 2468, 13), // "workplaceName"
QT_MOC_LITERAL(147, 2482, 12), // "activityName"
QT_MOC_LITERAL(148, 2495, 13), // "workprocesses"
QT_MOC_LITERAL(149, 2509, 21), // "selectNextWorkProcess"
QT_MOC_LITERAL(150, 2531, 25), // "selectPreviousWorkProcess"
QT_MOC_LITERAL(151, 2557, 22), // "workProcessTypeChanged"
QT_MOC_LITERAL(152, 2580, 18), // "resetWorkProcesses"
QT_MOC_LITERAL(153, 2599, 26), // "workProcessDurationChanged"
QT_MOC_LITERAL(154, 2626, 4), // "time"
QT_MOC_LITERAL(155, 2631, 17), // "selectWorkProcess"
QT_MOC_LITERAL(156, 2649, 24), // "saveWorkProcessFrequence"
QT_MOC_LITERAL(157, 2674, 9), // "frequence"
QT_MOC_LITERAL(158, 2684, 19), // "initializeEmployees"
QT_MOC_LITERAL(159, 2704, 14), // "createEmployee"
QT_MOC_LITERAL(160, 2719, 21), // "bodyMeasurementValues"
QT_MOC_LITERAL(161, 2741, 14), // "deleteEmployee"
QT_MOC_LITERAL(162, 2756, 14), // "selectEmployee"
QT_MOC_LITERAL(163, 2771, 12), // "saveEmployee"
QT_MOC_LITERAL(164, 2784, 19), // "setSelectedEmployee"
QT_MOC_LITERAL(165, 2804, 22), // "resetEmployeeSelection"
QT_MOC_LITERAL(166, 2827, 19), // "saveBodyMeasurement"
QT_MOC_LITERAL(167, 2847, 24), // "initializeFTPConnections"
QT_MOC_LITERAL(168, 2872, 16), // "IFTPConnections*"
QT_MOC_LITERAL(169, 2889, 6), // "widget"
QT_MOC_LITERAL(170, 2896, 19), // "createFTPConnection"
QT_MOC_LITERAL(171, 2916, 17), // "editFTPConnection"
QT_MOC_LITERAL(172, 2934, 19), // "selectFTPConnection"
QT_MOC_LITERAL(173, 2954, 10), // "importData"
QT_MOC_LITERAL(174, 2965, 12), // "IImportData*"
QT_MOC_LITERAL(175, 2978, 26), // "importDataDownloadFinished"
QT_MOC_LITERAL(176, 3005, 23), // "importDataDownloadError"
QT_MOC_LITERAL(177, 3029, 5), // "error"
QT_MOC_LITERAL(178, 3035, 8), // "sendData"
QT_MOC_LITERAL(179, 3044, 10), // "ISendData*"
QT_MOC_LITERAL(180, 3055, 21), // "sendDataUploadStarted"
QT_MOC_LITERAL(181, 3077, 22), // "sendDataUploadFinished"
QT_MOC_LITERAL(182, 3100, 8), // "filename"
QT_MOC_LITERAL(183, 3109, 19), // "sendDataUploadError"
QT_MOC_LITERAL(184, 3129, 15), // "initializeShift"
QT_MOC_LITERAL(185, 3145, 9), // "saveShift"
QT_MOC_LITERAL(186, 3155, 23), // "initializeRotationGroup"
QT_MOC_LITERAL(187, 3179, 24), // "createRotationGroupEntry"
QT_MOC_LITERAL(188, 3204, 29), // "createRotationGroupBreakEntry"
QT_MOC_LITERAL(189, 3234, 24), // "deleteRotationGroupEntry"
QT_MOC_LITERAL(190, 3259, 5), // "order"
QT_MOC_LITERAL(191, 3265, 24), // "moveRotationGroupEntryUp"
QT_MOC_LITERAL(192, 3290, 26), // "moveRotationGroupEntryDown"
QT_MOC_LITERAL(193, 3317, 28), // "initializeRotationGroupTasks"
QT_MOC_LITERAL(194, 3346, 23), // "createRotationGroupTask"
QT_MOC_LITERAL(195, 3370, 23), // "deleteRotationGroupTask"
QT_MOC_LITERAL(196, 3394, 23), // "selectRotationGroupTask"
QT_MOC_LITERAL(197, 3418, 21), // "saveRotationGroupTask"
QT_MOC_LITERAL(198, 3440, 34), // "initializeRotationGroupTaskEn..."
QT_MOC_LITERAL(199, 3475, 28), // "createRotationGroupTaskEntry"
QT_MOC_LITERAL(200, 3504, 28), // "deleteRotationGroupTaskEntry"
QT_MOC_LITERAL(201, 3533, 20), // "resetDatabaseFactory"
QT_MOC_LITERAL(202, 3554, 20), // "resetSelectedEntries"
QT_MOC_LITERAL(203, 3575, 23), // "ISelectedDatabaseReset*"
QT_MOC_LITERAL(204, 3599, 11) // "changeTheme"

    },
    "Controller\0showMessage\0\0message\0"
    "NotificationMessage::MessageType\0"
    "msgType\0NotificationMessage::MessageDisplayType\0"
    "msgDisplayType\0showView\0Types::ViewType\0"
    "view\0QList<Types::ViewType>*\0previousViews\0"
    "clearAll\0clearAnalysts\0createdAnalyst\0"
    "values\0selectedAnalyst\0updatedAnalyst\0"
    "removedAnalyst\0id\0selectedBranchOfIndustry\0"
    "selectedCorperation\0selectedFactory\0"
    "selectedRecording\0clearWorkplaces\0"
    "createdWorkplace\0selectedWorkplace\0"
    "updatedWorkplace\0removedWorkplace\0"
    "selectedComment\0updatedComment\0"
    "createdLine\0updatedLine\0editLine\0"
    "removedLine\0selectedLine\0clearLines\0"
    "clearEmployees\0createdEmployee\0"
    "selectedEmployee\0updatedEmployee\0"
    "removedEmployee\0employeeSelected\0"
    "selectedBodyMeasurement\0clearProducts\0"
    "createdProduct\0updatedProduct\0"
    "removedProduct\0clearActivities\0"
    "createdActivity\0updatedActivity\0"
    "removedActivity\0editActivity\0"
    "clearEquipments\0createdEquipment\0"
    "updatedEquipment\0removedEquipment\0"
    "clearTransportations\0createdTransportation\0"
    "updatedTransportation\0removedTransportation\0"
    "setLoadHandling\0setBodyPosture\0"
    "setAppliedForce\0setWorkProcess\0"
    "setExecutionCondition\0createdWorkProcess\0"
    "setSelectedWorkProcess\0setHasPreviousWorkProcess\0"
    "hasPrevious\0setHasNextWorkProcess\0"
    "hasNext\0setSelectedWorkProcessType\0"
    "AVType\0type\0initiliazedWorkProcesses\0"
    "QList<QHash<QString,QVariant> >\0"
    "selectedShift\0clearRotationGroup\0"
    "addRotationGroupEntry\0updatedRotationGroupEntry\0"
    "addRotationGroupBreakEntry\0"
    "clearRotationGroupTasks\0"
    "createdRotationGroupTask\0"
    "updatedRotationGroupTask\0"
    "removedRotationGroupTask\0"
    "selectedRotationGroupTask\0"
    "updatedRotationGroupTaskDuration\0"
    "duration\0clearRotationGroupTaskEntries\0"
    "createdRotationGroupTaskEntry\0"
    "removedRotationGroupTaskEntry\0"
    "initializeAnalysts\0createAnalyst\0"
    "deleteAnalyst\0selectAnalyst\0"
    "createBlankRecording\0setBranchOfIndustry\0"
    "saveBranchOfIndustry\0setCorperation\0"
    "saveCorperation\0setFactory\0saveFactory\0"
    "setRecording\0saveRecording\0"
    "initializeWorkplaces\0createWorkplace\0"
    "activityValues\0deleteWorkplace\0"
    "selectWorkplace\0saveWorkplace\0saveComment\0"
    "initializeLines\0createLine\0saveLine\0"
    "deleteLine\0selectLine\0initializeProducts\0"
    "createProduct\0saveProduct\0deleteProduct\0"
    "initializeActivities\0workplace_ID\0"
    "createActivity\0saveActivity\0deleteActivity\0"
    "showMsg\0selectActivity\0initializeEquipments\0"
    "createEquipment\0saveEquipment\0"
    "deleteEquipment\0initializeTansportations\0"
    "createTransportation\0saveTransportation\0"
    "deleteTransportation\0saveLoadHandling\0"
    "saveBodyPosture\0saveAppliedForce\0"
    "saveWorkProcess\0saveExecutionCondition\0"
    "initilizeWorkProcesses\0selectFirst\0"
    "createWorkprocess\0createWorkprocessList\0"
    "workplaceName\0activityName\0workprocesses\0"
    "selectNextWorkProcess\0selectPreviousWorkProcess\0"
    "workProcessTypeChanged\0resetWorkProcesses\0"
    "workProcessDurationChanged\0time\0"
    "selectWorkProcess\0saveWorkProcessFrequence\0"
    "frequence\0initializeEmployees\0"
    "createEmployee\0bodyMeasurementValues\0"
    "deleteEmployee\0selectEmployee\0"
    "saveEmployee\0setSelectedEmployee\0"
    "resetEmployeeSelection\0saveBodyMeasurement\0"
    "initializeFTPConnections\0IFTPConnections*\0"
    "widget\0createFTPConnection\0editFTPConnection\0"
    "selectFTPConnection\0importData\0"
    "IImportData*\0importDataDownloadFinished\0"
    "importDataDownloadError\0error\0sendData\0"
    "ISendData*\0sendDataUploadStarted\0"
    "sendDataUploadFinished\0filename\0"
    "sendDataUploadError\0initializeShift\0"
    "saveShift\0initializeRotationGroup\0"
    "createRotationGroupEntry\0"
    "createRotationGroupBreakEntry\0"
    "deleteRotationGroupEntry\0order\0"
    "moveRotationGroupEntryUp\0"
    "moveRotationGroupEntryDown\0"
    "initializeRotationGroupTasks\0"
    "createRotationGroupTask\0deleteRotationGroupTask\0"
    "selectRotationGroupTask\0saveRotationGroupTask\0"
    "initializeRotationGroupTaskEntries\0"
    "createRotationGroupTaskEntry\0"
    "deleteRotationGroupTaskEntry\0"
    "resetDatabaseFactory\0resetSelectedEntries\0"
    "ISelectedDatabaseReset*\0changeTheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     178,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      77,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  904,    2, 0x06 /* Public */,
       1,    2,  911,    2, 0x26 /* Public | MethodCloned */,
       1,    1,  916,    2, 0x26 /* Public | MethodCloned */,
       8,    2,  919,    2, 0x06 /* Public */,
       8,    1,  924,    2, 0x26 /* Public | MethodCloned */,
      13,    0,  927,    2, 0x06 /* Public */,
      14,    0,  928,    2, 0x06 /* Public */,
      15,    1,  929,    2, 0x06 /* Public */,
      17,    1,  932,    2, 0x06 /* Public */,
      18,    1,  935,    2, 0x06 /* Public */,
      19,    1,  938,    2, 0x06 /* Public */,
      21,    1,  941,    2, 0x06 /* Public */,
      22,    1,  944,    2, 0x06 /* Public */,
      23,    1,  947,    2, 0x06 /* Public */,
      24,    1,  950,    2, 0x06 /* Public */,
      25,    0,  953,    2, 0x06 /* Public */,
      26,    1,  954,    2, 0x06 /* Public */,
      27,    1,  957,    2, 0x06 /* Public */,
      28,    1,  960,    2, 0x06 /* Public */,
      29,    1,  963,    2, 0x06 /* Public */,
      30,    1,  966,    2, 0x06 /* Public */,
      31,    1,  969,    2, 0x06 /* Public */,
      32,    1,  972,    2, 0x06 /* Public */,
      33,    1,  975,    2, 0x06 /* Public */,
      34,    1,  978,    2, 0x06 /* Public */,
      35,    1,  981,    2, 0x06 /* Public */,
      36,    1,  984,    2, 0x06 /* Public */,
      37,    0,  987,    2, 0x06 /* Public */,
      38,    0,  988,    2, 0x06 /* Public */,
      39,    1,  989,    2, 0x06 /* Public */,
      40,    1,  992,    2, 0x06 /* Public */,
      41,    1,  995,    2, 0x06 /* Public */,
      42,    1,  998,    2, 0x06 /* Public */,
      43,    1, 1001,    2, 0x06 /* Public */,
      44,    1, 1004,    2, 0x06 /* Public */,
      45,    0, 1007,    2, 0x06 /* Public */,
      46,    1, 1008,    2, 0x06 /* Public */,
      47,    1, 1011,    2, 0x06 /* Public */,
      48,    1, 1014,    2, 0x06 /* Public */,
      49,    0, 1017,    2, 0x06 /* Public */,
      50,    1, 1018,    2, 0x06 /* Public */,
      51,    1, 1021,    2, 0x06 /* Public */,
      52,    1, 1024,    2, 0x06 /* Public */,
      53,    1, 1027,    2, 0x06 /* Public */,
      54,    0, 1030,    2, 0x06 /* Public */,
      55,    1, 1031,    2, 0x06 /* Public */,
      56,    1, 1034,    2, 0x06 /* Public */,
      57,    1, 1037,    2, 0x06 /* Public */,
      58,    0, 1040,    2, 0x06 /* Public */,
      59,    1, 1041,    2, 0x06 /* Public */,
      60,    1, 1044,    2, 0x06 /* Public */,
      61,    1, 1047,    2, 0x06 /* Public */,
      62,    1, 1050,    2, 0x06 /* Public */,
      63,    1, 1053,    2, 0x06 /* Public */,
      64,    1, 1056,    2, 0x06 /* Public */,
      65,    1, 1059,    2, 0x06 /* Public */,
      66,    1, 1062,    2, 0x06 /* Public */,
      67,    1, 1065,    2, 0x06 /* Public */,
      68,    1, 1068,    2, 0x06 /* Public */,
      69,    1, 1071,    2, 0x06 /* Public */,
      71,    1, 1074,    2, 0x06 /* Public */,
      73,    1, 1077,    2, 0x06 /* Public */,
      76,    1, 1080,    2, 0x06 /* Public */,
      78,    1, 1083,    2, 0x06 /* Public */,
      79,    0, 1086,    2, 0x06 /* Public */,
      80,    1, 1087,    2, 0x06 /* Public */,
      81,    1, 1090,    2, 0x06 /* Public */,
      82,    1, 1093,    2, 0x06 /* Public */,
      83,    0, 1096,    2, 0x06 /* Public */,
      84,    1, 1097,    2, 0x06 /* Public */,
      85,    1, 1100,    2, 0x06 /* Public */,
      86,    1, 1103,    2, 0x06 /* Public */,
      87,    1, 1106,    2, 0x06 /* Public */,
      88,    1, 1109,    2, 0x06 /* Public */,
      90,    0, 1112,    2, 0x06 /* Public */,
      91,    1, 1113,    2, 0x06 /* Public */,
      92,    1, 1116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      93,    0, 1119,    2, 0x0a /* Public */,
      94,    1, 1120,    2, 0x0a /* Public */,
      95,    1, 1123,    2, 0x0a /* Public */,
      96,    1, 1126,    2, 0x0a /* Public */,
      97,    0, 1129,    2, 0x0a /* Public */,
      98,    1, 1130,    2, 0x0a /* Public */,
      99,    1, 1133,    2, 0x0a /* Public */,
     100,    1, 1136,    2, 0x0a /* Public */,
     101,    1, 1139,    2, 0x0a /* Public */,
     102,    1, 1142,    2, 0x0a /* Public */,
     103,    1, 1145,    2, 0x0a /* Public */,
     104,    1, 1148,    2, 0x0a /* Public */,
     105,    1, 1151,    2, 0x0a /* Public */,
     106,    0, 1154,    2, 0x0a /* Public */,
     107,    1, 1155,    2, 0x0a /* Public */,
     107,    2, 1158,    2, 0x0a /* Public */,
     109,    1, 1163,    2, 0x0a /* Public */,
     110,    1, 1166,    2, 0x0a /* Public */,
     111,    1, 1169,    2, 0x0a /* Public */,
     112,    1, 1172,    2, 0x0a /* Public */,
     113,    0, 1175,    2, 0x0a /* Public */,
     114,    1, 1176,    2, 0x0a /* Public */,
      34,    1, 1179,    2, 0x0a /* Public */,
     115,    1, 1182,    2, 0x0a /* Public */,
     116,    1, 1185,    2, 0x0a /* Public */,
     117,    1, 1188,    2, 0x0a /* Public */,
     118,    0, 1191,    2, 0x0a /* Public */,
     119,    1, 1192,    2, 0x0a /* Public */,
     120,    1, 1195,    2, 0x0a /* Public */,
     121,    1, 1198,    2, 0x0a /* Public */,
     122,    1, 1201,    2, 0x0a /* Public */,
     124,    1, 1204,    2, 0x0a /* Public */,
     125,    1, 1207,    2, 0x0a /* Public */,
     126,    2, 1210,    2, 0x0a /* Public */,
     126,    1, 1215,    2, 0x2a /* Public | MethodCloned */,
     128,    1, 1218,    2, 0x0a /* Public */,
      53,    1, 1221,    2, 0x0a /* Public */,
     129,    0, 1224,    2, 0x0a /* Public */,
     130,    1, 1225,    2, 0x0a /* Public */,
     131,    1, 1228,    2, 0x0a /* Public */,
     132,    1, 1231,    2, 0x0a /* Public */,
     133,    0, 1234,    2, 0x0a /* Public */,
     134,    1, 1235,    2, 0x0a /* Public */,
     135,    1, 1238,    2, 0x0a /* Public */,
     136,    1, 1241,    2, 0x0a /* Public */,
     137,    1, 1244,    2, 0x0a /* Public */,
     138,    1, 1247,    2, 0x0a /* Public */,
     139,    1, 1250,    2, 0x0a /* Public */,
     140,    1, 1253,    2, 0x0a /* Public */,
     141,    1, 1256,    2, 0x0a /* Public */,
     142,    1, 1259,    2, 0x0a /* Public */,
     142,    0, 1262,    2, 0x2a /* Public | MethodCloned */,
     144,    1, 1263,    2, 0x0a /* Public */,
     145,    3, 1266,    2, 0x0a /* Public */,
     149,    0, 1273,    2, 0x0a /* Public */,
     150,    0, 1274,    2, 0x0a /* Public */,
     151,    1, 1275,    2, 0x0a /* Public */,
     152,    0, 1278,    2, 0x0a /* Public */,
     153,    1, 1279,    2, 0x0a /* Public */,
     155,    2, 1282,    2, 0x0a /* Public */,
     156,    1, 1287,    2, 0x0a /* Public */,
     158,    0, 1290,    2, 0x0a /* Public */,
     159,    1, 1291,    2, 0x0a /* Public */,
     159,    2, 1294,    2, 0x0a /* Public */,
     161,    1, 1299,    2, 0x0a /* Public */,
     162,    1, 1302,    2, 0x0a /* Public */,
     163,    1, 1305,    2, 0x0a /* Public */,
     164,    1, 1308,    2, 0x0a /* Public */,
     165,    0, 1311,    2, 0x0a /* Public */,
     166,    1, 1312,    2, 0x0a /* Public */,
     167,    1, 1315,    2, 0x0a /* Public */,
     170,    1, 1318,    2, 0x0a /* Public */,
     171,    2, 1321,    2, 0x0a /* Public */,
     172,    2, 1326,    2, 0x0a /* Public */,
     173,    1, 1331,    2, 0x0a /* Public */,
     175,    1, 1334,    2, 0x0a /* Public */,
     176,    1, 1337,    2, 0x0a /* Public */,
     178,    1, 1340,    2, 0x0a /* Public */,
     180,    0, 1343,    2, 0x0a /* Public */,
     181,    1, 1344,    2, 0x0a /* Public */,
     183,    1, 1347,    2, 0x0a /* Public */,
     184,    1, 1350,    2, 0x0a /* Public */,
     185,    1, 1353,    2, 0x0a /* Public */,
     186,    1, 1356,    2, 0x0a /* Public */,
     187,    1, 1359,    2, 0x0a /* Public */,
     188,    1, 1362,    2, 0x0a /* Public */,
     189,    1, 1365,    2, 0x0a /* Public */,
     191,    1, 1368,    2, 0x0a /* Public */,
     192,    1, 1371,    2, 0x0a /* Public */,
     193,    0, 1374,    2, 0x0a /* Public */,
     194,    1, 1375,    2, 0x0a /* Public */,
     195,    1, 1378,    2, 0x0a /* Public */,
     196,    1, 1381,    2, 0x0a /* Public */,
     197,    1, 1384,    2, 0x0a /* Public */,
     198,    1, 1387,    2, 0x0a /* Public */,
     199,    1, 1390,    2, 0x0a /* Public */,
     200,    2, 1393,    2, 0x0a /* Public */,
     200,    1, 1398,    2, 0x2a /* Public | MethodCloned */,
     201,    0, 1401,    2, 0x0a /* Public */,
     202,    1, 1402,    2, 0x0a /* Public */,
     204,    0, 1405,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Bool,   70,
    QMetaType::Void, QMetaType::Bool,   72,
    QMetaType::Void, 0x80000000 | 74,   75,
    QMetaType::Void, 0x80000000 | 77,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash, 0x80000000 | 77,   16,  108,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,  123,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,  127,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Bool,  143,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 77,  146,  147,  148,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 74,   75,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,  154,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 74,   20,   75,
    QMetaType::Void, QMetaType::Int,  157,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash, QMetaType::QVariantHash,   16,  160,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, 0x80000000 | 168,  169,
    QMetaType::Void, 0x80000000 | 168,  169,
    QMetaType::Void, 0x80000000 | 168, QMetaType::Int,  169,   20,
    QMetaType::Void, 0x80000000 | 168, QMetaType::Int,  169,   20,
    QMetaType::Void, 0x80000000 | 174,  169,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,  177,
    QMetaType::Void, 0x80000000 | 179,  169,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  182,
    QMetaType::Void, QMetaType::QString,  177,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,  190,
    QMetaType::Void, QMetaType::Int,  190,
    QMetaType::Void, QMetaType::Int,  190,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QVariantHash,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,  127,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 203,  169,
    QMetaType::Void,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        switch (_id) {
        case 0: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< NotificationMessage::MessageType(*)>(_a[2])),(*reinterpret_cast< NotificationMessage::MessageDisplayType(*)>(_a[3]))); break;
        case 1: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< NotificationMessage::MessageType(*)>(_a[2]))); break;
        case 2: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->showView((*reinterpret_cast< Types::ViewType(*)>(_a[1])),(*reinterpret_cast< QList<Types::ViewType>*(*)>(_a[2]))); break;
        case 4: _t->showView((*reinterpret_cast< Types::ViewType(*)>(_a[1]))); break;
        case 5: _t->clearAll(); break;
        case 6: _t->clearAnalysts(); break;
        case 7: _t->createdAnalyst((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 8: _t->selectedAnalyst((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 9: _t->updatedAnalyst((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 10: _t->removedAnalyst((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->selectedBranchOfIndustry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 12: _t->selectedCorperation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 13: _t->selectedFactory((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 14: _t->selectedRecording((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 15: _t->clearWorkplaces(); break;
        case 16: _t->createdWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 17: _t->selectedWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 18: _t->updatedWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 19: _t->removedWorkplace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->selectedComment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 21: _t->updatedComment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 22: _t->createdLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 23: _t->updatedLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 24: _t->editLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 25: _t->removedLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->selectedLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 27: _t->clearLines(); break;
        case 28: _t->clearEmployees(); break;
        case 29: _t->createdEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 30: _t->selectedEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 31: _t->updatedEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 32: _t->removedEmployee((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->employeeSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->selectedBodyMeasurement((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 35: _t->clearProducts(); break;
        case 36: _t->createdProduct((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 37: _t->updatedProduct((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 38: _t->removedProduct((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->clearActivities(); break;
        case 40: _t->createdActivity((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 41: _t->updatedActivity((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 42: _t->removedActivity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->editActivity((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 44: _t->clearEquipments(); break;
        case 45: _t->createdEquipment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 46: _t->updatedEquipment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 47: _t->removedEquipment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->clearTransportations(); break;
        case 49: _t->createdTransportation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 50: _t->updatedTransportation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 51: _t->removedTransportation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->setLoadHandling((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 53: _t->setBodyPosture((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 54: _t->setAppliedForce((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 55: _t->setWorkProcess((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 56: _t->setExecutionCondition((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 57: _t->createdWorkProcess((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 58: _t->setSelectedWorkProcess((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 59: _t->setHasPreviousWorkProcess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 60: _t->setHasNextWorkProcess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 61: _t->setSelectedWorkProcessType((*reinterpret_cast< AVType(*)>(_a[1]))); break;
        case 62: _t->initiliazedWorkProcesses((*reinterpret_cast< QList<QHash<QString,QVariant> >(*)>(_a[1]))); break;
        case 63: _t->selectedShift((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 64: _t->clearRotationGroup(); break;
        case 65: _t->addRotationGroupEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 66: _t->updatedRotationGroupEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 67: _t->addRotationGroupBreakEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 68: _t->clearRotationGroupTasks(); break;
        case 69: _t->createdRotationGroupTask((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 70: _t->updatedRotationGroupTask((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 71: _t->removedRotationGroupTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->selectedRotationGroupTask((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 73: _t->updatedRotationGroupTaskDuration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: _t->clearRotationGroupTaskEntries(); break;
        case 75: _t->createdRotationGroupTaskEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 76: _t->removedRotationGroupTaskEntry((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->initializeAnalysts(); break;
        case 78: _t->createAnalyst((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 79: _t->deleteAnalyst((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->selectAnalyst((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->createBlankRecording(); break;
        case 82: _t->setBranchOfIndustry((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 83: _t->saveBranchOfIndustry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 84: _t->setCorperation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->saveCorperation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 86: _t->setFactory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 87: _t->saveFactory((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 88: _t->setRecording((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 89: _t->saveRecording((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 90: _t->initializeWorkplaces(); break;
        case 91: _t->createWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 92: _t->createWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QHash<QString,QVariant> >(*)>(_a[2]))); break;
        case 93: _t->deleteWorkplace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 94: _t->selectWorkplace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: _t->saveWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 96: _t->saveComment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 97: _t->initializeLines(); break;
        case 98: _t->createLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 99: _t->editLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->saveLine((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 101: _t->deleteLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: _t->selectLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: _t->initializeProducts(); break;
        case 104: _t->createProduct((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 105: _t->saveProduct((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 106: _t->deleteProduct((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 107: _t->initializeActivities((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 108: _t->createActivity((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 109: _t->saveActivity((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 110: _t->deleteActivity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 111: _t->deleteActivity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 112: _t->selectActivity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 113: _t->editActivity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 114: _t->initializeEquipments(); break;
        case 115: _t->createEquipment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 116: _t->saveEquipment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 117: _t->deleteEquipment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 118: _t->initializeTansportations(); break;
        case 119: _t->createTransportation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 120: _t->saveTransportation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 121: _t->deleteTransportation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 122: _t->saveLoadHandling((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 123: _t->saveBodyPosture((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 124: _t->saveAppliedForce((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 125: _t->saveWorkProcess((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 126: _t->saveExecutionCondition((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 127: _t->initilizeWorkProcesses((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 128: _t->initilizeWorkProcesses(); break;
        case 129: _t->createWorkprocess((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 130: _t->createWorkprocessList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QHash<QString,QVariant> >(*)>(_a[3]))); break;
        case 131: _t->selectNextWorkProcess(); break;
        case 132: _t->selectPreviousWorkProcess(); break;
        case 133: _t->workProcessTypeChanged((*reinterpret_cast< AVType(*)>(_a[1]))); break;
        case 134: _t->resetWorkProcesses(); break;
        case 135: _t->workProcessDurationChanged((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 136: _t->selectWorkProcess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< AVType(*)>(_a[2]))); break;
        case 137: _t->saveWorkProcessFrequence((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 138: _t->initializeEmployees(); break;
        case 139: _t->createEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 140: _t->createEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[2]))); break;
        case 141: _t->deleteEmployee((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 142: _t->selectEmployee((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 143: _t->saveEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 144: _t->setSelectedEmployee((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 145: _t->resetEmployeeSelection(); break;
        case 146: _t->saveBodyMeasurement((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 147: _t->initializeFTPConnections((*reinterpret_cast< IFTPConnections*(*)>(_a[1]))); break;
        case 148: _t->createFTPConnection((*reinterpret_cast< IFTPConnections*(*)>(_a[1]))); break;
        case 149: _t->editFTPConnection((*reinterpret_cast< IFTPConnections*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 150: _t->selectFTPConnection((*reinterpret_cast< IFTPConnections*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 151: _t->importData((*reinterpret_cast< IImportData*(*)>(_a[1]))); break;
        case 152: _t->importDataDownloadFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 153: _t->importDataDownloadError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 154: _t->sendData((*reinterpret_cast< ISendData*(*)>(_a[1]))); break;
        case 155: _t->sendDataUploadStarted(); break;
        case 156: _t->sendDataUploadFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 157: _t->sendDataUploadError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 158: _t->initializeShift((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 159: _t->saveShift((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 160: _t->initializeRotationGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 161: _t->createRotationGroupEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 162: _t->createRotationGroupBreakEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 163: _t->deleteRotationGroupEntry((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 164: _t->moveRotationGroupEntryUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 165: _t->moveRotationGroupEntryDown((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 166: _t->initializeRotationGroupTasks(); break;
        case 167: _t->createRotationGroupTask((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 168: _t->deleteRotationGroupTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 169: _t->selectRotationGroupTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 170: _t->saveRotationGroupTask((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 171: _t->initializeRotationGroupTaskEntries((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 172: _t->createRotationGroupTaskEntry((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 173: _t->deleteRotationGroupTaskEntry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 174: _t->deleteRotationGroupTaskEntry((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 175: _t->resetDatabaseFactory(); break;
        case 176: _t->resetSelectedEntries((*reinterpret_cast< ISelectedDatabaseReset*(*)>(_a[1]))); break;
        case 177: _t->changeTheme(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 62:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QHash<QString,QVariant> > >(); break;
            }
            break;
        case 92:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QHash<QString,QVariant> > >(); break;
            }
            break;
        case 130:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QHash<QString,QVariant> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(QString , NotificationMessage::MessageType , NotificationMessage::MessageDisplayType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::showMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (Controller::*_t)(Types::ViewType , QList<Types::ViewType> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::showView)) {
                *result = 3;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearAll)) {
                *result = 5;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearAnalysts)) {
                *result = 6;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdAnalyst)) {
                *result = 7;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedAnalyst)) {
                *result = 8;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedAnalyst)) {
                *result = 9;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedAnalyst)) {
                *result = 10;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedBranchOfIndustry)) {
                *result = 11;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedCorperation)) {
                *result = 12;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedFactory)) {
                *result = 13;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedRecording)) {
                *result = 14;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearWorkplaces)) {
                *result = 15;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdWorkplace)) {
                *result = 16;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedWorkplace)) {
                *result = 17;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedWorkplace)) {
                *result = 18;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedWorkplace)) {
                *result = 19;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedComment)) {
                *result = 20;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedComment)) {
                *result = 21;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdLine)) {
                *result = 22;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedLine)) {
                *result = 23;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::editLine)) {
                *result = 24;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedLine)) {
                *result = 25;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedLine)) {
                *result = 26;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearLines)) {
                *result = 27;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearEmployees)) {
                *result = 28;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdEmployee)) {
                *result = 29;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedEmployee)) {
                *result = 30;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedEmployee)) {
                *result = 31;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedEmployee)) {
                *result = 32;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::employeeSelected)) {
                *result = 33;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedBodyMeasurement)) {
                *result = 34;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearProducts)) {
                *result = 35;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdProduct)) {
                *result = 36;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedProduct)) {
                *result = 37;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedProduct)) {
                *result = 38;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearActivities)) {
                *result = 39;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdActivity)) {
                *result = 40;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedActivity)) {
                *result = 41;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedActivity)) {
                *result = 42;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::editActivity)) {
                *result = 43;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearEquipments)) {
                *result = 44;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdEquipment)) {
                *result = 45;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedEquipment)) {
                *result = 46;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedEquipment)) {
                *result = 47;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearTransportations)) {
                *result = 48;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdTransportation)) {
                *result = 49;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedTransportation)) {
                *result = 50;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedTransportation)) {
                *result = 51;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setLoadHandling)) {
                *result = 52;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setBodyPosture)) {
                *result = 53;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setAppliedForce)) {
                *result = 54;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setWorkProcess)) {
                *result = 55;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setExecutionCondition)) {
                *result = 56;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdWorkProcess)) {
                *result = 57;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setSelectedWorkProcess)) {
                *result = 58;
            }
        }
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setHasPreviousWorkProcess)) {
                *result = 59;
            }
        }
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setHasNextWorkProcess)) {
                *result = 60;
            }
        }
        {
            typedef void (Controller::*_t)(AVType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::setSelectedWorkProcessType)) {
                *result = 61;
            }
        }
        {
            typedef void (Controller::*_t)(QList<QHash<QString,QVariant>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::initiliazedWorkProcesses)) {
                *result = 62;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedShift)) {
                *result = 63;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearRotationGroup)) {
                *result = 64;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::addRotationGroupEntry)) {
                *result = 65;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedRotationGroupEntry)) {
                *result = 66;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::addRotationGroupBreakEntry)) {
                *result = 67;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearRotationGroupTasks)) {
                *result = 68;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdRotationGroupTask)) {
                *result = 69;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedRotationGroupTask)) {
                *result = 70;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedRotationGroupTask)) {
                *result = 71;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::selectedRotationGroupTask)) {
                *result = 72;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::updatedRotationGroupTaskDuration)) {
                *result = 73;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::clearRotationGroupTaskEntries)) {
                *result = 74;
            }
        }
        {
            typedef void (Controller::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::createdRotationGroupTaskEntry)) {
                *result = 75;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::removedRotationGroupTaskEntry)) {
                *result = 76;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 178)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 178;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 178)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 178;
    }
    return _id;
}

// SIGNAL 0
void Controller::showMessage(QString _t1, NotificationMessage::MessageType _t2, NotificationMessage::MessageDisplayType _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 3
void Controller::showView(Types::ViewType _t1, QList<Types::ViewType> * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void Controller::clearAll()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Controller::clearAnalysts()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Controller::createdAnalyst(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::selectedAnalyst(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Controller::updatedAnalyst(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Controller::removedAnalyst(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Controller::selectedBranchOfIndustry(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Controller::selectedCorperation(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Controller::selectedFactory(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Controller::selectedRecording(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Controller::clearWorkplaces()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void Controller::createdWorkplace(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Controller::selectedWorkplace(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Controller::updatedWorkplace(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Controller::removedWorkplace(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Controller::selectedComment(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Controller::updatedComment(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Controller::createdLine(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Controller::updatedLine(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Controller::editLine(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Controller::removedLine(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void Controller::selectedLine(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Controller::clearLines()
{
    QMetaObject::activate(this, &staticMetaObject, 27, Q_NULLPTR);
}

// SIGNAL 28
void Controller::clearEmployees()
{
    QMetaObject::activate(this, &staticMetaObject, 28, Q_NULLPTR);
}

// SIGNAL 29
void Controller::createdEmployee(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void Controller::selectedEmployee(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void Controller::updatedEmployee(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void Controller::removedEmployee(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void Controller::employeeSelected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void Controller::selectedBodyMeasurement(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void Controller::clearProducts()
{
    QMetaObject::activate(this, &staticMetaObject, 35, Q_NULLPTR);
}

// SIGNAL 36
void Controller::createdProduct(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void Controller::updatedProduct(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void Controller::removedProduct(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void Controller::clearActivities()
{
    QMetaObject::activate(this, &staticMetaObject, 39, Q_NULLPTR);
}

// SIGNAL 40
void Controller::createdActivity(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void Controller::updatedActivity(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 42
void Controller::removedActivity(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void Controller::editActivity(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 43, _a);
}

// SIGNAL 44
void Controller::clearEquipments()
{
    QMetaObject::activate(this, &staticMetaObject, 44, Q_NULLPTR);
}

// SIGNAL 45
void Controller::createdEquipment(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 45, _a);
}

// SIGNAL 46
void Controller::updatedEquipment(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 46, _a);
}

// SIGNAL 47
void Controller::removedEquipment(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}

// SIGNAL 48
void Controller::clearTransportations()
{
    QMetaObject::activate(this, &staticMetaObject, 48, Q_NULLPTR);
}

// SIGNAL 49
void Controller::createdTransportation(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void Controller::updatedTransportation(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 50, _a);
}

// SIGNAL 51
void Controller::removedTransportation(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 51, _a);
}

// SIGNAL 52
void Controller::setLoadHandling(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 52, _a);
}

// SIGNAL 53
void Controller::setBodyPosture(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 53, _a);
}

// SIGNAL 54
void Controller::setAppliedForce(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 54, _a);
}

// SIGNAL 55
void Controller::setWorkProcess(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 55, _a);
}

// SIGNAL 56
void Controller::setExecutionCondition(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 56, _a);
}

// SIGNAL 57
void Controller::createdWorkProcess(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 57, _a);
}

// SIGNAL 58
void Controller::setSelectedWorkProcess(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 58, _a);
}

// SIGNAL 59
void Controller::setHasPreviousWorkProcess(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 59, _a);
}

// SIGNAL 60
void Controller::setHasNextWorkProcess(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 60, _a);
}

// SIGNAL 61
void Controller::setSelectedWorkProcessType(AVType _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 61, _a);
}

// SIGNAL 62
void Controller::initiliazedWorkProcesses(QList<QHash<QString,QVariant>> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 62, _a);
}

// SIGNAL 63
void Controller::selectedShift(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 63, _a);
}

// SIGNAL 64
void Controller::clearRotationGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 64, Q_NULLPTR);
}

// SIGNAL 65
void Controller::addRotationGroupEntry(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 65, _a);
}

// SIGNAL 66
void Controller::updatedRotationGroupEntry(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 66, _a);
}

// SIGNAL 67
void Controller::addRotationGroupBreakEntry(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 67, _a);
}

// SIGNAL 68
void Controller::clearRotationGroupTasks()
{
    QMetaObject::activate(this, &staticMetaObject, 68, Q_NULLPTR);
}

// SIGNAL 69
void Controller::createdRotationGroupTask(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 69, _a);
}

// SIGNAL 70
void Controller::updatedRotationGroupTask(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 70, _a);
}

// SIGNAL 71
void Controller::removedRotationGroupTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 71, _a);
}

// SIGNAL 72
void Controller::selectedRotationGroupTask(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 72, _a);
}

// SIGNAL 73
void Controller::updatedRotationGroupTaskDuration(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 73, _a);
}

// SIGNAL 74
void Controller::clearRotationGroupTaskEntries()
{
    QMetaObject::activate(this, &staticMetaObject, 74, Q_NULLPTR);
}

// SIGNAL 75
void Controller::createdRotationGroupTaskEntry(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 75, _a);
}

// SIGNAL 76
void Controller::removedRotationGroupTaskEntry(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 76, _a);
}
QT_END_MOC_NAMESPACE
