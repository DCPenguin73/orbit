/***********************************************************************
 * Source File:
 *    Sim : The foundation of everything on the screen
 * Author:
 *    Daniel Carr
 * Summary:
 *    Keeps track of everything on the screen.
 ************************************************************************/
#pragma once
#include "sim.h"
#include <cassert>

 /******************************************
  * SIM : RESET
  * Reset the simulation
  *****************************************/
void sim::reset()
{
	object.clear();
}

/******************************************
 * SIM : DRAW
 * Draw everything on the screen
 *****************************************/
void sim::draw()
{
	for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
	{
		it->draw();
	}
}

/******************************************
 * SIM : ADVANCE
 * Advance everything on the screen
 *****************************************/
void sim::advance()
{
	for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
	{
		it->advance();
	}
}

/******************************************
 * SIM : OBJECTCOLISION
 * Check for object colision
 *****************************************/
std::list<Object> sim::objectColision()
{
	std::list<Object> colision;
	for (std::list<Object>::iterator it = object.begin(); it != object.end(); ++it)
	{
		for (std::list<Object>::iterator it2 = object.begin(); it2 != object.end(); ++it2)
		{
			if (it != it2)
			{
				if (sqrt(pow(it->getX() - it2->getX(), 2) + pow(it->getY() - it2->getY(), 2)) < it->getRadius() + it2->getRadius())
				{
					colision.push_back(*it);
					colision.push_back(*it2);
				}
			}
		}
	}
	return colision;
}

/******************************************
 * SIM : COLIDE
 * Colide two objects
 *****************************************/
void sim::colide(Object object1, Object object2)
{
	
}
