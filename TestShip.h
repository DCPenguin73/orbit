/***********************************************************************
 * Header File:
 *    Test Ship : Test the Unique Ship class Functions
 * Author:
 *    Bryce Chesley & Daniel Carr
 * Summary:
 *    All the unit tests for unique Ship class functions
 ************************************************************************/
#pragma once


#include "Ship.h"
#include "unitTest.h"
#include "Position.h"
#include "Velocity.h"



class TestShip: public UnitTest
{
public:

   void advance1();
   void advance2();
   void advance3();
   void advance4();
   void advance5();

   void run()
   {
      advance1();
      advance2();
      advance3();
      advance4();
      advance5();

      report("Ship");
   }
};