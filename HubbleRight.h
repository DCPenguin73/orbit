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
	void draw(ogstream& gout) { gout.drawHubbleRight(this->getPosition(), this->getAngle()); }
	ObjectType getType() const { return HUBBLE_RIGHT; }   // frag amount: 2
	std::list<Object*> collide() const
	{
		Position pt = this->getPosition();
		pt.addPixelsX(((19) * sin(this->getAngle())));
		pt.addPixelsY(((19) * cos(this->getAngle())));
		Velocity vel;
		vel.setVelocityX(this->getVelocityX());
		vel.setVelocityY(this->getVelocityY());
		vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle())));
		vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle())));

		Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);
		Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() + 180), 1.0, 0.0);

		std::list<Object*> objects;
		objects.push_back(fragment1);
		objects.push_back(fragment2);
		return objects;
	}
};
