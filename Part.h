/****************************************************
 * Header File:
 *    Part : The representation of the parts
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the parts on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"

class TestPart;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * Part
 * A single part on the field in Meters
 *********************************************/
class Part : public Object
{
	friend TestPart;

	public:
		// constructors
		Part() : Object() {}
		Part(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); 
		this->setRadius(radius); this->setRotation(rotation); }
		Part(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }
		
		// other functions
		virtual void breakApart() = 0;
		
};
