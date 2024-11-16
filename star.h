/****************************************************
 * Header File:
 *    Star : The representation of a star
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything we need to know about a star on the screen.
****************************************************/

#pragma once
#include <iostream>
#include <cmath>
#include "position.h"

class TestStar;
class Position;

/*********************************************
 * Star
 * A single star on the field in Meters
 *********************************************/
class Star
{
   friend TestStar;

public:
	// constructors
	Star() : position(-128000 + rand() % (128000 - -128000 + 1), -128000 + rand() % (128000 - -128000 + 1)), phase('a' + rand()) {}
	Star(double x, double y, char phase) { position.setMetersX(x); position.setMetersY(y); this->phase=phase; }
	Star(const Star& pt) : position(pt.position), phase(pt.phase) {}	

	// getters
	double getX() const { return position.getMetersX(); }
	double getY() const { return position.getMetersY(); }
	char getPhase() const { return phase; }
	
	// setters
	void setX(double x) { position.setMetersX(x); }
	void setY(double y) { position.setMetersY(y); }
	void setPhase(char phase) { this->phase = phase; }
	

private:
	Position position;
	char phase;

};




