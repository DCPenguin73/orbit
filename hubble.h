
#pragma once
#include "object.h"

class TestHubble;

class Object;

/*********************************************
 * Hubble
 * a object in the sky
 *********************************************/
class Hubble : public Object
{
	friend TestHubble;
public:
	// constructors
	Hubble() : Object() {}
	Hubble(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	Hubble(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// getters
	ObjectType getType() const { return HUBBLE; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawHubble(this->getPosition(), this->getAngle()); }
	void advance();

private:
	const ObjectType type = HUBBLE;
};