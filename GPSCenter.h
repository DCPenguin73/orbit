/****************************************************
 * Header File:
 *    GPSCenter : The representation of theGPSCenter
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the GPSCenters on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestGPSCenter;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * GPSCenter
 * A single GPSCenter on the field in Meters
 *********************************************/
class GPSCenter : public Part
{
	friend TestGPSCenter;

	public:
		// constructors
		GPSCenter() : Part() {}
		GPSCenter(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		GPSCenter(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

		// other functions
		void breakApart() { return; }
};