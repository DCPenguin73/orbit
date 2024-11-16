/***************************************************
 * Header File:
 *    Sim : The representation of everything on the screen
 * Author:
 *    Daniel Carr & Bryce Chesley
 * Summary:
 *    Everything we need to know about everything on the screen.
***************************************************/
#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include "object.h"
#include "star.h"

//class TestSim;
class Object;
class Star;

/*********************************************
 * Sim
 * A single object on the field in Meters
 *********************************************/
class sim
{
	//friend TestSim;

public:
	// constructors
	sim() {}
	~sim() {}

	// getters
	//std::list<Object> getObject() const { return object; }

	// setters
	//void setObject(std::list<Object> object) { this->object = object; }

	// other functions
	void reset();
	void draw();
	void advance();
	//std::list<Object> objectColision();
	//void colide(Object object1, Object object2);
	//void addOdject(Object object);

private:
	//std::list<Object> object;
	Star stars[400];
};

