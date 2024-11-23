///***********************************************************************
// * Header File:
// *    Test Gps : Test the Gps class
// * Author:
// *    Daniel Carr
// * Summary:
// *    All the unit tests for Gps
// ************************************************************************/
//#pragma once
//#include "gps.h"
//#include "unitTest.h"
//#include "objectType.h"
//#include <iostream>
//
//
// /***************************************
//  * TEST Gps
//   * A friend class for Gps which contains the Gps unit tests
//	***************************************/
//class TestGps : public UnitTest
//{
//
//	public:
//		void run()
//		{
//			// Constructors
//			construct_default();
//			construct_nonDefault();
//
//			// Getters
//			getType();
//
//			// other functions
//			advance();
//
//			report("Gps");
//		}
//
//	private:
//
//		/*********************************************
//		* name:    DEFAULT CONSTRUCTOR
//		* input:   nothing
//		* output:  type=0
//		*********************************************/
//		void construct_default()
//		{
//			// setup
//			Gps gps;
//			// exercise
//			
//			// verify
//			assertEquals(gps.getType(), GPS);
//			assertEquals(gps.getX(), 0.0);
//			assertEquals(gps.getY(), 0.0);
//			assertEquals(gps.getVelocityX(), 0.0);
//			assertEquals(gps.getVelocityY(), 0.0);
//			assertEquals(gps.getAngle(), 0.0);
//			assertEquals(gps.getRadius(), 0.0);
//			assertEquals(gps.getRotation(), 0.0);
//
//			// teardown
//		}
//
//		/*********************************************
//		* name:    NON-DEFAULT CONSTRUCTOR
//		* input:   type=1
//		* output:  type=1
//		*********************************************/
//		void construct_nonDefault()
//		{
//			// setup
//			Gps gps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
//			// exercise
//			
//			// verify
//			assertEquals(gps.getType(), GPS);
//			assertEquals(gps.position.getMetersX(), 1.0);
//			assertEquals(gps.position.getMetersY(), 2.0);
//			assertEquals(gps.velocity.getVelocityX(), 3.0);
//			assertEquals(gps.velocity.getVelocityY(), 4.0);
//			assertEquals(gps.angle, 5.0);
//			assertEquals(gps.radius, 6.0);
//			assertEquals(gps.rotation, 7.0);
//			// teardown
//		}
//
//		/*********************************************
//		* name:    GET TYPE
//		* input:   type=1
//		* output:  type=1
//		*********************************************/
//		void getType()
//		{
//			// setup
//
//			// exercise
//			Gps gps;
//			// verify
//			assertEquals(gps.getType(), 1);
//			// teardown
//		}
//
//		/*********************************************
//		* name:    ADVANCE
//		* input:   type=1
//		* output:  type=1
//		*********************************************/
//		void advance()
//		{
//			// setup
//			Gps gps(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, -0.0069813170079773175);
//			// exercise
//			gps.advance();
//			// verify
//			assertEquals(gps.getType(), GPS);
//			assertEquals(gps.position.getMetersX(), -186240.000000000);
//			assertEquals(gps.position.getMetersY(), 26558045.627703581);
//			assertEquals(gps.velocity.getVelocityX(), -3880.0);
//			assertEquals(gps.velocity.getVelocityY(), -27.144059672480584);
//			assertEquals(gps.angle, 1.4930186829920227);
//			assertEquals(gps.radius, 10);
//			assertEquals(gps.rotation, -0.0069813170079773175);
//			// teardown
//		}
//};