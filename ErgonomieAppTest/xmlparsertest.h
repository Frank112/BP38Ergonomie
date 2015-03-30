#ifndef XMLPARSERTEST_H
#define XMLPARSERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "../xmlHandler/xmlparser.h"

class XMLParserTest : public QObject
{
    Q_OBJECT
public:
    XMLParserTest();

private Q_SLOTS:
    void initTestCase();

    void getModeNameTest();
    void getFileModeTest();

    void getSingleFilenameTest();

    void getTransportationsFilename();
    void getEquipmentsFilename();
    void getProductsFilename();
    void getEmployeesFilename();
    void getWorkplacesFilename();
    void getWorkprocessLists();

    void parseTransportationsTest();
    void parseTransportationsWithInvalidXMLNodeTest();
    void parseTransportationsWithInvalidXMLFileTest();

    void parseEquipmentsTest();
    void parseEquipmentsWithInvalidXMLNodeTest();
    void parseEquipmentsWithInvalidXMLFileTest();

    void parseProductsTest();
    void parseProductsWithInvalidXMLNodeTest();
    void parseProductsWithInvalidXMLFileTest();

    void parseEmployeesTest();
    void parseEmployeesWithInvalidXMLNodeTest();
    void parseEmployeesWithInvalidXMLFileTest();

    void parseWorkplacesTest();
    void parseWorkplacesWithInvalidXMLNodeTest();
    void parseWorkplacesWithInvalidXMLFileTest();

    void parseWorkprocessListsTest();
    void parseWorkprocessListsWithInvalidXMLNodeTest();
    void parseWorkprocessListsWithInvalidXMLFileTest();

    void cleanupTestCase();

private:
    XMLParser *xmlParser;
};

#endif // XMLPARSERTEST_H
