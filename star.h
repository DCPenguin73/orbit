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
#include "Position.h"
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
	Star(double x, double y, char p) { this->position.setMetersX(x); this->position.setMetersY(y); this->setPhase(p); }

	Star() : position(( - 128000 * 40) + rand() % ((128000 * 40) - ( - 128000 * 40) + 1), (-128000 * 40) + rand() % ((128000 * 40) - ( - 128000 * 40) + 1)), phase('a' + rand()) {}

	// getters
	double getX() const { return position.getMetersX(); }
	double getY() const { return position.getMetersY(); }
	char getPhase() const { return phase; }
	
	// setters
	void setX(double x) { position.setMetersX(x); }
	void setY(double y) { position.setMetersY(y); }
	void setPhase(char p) {this->phase = p; }

	// other functions
	void draw(ogstream& gout) { gout.drawStar(position, phase); }

	void advance() { this->setPhase(this->phase + 1);}
	

private:
	Position position;
	char phase;

};