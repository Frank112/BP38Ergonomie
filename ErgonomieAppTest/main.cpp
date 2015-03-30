#include <QCoreApplication>
#include "tst_dbhandlertest.h"
#include "tst_controllertest.h"
#include "xmlparsertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    DBHandlerTest dbHandlerTest;
    QTest::qExec(&dbHandlerTest, argc, argv);
    ControllerTest controllerTest;
    QTest::qExec(&controllerTest, argc, argv);
    XMLParserTest parserTest;
    QTest::qExec(&parserTest, argc, argv);

    return 0;
}
