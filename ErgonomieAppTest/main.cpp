#include <QCoreApplication>
#include "tst_dbhandlertest.h"
#include "tst_controllertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    DBHandlerTest dbHandlerTest;
    QTest::qExec(&dbHandlerTest, argc, argv);
    ControllerTest controllerTest;
    QTest::qExec(&controllerTest, argc, argv);

    return 0;
}
