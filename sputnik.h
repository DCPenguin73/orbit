
#pragma once
#include "Object.h"
#include "Satellite.h"
class Satellite;
class Object;

/*********************************************
 * Sputnik
 * a object in the sky
 *********************************************/
class Sputnik : public Satellite
{
	public:
		// constructors
		Sputnik() : Satellite() {}
		Sputnik(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		Sputnik(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return SPUTNIK; }

		// other functions
		void draw(ogstream& gout) { gout.drawSputnik(this->getPosition(), this->getAngle()); }

	private:
		const ObjectType type = SPUTNIK;
};