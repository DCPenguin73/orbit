/***************************************************
 * Header File:
 *    Velocity : The representation of a speed
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about a speed on the screen.
***************************************************/

#pragma once
#include <iostream> 
#include <cmath>

class TestVelocity;
class Acceleration;
class Position;
class TestObject;

/*********************************************
 * Velocity
 * A single velocity on the field in Meters per second
 *********************************************/
class Velocity
{
public:
	friend TestVelocity;
	friend TestObject;

	// constructors
	Velocity() : dx(0.0), dy(0.0), ddx(0.0), ddy(0.0) {}
	//Velocity(double dx, double dy, double ddx, double ddy) : dx(0.0), dy(0.0), ddx(0.0), ddy(0.0) { setVelocityX(dx); setVelocityY(dy); }
	Velocity(double dx, double dy, double ddx, double ddy) : dx(0.0), dy(0.0), ddx(0.0), ddy(0.0) { setVelocityX(dx); setVelocityY(dy); setAccelerationX(ddx); setAccelerationY(ddy); }
	Velocity(const Velocity& pt) : dx(pt.dx), dy(pt.dy), ddx(pt.ddx), ddy(pt.ddy) {}
	Velocity& operator = (const Velocity& pt);
	Velocity operator + (const Velocity& pt) const;

	// getters
	double getVelocityX()     const { return dx; }
	double getVelocityY()     const { return dy; }
	double getAccelerationX()  const { return ddx; }
	double getAccelerationY()  const { return ddy; }

	// setters
	void setVelocity(double dx, double dy) { this->dx = dx; this->dy = dy; }
	void setVelocityX(double dx) { this->dx = dx; }
	void setVelocityY(double dy) { this->dy = dy; }
	void setAccelerationX(double ddx) { this->ddx = ddx; }
	void setAccelerationY(double ddy) { this->ddy = ddy; }

private:
	double dx;
	double dy;
	double ddx;
	double ddy;
};