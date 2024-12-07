/****************************************************
 * Header File:
 *    StarLinkBody : The representation of the StarLinkBody
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the StarLinkBodys on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestStarLinkBody;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * StarLinkBody
 * A single StarLinkBody on the field in Meters
 *********************************************/
class StarLinkBody : public Part
{
	friend TestStarLinkBody;

public:
	// constructors
	StarLinkBody() : Part() {}
	StarLinkBody(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	StarLinkBody(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
