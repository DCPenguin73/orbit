/***********************************************************************
 * Source File:
 *    Test Ship : Test the Unique Ship class Functions
 * Author:
 *    Bryce Chesley & Daniel Carr
 * Summary:
 *    All the unit tests for unique Ship class functions
 ************************************************************************/


#include "TestShip.h"
#include "Ship.h"
#include "unitTest.h"
#include "Position.h"
#include "Velocity.h"


void TestShip::advance1()
{
   //setup
   Ship ship;
   ship.position.x = 900000;
   ship.position.y = 2 * 6378000.0;
   ship.velocity.dx = 0.0;
   ship.velocity.dy = 116.8;
   ship.angle = 1.234;
   ship.radius = 0.0;
   ship.rotation = 9.0;
   ship.thrust = false;

   //exercise
   ship.advance();

   //verify
   assertEqualsTolerance(-8.241287, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-0.006518, ship.velocity.dy, 0.01);
   assertEqualsTolerance(899604.4181, ship.position.x, 0.01);
   assertEqualsTolerance(12755999.68709, ship.position.y, 0.01);
   assertEquals(ship.angle, 10.234);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 9.0);
}

void TestShip::advance2()
{
   //setup
   Ship ship;
   ship.position.x = 900000;
   ship.position.y = 2 * 6378000.0;
   ship.velocity.dx = 0.0;
   ship.velocity.dy = 116.8;
   ship.angle = 1.234;
   ship.radius = 0.0;
   ship.rotation = 9.0;
   ship.thrust = true;

   //exercise
   ship.advance();

   //verify
   assertEqualsTolerance(0.81936, ship.velocity.dx, 0.01);
   assertEqualsTolerance(3.16594, ship.velocity.dy, 0.01);
   assertEqualsTolerance(900039.32961, ship.position.x, 0.01);
   assertEqualsTolerance(12756151.96541, ship.position.y, 0.01);
   assertEquals(ship.angle, 10.234);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 9.0);
}

void TestShip::advance3()
{
   //setup
   Ship ship;
   ship.position.x = 0.0;
   ship.position.y = 2 * 6378000.0;
   ship.velocity.dx = 0.0;
   ship.velocity.dy = 0.0;
   ship.angle = 0.0;
   ship.radius = 0.0;
   ship.rotation = 0.0;
   ship.thrust = true;

   //exercise
   ship.advance();

   //verify
   assertEqualsTolerance(0.0, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-108.07979, ship.velocity.dy, 0.01);
   assertEqualsTolerance(0.0, ship.position.x, 0.01);
   assertEqualsTolerance(12750812.16959, ship.position.y, 0.01);
   assertEquals(ship.angle, 0.0);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 0.0);
}

void TestShip::advance4()
{
   //setup
   Ship ship;
   ship.position.x = 0.0;
   ship.position.y = 2 * 6378000.0;
   ship.velocity.dx = 0.0;
   ship.velocity.dy = 0.0;
   ship.angle = 90.0;
   ship.radius = 0.0;
   ship.rotation = 0.0;
   ship.thrust = true;

   //exercise
   ship.advance();

   //verify
   assertEqualsTolerance(8.58236, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-121.98130, ship.velocity.dy, 0.01);
   assertEqualsTolerance(411.95366, ship.position.x, 0.01);
   assertEqualsTolerance(12750144.89727, ship.position.y, 0.01);
   assertEquals(ship.angle, 90.0);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 0.0);
}

void TestShip::advance5()
{
   //setup
   Ship ship;
   ship.position.x = 0.0;
   ship.position.y = 2 * 6378000.0;
   ship.velocity.dx = 0.0;
   ship.velocity.dy = 0.0;
   ship.angle = 270.0;
   ship.radius = 0.0;
   ship.rotation = 0.0;
   ship.thrust = true;

   //exercise
   ship.advance();

   //verify
   assertEqualsTolerance(-1.69004, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-108.22973, ship.velocity.dy, 0.01);
   assertEqualsTolerance(-81.12197, ship.position.x, 0.01);
   assertEqualsTolerance(12750804.97280, ship.position.y, 0.01);
   assertEquals(ship.angle, 270.0);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 0.0);
}