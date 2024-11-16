/***********************************************************************
 * Header File:
 *    Test Star : Test the Star class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for Star
 ************************************************************************/
#pragma once
#include "star.h"
#include "unitTest.h"
#include <cassert>

 /***************************************
  * TEST Star
  * A friend class for Star which contains the Star unit tests
  ***************************************/
class TestStar : public UnitTest
{
	public:
		void run()
		{
			// Constructors
			construct_default();
			

			//Getters
			getPhase();

			//Setters
			setPhase();

			// Other functions
			draw();
			advance();

			report("Star");
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
			Star star;
			// verify
			assert(star.getX() >= -1280000 && star.getX() <= 1280000);
			assert(star.getY() >= -1280000 && star.getY() <= 1280000);
			assert(star.getPhase() >= 0 && star.getPhase() <= 127);
			// teardown

		}


		/*********************************************
		* name:    GET PHASE
		* input:   phase='b'
		* output:  phase='b'
		*********************************************/
		void getPhase()
		{
			// setup
			Star star(3, 4, 'b');
			// exercise
			char phase = star.getPhase();
			// verify
			assertEquals(phase, 'b');
			// teardown

		}

		/*********************************************
				* name:    SET PHASE
						* input:   phase='b'
								* output:  phase
								* *********************************************/

};

