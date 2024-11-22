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
#include <vector>
#include "uiInteract.h"

class TestSim;
class object;
class Star;

/*********************************************
 * Sim
 * A single object on the field in Meters
 *********************************************/
class Sim
{
	//friend TestSim;

public:
	// constructors
	Sim(Position ptUpperRight) { this->upperRight = ptUpperRight; }
	~Sim() {}

	// getters

	std::list<Object*> getObjects() const { return objects; }

	// setters
	void setObjects(std::list<Object*> object) { this->objects = object; }


	// other functions
	void reset();
	void draw(ogstream& gout);
	void advance();
	void handleKeys(const Interface* ui);

	std::list<Object*> objectColision();
	void colide(Object object1, Object object2);
	void addOdject(Object object);

private:
	std::list<Object*> objects;

	std::list<Star> stars;
	Position upperRight;
};