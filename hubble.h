
#pragma once
#include "Object.h"
#include "Satellite.h"
#include "HubbleTelescope.h"
#include "HubbleLeft.h"
#include "HubbleRight.h"
#include "HubbleComputer.h"
class Satellite;
class Object;

/*********************************************
 * Hubble
 * a object in the sky
 *********************************************/
class Hubble : public Satellite
{
	public:
		// constructors
		Hubble() : Satellite() {}
		Hubble(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		Hubble(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return HUBBLE; }

		// setters

		// other functions
		void draw(ogstream& gout) { gout.drawHubble(this->getPosition(), this->getAngle()); }

		std::list<Object*> collide()
		{
			std::list<Object*> objectList;

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((10) * sin(this->getAngle())));
				pt.addPixelsY(((10) * cos(this->getAngle())));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle())));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle())));

				HubbleTelescope* hTelescope = new HubbleTelescope(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(hTelescope);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((10) * sin(this->getAngle() + 144)));
				pt.addPixelsY(((10) * cos(this->getAngle() + 144)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle() + 144)));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle() + 144)));

				HubbleComputer* hComputer = new HubbleComputer(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);

				objectList.push_back(hComputer);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((10) * sin(this->getAngle() + 216)));
				pt.addPixelsY(((10) * cos(this->getAngle() + 216)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle() + 216)));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle() + 216)));

				HubbleRight* hRight = new HubbleRight(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);

				objectList.push_back(hRight);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((6) * sin(this->getAngle() + 72)));
				pt.addPixelsY(((6) * cos(this->getAngle() + 72)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((5000) * sin(this->getAngle() + 72)));
				vel.setVelocityY(vel.getVelocityY() + ((5000) * cos(this->getAngle() + 72)));

				HubbleLeft* hLeft = new HubbleLeft(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 2.0, 0.0);
				objectList.push_back(hLeft);
			}
			return objectList;
		}


	private:
		const ObjectType type = HUBBLE;
};