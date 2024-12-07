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
#include "Position.h"
#include "Velocity.h"
#include "uiDraw.h"
#include "ObjectType.h"

class TestObject;
class Position;
class Velocity;

/*********************************************
 * Object
 * A single object on the field in Meters
 *********************************************/
class Object
{
	friend TestObject;

public:
	// constructors
	Object() : position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	Object(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); 
	this->angle = angle; this->radius = radius; this->rotation = rotation; }
	Object(const Object& pt) : position(pt.position), velocity(pt.velocity), angle(pt.angle), radius(pt.radius), rotation(pt.rotation) {}
	~Object() {}

	// getters
	double getX() const { return position.getMetersX(); }
	double getY() const { return position.getMetersY(); }
	Position getPosition() const { return position; }
	double getVelocityX() const { return velocity.getVelocityX(); }
	double getVelocityY() const { return velocity.getVelocityY(); }
	double getAngle() const { return angle; }
	double getRadius() const { return radius; }
	double getRotation() const { return rotation; }

	// setters
	void setX(double x) { this->position.setMetersX(x); }
	void setY(double y) { this->position.setMetersY(y); }
	void setPosition(Position pos) { this->position = pos; }
	void setVelocity(Velocity vel) { this->velocity.setVelocityX(vel.getVelocityX()); this->velocity.setVelocityY(vel.getVelocityY()); }
	void setVelocity(double dx, double dy) { velocity.setVelocityX(dx); velocity.setVelocityY(dy); }
	void setVelocityX(double dx) { this->velocity.setVelocityX(dx); }
	void setVelocityY(double dy) { this->velocity.setVelocityY(dy); }
	void setAngle(double angle) { this->angle = angle; }
	void setRadius(double radius) { this->radius = radius; }
	void setRotation(double rotation) { this->rotation = rotation; }

	// other functions
	virtual void draw(ogstream& gout) = 0;
	virtual void advance();
	virtual ObjectType getType() const = 0;
	//virtual std::list<Object*> collide() const = 0;

protected:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
};

class DummyObject : public Object
{
	friend TestObject;
public:
	DummyObject() : Object() {};
	DummyObject(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); 
	velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	~DummyObject() {}
	void draw(ogstream& gout)
	{
		return;
	}

	ObjectType getType() const
	{
		return DUMMY;
	}

};
