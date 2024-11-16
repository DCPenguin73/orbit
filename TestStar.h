///***********************************************************************
// * Header File:
// *    Test Star : Test the Star class
// * Author:
// *    Daniel Carr
// * Summary:
// *    All the unit tests for Star
// ************************************************************************/
//#pragma once
//#include "star.h"
//#include "unitTest.h"
//
// /***************************************
//  * TEST Star
//  * A friend class for Star which contains the Star unit tests
//  ***************************************/
//class TestStar : public UnitTest
//{
//	public:
//		void run()
//		{
//			// Constructors
//			construct_default();
//			
//			// Other functions
//			advance();
//
//			report("Star");
//		}
//
//	private:
//		/*********************************************
//		* name:    DEFAULT CONSTRUCTOR
//		* input:   nothing
//		* output:  pos=(0, 0))
//		*********************************************/
//		void construct_default()
//		{
//			// setup
//
//			// exercise
//			Star star;
//			// verify
//			assertUnit(star.getX() >= -1280000 && star.getX() <= 1280000);
//			assertUnit(star.getY() >= -1280000 && star.getY() <= 1280000);
//			assertUnit(star.getPhase() >= 0 && star.getPhase() <= 127);
//			// teardown
//
//		}
//
//		/*********************************************
//		* name:    ADVANCE
//		* input:   nothing
//		* output:  phase++
//		* ********************************************/
//		void advance()
//		{
//			// setup
//			Star star;
//			char phase = star.getPhase();
//			// exercise
//			star.advance();
//			// verify
//			assertUnit(star.getPhase() == phase + 1);
//			// teardown
//
//		}
//};
//
