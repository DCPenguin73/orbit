/****************************************************
 * Header File:
 *    CrewDragonRight : The representation of the CrewDragonRight
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the CrewDragonRights on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"

class TestCrewDragonRight;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * CrewDragonRight
 * A single CrewDragonRight on the field in Meters
 *********************************************/
class CrewDragonRight : public Part
{
	friend TestCrewDragonRight;

public:
	// constructors
	CrewDragonRight() : Part() {}
	CrewDragonRight(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	CrewDragonRight(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}
	ObjectType getType() const { return CREWDRAGON_RIGHT; }
	void draw(ogstream& gout) { gout.drawCrewDragonRight(this->getPosition(), this->getAngle()); }

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
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle())));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle())));

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
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 120)));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 120)));
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
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 240)));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 240)));
			Fragment* fragment3 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle() - 30), 2.0, 0.0);
			objects.push_back(fragment3);
		}
		return objects;
	}
};
