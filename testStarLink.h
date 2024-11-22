/***********************************************************************
 * Header File:
 *    Test StarLink : Test the StarLink class
 * Author:
 *    Arlo Jolley
 * Summary:
 *    All the unit tests for StarLink
 ************************************************************************/
#pragma once
#include "starLink.h"
#include "unitTest.h"
#include "objectType.h"
#include <iostream>


 /***************************************
  * TEST StarLink
   * A friend class for StarLink which contains the StarLink unit tests
	***************************************/
class TestStarLink : public UnitTest
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

		report("StarLink");
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
		StarLink starLink;
		// exercise

		// verify
		assertEquals(starLink.getType(), STARLINK);
		assertEquals(starLink.getX(), 0.0);
		assertEquals(starLink.getY(), 0.0);
		assertEquals(starLink.getVelocityX(), 0.0);
		assertEquals(starLink.getVelocityY(), 0.0);
		assertEquals(starLink.getAngle(), 0.0);
		assertEquals(starLink.getRadius(), 0.0);
		assertEquals(starLink.getRotation(), 0.0);

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
		StarLink starLink(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
		// exercise

		// verify
		assertEquals(starLink.getType(), STARLINK);
		assertEquals(starLink.position.getMetersX(), 1.0);
		assertEquals(starLink.position.getMetersY(), 2.0);
		assertEquals(starLink.velocity.getVelocityX(), 3.0);
		assertEquals(starLink.velocity.getVelocityY(), 4.0);
		assertEquals(starLink.angle, 5.0);
		assertEquals(starLink.radius, 6.0);
		assertEquals(starLink.rotation, 7.0);
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
		StarLink starLink;
		// verify
		assertEquals(starLink.getType(), 2);
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
		StarLink starLink(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, -0.0069813170079773175);
		// exercise
		starLink.advance();
		// verify
		assertEquals(starLink.getType(), STARLINK);
		assertEquals(starLink.position.getMetersX(), -186240.000000000);
		assertEquals(starLink.position.getMetersY(), 26558045.627703581);
		assertEquals(starLink.velocity.getVelocityX(), -3880.0);
		assertEquals(starLink.velocity.getVelocityY(), -27.144059672480584);
		assertEquals(starLink.angle, 1.4930186829920227);
		assertEquals(starLink.radius, 10);
		assertEquals(starLink.rotation, -0.0069813170079773175);
		// teardown
	}
};