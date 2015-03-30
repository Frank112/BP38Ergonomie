#include "xmlparsertest.h"
#include "../standardpaths.h"

XMLParserTest::XMLParserTest()
{

}

void XMLParserTest::initTestCase(){
    xmlParser = new XMLParser();
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation());
    QFile file(":/testData/transportations.xml");
    if(file.open(QIODevice::ReadOnly)){
        if(file.copy(path.arg("transportations.xml")))
            QFile::setPermissions(path.arg("transportations.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file.close();

    QFile file2(":/testData/equipments.xml");
    if(file2.open(QIODevice::ReadOnly)){
        if(file2.copy(path.arg("equipments.xml")))
            QFile::setPermissions(path.arg("equipments.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file2.close();

    QFile file3(":/testData/products.xml");
    if(file3.open(QIODevice::ReadOnly)){
        if(file3.copy(path.arg("products.xml")))
            QFile::setPermissions(path.arg("products.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file3.close();

    QFile file4(":/testData/employees.xml");
    if(file4.open(QIODevice::ReadOnly)){
        if(file4.copy(path.arg("employees.xml")))
            QFile::setPermissions(path.arg("employees.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file4.close();

    QFile file5(":/testData/workplaces.xml");
    if(file5.open(QIODevice::ReadOnly)){
        if(file5.copy(path.arg("workplaces.xml")))
            QFile::setPermissions(path.arg("workplaces.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file5.close();

    QFile file6(":/testData/workprocesslists.xml");
    if(file6.open(QIODevice::ReadOnly)){
        if(file6.copy(path.arg("workprocesslists.xml")))
            QFile::setPermissions(path.arg("workprocesslists.xml"), QFile::WriteOwner | QFile::ReadOwner);
    }
    file6.close();

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
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("transportations.xml");
    xmlParser->parseTransportations(path);
}
void XMLParserTest::parseTransportationsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseTransportationsWithInvalidXMLFileTest(){}

void XMLParserTest::parseEquipmentsTest(){
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("equipments.xml");
    xmlParser->parseEquipments(path);
}
void XMLParserTest::parseEquipmentsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseEquipmentsWithInvalidXMLFileTest(){}

void XMLParserTest::parseProductsTest(){
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("products.xml");
    xmlParser->parseProducts(path);
}
void XMLParserTest::parseProductsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseProductsWithInvalidXMLFileTest(){}

void XMLParserTest::parseEmployeesTest(){
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("employees.xml");
    xmlParser->parseEmployees(path);
}
void XMLParserTest::parseEmployeesWithInvalidXMLNodeTest(){}
void XMLParserTest::parseEmployeesWithInvalidXMLFileTest(){}

void XMLParserTest::parseWorkplacesTest(){
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("workplaces.xml");
    xmlParser->parseWorkplaces(path);
}
void XMLParserTest::parseWorkplacesWithInvalidXMLNodeTest(){}
void XMLParserTest::parseWorkplacesWithInvalidXMLFileTest(){}

void XMLParserTest::parseWorkprocessListsTest(){
    QString path = QString("%1/%2").arg(StandardPaths::writeableLocation()).arg("workprocesslists.xml");
    xmlParser->parseWorkprocessLists(path);
}
void XMLParserTest::parseWorkprocessListsWithInvalidXMLNodeTest(){}
void XMLParserTest::parseWorkprocessListsWithInvalidXMLFileTest(){}

void XMLParserTest::cleanupTestCase(){
    delete xmlParser;
}

