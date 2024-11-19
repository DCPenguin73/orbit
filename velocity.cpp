/***********************************************************************
 * Source File:
 *    Velocity : The representation of a speed on the screen
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about a speed on the screen.
 ************************************************************************/

#pragma once
#include "velocity.h"
#include <cassert>

 /******************************************
  * VELOCITY : ASSIGNMENT
  * Assign a velocity
  *****************************************/
Velocity::Velocity(double dx, double dy, double ddx, double ddy) : dx(0.0), dy(0.0), ddx(0.0), ddy(0.0)
{
	setVelocityX(dx);
	setVelocityY(dy);
	setAccelerationX(ddx);
	setAccelerationY(ddy);
}


/******************************************
 * VELOCITY : ASSIGNMENT
 * Assign a velocity
 *****************************************/
Velocity& Velocity::operator = (const Velocity& pt)
{
	dx = pt.dx;
	dy = pt.dy;
	ddx = pt.ddx;
	ddy = pt.ddy;
	return *this;
}


/******************************************
 * VELOCITY : ADDITION
 * Add two velocities together
 *****************************************/
Velocity Velocity::operator + (const Velocity& pt) const
{
	Velocity sum;
	sum.dx = dx + pt.dx;
	sum.dy = dy + pt.dy;
	sum.ddx = ddx + pt.ddx;
	sum.ddy = ddy + pt.ddy;
	return sum;
}
