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
Velocity::Velocity(double dx, double dy) : dx(0.0), dy(0.0)
{
	setVelocityX(dx);
	setVelocityY(dy);
}

/******************************************
 * VELOCITY : ASSIGNMENT
 * Assign a velocity
 *****************************************/
Velocity& Velocity::operator = (const Velocity& pt)
{
	dx = pt.dx;
	dy = pt.dy;
	return *this;
}

/******************************************
 * VELOCITY insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Velocity& pt)
{
	out << "(" << pt.getVelocityX() << "m/s , " << pt.getVelocityY() << "m/s)";
	return out;
}

