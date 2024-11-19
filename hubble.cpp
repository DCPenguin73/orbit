#define _USE_MATH_DEFINES
#include <iostream>
#include "hubble.h"
#include <cmath>



void Hubble::advance()
{
	const double timeDilation = 24.0 * 60.0;
	const double timePerFrame = 48.0; // timeDilation / 30; // =48
	const double secondsDay = 86400.0;
	const double frameRate = 30.0;
	double earthRotation = (-((2 * M_PI) / frameRate) * (timeDilation / secondsDay));
	const double earthRadius = 6378000.0;
	double x0 = position.getMetersX();
	double y0 = position.getMetersY();
	const double height = (std::sqrt((x0 * x0) + (y0 * y0))) - earthRadius; //35786000.000000000;
	//assert (35785000 < height && height < 35787000);
	const double gravSea = 9.80665;
	double gravity = gravSea * ((earthRadius / (earthRadius + height)) * (earthRadius / (earthRadius + height)));


	double dirGravPull = (std::atan2((0 - y0), (0 - x0)));


	double ddx = ((gravity)*std::cos(dirGravPull));
	double ddy = ((gravity)*std::sin(dirGravPull));
	ddx = ddx;
	ddy = ddy;
	velocity.setAccelerationX(ddx);
	velocity.setAccelerationY(ddy);
	double dx0 = velocity.getVelocityX();
	double dy0 = velocity.getVelocityY();
	double dx = dx0 + (ddx * timePerFrame);
	double dy = dy0 + (ddy * timePerFrame);
	double vel = std::sqrt((dx * dx) + (dy * dy));
	velocity.setVelocityX(dx);
	velocity.setVelocityY(dy);

	double x = x0 + (dx * timePerFrame) + (0.5 * ddx * (timePerFrame * timePerFrame));
	double y = y0 + (dy * timePerFrame) + (0.5 * ddy * (timePerFrame * timePerFrame));
	position.setMetersX(x);
	position.setMetersY(y);
	angle += rotation;
}