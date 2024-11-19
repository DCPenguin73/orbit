/***********************************************************************
 * Header File:
 *    Test CrewDragon : Test the CrewDragon class
 * Author:
 *    Arlo Jolley
 * Summary:
 *    All the unit tests for CrewDragon
 ************************************************************************/
#pragma once
#include "crewDragon.h"
#include "unitTest.h"
#include "objectType.h"
#include <iostream>


 /***************************************
  * TEST CrewDragon
   * A friend class for CrewDragon which contains the CrewDragon unit tests
	***************************************/
class TestCrewDragon : public UnitTest
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

		report("CrewDragon");
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
		CrewDragon crewDragon;
		// exercise

		// verify
		assertEquals(crewDragon.getType(), CREWDRAGON);
		assertEquals(crewDragon.getX(), 0.0);
		assertEquals(crewDragon.getY(), 0.0);
		assertEquals(crewDragon.getVelocityX(), 0.0);
		assertEquals(crewDragon.getVelocityY(), 0.0);
		assertEquals(crewDragon.getAngle(), 0.0);
		assertEquals(crewDragon.getRadius(), 0.0);
		assertEquals(crewDragon.getRotation(), 0.0);

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
		CrewDragon crewDragon(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
		// exercise

		// verify
		assertEquals(crewDragon.getType(), CREWDRAGON);
		assertEquals(crewDragon.position.getMetersX(), 1.0);
		assertEquals(crewDragon.position.getMetersY(), 2.0);
		assertEquals(crewDragon.velocity.getVelocityX(), 3.0);
		assertEquals(crewDragon.velocity.getVelocityY(), 4.0);
		assertEquals(crewDragon.angle, 5.0);
		assertEquals(crewDragon.radius, 6.0);
		assertEquals(crewDragon.rotation, 7.0);
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
		CrewDragon crewDragon;
		// verify
		assertEquals(crewDragon.getType(), 4);
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
		CrewDragon crewDragon(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, -0.0069813170079773175);
		// exercise
		crewDragon.advance();
		// verify
		assertEquals(crewDragon.getType(), CREWDRAGON);
		assertEquals(crewDragon.position.getMetersX(), -186240.000000000);
		assertEquals(crewDragon.position.getMetersY(), 26558045.627703581);
		assertEquals(crewDragon.velocity.getVelocityX(), -3880.0);
		assertEquals(crewDragon.velocity.getVelocityY(), -27.144059672480584);
		assertEquals(crewDragon.angle, 1.4930186829920227);
		assertEquals(crewDragon.radius, 10);
		assertEquals(crewDragon.rotation, -0.0069813170079773175);
		// teardown
	}
};