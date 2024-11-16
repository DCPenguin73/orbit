/***********************************************************************
 * Header File:
 *    Test Gps : Test the Gps class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for Gps
 ************************************************************************/
#pragma once
#include "gps.h"
#include "unitTest.h"
#include "objectType.h"


 /***************************************
  * TEST Gps
   * A friend class for Gps which contains the Gps unit tests
	***************************************/
class TestGps : public UnitTest
{

	public:
		void run()
		{
			// Constructors
			construct_default();
			construct_nonDefault();

			// Getters
			getType();

			// other functions
			advance();

			report("Gps");
		}

	private:

		/*********************************************
		* name:    DEFAULT CONSTRUCTOR
		* input:   nothing
		* output:  type=0
		*********************************************/
		void construct_default()
		{
			// setup
			Gps gps;
			// exercise
			
			// verify
			assertEquals(gps.getType(), GPS);
			assertEquals(gps.getX(), 0.0);
			assertEquals(gps.getY(), 0.0);
			assertEquals(gps.getVelocityX(), 0.0);
			assertEquals(gps.getVelocityY(), 0.0);
			assertEquals(gps.getAngle(), 0.0);
			assertEquals(gps.getRadius(), 0.0);
			assertEquals(gps.getRotation(), 0.0);

			// teardown
		}

		/*********************************************
		* name:    NON-DEFAULT CONSTRUCTOR
		* input:   type=1
		* output:  type=1
		*********************************************/
		void construct_nonDefault()
		{
			// setup
			Gps gps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
			// exercise
			
			// verify
			assertEquals(gps.getType(), GPS);
			assertEquals(gps.getX(), 1.0);
			assertEquals(gps.getY(), 2.0);
			assertEquals(gps.getVelocityX(), 3.0);
			assertEquals(gps.getVelocityY(), 4.0);
			assertEquals(gps.getAngle(), 5.0);
			assertEquals(gps.getRadius(), 6.0);
			assertEquals(gps.getRotation(), 7.0);
			// teardown
		}

		/*********************************************
		* name:    GET TYPE
		* input:   type=1
		* output:  type=1
		*********************************************/
		void getType()
		{
			// setup

			// exercise
			Gps gps;
			// verify
			assertEquals(gps.getType(), 1);
			// teardown
		}

		/*********************************************
		* name:    ADVANCE
		* input:   type=1
		* output:  type=1
		*********************************************/
		void advance()
		{
			// setup
			Gps gps;
			// exercise
			gps.advance();
			// verify
			assertEquals(gps.getType(), GPS);
			assertEquals(gps.getX(), 1.0);
			assertEquals(gps.getY(), 2.0);
			assertEquals(gps.getVelocityX(), 3.0);
			assertEquals(gps.getVelocityY(), 4.0);
			assertEquals(gps.getAngle(), 5.0);
			assertEquals(gps.getRadius(), 6.0);
			assertEquals(gps.getRotation(), 7.0);
			// teardown
		}
};