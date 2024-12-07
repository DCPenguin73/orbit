/****************************************************
 * Header File:
 *    StarLinkArray : The representation of the StarLinkArray
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the StarLinkArrays on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestStarLinkArray;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * StarLinkArray
 * A single StarLinkArray on the field in Meters
 *********************************************/
class StarLinkArray : public Part
{
	friend TestStarLinkArray;

public:
	// constructors
	StarLinkArray() : Part() {}
	StarLinkArray(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	StarLinkArray(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
