
#pragma once
#include "satellite.h"

class TestSputnik;

class Satellite;

/*********************************************
 * Sputnik
 * a object in the sky
 *********************************************/
class Sputnik : public Satellite
{
	friend TestSputnik;
public:
	// constructors
	Sputnik() : Satellite(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	Sputnik(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	Sputnik(Position pos, Velocity vel, double angle, double radius, double rotation) { this->position = pos; this->velocity = vel; this->angle = angle; this->radius = radius; this->rotation = rotation; }

	// getters
	ObjectType getType() const { return SPUTNIK; }

	// setters

	// other functions
	void draw(ogstream& gout)
	{
		Position& pos = position;
		gout.drawSputnik(pos, angle);
	}
	void advance();

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
	const ObjectType type = SPUTNIK;
};

