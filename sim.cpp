/***********************************************************************
 * Source File:
 *    Sim : The foundation of everything on the screen
 * Author:
 *    Daniel Carr
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
#include <cassert>
#include "uiDraw.h"
#include <cmath>
#include "earth.h"
#include <random>

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
	Gps* gps = new Gps(0.0, 26560000.0, -3880.0, 0.0, 1.5, 10.0, (1.5 * earthRotation));
	StarLink* starLink = new StarLink(0.0, -13020000.0, 5800.0, 0.0, 0.75, 10.0, (4.5 * earthRotation));
	CrewDragon* crewDragon = new CrewDragon(0.0, 8000000.0, -7900.0, 0.0, 0.0, 10.0, (1 * earthRotation));
	Sputnik* sputnik = new Sputnik(-36515095.13, 21082000.0, 2050.0, 2684.68, 1.5, 10.0, (-0.5 * earthRotation));

	Earth* earth = new Earth(0.0,0.0,0.0,0.0,0.0,6378000.0,earthRotation);

	objects.push_back(gps);
	objects.push_back(starLink);
	objects.push_back(crewDragon);
	objects.push_back(sputnik);
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
	for (Star& star : stars)
	{
		star.setPhase(star.getPhase() + 1);
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
