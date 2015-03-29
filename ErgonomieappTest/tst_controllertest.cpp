#include "tst_controllertest.h"

ControllerTest::ControllerTest(){

}

void ControllerTest::initTestCase(){
    c = new Controller();
}

void ControllerTest::cleanupTestCase(){
    delete c;
}
