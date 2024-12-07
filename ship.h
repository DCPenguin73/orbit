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
#include "Fragment.h"

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
		Ship(double x, double y, double dx, double dy, double angle, double radius, double rotation) { this->setX(x); this->setY(y); this->setVelocityX(dx); this->setVelocityY(dy); this->setAngle(angle); 
		this->setRadius(radius); this->setRotation(rotation);}
		Ship(Position pos, Velocity vel, double angle, double radius, double rotation) { this->setPosition(pos); this->setVelocity(vel); this->setAngle(angle); this->setRadius(radius); 
		this->setRotation(rotation); }

		// getters
		ObjectType getType() const { return SHIP; }
		bool getThrust() const { return thrust; }

		// setters
		void setThrust(bool thrust) { this->thrust = thrust; }

		// other functions
		void draw(ogstream& gout) { gout.drawShip(this->getPosition(), this->getAngle(), this->getThrust()); }
		void advance();
		std::list<Object*> collide()
		{
			std::list<Object*> objects;
			Position pt = this->getPosition();
			pt.addPixelsX(((19) * sin(this->getAngle())));
			pt.addPixelsY(((19) * cos(this->getAngle())));
			Velocity vel;
			vel.setVelocityX(this->getVelocityX());
			vel.setVelocityY(this->getVelocityY());
			vel.setVelocityX(vel.getVelocityX() + ((4000) * sin(this->getAngle())));
			vel.setVelocityY(vel.getVelocityY() + ((4000) * cos(this->getAngle())));
			double angle = this->getAngle();
			Fragment* fragment = new Fragment(pt.getMetersX(), pt.getMetersY(), vel.getVelocityX(), vel.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment);
			Position pt2 = this->getPosition();
			pt2.addPixelsX(((19) * sin(this->getAngle() + 30)));
			pt2.addPixelsY(((19) * cos(this->getAngle() + 30)));
			Velocity vel2;
			vel2.setVelocityX(this->getVelocityX());
			vel2.setVelocityY(this->getVelocityY());
			vel2.setVelocityX(vel2.getVelocityX() + ((4000) * sin(this->getAngle() + 30)));
			vel2.setVelocityY(vel2.getVelocityY() + ((4000) * cos(this->getAngle() + 30)));
			Fragment* fragment2 = new Fragment(pt2.getMetersX(), pt2.getMetersY(), vel2.getVelocityX(), vel2.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment2);
			Position pt3 = this->getPosition();
			pt3.addPixelsX(((19) * sin(this->getAngle() + 60)));
			pt3.addPixelsY(((19) * cos(this->getAngle() + 60)));
			Velocity vel3;
			vel3.setVelocityX(this->getVelocityX());
			vel3.setVelocityY(this->getVelocityY());
			vel3.setVelocityX(vel3.getVelocityX() + ((4000) * sin(this->getAngle() + 60)));
			vel3.setVelocityY(vel3.getVelocityY() + ((4000) * cos(this->getAngle() + 60)));
			Fragment* fragment3 = new Fragment(pt3.getMetersX(), pt3.getMetersY(), vel3.getVelocityX(), vel3.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment3);
			Position pt4 = this->getPosition();
			pt4.addPixelsX(((19) * sin(this->getAngle() + 90)));
			pt4.addPixelsY(((19) * cos(this->getAngle() + 90)));
			Velocity vel4;
			vel4.setVelocityX(this->getVelocityX());
			vel4.setVelocityY(this->getVelocityY());
			vel4.setVelocityX(vel4.getVelocityX() + ((4000) * sin(this->getAngle() + 90)));
			vel4.setVelocityY(vel4.getVelocityY() + ((4000) * cos(this->getAngle() + 90)));
			Fragment* fragment4 = new Fragment(pt4.getMetersX(), pt4.getMetersY(), vel4.getVelocityX(), vel4.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment4);
			Position pt5 = this->getPosition();
			pt5.addPixelsX(((19) * sin(this->getAngle() + 120)));
			pt5.addPixelsY(((19) * cos(this->getAngle() + 120)));
			Velocity vel5;
			vel5.setVelocityX(this->getVelocityX());
			vel5.setVelocityY(this->getVelocityY());
			vel5.setVelocityX(vel5.getVelocityX() + ((4000) * sin(this->getAngle() + 120)));
			vel5.setVelocityY(vel5.getVelocityY() + ((4000) * cos(this->getAngle() + 120)));
			Fragment* fragment5 = new Fragment(pt5.getMetersX(), pt5.getMetersY(), vel5.getVelocityX(), vel5.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment5);
			Position pt6 = this->getPosition();
			pt6.addPixelsX(((19) * sin(this->getAngle() + 150)));
			pt6.addPixelsY(((19) * cos(this->getAngle() + 150)));
			Velocity vel6;
			vel6.setVelocityX(this->getVelocityX());
			vel6.setVelocityY(this->getVelocityY());
			vel6.setVelocityX(vel6.getVelocityX() + ((4000) * sin(this->getAngle() + 150)));
			vel6.setVelocityY(vel6.getVelocityY() + ((4000) * cos(this->getAngle() + 150)));
			Fragment* fragment6 = new Fragment(pt6.getMetersX(), pt6.getMetersY(), vel6.getVelocityX(), vel6.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment6);
			Position pt7 = this->getPosition();
			pt7.addPixelsX(((19) * sin(this->getAngle() + 180)));
			pt7.addPixelsY(((19) * cos(this->getAngle() + 180)));
			Velocity vel7;
			vel7.setVelocityX(this->getVelocityX());
			vel7.setVelocityY(this->getVelocityY());
			vel7.setVelocityX(vel7.getVelocityX() + ((4000) * sin(this->getAngle() + 180)));
			vel7.setVelocityY(vel7.getVelocityY() + ((4000) * cos(this->getAngle() + 180)));
			Fragment* fragment7 = new Fragment(pt7.getMetersX(), pt7.getMetersY(), vel7.getVelocityX(), vel7.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment7);
			Position pt8 = this->getPosition();
			pt8.addPixelsX(((19) * sin(this->getAngle() + 210)));
			pt8.addPixelsY(((19) * cos(this->getAngle() + 210)));
			Velocity vel8;
			vel8.setVelocityX(this->getVelocityX());
			vel8.setVelocityY(this->getVelocityY());
			vel8.setVelocityX(vel8.getVelocityX() + ((4000) * sin(this->getAngle() + 210)));
			vel8.setVelocityY(vel8.getVelocityY() + ((4000) * cos(this->getAngle() + 210)));
			Fragment* fragment8 = new Fragment(pt8.getMetersX(), pt8.getMetersY(), vel8.getVelocityX(), vel8.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment8);
			Position pt9 = this->getPosition();
			pt9.addPixelsX(((19) * sin(this->getAngle() + 240)));
			pt9.addPixelsY(((19) * cos(this->getAngle() + 240)));
			Velocity vel9;
			vel9.setVelocityX(this->getVelocityX());
			vel9.setVelocityY(this->getVelocityY());
			vel9.setVelocityX(vel9.getVelocityX() + ((4000) * sin(this->getAngle() + 240)));
			vel9.setVelocityY(vel9.getVelocityY() + ((4000) * cos(this->getAngle() + 240)));
			Fragment* fragment9 = new Fragment(pt9.getMetersX(), pt9.getMetersY(), vel9.getVelocityX(), vel9.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment9);
			Position pt10 = this->getPosition();
			pt10.addPixelsX(((19) * sin(this->getAngle() + 270)));
			pt10.addPixelsY(((19) * cos(this->getAngle() + 270)));
			Velocity vel10;
			vel10.setVelocityX(this->getVelocityX());
			vel10.setVelocityY(this->getVelocityY());
			vel10.setVelocityX(vel10.getVelocityX() + ((4000) * sin(this->getAngle() + 270)));
			vel10.setVelocityY(vel10.getVelocityY() + ((4000) * cos(this->getAngle() + 270)));
			Fragment* fragment10 = new Fragment(pt10.getMetersX(), pt10.getMetersY(), vel10.getVelocityX(), vel10.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment10);
			Position pt11 = this->getPosition();
			pt11.addPixelsX(((19)* sin(this->getAngle() + 300)));
			pt11.addPixelsY(((19)* cos(this->getAngle() + 300)));
			Velocity vel11;
			vel11.setVelocityX(this->getVelocityX());
			vel11.setVelocityY(this->getVelocityY());
			vel11.setVelocityX(vel11.getVelocityX() + ((4000) * sin(this->getAngle() + 300)));
			vel11.setVelocityY(vel11.getVelocityY() + ((4000) * cos(this->getAngle() + 300)));
			Fragment* fragment11 = new Fragment(pt11.getMetersX(), pt11.getMetersY(), vel11.getVelocityX(), vel11.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment11);
			Position pt12 = this->getPosition();
			pt12.addPixelsX(((19)* sin(this->getAngle() + 330)));
			pt12.addPixelsY(((19)* cos(this->getAngle() + 330)));
			Velocity vel12;
			vel12.setVelocityX(this->getVelocityX());
			vel12.setVelocityY(this->getVelocityY());
			vel12.setVelocityX(vel12.getVelocityX() + ((4000) * sin(this->getAngle() + 330)));
			vel12.setVelocityY(vel12.getVelocityY() + ((4000) * cos(this->getAngle() + 330)));
			Fragment* fragment12 = new Fragment(pt12.getMetersX(), pt12.getMetersY(), vel12.getVelocityX(), vel12.getVelocityY(), angle, 1.0, 0.0);
			objects.push_back(fragment12);
			return objects;
		}

	private:
		bool thrust = false;
		const ObjectType type = SHIP;

};

