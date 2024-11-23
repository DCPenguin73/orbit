
#pragma once
#include "object.h"
#include "satellite.h"
class Satellite;

class TestCrewDragon;

class Object;

/*********************************************
 * CrewDragon
 * a object in the sky
 *********************************************/
class CrewDragon : public Satellite
{
	friend TestCrewDragon;
public:
	// constructors
	CrewDragon() : Satellite() {}
	CrewDragon(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	CrewDragon(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// getters
	ObjectType getType() const { return CREWDRAGON; }

	// setters

	// other functions
	void draw(ogstream& gout) { gout.drawCrewDragon(this->getPosition(), this->getAngle()); }

private:
	const ObjectType type = CREWDRAGON;
};