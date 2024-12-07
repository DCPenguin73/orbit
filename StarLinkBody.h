/****************************************************
 * Header File:
 *    StarLinkBody : The representation of the StarLinkBody
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the StarLinkBodys on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"
#include "Fragment.h"
#include "Part.h"
#include "Fragment.h"


class TestStarLinkBody;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * StarLinkBody
 * A single StarLinkBody on the field in Meters
 *********************************************/
class StarLinkBody : public Part
{
	friend TestStarLinkBody;

public:
	// constructors
	StarLinkBody() : Part() {}
	StarLinkBody(double x, double y, double dx, double dy, double angle, double radius, double rotation) {
		this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy);
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
	}
	StarLinkBody(Position pos, Velocity vel, double angle, double radius, double rotation) {
		this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius);
		this->setRotation(rotation);
	}

	// other functions
	void draw(ogstream& gout) { gout.drawStarlinkBody(this->getPosition(), this->getAngle()); }
	ObjectType getType() const { return STARLINK_BODY; }
	std::list<Object*> collide()

	{
		std::list<Object*> objects;
		double angle = this->getAngle();
		Position pt3 = this->getPosition();
		pt3.addPixelsX(((19) * sin(this->getAngle())));
		pt3.addPixelsY(((19) * cos(this->getAngle())));
		Velocity vel3;
		vel3.setVelocityX(this->getVelocityX());
		vel3.setVelocityY(this->getVelocityY());
		vel3.setVelocityX(vel3.getVelocityX() + ((7000) * sin(this->getAngle())));
		vel3.setVelocityY(vel3.getVelocityY() + ((7000) * cos(this->getAngle())));
		Fragment* fragment3 = new Fragment(pt3.getMetersX(), pt3.getMetersY(), vel3.getVelocityX(), vel3.getVelocityY(), angle, 2.0, 0.0);
		objects.push_back(fragment3);
		Position pt4 = this->getPosition();
		pt4.addPixelsX(((19) * sin(this->getAngle()) + 120));
		pt4.addPixelsY(((19) * cos(this->getAngle()) + 120));
		Velocity vel4;
		vel4.setVelocityX(this->getVelocityX());
		vel4.setVelocityY(this->getVelocityY());
		vel4.setVelocityX(vel4.getVelocityX() + ((7000) * sin(this->getAngle())));
		vel4.setVelocityY(vel4.getVelocityY() + ((7000) * cos(this->getAngle())));
		Fragment* fragment2 = new Fragment(pt4.getMetersX(), pt4.getMetersY(), vel4.getVelocityX(), vel4.getVelocityY(), angle, 2.0, 0.0);
		objects.push_back(fragment2);
		Position pt = this->getPosition();
		pt.addPixelsX(((19) * sin(this->getAngle()) + 240));
		pt.addPixelsY(((19) * cos(this->getAngle()) + 240));
		Velocity vel;
		vel.setVelocityX(this->getVelocityX());
		vel.setVelocityY(this->getVelocityY());
		vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle())));
		vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle())));
		Fragment* fragment = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), angle, 2.0, 0.0);
		objects.push_back(fragment);
		return objects;
	}
};
