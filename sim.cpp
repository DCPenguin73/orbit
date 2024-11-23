/***********************************************************************
 * Source File:
 *    Sim : The foundation of everything on the screen
 * Author:
 *    Daniel Carr & Arlo Jolley & Bryce Chesley
 * Summary:
 *    Keeps track of everything on the screen.
 ************************************************************************/
#define _USE_MATH_DEFINES
#pragma once
#include "sim.h"
#include "object.h"
#include "star.h"
#include <list>
#include <iostream>
#include "gps.h"
#include "starLink.h"
#include "crewDragon.h"
#include "sputnik.h"
#include "hubble.h"
#include <cassert>
#include "uiDraw.h"
#include <cmath>
#include "earth.h"
#include <random>
#include "ship.h"

class Object;
 /******************************************
  * SIM : RESETs
  * Reset the simulation
  *****************************************/
void Sim::reset()
{
	objects.clear();
	const double timeDilation = 24.0 * 60.0;
	const double timePerFrame = 48.0; // timeDilation / 30; // =48
	const double secondsDay = 86400.0;
	const double frameRate = 30.0;
	double earthRotation = (-((2 * M_PI) / frameRate) * (timeDilation / secondsDay));
	Gps* gps1 = new Gps(0.0, 26560000.0, -3880.0, 0.0, 1.5, 12.0, (2.0 * earthRotation));
	Gps* gps2 = new Gps(23001634.72, 13280000.0, -1940.00, 3360.18, 2.6, 12.0, (2.0 * earthRotation));
	Gps* gps3 = new Gps(23001634.72, -13280000.0, 1940.00, 3360.18, -2.6, 12.0, (2.0 * earthRotation));
	Gps* gps4 = new Gps(0.0, -26560000.0, 3880.0, 0.0, -1.5, 12.0, (2.0 * earthRotation));
	Gps* gps5 = new Gps(-23001634.72, -13280000.0, 1940.00, -3360.1, -0.5, 12.0, (2.0 * earthRotation));
	Gps* gps6 = new Gps(-23001634.72, 13280000.0, -1940.00, -3360.1, 0.5, 12.0, (2.0 * earthRotation));
	StarLink* starLink = new StarLink(0.0, -13020000.0, 5800.0, 0.0, 0.75, 6.0, (4.7 * earthRotation));
	CrewDragon* crewDragon = new CrewDragon(0.0, 8000000.0, -7900.0, 0.0, 0.0, 7.0, (3 * earthRotation));
	Sputnik* sputnik = new Sputnik(-36515095.13, 21082000.0, 2050.0, 2684.68, 1.5, 4.0, (-0.5 * earthRotation));
	Hubble* hubble = new Hubble(0.0, -42164000.0, 3100.0, 0.0, 1.5, 10.0, (-0.5 * earthRotation));

	Ship* ship = new Ship(-60000000.0, 60000000.0, 0.0, -2000.0, 0.0, 10.0, 0.0);  // corect position
	//Ship* ship = new Ship(0.0, 30000000.0, 0.0, 0.0, 0.0, 10.0, 0.0);

	Earth* earth = new Earth(0.0,0.0,0.0,0.0,0.0,6378000.0,earthRotation);

	objects.push_back(ship);
	objects.push_back(gps1);
	objects.push_back(gps2);
	objects.push_back(gps3);
	objects.push_back(gps4);
	objects.push_back(gps5);
	objects.push_back(gps6);
	objects.push_back(starLink);
	objects.push_back(crewDragon);
	objects.push_back(sputnik);
	objects.push_back(hubble);
	objects.push_back(earth);

	const int minRange = -1280000 * 50;
	const int maxRange = 1280000 * 50;

	for (int i = 0; i < 400; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(minRange, maxRange);
		int randomNumberX = dist(gen);
		int randomNumberY = dist(gen);
		int randomPhase = (dist(gen)) % 256;
		char p = char(randomPhase);

		Star star(randomNumberX,randomNumberY,p);
		this->stars.push_back(star);
	}

}

/******************************************
 * SIM : DRAW
 * Draw everything on the screen
 *****************************************/
void Sim::draw(ogstream& gout)
{
	for (Star star : stars)
	{
		star.draw(gout);
	}
	for (Object* obj : objects) {

		obj->draw(gout);
	}

}

/******************************************
 * SIM : ADVANCE
 * Advance everything on the screen
 *****************************************/
void Sim::advance()
{
	for (Object* obj : objects) {

		obj->advance();
	}
	/*for (Object* obj : objects) {

		obj->advance();
	}*/
	for (Star& star : stars)
	{
		star.setPhase(star.getPhase() + 1);
	}
}

/******************************************
 * SIM : HANDLEKEYS
 * Handle the keys
 *****************************************/
void Sim::handleKeys(const Interface* ui)
{
	for (Object* obj : objects)
	{
		if (obj->getType() == SHIP)
		{
			Ship* ship = dynamic_cast<Ship*>(obj);
			if (ui->isDown())
			{
				ship->setThrust(true);
			}
			else
			{
				ship->setThrust(false);
			}
			if (ui->isLeft())
			{
				ship->setRotation(ship->getRotation() - 0.01);
			}
			if (ui->isRight())
			{
				ship->setRotation(ship->getRotation() + 0.01);
			}
			if (ui->isSpace())
			{
				ship->fire();
			}

		}
	}
}

/******************************************
 * SIM : OBJECTCOLISION
 * Check for object colision
 *****************************************/
//std::list<Object> sim::objectColision()
//{
//	std::list<Object> colision;
//	for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
//	{
//		for (std::list<Object>::iterator it2 = object.begin(); it2 != object.end(); ++it2)
//		{
//			if (it != it2)
//			{
//				if (sqrt(pow(it->getX() - it2->getX(), 2) + pow(it->getY() - it2->getY(), 2)) < it->getRadius() + it2->getRadius())
//				{
//					colision.push_back(*it);
//					colision.push_back(*it2);
//				}
//			}
//		}
//	}
//	return colision;
//}

/******************************************
 * SIM : COLIDE
 * Colide two objects
 *****************************************/
//void sim::colide(Object object1, Object object2)
//{
//	
//}
