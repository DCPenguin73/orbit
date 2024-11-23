/****************************************************
 * Header File:
 *    GPSLeft : The representation of the GPSLeft
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the GPSLefts on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestGPSLeft;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * GPSLeft
 * A single GPSLeft on the field in Meters
 *********************************************/
class GPSLeft : public Part
{
	friend TestGPSLeft;

public:
	// constructors
	GPSLeft() : Part() {}
	GPSLeft(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	GPSLeft(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// other functions
	void breakApart() { return; }
};
