/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/

#pragma once
#include "velocity.h"
#include "unitTest.h"


 /***************************************
  * TEST Velocity
  * A friend class for Velocity which contains the Velocity unit tests
  ***************************************/
class TestVelocity : public UnitTest
{
public:
	void run()
	{
		// Constructors
		construct_default();
		construct_nonDefault();
		construct_copy();


		// Getters
		getVelocityX();
		getVelocityY();
		getAccelerationX();
		getAccelerationY();

		// Setters
		setVelocity();
		setVelocityX();
		setVelocityY();
		setAccelerationX();
		setAccelerationY();

		report("Velocity");
	}

private:
	/*********************************************
	* name:    DEFAULT CONSTRUCTOR
	* input:   nothing
	* output:  dx=0, dy=0, ddx=0, ddy=0
	*********************************************/
	void construct_default()
	{
		// setup

		// exercise
		Velocity vel;
		// verify
		assertEquals(vel.getVelocityX(), 0.0);
		assertEquals(vel.getVelocityY(), 0.0);
		assertEquals(vel.getAccelerationX(), 0.0);
		assertEquals(vel.getAccelerationY(), 0.0);
		// teardown

	}

	/*********************************************
	* name:    NON-DEFAULT CONSTRUCTOR
	* input:   dx=3, dy=4, ddx=5, ddy=6
	* output:  dx=3, dy=4, ddx=5, ddy=6
	*********************************************/
	void construct_nonDefault()
	{
		// setup

		// exercise
		Velocity vel(3, 4, 5, 6);
		// verify
		assertEquals(vel.getVelocityX(), 3.0);
		assertEquals(vel.getVelocityY(), 4.0);
		assertEquals(vel.getAccelerationX(), 5.0);
		assertEquals(vel.getAccelerationY(), 6.0);
		// teardown

	}

	/*********************************************
	* name:    COPY CONSTRUCTOR
	* input:   dx=3, dy=4, ddx=5, ddy=6
	* output:  dx=3, dy=4, ddx=5, ddy=6
	*********************************************/
	void construct_copy()
	{
		// setup
		Velocity vel(3, 4, 5, 6);
		// exercise
		Velocity vel2(vel);
		// verify
		assertEquals(vel2.getVelocityX(), 3.0);
		assertEquals(vel2.getVelocityY(), 4.0);
		assertEquals(vel2.getAccelerationX(), 5.0);
		assertEquals(vel2.getAccelerationY(), 6.0);
		// teardown

	}

	/*********************************************
	* name:    GET VELOCITY X
	* input:   dx=3
	* output:  dx=3
	*********************************************/
	void getVelocityX()
	{
		// setup
		Velocity vel(3, 4, 5, 6);
		// exercise
		double dx = vel.getVelocityX();
		// verify
		assertEquals(dx, 3.0);
		// teardown

	}

	/*********************************************
	* name:    GET VELOCITY Y
	* input:   dy=4
	* output:  dy=4
	*********************************************/
	void getVelocityY()
	{
		// setup
		Velocity vel(3, 4, 5, 6);
		// exercise
		double dy = vel.getVelocityY();
		// verify
		assertEquals(dy, 4.0);
		// teardown

	}

	/*********************************************
	* name:    GET ACCELERATION X
	* input:   ddx=5
	* output:  ddx=5
	*********************************************/
	void getAccelerationX()
	{
		// setup
		Velocity vel(3, 4, 5, 6);
		// exercise
		double ddx = vel.getAccelerationX();
		// verify
		assertEquals(ddx, 5.0);
		// teardown

	}

	/*********************************************
	* name:    GET ACCELERATION Y
	* input:   ddy=6
	* output:  ddy=6
	*********************************************/
	void getAccelerationY()
	{
		// setup
		Velocity vel(3, 4, 5, 6);
		// exercise
		double ddy = vel.getAccelerationY();
		// verify
		assertEquals(ddy, 6.0);
		// teardown

	}

	/*********************************************
	* name:    SET VELOCITY
	* input:   dx=3, dy=4
	* output:  dx=3, dy=4
	**********************************************/
	void setVelocity()
	{
		// setup
		Velocity vel;
		// exercise
		vel.setVelocity(3, 4);
		// verify
		assertEquals(vel.getVelocityX(), 3.0);
		assertEquals(vel.getVelocityY(), 4.0);
		// teardown

	}

	/*********************************************
	* name:    SET VELOCITY X
	* input:   dx=3
	* output:  dx=3
	**********************************************/
	void setVelocityX()
	{
		// setup
		Velocity vel;
		// exercise
		vel.setVelocityX(3);
		// verify
		assertEquals(vel.getVelocityX(), 3.0);
		// teardown

	}

	/*********************************************
	* name:    SET VELOCITY Y
	* input:   dy=4
	* output:  dy=4
	* **********************************************/
	void setVelocityY()
	{
		// setup
		Velocity vel;
		// exercise
		vel.setVelocityY(4);
		// verify
		assertEquals(vel.getVelocityY(), 4.0);
		// teardown

	}

	/*********************************************
	* name:    SET
	* input:   ddx=5
	* output:  ddx=5
	* **********************************************/
	void setAccelerationX()
	{
		// setup
		Velocity vel;
		// exercise
		vel.setAccelerationX(5);
		// verify
		assertEquals(vel.getAccelerationX(), 5.0);
		// teardown

	}

	/*********************************************
	* name:    SET
	* input:   ddy=6
	* output:  ddy=6
	* **********************************************/
	void setAccelerationY()
	{
		// setup
		Velocity vel;
		// exercise
		vel.setAccelerationY(6);
		// verify
		assertEquals(vel.getAccelerationY(), 6.0);
		// teardown

	}
};

