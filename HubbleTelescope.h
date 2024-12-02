/****************************************************
 * Header File:
 *    HubbleTelescope : The representation of the HubbleTelescope
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the HubbleTelescope on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestHubbleTelescope;
class Position;
class Velocity;
class uiDraw;
	
/*********************************************
 * HubbleTelescope
 * A single HubbleTelescope on the field in Meters
 *********************************************/
class HubbleTelescope : public Part
{
	friend TestHubbleTelescope;

	public:
		// constructors
		HubbleTelescope() : Part() {}
		HubbleTelescope(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		HubbleTelescope(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// other functions
		void breakApart() { return; }
};
