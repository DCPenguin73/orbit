/****************************************************
 * Header File:
 *    CrewDragonLeft : The representation of the CrewDragonLeft
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the CrewDragonLefts on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestCrewDragonLeft;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * CrewDragonLeft
 * A single CrewDragonLeft on the field in Meters
 *********************************************/
class CrewDragonLeft : public Part
{
	friend TestCrewDragonLeft;

public:
	// constructors
	CrewDragonLeft() : Part() {}
	CrewDragonLeft(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	CrewDragonLeft(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
