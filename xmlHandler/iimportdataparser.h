#ifndef IIMPORTDATAPARSER
#define IIMPORTDATAPARSER

#include <QtPlugin>

/**
 * @brief The IImportDataParser is the interface for parsing files and importing
 * them into the local database of the application.
 *
 * @author Frank Loeffler
 */
class IImportDataParser{
public:
    /**
     * @brief The FileMode indicates if the parser uses only a single file or
     * the splitted version into multiple files.
     */
    enum FileMode {
        SingleFile,
        MultiFile};

    /**
     * @brief Returns the abstract name of the parser.
     *
     * Example: XML Parser would return "XML".
     * @return
     *          The name of the parser.
     */
    virtual QString getName() const = 0;

    /**
     * @brief Returns the file mode of the parser.
     *
     * @see FileMode
     * @return
     *          The file mode of the parser.
     */
    virtual FileMode getFileMode() const = 0;

    /**
     * @brief Returns the expected filename of the file with
     * the transportations.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getTransportationFilename() const = 0;

    /**
     * @brief Returns the expected filename of the file with
     * the equipments.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getEquipmentFilename() const = 0;

    /**
     * @brief Returns the expected filename of the file with
     * the products.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getProductFilename() const = 0;

    /**
     * @brief Returns the expected filename of the file with
     * the employees.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getEmployeeFilename() const = 0;

    /**
     * @brief Returns the expected filename of the file with
     * the workplaces.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getWorkplaceFilename() const = 0; 

    /**
     * @brief Returns the expected filename of the file with
     * the workprocess lists.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getWorkprocessListFilename() const = 0;

    /**
     * @brief Returns the expected filename of the file when
     * you have the file mode SingleFile.
     *
     * @return
     *      The expected filename.
     */
    virtual QString getSingleFilename() const = 0;

    /**
     * @brief Starts the parsing of the transportions with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseTransportations(const QString path) = 0;

    /**
     * @brief Starts the parsing of the equipments with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseEquipments(const QString path) = 0;

    /**
     * @brief Starts the parsing of the products with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseProducts(const QString path) = 0;

    /**
     * @brief Starts the parsing of the employees with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseEmployees(const QString path) = 0;

    /**
     * @brief Starts the parsing of the workplaces with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseWorkplaces(const QString path) = 0;

    /**
     * @brief Starts the parsing of the workprocess lists with the
     * given file.
     *
     * @param path
     *          The path where the file is located
     */
    virtual void parseWorkprocessLists(const QString path) = 0;

signals:
    /**
     * @brief Is emitted when ever a new transportation with the given
     * values should be created.
     *
     * @param values
     *          The mapping of the name of the database field and the
     *          value of this field.
     */
    virtual void createTransportation(QHash<QString, QVariant> values) = 0;

    /**
     * @brief Is emitted when ever a new equipment with the given
     * values should be created.
     *
     * @param values
     *          The mapping of the name of the database field and the
     *          value of this field.
     */
    virtual void createEquipment(QHash<QString, QVariant> values) = 0;

    /**
     * @brief Is emitted when ever a new product with the given
     * values should be created.
     *
     * @param values
     *          The mapping of the name of the database field and the
     *          value of this field.
     */
    virtual void createProduct(QHash<QString, QVariant> values) = 0;

    /**
     * @brief Is emitted when ever a new employee with the given
     * values and the given body measurement should be created.
     *
     * @param values
     *          The mapping of the name of the database field and the
     *          value of this field for the employee.
     * @param bodyMeasurementValues
     *          The mapping of the name of the database field and the
     *          value of this field for the body measurement of the employee.
     */
    virtual void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues) = 0;

    /**
     * @brief Is emitted when ever a new workplace with the given
     * values and the given list of activities should be created.
     *
     * @param values
     *          The mapping of the name of the database field and the
     *          value of this field for the workplace.
     * @param activityValues
     *          The list of the values with the mapping of the name of the
     *          database field and the value of this field for the activity that
     *          should be created for the new workplace
     */
    virtual void createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues) = 0;

    /**
     * @brief Is emitted when ever a new list of workprocesses should be
     * created for the given workplace with the given activity.
     *
     * @param workplaceName
     *          The name of the workplace of the activity.
     * @param activityName
     *          The name of the activity where the workprocesses are booked.
     * @param workprocessList
     *          The list of workprocesses consisting of the mapping of the
     *          name of the database field and the value for this field for
     *          the workprocess that should be created.
     */
    virtual void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocessList) = 0;
};

#define IImportDataParser_iid "IImportDataParser"

Q_DECLARE_INTERFACE(IImportDataParser, IImportDataParser_iid)

#endif // IIMPORTDATAPARSER

