/****************************************************
 * Header File:
 *    CrewDragonCenter : The representation of theCrewDragonCenter
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the CrewDragonCenters on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Part.h"
#include <list>
#include "Fragment.h"

class TestCrewDragonCenter;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * CrewDragonCenter
 * A single CrewDragonCenter on the field in Meters
 *********************************************/
class CrewDragonCenter : public Part
{
	friend TestCrewDragonCenter;

public:
	// constructors
	CrewDragonCenter() : Part() {}
	CrewDragonCenter(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	CrewDragonCenter(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	ObjectType getType() const { return CREWDRAGON_CENTER; }
	void draw(ogstream& gout) { gout.drawCrewDragonCenter(this->getPosition(), this->getAngle()); }
	std::list<Object*> collide() 
	{  
		Position pt = this->getPosition();
		pt.addPixelsX(((19) * sin(this->getAngle())));
		pt.addPixelsY(((19) * cos(this->getAngle())));
		Velocity vel;
		vel.setVelocityX(this->getVelocityX());
		vel.setVelocityY(this->getVelocityY());
		vel.setVelocityX(vel.getVelocityX() + ((9000) * sin(this->getAngle())));
		vel.setVelocityY(vel.getVelocityY() + ((9000) * cos(this->getAngle())));

		Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);
		Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle()+30), 1.0, 0.0);
		Fragment* fragment3 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle()-30), 1.0, 0.0);
		Fragment* fragment4 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), (this->getAngle()+90), 1.0, 0.0);

		std::list<Object*> objects;
		objects.push_back(fragment1);
		objects.push_back(fragment2);
		objects.push_back(fragment3);
		objects.push_back(fragment4);
		return objects;

	}

	// other functions
private:
	const ObjectType type = CREWDRAGON_CENTER;
};
