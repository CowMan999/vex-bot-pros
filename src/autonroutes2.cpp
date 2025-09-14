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

void autonGoalRed3() {
	const int speedSlow = 75;
	const int speedMed = 88;
	const int speedFast = 98;

	// init
	startPos(14, 8.25, 270-20);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab mogo
	moveToAuto(48+4, 23, 100, 2, false, 0.92/*, 0.8 less decel */);
	arm.set_value(true);
	pros::delay(300);

	rotateToAuto(270);
	moveAuto(false, 20, speedSlow);
	arm.set_value(false);
	pros::delay(100);
	xPos -= 20;

	// mogo grab
	moveToAuto(50, 12, speedSlow/1.2, 2, true, 0.9);
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
	moveToAuto(48.5, 47, speedSlow/1.4, 2, true);
	mogo.set_value(true);
	pros::delay(100);
	new pros::Task( [&](){
		pros::delay(285);
		conveyor.move(127);
		pros::delay(150);
	});

	moveToAuto(54, 63-6, speedFast, 2, false);

	// grab middle donut
	//intake.set_value(true);
	//moveToAuto(24.5, 48+11, speedSlow/1.2, 3);
	//conveyor.move(127);
	//pros::delay(120);
	//intake.set_value(false);
	//pros::delay(300);

	//rotateToAuto(60, 75, 3);
	//moveAuto(true, 31.5, speedMed);


	// book corner
	//moveToAuto(30.5, 13, speedSlow, 2);
	//arm.set_value(true);
	//moveAuto(true, 5.5, 70);

	//rotateToAuto(60, 75, 3);
	//moveAuto(true, 29.5, speedFast);
//
	//rotateToAuto(18, 75, 3);
	//moveAuto(true, 36, speedFast);
//
	//conveyor.move(0);
	//new pros::Task([&](){
	//	pros::delay(550);
	//	motorOverideAuton = true;
	//});
	//moveAuto(true, 80, speedSlow/2, 10);
	//moveAuto(false, 9, speedMed);
	//
	//pros::delay(150);
	//intakeMotor.move(0);

	//arm.set_value(true);
	//conveyor.move(127);
	//pros::delay(100);

	//rotateToAuto((360+270)/2.f, speedFast, 2);
	//moveAuto(true, 48, speedFast);

	//intake.set_value(true);
	//new pros::Task([&](){
	//	pros::delay(650);
	//	motorOverideAuton = true;
	//});
	//moveAuto(true, 45, speedMed);
	//pros::delay(100);
	//moveAuto(false, 9, speedMed);
	//intake.set_value(false);
	//moveAuto(true, 45, speedMed);


	// arm and turn
	//pros::delay(100);
	//rotateToAuto(270+14, 110, 1);
	//pros::delay(220);
	//arm.set_value(false);
	//rotateToAuto(270-10, 110, 1);
	//
	//intakeMotor.move(0);
	//moveAuto(true, 24, 100);

	// coast wall
	//moveAuto(true, 37, speedSlow/1.15);
}
void autonGoalRed2() {
	const int speedSlow = 75;
	const int speedMed = 88;
	const int speedFast = 98;

	// init
	startPos(14, 8.25, 270-20);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab mogo
	moveToAuto(48+4, 23, 100, 2, false, 0.92/*, 0.8 less decel */);
	arm.set_value(true);
	pros::delay(300);

	rotateToAuto(270);
	moveAuto(false, 20, speedSlow);
	arm.set_value(false);
	pros::delay(100);
	xPos -= 20;

	// mogo grab
	moveToAuto(50, 12, speedSlow/1.2, 2, true, 0.9);
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
	moveToAuto(48.5, 47, speedSlow/1.4, 2, true);
	startPos(44, 48, -999);
	mogo.set_value(true);
	pros::delay(100);
	new pros::Task( [&](){
		pros::delay(285);
		conveyor.move(127);
		pros::delay(150);
	});

	// grab middle donut
	//intake.set_value(true);
	//moveToAuto(24.5, 48+11, speedSlow/1.2, 3);
	//conveyor.move(127);
	//pros::delay(120);
	//intake.set_value(false);
	//pros::delay(300);

	//rotateToAuto(60, 75, 3);
	//moveAuto(true, 31.5, speedMed);


	// book corner
	//moveToAuto(30.5, 13, speedSlow, 2);
	//arm.set_value(true);
	//moveAuto(true, 5.5, 70);

	rotateToAuto(60, 75, 3);
	moveAuto(true, 29.5, speedFast);

	rotateToAuto(18, 75, 3);
	moveAuto(true, 36, speedFast);

	conveyor.move(0);
	new pros::Task([&](){
		pros::delay(550);
		motorOverideAuton = true;
	});
	moveAuto(true, 80, speedSlow/2, 10);
	moveAuto(false, 9, speedMed);
	
	pros::delay(150);
	intakeMotor.move(0);

	arm.set_value(true);
	conveyor.move(127);

	moveAuto(true, 8, speedSlow/1.5);

	//intake.set_value(true);
	//new pros::Task([&](){
	//	pros::delay(650);
	//	motorOverideAuton = true;
	//});
	//moveAuto(true, 45, speedMed);
	//pros::delay(100);
	//moveAuto(false, 9, speedMed);
	//intake.set_value(false);
	//moveAuto(true, 45, speedMed);


	// arm and turn
	pros::delay(100);
	rotateToAuto(270+14, 110, 1);
	pros::delay(220);
	arm.set_value(false);
	rotateToAuto(270-10, 110, 1);
	
	intakeMotor.move(0);
	moveAuto(true, 24, 100);

	// coast wall
	//moveAuto(true, 37, speedSlow/1.15);
}

//      ^ 0      
// 90 <   > 270   (144, 144)
//      v 180      |
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

void autonGoalBlue2() {
	const int speedSlow = 75;
	const int speedMed = 88;
	const int speedFast = 98;

	// init
	startPos(144-14, 36, 90-20);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab mogo
	moveToAuto(144-(48+4), 23, 100, 2, false, 0.93/*, 0.8 less decel */);
	arm.set_value(true);
	pros::delay(240);

	rotateToAuto(90, 45, 2);
	moveAuto(false, 20, speedSlow);
	arm.set_value(false);
	pros::delay(100);
	xPos += 20;

	// mogo grab
	moveToAuto(144-51, 36, speedSlow/1.2, 2, true, 0.87);
	pros::delay(100);
	mogo.set_value(true);
	pros::delay(240);
	conveyor.move(127);
	pros::delay(460);

	// drop mogo
	mogo.set_value(false);
	pros::delay(100);
	conveyor.move(0);

	// grab original mogo
	moveToAuto(144-48.5, 52.5, speedSlow/1.4, 2, true);
	startPos(144-47, 48, -999);
	mogo.set_value(true);
	pros::delay(200);
	new pros::Task( [&](){
		pros::delay(185);
		conveyor.move(127);
		pros::delay(150);
	});

	// grab middle donut
	//intake.set_value(true);
	//moveToAuto(24.5, 48+11, speedSlow/1.2, 3);
	//conveyor.move(127);
	//pros::delay(120);
	//intake.set_value(false);
	//pros::delay(300);

	//rotateToAuto(60, 75, 3);
	//moveAuto(true, 31.5, speedMed);


	// book corner
	//moveToAuto(30.5, 13, speedSlow, 2);
	//arm.set_value(true);
	//moveAuto(true, 5.5, 70);

	// temp end auton
	pros::delay(15000);

	rotateToAuto(350, 75, 3);
	moveAuto(true, 33.5, speedMed);

	rotateToAuto(300, 75, 3);
	moveAuto(true, 29, speedFast);

	conveyor.move(0);
	new pros::Task([&](){
		pros::delay(420);
		controller.set_text(0,0,"rride");
		motorOverideAuton = true;
	});
	moveAuto(true, 100, speedSlow/2, 10);
	moveAuto(false, 9+6, speedMed);
	pros::delay(150);

	intakeMotor.move(0);
	arm.set_value(true);

	conveyor.move(127);
	moveAuto(true, 7+6, speedSlow/1.5);

/*
	moveAuto(true, 80, speedSlow/2, 10);
	moveAuto(false, 9, speedMed);
	
	pros::delay(150);
	pros::delay(250);
	intakeMotor.move(0);

	arm.set_value(true);
	conveyor.move(127);

	moveAuto(true, 8, speedSlow/1.5);
	
*/

	//intake.set_value(true);
	//new pros::Task([&](){
	//	pros::delay(650);
	//	motorOverideAuton = true;
	//});
	//moveAuto(true, 45, speedMed);
	//pros::delay(100);
	//moveAuto(false, 9, speedMed);
	//intake.set_value(false);
	//moveAuto(true, 45, speedMed);


	// arm and turn
	pros::delay(100);
	rotateToAuto(190, 110, 1);
	pros::delay(320);
	arm.set_value(false);
	rotateToAuto(210, 110, 1);

	// coast wall
	//moveAuto(true, 37, speedSlow/1.15);
}

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

void autonRingBlue2() {
	const int speedSlow = 80;
	const int speedMed = 90;
	const int speedFast = 98;

	// init
	startPos(144-18, 144-24, 90);

	// book and intake
	intakeMotor.move(127);
	
	moveToAuto(144-(24*3-10),144-24, speedFast, 2, false, 0.6);
	pros::delay(100);
	moveToAuto(144-(24*3-13),144-24, speedSlow, 2, true);

	pros::delay(100);

	// mogo grab
	moveToAuto(144-45.5,94, speedMed, 2, true);
	mogo.set_value(true);
	pros::delay(600);

	// drop preload
	conveyor.move(127);
	pros::delay(500);

	// move corner
	moveToAuto(144-24, 144-24, speedSlow, 2);
	new pros::Task([&](){
		pros::delay(900);
		motorOverideAuton = true;
	});
	moveToAuto(144, 144+3, speedSlow, 2);

	new pros::Task([&](){
		pros::delay(650);
		motorOverideAuton = true;
	});
	moveAuto(true, 80, speedSlow/2, 10);
	moveAuto(false, 9, speedMed);
	conveyor.move(127);
	intakeMotor.move(0);
	moveAuto(true, 8, speedMed);
	
	moveToAuto(144-32, 144-24, speedMed, 2, true);

}

void autonGoalBlue3() {
	const int speedSlow = 75;
	const int speedMed = 88;
	const int speedFast = 98;

	// init
	startPos(144-14, 36, 90-20);

	// intake run, grab donut
	intakeMotor.move(127);
	
	// grab mogo
	moveToAuto(144-(48+4), 23, 50, 2, false, 0.93/*, 0.8 less decel */);
	pros::delay(240);


	// grab original mogo
	moveToAuto(144-46, 50.5, speedSlow/1.4, 2, true);
	mogo.set_value(true);
	pros::delay(200);
	new pros::Task( [&](){
		pros::delay(185);
		conveyor.move(127);
		pros::delay(150);
	});

	// grab middle donut
	//intake.set_value(true);
	//moveToAuto(24.5, 48+11, speedSlow/1.2, 3);
	//conveyor.move(127);
	//pros::delay(120);
	//intake.set_value(false);
	//pros::delay(300);

	//rotateToAuto(60, 75, 3);
	//moveAuto(true, 31.5, speedMed);


	// book corner
	//moveToAuto(30.5, 13, speedSlow, 2);
	//arm.set_value(true);
	//moveAuto(true, 5.5, 70);

	// temp end auton
}