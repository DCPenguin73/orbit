/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testStar.h"
#include "testEarth.h"
#include "testGps.h"
#include "testStarLink.h"
#include "testSputnik.h"
#include "testCrewDragon.h"
#include "testHubble.h"
#include "testObject.h"
#include "TestShip.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestVelocity().run();
   TestStar().run();
   TestObject().run();
   TestShip().run();
   //TestEarth().run();
   //TestGps().run();
   //TestStarLink().run();
   //TestCrewDragon().run();
   //TestSputnik().run();
   //TestHubble().run();
}
