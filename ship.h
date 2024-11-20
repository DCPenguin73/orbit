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
#include "position.h"
#include "uiDraw.h"
#include "object.h"
#include "objectType.h"

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
		Ship() : Object(), position(), velocity(), angle(0.0), radius(0.0), rotation(0.0) {}
		Ship(double x, double y, double dx, double dy, double angle, double radius, double rotation) { position.setMetersX(x); position.setMetersY(y); velocity.setVelocityX(dx); velocity.setVelocityY(dy); this->angle = angle; this->radius = radius; this->rotation = rotation; }
		Ship(Position pos, Velocity vel, double angle, double radius, double rotation) { this->position = pos; this->velocity = vel; this->angle = angle; this->radius = radius; this->rotation = rotation; }

		// getters
		double getX() const { return Object::getX(); }
		double getY() const { return Object::getY(); }
		double getVelocityX() const { return Object::getVelocityX(); }
		double getVelocityY() const { return Object::getVelocityY(); }
		double getAccelerationX() const { return velocity.getAccelerationX(); }
		double getAccelerationY() const { return velocity.getAccelerationY(); }
		double getAngle() const { return Object::getAngle(); }
		double getRadius() const { return Object::getRadius(); }
		double getRotation() const { return Object::getRotation(); }
		ObjectType getType() const { return SHIP; }
		bool getThrust() const { return thrust; }

		// setters
		void setX(double x) { Object::setX(x); }
		void setY(double y) { Object::setY(y); }
		void setVelocity(double dx, double dy) { Object::setVelocity(dx, dy); }
		void setVelocityX(double dx) { Object::setVelocityX(dx); }
		void setVelocityY(double dy) { Object::setVelocityY(dy); }
		void setAccelerationY(double ddy) { velocity.setAccelerationY(ddy); }
		void setAccelerationX(double ddx) { velocity.setAccelerationX(ddx); }
		void setAngle(double angle) { Object::setAngle(angle); }
		void setRadius(double radius) { Object::setRadius(radius); }
		void setRotation(double rotation) { Object::setRotation(rotation); }
		void setThrust(bool thrust) { this->thrust = thrust; }

		// other functions
		void draw(ogstream& gout) { Position& pos = position; gout.drawShip(pos, angle, thrust); }
		void advance();
		void fire();
		void rotateLeft();
		void rotateRight();
		void thrustOn();
		void thrustOff();

	private:
		Position position;
		Velocity velocity;
		double angle;
		double radius;
		double rotation;
		bool thrust = false;
		const ObjectType type = SHIP;

};

