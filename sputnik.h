
#pragma once
#include "Object.h"
#include "Satellite.h"
#include "Fragment.h"
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
		Sputnik(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		Sputnik(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return SPUTNIK; }

		// other functions
		void draw(ogstream& gout) { gout.drawSputnik(this->getPosition(), this->getAngle()); }
		std::list<Object*> collide()
		{
			std::list<Object*> objects;
			Position pt = this->getPosition();
			pt.addPixelsX(((19) * sin(this->getAngle())));
			pt.addPixelsY(((19) * cos(this->getAngle())));
			Velocity vel;
			vel.setVelocityX(this->getVelocityX());
			vel.setVelocityY(this->getVelocityY());
			vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle())));
			vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle())));
			double angle = this->getAngle();
			Fragment* fragment = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), angle, 2.0, 0.0);
			objects.push_back(fragment);
			Position pt2 = this->getPosition();
			pt2.addPixelsX(((19) * sin(this->getAngle() + 180)));
			pt2.addPixelsY(((19) * cos(this->getAngle() + 180)));
			Velocity vel2;
			vel2.setVelocityX(this->getVelocityX());
			vel2.setVelocityY(this->getVelocityY());
			vel2.setVelocityX(vel2.getVelocityX() + ((7000) * sin(this->getAngle() + 180)));
			vel2.setVelocityY(vel2.getVelocityY() + ((7000) * cos(this->getAngle() + 180)));
			Fragment* fragment2 = new Fragment(pt2.getMetersX(), pt2.getMetersY(), vel2.getVelocityX(), vel2.getVelocityY(), angle, 2.0, 0.0);
			objects.push_back(fragment2);
			Position pt3 = this->getPosition();
			pt3.addPixelsX(((19) * sin(this->getAngle() + 90)));
			pt3.addPixelsY(((19) * cos(this->getAngle() + 90)));
			Velocity vel3;
			vel3.setVelocityX(this->getVelocityX());
			vel3.setVelocityY(this->getVelocityY());
			vel3.setVelocityX(vel3.getVelocityX() + ((7000) * sin(this->getAngle() + 90)));
			vel3.setVelocityY(vel3.getVelocityY() + ((7000) * cos(this->getAngle() + 90)));
			Fragment* fragment3 = new Fragment(pt3.getMetersX(), pt3.getMetersY(), vel3.getVelocityX(), vel3.getVelocityY(), angle, 2.0, 0.0);
			objects.push_back(fragment3);
			Position pt4 = this->getPosition();
			pt4.addPixelsX(((19) * sin(this->getAngle() + 270)));
			pt4.addPixelsY(((19) * cos(this->getAngle() + 270)));
			Velocity vel4;
			vel4.setVelocityX(this->getVelocityX());
			vel4.setVelocityY(this->getVelocityY());
			vel4.setVelocityX(vel4.getVelocityX() + ((7000) * sin(this->getAngle() + 270)));
			vel4.setVelocityY(vel4.getVelocityY() + ((7000) * cos(this->getAngle() + 270)));
			Fragment* fragment4 = new Fragment(pt4.getMetersX(), pt4.getMetersY(), vel4.getVelocityX(), vel4.getVelocityY(), angle, 2.0, 0.0);
			objects.push_back(fragment4);
			return objects;
		}

	private:
		const ObjectType type = SPUTNIK;
};