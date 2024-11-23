/***********************************************************************
 * Source File:
 *    Test Object : Test the Object class
 * Author:
 *    Bryce Chesley & Daniel Carr
 * Summary:
 *    All the unit tests for Object
 ************************************************************************/


#pragma once


#include "Position.h"
#include "Velocity.h"
#include "TestObject.h"


void TestObject::construct_default() 
{

   // setup
   

   // exercise
   DummyObject obj;
   // verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 0.0);
   assertEquals(obj.velocity.dx, 0.0);
   assertEquals(obj.velocity.dy, 0.0);
   assertEquals(obj.angle, 0.0);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 0.0);
   // teardown
  
}

void TestObject::construct_nonDefault()
{
   //setup
   double x=0.0;
   double y = 1.0;
   double dx = 2.0;
   double dy = 3.0;
   double angle = 4.0;
   double radius = 5.0;
   double rotation = 6.0;

   //exercise
   DummyObject obj(x, y, dx, dy, angle, radius, rotation);
   
   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::getPosition()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   Position pos = obj.getPosition();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(pos.x, 0.0);
   assertEquals(pos.y, 1.0);
}

void TestObject::getVelocityX()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double dx = obj.getVelocityX();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(dx, 2.0);
}

void TestObject::getVelocityY()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double dy = obj.getVelocityY();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(dy, 3.0);
}

void TestObject::getX()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double X = obj.getX();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(X, 0.0);
}

void TestObject::getY()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double Y = obj.getY();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(Y, 1.0);
}

void TestObject::getAngle()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double angle = obj.getAngle();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(angle, 4.0);
}

void TestObject::getRadius()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double radius = obj.getRadius();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(radius, 5.0);
}

void TestObject::getRotation()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   double rotation = obj.getRotation();

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
   assertEquals(rotation, 6.0);
}

void TestObject::setX()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setX(99.0);

   //verify
   assertEquals(obj.position.x, 99.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setY()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setY(99.0);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 99.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setPosition()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;
   Position pos;
   pos.x = 99.0;
   pos.y = 999.0;

   //exercise
   obj.setPosition(pos);

   //verify
   assertEquals(obj.position.x, 99.0);
   assertEquals(obj.position.y, 999.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setVelocity()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;
   Velocity vel;
   vel.dx = 99.0;
   vel.dy = 999.0;

   //exercise
   obj.setVelocity(vel);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 99.0);
   assertEquals(obj.velocity.dy, 999.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setVelocityX()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setVelocityX(999);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 999.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}
void TestObject::setVelocityY()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setVelocityY(99);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 99.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setAngle()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setAngle(99.0);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 99.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setRadius()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setRadius(99.0);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 99.0);
   assertEquals(obj.rotation, 6.0);
}

void TestObject::setRotation()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 1.0;
   obj.velocity.dx = 2.0;
   obj.velocity.dy = 3.0;
   obj.angle = 4.0;
   obj.radius = 5.0;
   obj.rotation = 6.0;

   //exercise
   obj.setRotation(99.0);

   //verify
   assertEquals(obj.position.x, 0.0);
   assertEquals(obj.position.y, 1.0);
   assertEquals(obj.velocity.dx, 2.0);
   assertEquals(obj.velocity.dy, 3.0);
   assertEquals(obj.angle, 4.0);
   assertEquals(obj.radius, 5.0);
   assertEquals(obj.rotation, 99.0);
}

void TestObject::advance1()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 6378000.0;
   obj.velocity.dx = 0.0;
   obj.velocity.dy = 0.0;
   obj.angle = 1.234;
   obj.radius = 0.0;
   obj.rotation = 0.0;

   //exercise
   obj.advance();

   //verify
   assertEqualsTolerance(0.0, obj.velocity.dx, 0.01);
   assertEqualsTolerance(-470.7192, obj.velocity.dy, 0.01);
   assertEqualsTolerance(0.0, obj.position.x, 0.01);
   assertEqualsTolerance(6355405.47839, obj.position.y, 0.01);
   assertEquals(obj.angle, 1.234);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 0.0);
}

void TestObject::advance2()
{
   //setup
   DummyObject obj;
   obj.position.x = 0.0;
   obj.position.y = 63780000.0;
   obj.velocity.dx = 3000.0;
   obj.velocity.dy = 0.0;
   obj.angle = 1.234;
   obj.radius = 0.0;
   obj.rotation = 0.0;

   //exercise
   obj.advance();

   //verify
   assertEqualsTolerance(3000.0, obj.velocity.dx, 0.01);
   assertEqualsTolerance(-4.70719, obj.velocity.dy, 0.01);
   assertEqualsTolerance(144000.0, obj.position.x, 0.01);
   assertEqualsTolerance(63779774.05478, obj.position.y, 0.01);
   assertEquals(obj.angle, 1.234);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 0.0);
}

void TestObject::advance3()
{
   //setup
   DummyObject obj;
   obj.position.x = 900000;
   obj.position.y = 2*6378000.0;
   obj.velocity.dx = 0.0;
   obj.velocity.dy = 0.0;
   obj.angle = 1.234;
   obj.radius = 0.0;
   obj.rotation = 0.0;

   //exercise
   obj.advance();

   //verify
   assertEqualsTolerance(-8.24128, obj.velocity.dx, 0.01);
   assertEqualsTolerance(-116.80651, obj.velocity.dy, 0.01);
   assertEqualsTolerance(899604.418186, obj.position.x, 0.01);
   assertEqualsTolerance(12750393.287090, obj.position.y, 0.01);
   assertEquals(obj.angle, 1.234);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 0.0);
}

void TestObject::advance4()
{
   //setup
   DummyObject obj;
   obj.position.x = 900000;
   obj.position.y = 2 * 6378000.0;
   obj.velocity.dx = 0.0;
   obj.velocity.dy = 0.0;
   obj.angle = 1.234;
   obj.radius = 0.0;
   obj.rotation = 9.0;

   //exercise
   obj.advance();

   //verify
   assertEqualsTolerance(-8.24128, obj.velocity.dx, 0.01);
   assertEqualsTolerance(-116.80651, obj.velocity.dy, 0.01);
   assertEqualsTolerance(899604.418186, obj.position.x, 0.01);
   assertEqualsTolerance(12750393.287090, obj.position.y, 0.01);
   assertEquals(obj.angle, 10.234);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 9.0);
}

void TestObject::advance5()
{
   //setup
   DummyObject obj;
   obj.position.x = 900000;
   obj.position.y = 2 * 6378000.0;
   obj.velocity.dx = 0.0;
   obj.velocity.dy = 116.8;
   obj.angle = 1.234;
   obj.radius = 0.0;
   obj.rotation = 9.0;

   //exercise
   obj.advance();

   //verify
   assertEqualsTolerance(-8.241287, obj.velocity.dx, 0.01);
   assertEqualsTolerance(-0.006518, obj.velocity.dy, 0.01);
   assertEqualsTolerance(899604.4181, obj.position.x, 0.01);
   assertEqualsTolerance(12755999.68709, obj.position.y, 0.01);
   assertEquals(obj.angle, 10.234);
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.rotation, 9.0);
}