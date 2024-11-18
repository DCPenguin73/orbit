/***********************************************************************
 * Header File:
 *    Test Earth : Test the Earth class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for Earth
 ************************************************************************/

#define _USE_MATH_DEFINES 
#pragma once
#include "earth.h"
#include "unitTest.h"
#include <iostream>
#include <cmath>


 /***************************************
  * TEST Earth
  * A friend class for Earth which contains the Earth unit tests
  ***************************************/
class TestEarth : public UnitTest
{
public:
	void run()
	{
		// Constructors
		construct_default();
		construct_nonDefault();

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
		Earth earth;
		const double timeDilation = 24.0 * 60.0;
		const double timePerFrame = 48.0; // timeDilation / 30; // =48
		const double secondsDay = 86400.0;
		const double frameRate = 30.0;
		const double PI = 3.14159265358979323846;
		double rotation = (-((2 * PI) / frameRate) * (timeDilation / secondsDay));

		// exercise
		
		// verify
		assertEquals(earth.position.getMetersX(), 0.0);
		assertEquals(earth.position.getMetersY(), 0.0);
		assertEquals(earth.angle, 0.0);
		assertEquals(earth.radius, 6378000.0);
		//assertEquals(earth.rotation, rotation);
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
		Earth earth(3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
		// verify
		assertEquals(earth.position.getMetersX(), 3.0);
		assertEquals(earth.position.getMetersY(), 4.0);
		assertEquals(earth.angle, 7.0);
		assertEquals(earth.radius, 8.0);
		assertEquals(earth.rotation, 9.0);
		// teardown

	}
};

