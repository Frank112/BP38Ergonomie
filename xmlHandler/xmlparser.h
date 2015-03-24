#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>
#include <QFile>
#include <QXmlStreamReader>
#include <QTime>
#include "../databaseHandler/dbconstants.h"
#include "xmlconstants.h"
#include "iimportdataparser.h"

class XMLParser : public QObject, IImportDataParser
{
    Q_OBJECT
    Q_INTERFACES(IImportDataParser)

public:
    explicit XMLParser(QObject *parent = 0);
    ~XMLParser();

    QString getModeName() const;
    FileMode getFileMode() const;

    QString getSingleFilename() const;
    QString getTransportationFilename() const;
    QString getEquipmentFilename() const;
    QString getProductFilename() const;
    QString getEmployeeFilename() const;
    QString getWorkplaceFilename() const;
    QString getWorkprocessListFilename() const;

    void parseTransportations(const QString path);
    void parseEquipments(const QString path);
    void parseProducts(const QString path);
    void parseEmployees(const QString path);
    void parseWorkplaces(const QString path);
    void parseWorkprocessLists(const QString path);

signals:
    void createTransportation(QHash<QString, QVariant> values);
    void createEquipment(QHash<QString, QVariant> values);
    void createProduct(QHash<QString, QVariant> values);
    void createEmployee(QHash<QString, QVariant> values, QHash<QString, QVariant> bodyMeasurementValues);
    void createWorkplace(QHash<QString, QVariant> values, QList<QHash<QString, QVariant>> activityValues);
    void createWorkprocessList(QString workplaceName, QString activityName, QList<QHash<QString, QVariant>> workprocessList);

private:
    void parseTransportation(QXmlStreamReader &xmlReader);

    void parseEquipment(QXmlStreamReader &xmlReader);

    void parseProduct(QXmlStreamReader &xmlReader);

    void parseEmployee(QXmlStreamReader &xmlReader);
    QHash<QString, QVariant> parseBodyMeasurement(QXmlStreamReader &xmlReader);

    void parseWorkplace(QXmlStreamReader &xmlReader);
    QList<QHash<QString, QVariant>> parseActivities(QXmlStreamReader &xmlReader);
    QHash<QString, QVariant> parseActivity(QXmlStreamReader &xmlReader);

    void parseWorkprocessList(QXmlStreamReader &xmlReader);
    QHash<QString, QVariant> parseWorkprocess(QXmlStreamReader &xmlReader, QTime startTime);

    void addElementDataToHash(QXmlStreamReader &xmlReader, const QString &key, QHash<QString, QVariant> &values);
};

#endif // XMLPARSER_H
