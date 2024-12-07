
#pragma once
#include "Object.h"
#include "Satellite.h"
#include"CrewDragonCenter.h"
#include "CrewDragonLeft.h"
#include "CrewDragonRight.h"
#include <list>
class Satellite;
class Object;


/*********************************************
 * CrewDragon
 * a object in the sky
 *********************************************/
class CrewDragon : public Satellite
{
	public:
		// constructors
		CrewDragon() : Satellite() {}
		CrewDragon(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); 
		this->setAngle(angle); this->setRadius(radius); this->setRotation(rotation); }
		CrewDragon(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return CREWDRAGON; }

		// setters

		// other functions
		void draw(ogstream& gout) { gout.drawCrewDragon(this->getPosition(), this->getAngle()); }
		std::list<Object*> collide()
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

				CrewDragonCenter* crewDragonCenter = new CrewDragonCenter(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);
				objectList.push_back(crewDragonCenter);
			}
			
			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 144)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 144)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle() + 144)));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle() + 144)));

				CrewDragonLeft* crewDragonLeft = new CrewDragonLeft(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);

				objectList.push_back(crewDragonLeft);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 216)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 216)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((2000) * sin(this->getAngle() + 216)));
				vel.setVelocityY(vel.getVelocityY() + ((2000) * cos(this->getAngle() + 216)));

				CrewDragonRight* crewDragonRight = new CrewDragonRight(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);

				objectList.push_back(crewDragonRight);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 72)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 72)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 72)));
				vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 72)));

				Fragment* fragment1 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);
				objectList.push_back(fragment1);
			}

			{
				Position pt = this->getPosition();
				pt.addPixelsX(((19) * sin(this->getAngle() + 288)));
				pt.addPixelsY(((19) * cos(this->getAngle() + 288)));
				Velocity vel;
				vel.setVelocityX(this->getVelocityX());
				vel.setVelocityY(this->getVelocityY());
				vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle() + 288)));
				vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle() + 288)));

				Fragment* fragment2 = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), this->getAngle(), 1.0, 0.0);
				objectList.push_back(fragment2);
			}
			return objectList;
		}

	private:
		const ObjectType type = CREWDRAGON;
};