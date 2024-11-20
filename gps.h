

#pragma once
#include "Object.h"

class TestGps;

class Object;

/*********************************************
 * Gps
 * a object in the sky
 *********************************************/
class Gps : public Object
{
	friend TestGps;
public:
	// constructors
	Gps() : Object() {}
	Gps(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	Gps(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}

	// getters
	ObjectType getType() const { return GPS; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawGPS(this->getPosition(), this->getAngle()); }
	void advance();

private:
	const ObjectType type = GPS;
};

