#ifndef VIEWTYPE
#define VIEWTYPE

class Types {

public:

/**
 * @brief The ViewType enum
 */
enum ViewType{
    UNKNOWN, ///< Represents an unknown view
    ANALYST_SELECTION_VIEW, ///< Represents the AnalystSelectionView
    MAIN_MENU_VIEW, ///< Represents the MainMenuView
    METADATA_VIEW, ///< Represents the MetaDataView
    WORKPLACELIST_VIEW, ///< Represents the WorkplacesListView
    WORKPLACE_VIEW, ///< Represents the WorkplaceView
    LINE_VIEW, ///< Represents the LineView
    ACTIVITY_VIEW, ///< Represents the ActivityView
    COMMENT_VIEW, ///< Represents the CommentView
    DOCUMENTATION_VIEW, ///< Represents the DocumentationView
    RESSOURCE_MANAGMENT_VIEW, ///< Represents the RessourceManagementView
    EQUIPMENT_VIEW, ///< Represents the EquipmentView
    TRANSPORTATION_VIEW, ///< Represents the TransportationView
    SHIFT_VIEW, ///< Represents the ShiftView
    SETTINGS_VIEW, ///< Represents the SettingsView
    PRODUCT_VIEW, ///< Represents the ProductView
    EMPLOYEE_VIEW, ///< Represents the EmployeeView
    EMPLOYEE_LIST_VIEW, ///< Represents the EmployeeListView
    BODY_MEASUREMENT_VIEW, ///< Represents the BodyMeasurementView
    SHIFT_CALENDAR_VIEW, ///< Represents the ShiftCalendar
    ROTATION_GROUP_TASK_VIEW, ///< Represents the RotationGroupTaskView
    ROTATION_GROUP_TASK_LIST_VIEW, ///< Represents the RotationGroupTaskListView
    GANTT_VIEW, ///< Represents the GanttTimerView
    BODY_POSTURE_VIEW, ///< Represents the BodyPostureView
    APPLIED_FORCE_VIEW, ///< Represents the AppliedForceView
    WORKING_CONDITION_VIEW, ///< Represents the ExecutionConditionView
    LOAD_HANDLING_VIEW, ///< Represents the LoadHandlingView
    WORK_PROCESS_META_DATA_VIEW, ///< Represents the WorkProcessMetaDataView
    ERROR_LOG_VIEW ///< Represents the ErrorLogView
};

/**
 * @brief The PopUpType enum
 */
enum PopUpType{
    ANALYST_POPUP, ///< Represents the AnalystPopUp
    ACTIVITY_POPUP, ///< Represents the ActivityPopUp
    CREATE_PRODUCT_POPUP, ///< Represents the CreateProductPopUp
    EQUIPMENT_POPUP, ///< Represents the EquipmentPopUp
    TRANSPORTATION_POPUP, ///< Represents the TransportationPopUp
    DB_SEND_POPUP, ///< Represents the SendDatabasePopUp
    LANGUAGE_POPUP, ///< Represents the LanguagePopUp
    THEME_POPUP, ///< Represents the ThemePopUp
    WORKPLACE_POPUP, ///< Represents the WorkplacePopUp
    IMPORT_DATA_POPUP, ///< Represents the ImportDataPopUp
    RESET_POPUP, ///< Represents the ResetPopUp
    EMPLOYEE_POPUP, ///< Represents the EmployeePopUp
    FACTORYSETTINGS_POPUP, ///< Represents the FactorySettingsPopUp
    LINE_POPUP ///< Represents the LinePopUp
};

};
#endif // VIEWTYPE

