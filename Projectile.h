/****************************************************
 * Header File:
 *    Projectile : The representation of the projectile
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about the projectiles on the screen.
****************************************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Position.h"
#include "uiDraw.h"
#include "Object.h"
#include "ObjectType.h"

class TestProjectile;
class Position;
class Velocity;
class uiDraw;

/*********************************************
 * Projectile
 * A single projectile on the field in Meters
 *********************************************/
class Projectile : public Object
{
	friend TestProjectile;

	public:
		// constructors
		Projectile() : Object(), age(0) {}
		Projectile(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		Projectile(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return PROJECTILE; }
		int getAge() const { return age; }

		// setters
		void setAge(int age) { this->age = age; }

		// other functions
		void draw(ogstream& gout) { gout.drawProjectile(this->getPosition()); }

	private:
		const ObjectType type = PROJECTILE;
		int age = 0;
};
