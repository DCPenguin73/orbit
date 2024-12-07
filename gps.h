

#pragma once
#include "Object.h"
#include "Satellite.h"
#include "GPSCenter.h"
#include "GPSLeft.h"
#include "GPSRight.h"
class Satellite;
class Object;

/*********************************************
 * Gps
 * a object in the sky
 *********************************************/
class Gps : public Satellite
{
	public:
		// constructors
		Gps() : Satellite() {}
		Gps(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); 
		this->setRadius(radius); this->setRotation(rotation); }
		Gps(Position pos, Velocity vel, double angle, double radius, double rotation) {
			this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation);
		}

		// getters
		ObjectType getType() const { return GPS; }

		// setters

		// other functions
		void draw(ogstream& gout) { gout.drawGPS(this->getPosition(), this->getAngle()); }

		std::list<Object*> collide()
		{
			std::list<Object*> objectList;

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((30) * sin(this->getAngle())));
				pt.addPixelsY(((30) * cos(this->getAngle())));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle())));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle())));

				GPSCenter* GPSCenter1 = new GPSCenter(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(GPSCenter1);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((30) * sin(this->getAngle() + 144)));
				pt.addPixelsY(((30) * cos(this->getAngle() + 144)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle() + 144)));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle() + 144)));

				GPSLeft* GPSLeft1 = new GPSLeft(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);

				objectList.push_back(GPSLeft1);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((30) * sin(this->getAngle() + 216)));
				pt.addPixelsY(((30) * cos(this->getAngle() + 216)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle() + 216)));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle() + 216)));

				GPSRight* GPSRight1 = new GPSRight(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);

				objectList.push_back(GPSRight1);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((30) * sin(this->getAngle() + 72)));
				pt.addPixelsY(((30) * cos(this->getAngle() + 72)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle() + 72)));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle() + 72)));

				Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 2.0, 0.0);
				objectList.push_back(fragment1);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((30) * sin(this->getAngle() + 288)));
				pt.addPixelsY(((30) * cos(this->getAngle() + 288)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((7000) * sin(this->getAngle() + 288)));
				vel.setVelocityY(vel.getVelocityY() + ((7000) * cos(this->getAngle() + 288)));

				Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 2.0, 0.0);
				objectList.push_back(fragment2);
			}
			return objectList;
		}

	private:
		const ObjectType type = GPS;
};

