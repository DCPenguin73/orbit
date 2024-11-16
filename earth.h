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

const double timeDilation = 24.0 * 60.0;
const double timePerFrame = 48.0; // timeDilation / 30; // =48
const double secondsDay = 86400.0;
const double frameRate = 30.0;
const double PI = 3.14159265358979323846;

/*********************************************
 * Earth
 * A single object on the field in Meters
 *********************************************/

class Earth : public Object
{
	friend TestEarth;

public:
	// constructors
	Earth() : Object(), angle(0.0), radius(6378000.0), rotation(rotation) {}
	Earth(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
	Earth(const Earth& pt) : Object(pt), angle(pt.angle), radius(pt.radius), rotation(pt.rotation) {}
	~Earth() {}


	// setters
	void setX(double x) { position.setMetersX(0.0); }
	void setY(double y) { position.setMetersY(0.0); }
	void setVelocity(double dx, double dy) { velocity.setVelocityX(0.0); velocity.setVelocityY(0.0); }
	void setVelocityX(double dx) { velocity.setVelocityX(0.0); }
	void setVelocityY(double dy) { velocity.setVelocityY(0.0); }

	// other functions
	void draw(ogstream& gout) 
	{
		gout.drawEarth(position, angle); 
	}
	void advance() { angle += rotation; }

private:
	Position position;
	Velocity velocity;
	double angle = 0.0;
	const double radius = 6378000.0;
	const double rotation = (-((2 * PI) / frameRate) * (timeDilation / secondsDay));;
};

