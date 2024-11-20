/***************************************************
 * Header File:
 *    satellite : Virtual representation of a whole object
 * Author:
 *    Arlo Jolley
 * Summary:
 *    types of satellite
***************************************************/

#pragma once
#include <iostream> 
#include <cmath>
#include "object.h"
#include "position.h"
#include "velocity.h"
#include "objectType.h"
#include "uiDraw.h"


class TestSatellite;
class Position;
class Velocity;

/*********************************************
 * Satellite
 * a virtual object in the sky
 *********************************************/
class Satellite : public Object
{
public:
	friend TestSatellite;

	// constructors
	Satellite() :Object(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
	Satellite(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation;}

	// getters
	//virtual ObjectType getType() const = 0;

	// setters


	// other functions
	virtual void draw(ogstream& gout) {}

protected:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
};