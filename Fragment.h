/****************************************************
 * Header File:
 *    Fragment : The representation of the fragments
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the fragments on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"

class TestFragment;
class Position;
class Velocity;
class uiDraw;
	
/*********************************************
 * Fragment
 * A single fragment on the field in Meters
 *********************************************/
class Fragment : public Object
{
	friend TestFragment;

	public:
		// constructors
		Fragment() : Object(), age(0) {}
		Fragment(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		Fragment(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		 this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return FRAGMENT; }
		int getAge() const { return age; }

		// setters
		void setAge(int age) { this->age = age; }

		// other functions
		void draw(ogstream& gout) { gout.drawFragment(this->getPosition(), this->getRotation()); }

	private:
		const ObjectType type = FRAGMENT;
		int age = 0;
};