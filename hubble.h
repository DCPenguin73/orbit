
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
		std::list<Object*> collide() const
		{
			std::list<Object*> objectList;
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle())));
				pt.addPixelsY(((19) * cos(this->getAngle())));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle())));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle())));
				HubbleTelescope* hubbleTelescope = new HubbleTelescope(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(hubbleTelescope);
			}
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 90)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 90)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle() + 90)));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle() + 90)));
				HubbleLeft* hubbleLeft = new HubbleLeft(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(hubbleLeft);
			}
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 180)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 180)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle() + 180)));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle() + 180)));
				HubbleRight* hubbleRight = new HubbleRight(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(hubbleRight);
			}
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 280)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 270)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle() + 270)));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle() + 270)));
				HubbleComputer* hubbleComputer = new HubbleComputer(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 6.0, 0.0);
				objectList.push_back(hubbleComputer);
			}
			return objectList;			
		}

	private:
		const ObjectType type = HUBBLE;
};