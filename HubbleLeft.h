/****************************************************
 * Header File:
 *    HubbleLeft : The representation of the HubbleLeft
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the HubbleLeft on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestHubbleLeft;
class Position;
class Velocity;
class uiDraw;
	
/*********************************************
 * HubbleLeft
 * A single HubbleLeft on the field in Meters
 *********************************************/
class HubbleLeft : public Part
{
	friend TestHubbleLeft;

	public:
		// constructors
		HubbleLeft() : Part() {}
		HubbleLeft(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		HubbleLeft(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

		// other functions
		void breakApart() { return; }
};
