/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#define _USE_MATH_DEFINES
using namespace std;

const double PI = 3.14159265358979323846;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setMeters(0.0, -42164000.0);
      ptHubble.setVelocity(3100.0, 0.0);

      ptSputnik.setMeters(-36515095.13 ,21082000.0 );
      ptSputnik.setVelocity(2050.0, 2684.68);

      ptStarlink.setMeters(0.0, -13020000.0);
      ptStarlink.setVelocity(5800.0, 0.0);

      ptCrewDragon.setMeters(0.0, 8000000.0);
      ptCrewDragon.setVelocity(-7900.0, 0.0);

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      ptGPS.setMeters(0.0, 26560000.0);
	  ptGPS.setVelocity(-3880.0, 0.0);
	  ptGPS1.setMeters(23001634.72, 13280000.0);
	  ptGPS1.setVelocity(-1940.00, 3360.18);
	  ptGPS2.setMeters(23001634.72, -13280000.0);
	  ptGPS2.setVelocity(1940.00, 3360.18);
	  ptGPS3.setMeters(-23001634.72, 13280000.0);
	  ptGPS3.setVelocity(-1940.00, -3360.18);
	  ptGPS4.setMeters(-23001634.72, -13280000.0);
	  ptGPS4.setVelocity(1940.00, -3360.18);
	  ptGPS5.setMeters(0.0, -26560000.0);
	  ptGPS5.setVelocity(3880.0, 0.0);


      for (int i = 0; i < 400; i++)
      {
		  ptStars[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));  
		  ptStars[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
		 

      }
      //ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 1.5;
      angleEarth = 0.0;
	  phaseStar = 0;
	  phaseStar2 = 120;
	  phaseStar3 = 40;
	  phaseStar4 = 160;
	  phaseStar5 = 80;
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS1;
   Position ptGPS2;
   Position ptGPS3;
   Position ptGPS4;
   Position ptGPS5;
   Position ptGPS;
   Position ptUpperRight;
   Position ptStars[400];

   unsigned char phaseStar;
   unsigned char phaseStar2;
   unsigned char phaseStar3;
   unsigned char phaseStar4;
   unsigned char phaseStar5;

   double angleShip;
   double angleEarth;

   int count = 0;
   char phase = 'a' + rand();
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // equations of motion
   const double timeDilation = 24.0 * 60.0;
   const double timePerFrame = 48.0; // timeDilation / 30; // =48
   const double secondsDay = 86400.0;
   const double frameRate = 30.0;
   double earthRotation = (-((2 * PI) / frameRate) * (timeDilation / secondsDay));
   const double earthRadius = 6378000.0;
   double x0 = pDemo->ptGPS.getMetersX();
   double y0 = pDemo->ptGPS.getMetersY();
   const double height = (std::sqrt((x0 * x0) + (y0 * y0))) - earthRadius; //35786000.000000000;
   //assert (35785000 < height && height < 35787000);
   const double gravSea =  9.80665;
   double gravity = gravSea * ((earthRadius / (earthRadius + height)) * (earthRadius / (earthRadius + height)));
   //double ddx0 = pDemo->ptGPS.getAccelerationX();
   //double ddy0 = pDemo->ptGPS.getAccelerationY();
   double dirGravPull = (std::atan2((0 - y0), (0 - x0)));
   //cout << fixed << std::setprecision(15) << endl;
   //cout << "dirGravPull: " << dirGravPull << endl;
   double ddx = ((gravity ) * std::cos(dirGravPull));
   double ddy = ((gravity ) * std::sin(dirGravPull));
   ddx = ddx ;
   ddy = ddy ;
   pDemo->ptGPS.setAccelerationX(ddx);
   pDemo->ptGPS.setAccelerationY(ddy);
   double dx0 = pDemo->ptGPS.getVelocityX();
   double dy0 = pDemo->ptGPS.getVelocityY();
   double dx = dx0 + (ddx * timePerFrame);
   double dy = dy0 + (ddy * timePerFrame);
   double velocity = std::sqrt((dx * dx) + (dy * dy)); // updated velocity should == -3100
   //assert(velocity == -3100);
   pDemo->ptGPS.setVelocityX(dx);
   pDemo->ptGPS.setVelocityY(dy);

   double x = x0 + (dx * timePerFrame) + (0.5 * ddx * (timePerFrame * timePerFrame));
   double y = y0 + (dy * timePerFrame) + (0.5 * ddy * (timePerFrame * timePerFrame));
   pDemo->ptGPS.setMetersX(x);
   pDemo->ptGPS.setMetersY(y);

   //double id = 0; // initial distance
  
   //double distance = id + (velocity * timePerFrame) + (0.5 * accel * (timePerFrame * timePerFrame));
   //double velAccel = velocity + (accel * timePerFrame);
   //double horizVelAccel = velocityX + (horizAccel * timePerFrame);
   //double vertVelAccel = velocityY + (vertAccel * timePerFrame);
   
   /*double inerta = id + velocity * timePerFrame;
   velocityX = horizVelAccel;
   velocityY = vertVelAccel;
   */


   // rotate the earth, ship, and stars
   pDemo->angleEarth += earthRotation; 
   pDemo->angleShip += (1.5 * earthRotation);
   pDemo->phase = pDemo->phase + 1;
   pDemo->phaseStar++;
   pDemo->phaseStar2++;
   pDemo->phaseStar3++;
   pDemo->phaseStar4++;
   pDemo->phaseStar5++;
   

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   gout.drawGPS(pDemo->ptGPS1, pDemo->angleShip);
   gout.drawGPS(pDemo->ptGPS2, pDemo->angleShip);
   gout.drawGPS(pDemo->ptGPS3, pDemo->angleShip);
   gout.drawGPS(pDemo->ptGPS4, pDemo->angleShip);
   gout.drawGPS(pDemo->ptGPS5, pDemo->angleShip);

   // draw parts
   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);

   // draw stars
   for (int i = 0; i < 400; i++)
   {
       gout.drawStar(pDemo->ptStars[i], (i * pDemo->phase));
   
       /*if (i % 5 == 0)
       {
           gout.drawStar(pDemo->ptStars[i], pDemo->phaseStar5);
       }
       else if (i % 5 == 1)
       {
		   gout.drawStar(pDemo->ptStars[i], pDemo->phaseStar4);
	   }
	   else if (i % 5 == 2)
	   {
		   gout.drawStar(pDemo->ptStars[i], pDemo->phaseStar3);
	   }
	   else if (i % 5 == 3)
	   {
		   gout.drawStar(pDemo->ptStars[i], pDemo->phaseStar2);
	   }
	   else
	   {
		   gout.drawStar(pDemo->ptStars[i], pDemo->phaseStar);
	   }*/
       
   }
   ;

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);
   

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
