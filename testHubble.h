///***********************************************************************
// * Header File:
// *    Test Hubble : Test the Hubble class
// * Author:
// *    Arlo Jolley
// * Summary:
// *    All the unit tests for Hubble
// ************************************************************************/
//#pragma once
//#include "hubble.h"
//#include "unitTest.h"
//#include "objectType.h"
//#include <iostream>
//
//
// /***************************************
//  * TEST Hubble
//   * A friend class for Hubble which contains the Hubble unit tests
//	***************************************/
//class TestHubble : public UnitTest
//{
//
//public:
//	void run()
//	{
//		// Constructors
//		construct_default();
//		construct_nonDefault();
//
//		// Getters
//		getType();
//
//		// other functions
//		advance();
//
//		report("Hubble");
//	}
//
//private:
//
//	/*********************************************
//	* name:    DEFAULT CONSTRUCTOR
//	* input:   nothing
//	* output:  type=0
//	*********************************************/
//	void construct_default()
//	{
//		// setup
//		Hubble hubble;
//		// exercise
//
//		// verify
//		assertEquals(hubble.getType(), HUBBLE);
//		assertEquals(hubble.getX(), 0.0);
//		assertEquals(hubble.getY(), 0.0);
//		assertEquals(hubble.getVelocityX(), 0.0);
//		assertEquals(hubble.getVelocityY(), 0.0);
//		assertEquals(hubble.getAngle(), 0.0);
//		assertEquals(hubble.getRadius(), 0.0);
//		assertEquals(hubble.getRotation(), 0.0);
//
//		// teardown
//	}
//
//	/*********************************************
//	* name:    NON-DEFAULT CONSTRUCTOR
//	* input:   type=1
//	* output:  type=1
//	*********************************************/
//	void construct_nonDefault()
//	{
//		// setup
//		Hubble hubble(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
//		// exercise
//
//		// verify
//		assertEquals(hubble.getType(), HUBBLE);
//		assertEquals(hubble.position.getMetersX(), 1.0);
//		assertEquals(hubble.position.getMetersY(), 2.0);
//		assertEquals(hubble.velocity.getVelocityX(), 3.0);
//		assertEquals(hubble.velocity.getVelocityY(), 4.0);
//		assertEquals(hubble.angle, 5.0);
//		assertEquals(hubble.radius, 6.0);
//		assertEquals(hubble.rotation, 7.0);
//		// teardown
//	}
//
//	/*********************************************
//	* name:    GET TYPE
//	* input:   type=1
//	* output:  type=1
//	*********************************************/
//	void getType()
//	{
//		// setup
//
//		// exercise
//		Hubble hubble;
//		// verify
//		assertEquals(hubble.getType(), 0);
//		// teardown
//	}
//
//	/*********************************************
//	* name:    ADVANCE
//	* input:   type=1
//	* output:  type=1
//	*********************************************/
//	void advance()
//	{
//		// setup
//		Hubble hubble(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, -0.0069813170079773175);
//		// exercise
//		hubble.advance();
//		// verify
//		assertEquals(hubble.getType(), HUBBLE);
//		assertEquals(hubble.position.getMetersX(), -186240.000000000);
//		assertEquals(hubble.position.getMetersY(), 26558045.627703581);
//		assertEquals(hubble.velocity.getVelocityX(), -3880.0);
//		assertEquals(hubble.velocity.getVelocityY(), -27.144059672480584);
//		assertEquals(hubble.angle, 1.4930186829920227);
//		assertEquals(hubble.radius, 10);
//		assertEquals(hubble.rotation, -0.0069813170079773175);
//		// teardown
//	}
//};