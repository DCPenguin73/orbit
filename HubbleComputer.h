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
	HubbleComputer(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
	this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
	HubbleComputer(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
	this->setRotation(rotation); }

	// other functions
	void draw(ogstream& gout) { gout.drawHubbleComputer(this->getPosition(), this->getAngle()); }
	ObjectType getType() const { return HUBBLE_COMPUTER; }    // frag amount: 2
	std::list<Object*> collide() const
	{
		std::list<Object*> objects;
		{
			Position pt = this->getPosition();
			pt.addPixelsX(((19) * sin(this->getAngle())));
			pt.addPixelsY(((19) * cos(this->getAngle())));
			Velocity vel;
			vel.setVelocityX(this->getVelocityX());
			vel.setVelocityY(this->getVelocityY());
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle())));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle())));

			Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 2.0, 0.0);
			objects.push_back(fragment1);
		}
		{
			Position pt = this->getPosition();
			pt.addPixelsX(((19) * sin(this->getAngle() + 90)));
			pt.addPixelsY(((19) * cos(this->getAngle() + 90)));
			Velocity vel;
			vel.setVelocityX(this->getVelocityX());
			vel.setVelocityY(this->getVelocityY());
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 90)));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 90)));
			Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() + 30), 2.0, 0.0);
			objects.push_back(fragment2);
		}
		return objects;
	}
};
