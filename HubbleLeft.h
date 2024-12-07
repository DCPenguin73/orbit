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
		HubbleLeft(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		HubbleLeft(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// other functions
		void draw(ogstream& gout) { gout.drawHubbleLeft(this->getPosition(), this->getAngle()); }
		ObjectType getType() const { return HUBBLE_LEFT; }  // frag amount: 2
		std::list<Object*> collide() const
		{
			std::list<Object*> objects;
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((4) * sin(this->getAngle())));
				pt.addPixelsY(((4) * cos(this->getAngle())));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle())));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle())));

				Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 2.0, 0.0);
				objects.push_back(fragment1);
			}
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((4) * sin(this->getAngle() + 90)));
				pt.addPixelsY(((4) * cos(this->getAngle() + 90)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle() + 90)));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle() + 90)));
				Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() + 30), 2.0, 0.0);
				objects.push_back(fragment2);
			}
			return objects;
		}
};
