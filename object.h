/***************************************************
 * Header File:
 *    Object : The representation of an object
 * Author:
 *    Daniel Carr & Bryce Chesley
 * Summary:
 *    Everything we need to know about an object on the screen.
***************************************************/

#pragma once

#include <iostream>
#include <cmath>
#include "position.h"
#include "velocity.h"

class TestObject;
class Position;
class Velocity;

/*********************************************
 * Object
 * A single object on the field in Meters
 *********************************************/
class object
{
	friend TestObject;

public:
	// constructors
	object() : position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	object(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	object(const object& pt) : position(pt.position), velocity(pt.velocity), angle(pt.angle), radius(pt.radius), rotation(pt.rotation) {}
	~object() {}

	// getters
	double getX() const { return position.getMetersX(); }
	double getY() const { return position.getMetersY(); }
	double getVelocityX() const { return velocity.getVelocityX(); }
	double getVelocityY() const { return velocity.getVelocityY(); }
	double getAngle() const { return angle; }
	double getRadius() const { return radius; }
	double getRotation() const { return rotation; }

	// setters
	void setX(double x) { position.setMetersX(x); }
	void setY(double y) { position.setMetersY(y); }
	void setVelocity(double dx, double dy) { velocity.setVelocityX(dx); velocity.setVelocityY(dy); }
	void setVelocityX(double dx) { velocity.setVelocityX(dx); }
	void setVelocityY(double dy) { velocity.setVelocityY(dy); }
	void setAngle(double angle) { this->angle = angle; }
	void setRadius(double radius) { this->radius = radius; }
	void setRotation(double rotation) { this->rotation = rotation; }

	// other functions
	virtual void draw() = 0;
	virtual void advance() = 0;

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
};
