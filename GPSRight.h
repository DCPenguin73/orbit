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
#include "Fragment.h"

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
		ObjectType getType() const { return GPS_RIGHT; }
		void draw(ogstream& gout) { gout.drawGPSRight(this->getPosition(), this->getAngle()); }

		std::list<Object*> collide()
		{
			std::list<Object*> objects;
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((6) * sin(this->getAngle())));
				pt.addPixelsY(((6) * cos(this->getAngle())));
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
				pt.addPixelsX(((6) * sin(this->getAngle() + 120)));
				pt.addPixelsY(((6) * cos(this->getAngle() + 120)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle() + 120)));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle() + 120)));
				Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() + 30), 2.0, 0.0);
				objects.push_back(fragment2);
			}
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((6) * sin(this->getAngle() + 240)));
				pt.addPixelsY(((6) * cos(this->getAngle() + 240)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle() + 240)));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle() + 240)));
				Fragment* fragment3 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() - 30), 2.0, 0.0);
				objects.push_back(fragment3);
			}
			return objects;
		}

};
