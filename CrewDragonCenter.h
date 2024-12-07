/****************************************************
 * Header File:
 *    CrewDragonCenter : The representation of theCrewDragonCenter
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the CrewDragonCenters on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestCrewDragonCenter;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * CrewDragonCenter
 * A single CrewDragonCenter on the field in Meters
 *********************************************/
class CrewDragonCenter : public Part
{
	friend TestCrewDragonCenter;

public:
	// constructors
	CrewDragonCenter() : Part() {}
	CrewDragonCenter(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	CrewDragonCenter(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
