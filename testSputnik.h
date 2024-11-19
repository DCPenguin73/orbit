/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the Sputnik class
 * Author:
 *    Arlo Jolley
 * Summary:
 *    All the unit tests for Sputnik
 ************************************************************************/
#pragma once
#include "sputnik.h"
#include "unitTest.h"
#include "objectType.h"
#include <iostream>


 /***************************************
  * TEST Sputnik
   * A friend class for Sputnik which contains the Sputnik unit tests
	***************************************/
class TestSputnik : public UnitTest
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

		report("Sputnik");
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
		Sputnik sputnik;
		// exercise

		// verify
		assertEquals(sputnik.getType(), SPUTNIK);
		assertEquals(sputnik.getX(), 0.0);
		assertEquals(sputnik.getY(), 0.0);
		assertEquals(sputnik.getVelocityX(), 0.0);
		assertEquals(sputnik.getVelocityY(), 0.0);
		assertEquals(sputnik.getAngle(), 0.0);
		assertEquals(sputnik.getRadius(), 0.0);
		assertEquals(sputnik.getRotation(), 0.0);

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
		Sputnik sputnik(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
		// exercise

		// verify
		assertEquals(sputnik.getType(), SPUTNIK);
		assertEquals(sputnik.position.getMetersX(), 1.0);
		assertEquals(sputnik.position.getMetersY(), 2.0);
		assertEquals(sputnik.velocity.getVelocityX(), 3.0);
		assertEquals(sputnik.velocity.getVelocityY(), 4.0);
		assertEquals(sputnik.angle, 5.0);
		assertEquals(sputnik.radius, 6.0);
		assertEquals(sputnik.rotation, 7.0);
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
		Sputnik sputnik;
		// verify
		assertEquals(sputnik.getType(), 3);
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
		Sputnik sputnik(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, -0.0069813170079773175);
		// exercise
		sputnik.advance();
		// verify
		assertEquals(sputnik.getType(), SPUTNIK);
		assertEquals(sputnik.position.getMetersX(), -186240.000000000);
		assertEquals(sputnik.position.getMetersY(), 26558045.627703581);
		assertEquals(sputnik.velocity.getVelocityX(), -3880.0);
		assertEquals(sputnik.velocity.getVelocityY(), -27.144059672480584);
		assertEquals(sputnik.angle, 1.4930186829920227);
		assertEquals(sputnik.radius, 10);
		assertEquals(sputnik.rotation, -0.0069813170079773175);
		// teardown
	}
};