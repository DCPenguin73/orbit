/***********************************************************************
 * Header File:
 *    Test Object : Test the Object class
 * Author:
 *    Bryce Chesley & Daniel Carr
 * Summary:
 *    All the unit tests for Object
 ************************************************************************/
#pragma once


#include "object.h"
#include "unitTest.h"





class TestObject : public UnitTest
{
public:

   void construct_default();
   void construct_nonDefault();

   void getPosition();
   void getVelocityX();
   void getVelocityY();
   void getX();
   void getY();
   void getAngle();
   void getRadius();
   void getRotation();

   void setX();
   void setY();
   void setPosition();
   void setVelocity();
   void setVelocityX();
   void setVelocityY();
   void setAngle();
   void setRadius();
   void setRotation();
   void advance1();
   void advance2();
   void advance3();
   void advance4();
   void advance5();

   void run()
   {
      construct_default();
      construct_nonDefault();

      getPosition();
      getVelocityX();
      getVelocityY();
      getX();
      getY();
      getAngle();
      getRadius();
      getRotation();

      setX();
      setY();
      setPosition();
      setVelocity();
      setVelocityX();
      setVelocityY();
      setAngle();
      setRadius();
      setRotation();

      advance1();
      advance2();
      advance3();
      advance4();
      advance5();

      report("Object");
   }
};

