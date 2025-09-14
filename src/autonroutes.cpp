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

void autonGoalRed() {
	const int speedSlow = 75;
	const int speedMed = 85;
	const int speedFast = 95;

	// init
	startPos(12+6, 12, 270);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab donut
	moveToAuto(48+7, 24, speedSlow, 2);
	arm.set_value(true);
	pros::delay(300);

	rotateToAuto(270);
	moveAuto(false, 20, speedSlow);
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
	moveToAuto(24.5, 48+9, speedSlow/1.35, 3);
	conveyor.move(127);
	pros::delay(120);
	intake.set_value(false);
	pros::delay(300);

	// touch ladder
	moveToAuto(34, 57, speedSlow, 3);
}

void autonGoalBlue() {
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
	pros::delay(1000);

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

	// touch ladder
	moveToAuto(144-(34), 48+25, speedSlow, 3);
}

void autonRingRed() {
	const int speedSlow = 30;
	const int speedMed = 50;
	const int speedFast = 70;

	// init
	startPosTile(0.5, 4, 90);

	// mogo grab
	moveToAuto(48,96, speedMed, 2, true);
	mogo.set_value(true);
	pros::delay(250);

	// drop preload
	conveyor.move(127);

	// other donut
	intakeMotor.move(127);
	moveToAuto(48, 120, speedSlow, 2);
	
	// get the last donut
	moveToAuto(48+19, 124, speedSlow, 2);
	moveToAuto(48, 120, speedFast, 2, false);
	moveToAuto(48+19, 116, speedSlow, 2);
	moveToAuto(48, 120, speedFast, 2, false);

	// middle stack
	intake.set_value(true);
	moveToAuto(24, 70, speedMed, 3);

	// touch ladder
	moveToAuto(62, 82, speedFast, 2);
}



void autonRingBlue() {
	const int speedSlow = 30;
	const int speedMed = 50;
	const int speedFast = 70;

	// init
	startPosTile(5.5, 4, 270);

	// mogo grab
	moveToAuto(144-48,96, speedMed, 2, true);
	mogo.set_value(true);
	pros::delay(250);

	// drop preload
	conveyor.move(127);

	// other donut
	intakeMotor.move(127);
	moveToAuto(144-48, 120, speedSlow, 2);
	
	// get the last donut
	moveToAuto(144-(48+19), 124, speedSlow, 2);
	moveToAuto(144-(48), 120, speedFast, 2, false);
	moveToAuto(144-(48+19), 116, speedSlow, 2);
	moveToAuto(144-(48), 120, speedFast, 2, false);

	// middle stack
	intake.set_value(true);
	moveToAuto(144-24, 70, speedMed, 3);

	// touch ladder
	moveToAuto(144-62, 82, speedFast, 2);
}