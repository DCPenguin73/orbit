

#pragma once
#include "satellite.h"

class TestStarLink;

class Satellite;

/*********************************************
 * StarLink
 * a object in the sky
 *********************************************/
class StarLink : public Satellite
{
	friend TestStarLink;
public:
	// constructors
	StarLink() : Satellite(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	StarLink(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	StarLink(Position pos, Velocity vel, double angle, double radius, double rotation) { this->position = pos; this->velocity = vel; this->angle = angle; this->radius = radius; this->rotation = rotation; }

	// getters
	ObjectType getType() const { return STARLINK; }

	// setters

	// other functions
	void draw(ogstream& gout)
	{
		Position& pos = position;
		gout.drawStarlink(pos, angle);
	}
	void advance();

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
	const ObjectType type = STARLINK;
};

