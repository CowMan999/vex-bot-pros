#include "auton.h"

//       ^ 0      
// 270 <   > 90   (144, 144)
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

void autonSkills() {

	const int speedSlow = 35;
	const int speedMed = 45;
	const int speedFast = 55;

	// init
	startPosTile(0.5, 2, 90);

	// grab mogo
	moveToAuto(2*12, 4*12, speedSlow/1.5, 3, true);
	mogo.set_value(true);
	pros::delay(250);
	
	// get donut beside
	intakeMotor.move(127);
	conveyor.move(127);
	pros::delay(750);
	moveToAuto(4*12, 4*12, speedMed, 4);
	pros::delay(500);
	moveToAuto(4*12, 2*12, speedMed, 4); // get donut under
	pros::delay(500);
	moveToAuto(6*12, 2*12, speedMed, 4); // middle donut
	moveToAuto(2*12, 2*12, speedMed, 4); // corner three
	moveToAuto(2*12, 1*12, speedMed, 4); 
	moveToAuto(3*12, 3*12, speedFast, 4); 

	// move to corner and drop mogo, stop intake
	moveToAuto(2*12, 2*12, speedMed, 2, true);
	moveToAuto(0, 0, speedSlow*1.25, 2, true);
	mogo.set_value(false);
	intakeMotor.move(0);
	conveyor.move(0);
	startPos(12, 12, -999);
	moveToAuto(2*12, 2*12, speedMed, 3);

	// level against wall
	moveToAuto(2*12, 4*12, speedMed, 3);
	moveToAuto(0, 4*12, speedSlow/1.75, 3);
	startPos(8, 4*12, 90);
	moveToAuto(2*12, 4*12, speedSlow/1.25, 3, true);


	// grab other mogo
	moveToAuto(2*12, 5*12, speedSlow/1.25, 3);
	moveToAuto(2*12, 8.45*12, speedSlow, 3, true);
	mogo.set_value(true);
	pros::delay(250);

	intakeMotor.move(127);
	conveyor.move(127);
	moveToAuto(4*12, 8*12, speedMed, 3);
	moveToAuto(4*12, 10*12, speedMed, 3); // get donut under
	moveToAuto(6*12, 10*12, speedMed, 3); // middle donut
	moveToAuto(2*12, 10*12, speedMed, 3); // corner three
	moveToAuto(2*12, 11*12, speedMed, 3);
	moveToAuto(3*12, 9*12, speedFast, 3);

	// move to corner and drop mogo, stop intake
	moveToAuto(2*12, 10*12, speedMed, 3, true);
	moveToAuto(0*12, 12*12, speedSlow, 3, true);
	mogo.set_value(false);
	intakeMotor.move(0);
	conveyor.move(0);
	return;


	startPos(12, 12, -999);
	moveToAuto(2*12, 10*12, speedMed, 3);
	
	// other side
	moveToAuto(6*12, 10*12, speedFast, 3);
	moveToAuto(9*12, 8*12, speedFast, 3);

	// grab mogo
	moveToAuto(6*12, 10*12, speedMed, 3, true);
	moveToAuto(6*12, 11.5*12, speedSlow/1, 3, true);
	mogo.set_value(true);
	pros::delay(250);

	// spin
	intakeMotor.move(127);
	conveyor.move(127);

	// donuts
	moveToAuto(8*12, 4*12, speedMed, 2);
	moveToAuto(8*12, 2*12, speedMed, 2);
	moveToAuto(10*12, 2*12, speedMed, 2);


	// grab side donuts
	intakeMotor.move(32);
	moveToAuto(8*12, 10*12, speedMed, 3);
	moveToAuto(8*12, 8*12, speedMed, 3);
	intakeMotor.move(0);

	// place on wall stake
	moveToAuto(6*12, 10*12, speedFast, 3);
	moveToAuto(6*12, 11.5*12, speedMed, 3, true);

	// go to other side
	moveToAuto(2*12, 6*12, speedFast, 3);
	moveToAuto(4*12, 2*12, speedFast, 3);

	// grab side donuts
	intakeMotor.move(32);
	moveToAuto(8*12, 2*12, speedMed, 3);
	moveToAuto(8*12, 4*12, speedMed, 3);
	intakeMotor.move(0);

	// place on wall stake
	moveToAuto(6*12, 2*12, speedFast, 3);
	moveToAuto(6*12, 0.5*12, speedMed, 3, true);

	// elevate
	//moveToAuto(8*12, 4*12, speedFast, 3);
	//moveToAuto(6*12, 6*12, speedFast, 3);

}