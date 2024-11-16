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
#include "uiDraw.h"

class TestStar;
class Position;
class uiDraw;

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

	// getters
	double getX() const { return position.getMetersX(); }
	double getY() const { return position.getMetersY(); }
	char getPhase() const { return phase; }
	
	// setters
	void setX(double x) { position.setMetersX(x); }
	void setY(double y) { position.setMetersY(y); }
	void setPhase(char phase) { this->phase = phase; }

	// other functions
	void draw(ogstream& gout) { gout.drawStar(position, phase); }
	void advance() { phase++; }
	

private:
	Position position;
	char phase;

};




