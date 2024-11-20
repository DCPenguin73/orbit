
#pragma once
#include "satellite.h"

class TestCrewDragon;

class Satellite;

/*********************************************
 * CrewDragon
 * a object in the sky
 *********************************************/
class CrewDragon : public Object
{
	friend TestCrewDragon;
public:
	// constructors
	CrewDragon() : Object() {}
	CrewDragon(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	CrewDragon(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}

	// getters
	ObjectType getType() const { return CREWDRAGON; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawCrewDragon(this->getPosition(), this->getAngle()); }
	void advance();

private:
	const ObjectType type = CREWDRAGON;
};

