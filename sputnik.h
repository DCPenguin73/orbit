
#pragma once
#include "object.h"

class TestSputnik;

class Object;

/*********************************************
 * Sputnik
 * a object in the sky
 *********************************************/
class Sputnik : public Object
{
	friend TestSputnik;
public:
	// constructors
	Sputnik() : Object() {}
	Sputnik(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	Sputnik(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// getters
	ObjectType getType() const { return SPUTNIK; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawSputnik(this->getPosition(), this->getAngle()); }
	void advance();

private:
	const ObjectType type = SPUTNIK;
};