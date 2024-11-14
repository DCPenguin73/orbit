/***************************************************
 * Header File:
 *    Earth : The representation of earth on the screen
 * Author:
 *    Daniel Carr & Bryce Chesley
 * Summary:
 *    Everything we need to know about earth on the screen.
***************************************************/
#pragma once

#include <iostream>
#include <cmath>
#include "object.h"
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"

class TestEarth;
class Position;
class Velocity;

/*********************************************
 * Earth
 * A single object on the field in Meters
 *********************************************/
class earth : public object
{
	friend TestEarth;

public:
	// constructors
	earth() : object(), angle(0.0), radius(0.0), rotation(0.0) {}
	earth(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	earth(const earth& pt) : object(pt), angle(pt.angle), radius(pt.radius), rotation(pt.rotation) {}
	~earth() {}


	// setters
	void setX(double x) { position.setMetersX(0.0); }
	void setY(double y) { position.setMetersY(0.0); }
	void setVelocity(double dx, double dy) { velocity.setVelocityX(0.0); velocity.setVelocityY(0.0); }
	void setVelocityX(double dx) { velocity.setVelocityX(0.0); }
	void setVelocityY(double dy) { velocity.setVelocityY(0.0); }

	// other functions
	void draw() 
	{
		ogstream earth;
		earth.drawEarth(position, angle); 
	}
	void advance() {};

private:
	Position position;
	Velocity velocity;
	double angle;
	double radius;
	double rotation;
};

