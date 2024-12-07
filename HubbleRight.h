/****************************************************
 * Header File:
 *    HubbleRight : The representation of the HubbleRight
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the HubbleRight on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestHubbleRight;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * HubbleRight
 * A single HubbleRight on the field in Meters
 *********************************************/
class HubbleRight : public Part
{
	friend TestHubbleRight;

public:
	// constructors
	HubbleRight() : Part() {}
	HubbleRight(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	HubbleRight(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void breakApart() { return; }
};
