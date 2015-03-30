#include "xmlparsertest.h"

XMLParserTest::XMLParserTest()
{

}

void XMLParserTest::initTestCase(){
    xmlParser = new XMLParser();
}

void XMLParserTest::getModeNameTest(){
    QCOMPARE(xmlParser->getModeName(), QString("XML"));
}
void XMLParserTest::getFileModeTest(){
    int mode = xmlParser->getFileMode();
    int multiFileMode = IImportDataParser::MultiFile;
    QCOMPARE(mode, multiFileMode);
}

void XMLParserTest::getSingleFilenameTest(){
    QCOMPARE(xmlParser->getSingleFilename(), QString(""));
}

void XMLParserTest::getTransportationsFilename(){
    QCOMPARE(xmlParser->getTransportationFilename(), QString("transportations.xml"));
}
void XMLParserTest::getEquipmentsFilename(){
    QCOMPARE(xmlParser->getEquipmentFilename(), QString("equipments.xml"));
}
void XMLParserTest::getProductsFilename(){
    QCOMPARE(xmlParser->getProductFilename(), QString("products.xml"));
}
void XMLParserTest::getEmployeesFilename(){
    QCOMPARE(xmlParser->getEmployeeFilename(), QString("employees.xml"));
}
void XMLParserTest::getWorkplacesFilename(){
    QCOMPARE(xmlParser->getWorkplaceFilename(), QString("workplaces.xml"));
}
void XMLParserTest::getWorkprocessLists(){
    QCOMPARE(xmlParser->getWorkprocessListFilename(), QString("workprocesslists.xml"));
}

void XMLParserTest::parseTransportationsTest(){
    xmlParser->parseTransportations(":/testData/transportations.xml");
}
void XMLParserTest::parseTransportationsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseTransportationsWithInvalidXMLFileTest(){}

void XMLParserTest::parseEquipmentsTest(){
    xmlParser->parseEquipments(":/testData/equipments.xml");
}
void XMLParserTest::parseEquipmentsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseEquipmentsWithInvalidXMLFileTest(){}

void XMLParserTest::parseProductsTest(){
    xmlParser->parseProducts(":/testData/products.xml");
}
void XMLParserTest::parseProductsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseProductsWithInvalidXMLFileTest(){}

void XMLParserTest::parseEmployeesTest(){
    xmlParser->parseTransportations(":/testData/employees.xml");
}
void XMLParserTest::parseEmployeesWithInvalidXMLNodeTest(){}
void XMLParserTest::parseEmployeesWithInvalidXMLFileTest(){}

void XMLParserTest::parseWorkplacesTest(){
    xmlParser->parseTransportations(":/testData/workplaces.xml");
}
void XMLParserTest::parseWorkplacesWithInvalidXMLNodeTest(){}
void XMLParserTest::parseWorkplacesWithInvalidXMLFileTest(){}

void XMLParserTest::parseWorkprocessListsTest(){
    xmlParser->parseTransportations(":/testData/workprocesslists.xml");
}
void XMLParserTest::parseWorkprocessListsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseWorkprocessListsWithInvalidXMLFileTest(){}

void XMLParserTest::cleanupTestCase(){
    delete xmlParser;
}

