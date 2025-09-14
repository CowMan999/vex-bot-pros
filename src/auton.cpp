#include "auton.h"

float xPos = 0;
float yPos = 0;
float orientationStart = 0;

const int RPM = 600;

const float ROBOTDIA = 10.5;//12.5;
const float WHEELDIA = 3.25;
const float GEARRATIO = 0.75;
const int PIDTHRESHMIN = 150;
const int PIDTHRESHMAX = 600;
const float PIDMULT = 0.32;

bool motorOverideAuton = false;

//       ^ 0      
// 90 <   > 270   (144, 144)
//       v 180      |
//                  v
//   |---------------|
//   |    x     x    |
//   |               |
//   |    x     x    |
//   |       x       |
//   |---------------|
//    ^
//    |
// (0,0)


void moveAuto(bool forw, float distance, float speed, float decelMult) {
	float deg = 360.f*(distance/((GEARRATIO)*(WHEELDIA*M_PI)));

	bool targetPositive = true;

	if(!forw) {
		targetPositive = false;
		deg = -deg;
	}
	
	float target = (leftMotors.get_position()+rightMotors.get_position())/2.f + deg;
	float speedMult = (speed/100.f);

	int dist = targetPositive ? 999 : -999;

	//int count = 100*5;
	while((targetPositive && (dist > 5)) || (!targetPositive && (dist < -5))) {
		dist = target - (leftMotors.get_position()+rightMotors.get_position())/2.f;
		float distS = std::abs(dist*(PIDMULT)*(1.f/speedMult));
		distS *= 1.f/decelMult;
		if(distS > PIDTHRESHMAX) {
			distS = PIDTHRESHMAX;
		} else if(distS < PIDTHRESHMIN) {
			distS = PIDTHRESHMIN;
		}

		if(targetPositive) {
			leftMotors.move_velocity(distS*speedMult);
			rightMotors.move_velocity(distS*speedMult);
		} else {
			leftMotors.move_velocity(-distS*speedMult);
			rightMotors.move_velocity(-distS*speedMult);
		}
		
		if(motorOverideAuton) {
			motorOverideAuton = false;
			break;
		}

		//pros::delay(5);
		//count--;
		//if(count < 0) {
		//	break;
		//}
	}

	leftMotors.move(0);
	rightMotors.move(0);
//
	//while(std::abs(leftMotors.get_position() - target) > err) {
	//	float adj = leftMotors.get_position() - target;
//
	//	leftMotors.move_relative(adj, RPM*(speed/200.f));
	//	rightMotors.move_relative(adj, RPM*(speed/200.f));
	//	pros::delay(100);
	//}
}

void rotateToAuto(float orientation, float speed, int acc) {
	
	double movedeg = (orientation - (inertial.get_rotation()+orientationStart));
	while(movedeg > 360) movedeg -=360;
	while(movedeg < -360) movedeg +=360;
	while (movedeg > 180) movedeg -= 360;
	while (movedeg < -180) movedeg += 360;

	float deg = 360.f*((((M_PI*2*(ROBOTDIA/2.f))*(movedeg/360.f))/(WHEELDIA*M_PI))/(GEARRATIO));
	float target = leftMotors.get_position() + deg;

	leftMotors.move_relative(deg, RPM*(speed/100.f));
	rightMotors.move_relative(-deg, RPM*(speed/100.f));
	

	int count = 30*5*2;
	while(std::abs(leftMotors.get_position() - target) > 8) {
		pros::delay(2.5);
		count--;
		if(count < 0) {
			break;
		}
		if(motorOverideAuton) {
			motorOverideAuton = false;
			return;
		}

	}

	if(--acc != 0) {
		rotateToAuto(orientation, speed, acc);
	}
}

void moveToAuto(float x, float y, float speed, int acc, bool rev, float decelMult) {

	pros::delay(5);

	float dist = sqrt(pow(x-xPos, 2) + pow(y-yPos, 2));
	float dy = yPos - y, dx = xPos - x;
	float theta = (rev ? 180 : 0);

	theta += atan2(dx,dy) * 180.f/M_PI;
	
	rotateToAuto(theta, speed*0.9, acc);
	moveAuto(!rev, dist, speed, decelMult);

	yPos = y; xPos = x;
}

	
void startPos(float x, float y, float ori) {
	if(ori != -999)
		orientationStart = ori;
	xPos = x; yPos = y;
}

void startPosft(float xf, float yf, float ori) {
	xPos = xf*12; yPos = yf*12; orientationStart = ori;
}

void startPosTile(float xf, float yf, float ori) {
	xPos = xf*24; yPos = yf*24; orientationStart = ori;
}