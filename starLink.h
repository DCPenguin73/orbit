

#pragma once
#include "object.h"

class TestStarLink;

class Object;

/*********************************************
 * StarLink
 * a object in the sky
 *********************************************/
class StarLink : public Object
{
	friend TestStarLink;
public:
	// constructors
	StarLink() : Object() {}
	StarLink(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	StarLink(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// getters
	ObjectType getType() const { return STARLINK; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawStarlink(this->getPosition(), this->getAngle()); }
	void advance();

private:
	const ObjectType type = STARLINK;
};