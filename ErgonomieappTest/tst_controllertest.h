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

    void cleanupTestCase();

private:
    Controller *c;
};

#endif // TST_CONTROLLERTEST

