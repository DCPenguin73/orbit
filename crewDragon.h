
#pragma once
#include "satellite.h"

class TestCrewDragon;

class Satellite;

/*********************************************
 * CrewDragon
 * a object in the sky
 *********************************************/
class CrewDragon : public Satellite
{
	friend TestCrewDragon;
public:
	// constructors
	CrewDragon() : Satellite(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	CrewDragon(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	CrewDragon(Position pos, Velocity vel, double angle, double radius, double rotation) { this->position = pos; this->velocity = vel; this->angle = angle; this->radius = radius; this->rotation = rotation; }

	// getters
	ObjectType getType() const { return CREWDRAGON; }

	// setters

	// other functions
	void draw(ogstream& gout)
	{
		Position& pos = position;
		gout.drawCrewDragon(pos, angle);
	}
	void advance();

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
	const ObjectType type = CREWDRAGON;
};

