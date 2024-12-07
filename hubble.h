
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
		/*std::list<Object*> collide() const
		{
			std::list<Object*> objects;
			Position pt = this->getPosition();
			pt.addPixelsX(((19) * sin(this->getAngle())));
			pt.addPixelsY(((19) * cos(this->getAngle())));
			Velocity vel;
			vel.setVelocityX(this->getVelocityX());
			vel.setVelocityY(this->getVelocityY());
			vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle())));
			vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle())));
			double angle = this->getAngle();
			HubbleTelescope* hubbleTelescope = new HubbleTelescope(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(hubbleTelescope);
			Position pt2 = this->getPosition();
			pt2.addPixelsX(((19) * sin(this->getAngle() + 180)));
			pt2.addPixelsY(((19) * cos(this->getAngle() + 180)));
			Velocity vel2;
			vel2.setVelocityX(this->getVelocityX());
			vel2.setVelocityY(this->getVelocityY());
			vel2.setVelocityX(vel2.getVelocityX() + ((2000) * sin(this->getAngle() + 180)));
			vel2.setVelocityY(vel2.getVelocityY() + ((2000) * cos(this->getAngle() + 180)));
			HubbleRight* hubbleRight = new HubbleRight(pt2.getMetersX(), pt2.getMetersY(), vel2.getVelocityX(), vel2.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(hubbleRight);
			Position pt3 = this->getPosition();
			pt3.addPixelsX(((19) * sin(this->getAngle() + 90)));
			pt3.addPixelsY(((19) * cos(this->getAngle() + 90)));
			Velocity vel3;
			vel3.setVelocityX(this->getVelocityX());
			vel3.setVelocityY(this->getVelocityY());
			vel3.setVelocityX(vel3.getVelocityX() + ((2000) * sin(this->getAngle() + 90)));
			vel3.setVelocityY(vel3.getVelocityY() + ((2000) * cos(this->getAngle() + 90)));
			HubbleLeft* hubbleLeft = new HubbleLeft(pt3.getMetersX(), pt3.getMetersY(), vel3.getVelocityX(), vel3.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(hubbleLeft);
			Position pt4 = this->getPosition();
			pt4.addPixelsX(((19) * sin(this->getAngle() + 270)));
			pt4.addPixelsY(((19) * cos(this->getAngle() + 270)));
			Velocity vel4;
			vel4.setVelocityX(this->getVelocityX());
			vel4.setVelocityY(this->getVelocityY());
			vel4.setVelocityX(vel4.getVelocityX() + ((2000) * sin(this->getAngle() + 270)));
			vel4.setVelocityY(vel4.getVelocityY() + ((2000) * cos(this->getAngle() + 270)));
			HubbleComputer* hubbleComputer = new HubbleComputer(pt4.getMetersX(), pt4.getMetersY(), vel4.getVelocityX(), vel4.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(hubbleComputer);
			return objects;
		}*/

	private:
		const ObjectType type = HUBBLE;
};