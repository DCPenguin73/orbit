/****************************************************
 * Header File:
 *    Ship : The representation of the ship
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the ship on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"

class TestShip;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * Ship
 * A single ship on the field in Meters
 *********************************************/
class Ship : public Object
{
	friend TestShip;

	public:
		// constructors
		Ship() : Object(), thrust(false) {}
		Ship(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);}
		Ship(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return SHIP; }
		bool getThrust() const { return thrust; }

		// setters
		void setThrust(bool thrust) { this->thrust = thrust; }

		// other functions
		void draw(ogstream& gout) { gout.drawShip(this->getPosition(), this->getAngle(), this->getThrust()); }
		void advance();

	private:
		bool thrust = false;
		const ObjectType type = SHIP;

};

