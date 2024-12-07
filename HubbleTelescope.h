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
		void draw(ogstream& gout) { gout.drawHubbleTelescope(this->getPosition(), this->getAngle()); }
		ObjectType getType() const { return HUBBLE_TELESCOPE; }  // frag amount: 3
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
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 180)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 180)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 180)));
				vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 180)));
				Fragment* fragment3 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() - 30), 2.0, 0.0);
				objects.push_back(fragment3);
			}
			return objects;
		}
};
