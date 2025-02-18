#include "auton.h"

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


void autonGoalRed2() {
	const int speedSlow = 75;
	const int speedMed = 85;
	const int speedFast = 95;

	// init
	startPos(12+6, 12, 270);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab donut
	moveToAuto(48+7, 24, 200, 2);
	arm.set_value(true);
	pros::delay(300);

	rotateToAuto(270);
	moveAuto(false, 20, speedMed);
	arm.set_value(false);
	pros::delay(150);
	xPos -= 20;

	// mogo grab
	moveToAuto(50, 16, speedSlow/1.4, 2, true);
	pros::delay(100);
	mogo.set_value(true);
	pros::delay(150);
	conveyor.move(127);
	pros::delay(500);

	// drop mogo
	mogo.set_value(false);
	pros::delay(100);
	conveyor.move(0);

	// grab original mogo
	moveToAuto(52.5, 47, speedSlow/1.5, 2, true);
	startPos(48, 48, -999); // prevent desync
	mogo.set_value(true);
	pros::delay(100);
	intake.set_value(true);

	// grab middle donut
	moveToAuto(22.5, 48+7, speedSlow/1.35, 3);
	conveyor.move(127);
	pros::delay(100);
	intake.set_value(false);
	pros::delay(300);

	// book corner
	moveToAuto(-25, 10, speedMed, 3);
}

void autonGoalBlue2() {
	const int speedSlow = 75;
	const int speedMed = 85;
	const int speedFast = 95;

	// init
	startPos(144-(12+6), 12+24, 90);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab donut
	moveToAuto(144-(48+7), 24, speedSlow, 2);
	arm.set_value(true);
	pros::delay(300);

	rotateToAuto(90);
	moveAuto(false, 20, speedSlow);
	arm.set_value(false);
	pros::delay(150);
	xPos += 20;

	// mogo grab
	moveToAuto(144-50, 32, speedSlow/1.4, 2, true);
	pros::delay(100);
	mogo.set_value(true);
	pros::delay(150);
	conveyor.move(127);
	pros::delay(500);

	// drop mogo
	mogo.set_value(false);
	pros::delay(100);
	conveyor.move(0);
	pros::delay(200);

	// grab original mogo
	moveToAuto(144-(49.5), 50, speedSlow/1.5, 2, true);
	startPos(144-(48), 48, -999); // prevent desync
	mogo.set_value(true);
	pros::delay(100);
	intake.set_value(true);

	// grab middle donut
	moveToAuto(144-(22.5), 48+24, speedSlow/1.35, 3);
	conveyor.move(127);
	pros::delay(100);
	intake.set_value(false);
	pros::delay(300);

	// book corner
	moveToAuto(144-(-20), -38, speedMed, 3);
}