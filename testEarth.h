/***********************************************************************
 * Header File:
 *    Test Earth : Test the Earth class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for Earth
 ************************************************************************/
#pragma once
#include "earth.h"
#include "unitTest.h"

 /***************************************
  * TEST Earth
  * A friend class for Earth which contains the Earth unit tests
  ***************************************/
class testEarth : public UnitTest
{
public:
	void run()
	{
		// Constructors
		construct_default();
		construct_nonDefault();
		construct_copy();

		// Other functions
		advance();

		report("Earth");
	}

private:
	/*********************************************
	* name:    DEFAULT CONSTRUCTOR
	* input:   nothing
	* output:  pos=(0, 0))
	*********************************************/
	void construct_default()
	{
		// setup

		// exercise
		//Earth earth;
		// verify
		/*assertEquals(earth.position.getMetersX(), 0.0);
		assertEquals(earth.position.getMetersY(), 0.0);
		assertEquals(earth.angle, 0.0);
		assertEquals(earth.radius, 6378000.0);
		assertEquals(earth.rotation, 0.0);*/
		// teardown

	}

	/*********************************************
	* name:    NON-DEFAULT CONSTRUCTOR
	* input:   x=3, y=4, dx=5, dy=6, angle=7, radius=8, rotation=9
	* output:  pos=(3, 4)
	*********************************************/
	void construct_nonDefault()
	{
		// setup

		// exercise
		//Earth earth(3, 4, 5, 6, 7, 8, 9);
		// verify
		/*assertEquals(earth.position.getMetersX(), 3.0);
		assertEquals(earth.position.getMetersY(), 4.0);
		assertEquals(earth.angle, 7.0);
		assertEquals(earth.radius, 8.0);
		assertEquals(earth.rotation, 9.0);*/
		// teardown

	}
	/*********************************************
	* name:    COPY CONSTRUCTOR
	* input:   x=3, y=4, dx=5, dy=6, angle=7, radius=8, rotation=9
	* output:  pos=(3, 4)
	*********************************************/
	void construct_copy()
	{
		// setup
		//Earth earth(3, 4, 5, 6, 7, 8, 9);
		// exercise
		//Earth earthCopy(earth);
		// verify
		/*assertEquals(earthCopy.position.getMetersX(), 3.0);
		assertEquals(earthCopy.position.getMetersY(), 4.0);
		assertEquals(earthCopy.angle, 7.0);
		assertEquals(earthCopy.radius, 8.0);
		assertEquals(earthCopy.rotation, 9.0);*/
		// teardown

	}


	/*********************************************
	* name:    ADVANCE
	* input:   nothing
	* output:  nothing
	* remarks: This function is a void function that advances the earth
	* by rotating it
	***********************************************/
	void advance()
	{
		// setup
		//Earth earth;
		// exercise
		//earth.advance();
		// verify
		/*assertEquals(earth.angle, 0.0);*/
		// teardown

	}
};

