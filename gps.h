

#pragma once
#include "satellite.h"

class Satellite;

/*********************************************
 * Gps
 * a object in the sky
 *********************************************/
class Gps :
    public Satellite
{
public:
	// constructors
	Gps() : Satellite(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	Gps(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }

	// getters
	ObjectType getType() const { return GPS; }

	// setters

	// other functions
	void draw() {
		ogstream gps;
		gps.drawGPS(position, angle);
	}
	void advance() {}

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
	const ObjectType type = GPS;
};
