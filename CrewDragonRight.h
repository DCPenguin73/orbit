/****************************************************
 * Header File:
 *    CrewDragonRight : The representation of the CrewDragonRight
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the CrewDragonRights on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestCrewDragonRight;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * CrewDragonRight
 * A single CrewDragonRight on the field in Meters
 *********************************************/
class CrewDragonRight : public Part
{
	friend TestCrewDragonRight;

public:
	// constructors
	CrewDragonRight() : Part() {}
	CrewDragonRight(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	CrewDragonRight(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
