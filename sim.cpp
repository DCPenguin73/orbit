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
#include <cassert>
#include "uiDraw.h"
#include <cmath>

 /******************************************
  * SIM : RESETs
  * Reset the simulation
  *****************************************/
void sim::reset()
{
	objects.clear();
	const double timeDilation = 24.0 * 60.0;
	const double timePerFrame = 48.0; // timeDilation / 30; // =48
	const double secondsDay = 86400.0;
	const double frameRate = 30.0;
	double earthRotation = (-((2 * M_PI) / frameRate) * (timeDilation / secondsDay));
	Gps gps(0.0, 2656000.0, -3880.0, 0.0, 1.5, 10.0, (1.5 * earthRotation));
}

/******************************************
 * SIM : DRAW
 * Draw everything on the screen
 *****************************************/
void sim::draw()
{
	/*for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
	{
		it->draw();
	}*/
}

/******************************************
 * SIM : ADVANCE
 * Advance everything on the screen
 *****************************************/
void sim::advance()
{
	/*for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
	{
		it->advance();
	}*/
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
