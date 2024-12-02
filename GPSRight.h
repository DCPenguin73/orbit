/****************************************************
 * Header File:
 *    GPSRight : The representation of the GPSRight
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the GPSRights on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestGPSRight;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * GPSRight
 * A single GPSRight on the field in Meters
 *********************************************/
class GPSRight : public Part
{
	friend TestGPSRight;

	public:
		// constructors
		GPSRight() : Part() {}
		GPSRight(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		GPSRight(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// other functions
		void breakApart() { return; }
};
