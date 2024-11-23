/****************************************************
 * Header File:
 *    HubbleComputer : The representation of the HubbleComputer
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the HubbleComputer on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestHubbleComputer;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * HubbleComputer
 * A single HubbleComputer on the field in Meters
 *********************************************/
class HubbleComputer : public Part
{
	friend TestHubbleComputer;

public:
	// constructors
	HubbleComputer() : Part() {}
	HubbleComputer(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	HubbleComputer(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

	// other functions
	void breakApart() { return; }
};
