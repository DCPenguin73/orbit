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
   assertEqualsTolerance(82.36526, ship.velocity.dx, 0.01);
   assertEqualsTolerance(31.71813, ship.velocity.dy, 0.01);
   assertEqualsTolerance(903953.53249, ship.position.x, 0.01);
   assertEqualsTolerance(12757522.4703, ship.position.y, 0.01);
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
   assertEqualsTolerance(-21.67979, ship.velocity.dy, 0.01);
   assertEqualsTolerance(0.0, ship.position.x, 0.01);
   assertEqualsTolerance(12754959.369600002, ship.position.y, 0.01);
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
   assertEqualsTolerance(85.82367, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-160.69486, ship.velocity.dy, 0.01);
   assertEqualsTolerance(4119.53662, ship.position.x, 0.01);
   assertEqualsTolerance(12748286.64637, ship.position.y, 0.01);
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
   assertEqualsTolerance(-16.9004, ship.velocity.dx, 0.01);
   assertEqualsTolerance(-23.17913, ship.velocity.dy, 0.01);
   assertEqualsTolerance(-811.21972, ship.position.x, 0.01);
   assertEqualsTolerance(12754887.40162, ship.position.y, 0.01);
   assertEquals(ship.angle, 270.0);
   assertEquals(ship.radius, 0.0);
   assertEquals(ship.rotation, 0.0);
}