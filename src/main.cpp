#include "main.h"

#include "globals.h"
#include "auton.h"

bool throwRed = false;
bool throwBlue = false;
bool conveyorOverride = false;
enum {
	wallDown,
	wallCatch,
	wallUp
} wallState;

bool wallStateLock = false;
bool wallStateLockR = false;
bool resetLB = false;

#define TOGGLE_DIGOUT(out, button) \
if(controller.get_digital_new_press(pros::button)) { \
	static int t = false; t = !t; \
	out.set_value(t); \
} \

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();

	leftMotors.set_encoder_units_all(pros::E_MOTOR_ENCODER_DEGREES);
	rightMotors.set_encoder_units_all(pros::E_MOTOR_ENCODER_DEGREES);
	inertial.reset(true);
}

void disabled() {}

void competition_initialize() {}

bool seeRed() {
	return optical.get_proximity()>=255 && optical.get_hue() > 0 && optical.get_hue() < 18;
}


bool seeBlue() {
	return optical.get_proximity()>=255 && optical.get_hue() > 190 && optical.get_hue() < 240;
}

void autonomous() {
//void opcontrol() {

	optical.set_led_pwm(50);
	throwRed = true;
	new pros::Task([&](){
		while(true) {
			if(!conveyorOverride) {
				if(((throwRed && seeRed()) || (throwBlue && seeBlue()))) {
					conveyorOverride = true;
					
					// async the task to prevent drive brick
					pros::Task async([&](){
						conveyor.move(127);
						while(optical.get_proximity()>=255);
						int count = 5;
						while(count > 0) {
							if(distance.get()>100) {
								count--;
							} else{
								count = 5;
							}
						}
						pros::delay(11);
						conveyor.move(-127);
						pros::delay(350);
						conveyorOverride = false;
						conveyor.move(127);
					});
				}
			}
		}
	});

	leftMotors.set_brake_mode_all(MOTOR_BRAKE_BRAKE);
	rightMotors.set_brake_mode_all(MOTOR_BRAKE_BRAKE);

	//startPosTile(0.5, 2, 270);
	//startPos(24, 24, 270);
	//moveToAuto(48, 48, 30, 2);
	//moveToAuto(24, 48, 30, 2);
	//moveToAuto(36, 36, 30, 2);


	//moveAuto(false, 12, 40, 5);
	//throwBlue = true;
	autonGoalBlue3();
	//throwBlue = false;
	//autonSkills();

	//moveAuto(true, 24, 80);

	//moveAuto(true, 48, 80);
}



void opcontrol() {
//void autonomous() {
	leftMotors.set_brake_mode_all(MOTOR_BRAKE_HOLD);
	rightMotors.set_brake_mode_all(MOTOR_BRAKE_HOLD);
	wallstake.set_brake_mode(MOTOR_BRAKE_HOLD);
	leftMotors.set_gearing_all(pros::motor_gearset_e_t::E_MOTOR_GEAR_BLUE);
	rightMotors.set_gearing_all(pros::motor_gearset_e_t::E_MOTOR_GEAR_BLUE);
	conveyor.set_gearing_all(pros::motor_gearset_e_t::E_MOTOR_GEAR_BLUE);
	wallstake.set_gearing_all(pros::motor_gearset_e_t::E_MOTOR_GEAR_GREEN);
	wallstake.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
	wallstake.tare_position();


	while (true) {
		int dir = controller.get_analog(ANALOG_LEFT_Y);
		int turn = controller.get_analog(ANALOG_LEFT_X); 
		leftMotors.move(dir + turn);  
		rightMotors.move(dir - turn); 

		TOGGLE_DIGOUT(mogo, E_CONTROLLER_DIGITAL_R1);
		TOGGLE_DIGOUT(arm, E_CONTROLLER_DIGITAL_Y);
		TOGGLE_DIGOUT(intake, E_CONTROLLER_DIGITAL_L1);

		//if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		//	autonomous();
		//}

		// optical crap
		if(!conveyorOverride) {
			if(((throwRed && seeRed()) || (throwBlue && seeBlue()))) {
				conveyorOverride = true;
				
				// async the task to prevent drive brick
				pros::Task async([&](){
					conveyor.move(127);
					while(optical.get_proximity()>=255);
					int count = 5;
					while(count > 0) {
						if(distance.get()>100) {
							count--;
						} else{
							count = 5;
						}
					}
					pros::delay(8);
					conveyor.move(-127);
					pros::delay(350);
					conveyorOverride = false;
				});
			}
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			intakeMotor.move(127);
			if(!conveyorOverride) conveyor.move(127);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			intakeMotor.move(-127);
			if(!conveyorOverride) conveyor.move(-127);
		} else {
			intakeMotor.move(0);
			if(!conveyorOverride) conveyor.move(0);
		}

		// ladybrown
		if(!wallStateLock && !wallStateLockR) {
			if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
				wallStateLock = true;
				if(wallState == wallDown) {
					wallState = wallCatch;
					wallstake.move_absolute(130-10+ (resetLB?10:0), 200);

					pros::Task async([&](){
						pros::delay(400);
						wallStateLock = false;
					});

				} else if(wallState == wallCatch) {
					wallState = wallUp;
					wallstake.move_absolute(575+130+ (resetLB?10:0), 200);

					pros::Task async([&](){
						pros::delay(800);
						wallStateLock = false;
					});
				} else {
					wallStateLock = false;
				}

			} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
				wallStateLock = true;
				if(wallState == wallCatch) {
					wallState = wallDown;
					wallstake.move_absolute(0, 200);

					pros::Task async([&](){
						pros::delay(400);
						wallStateLock = false;
					});

				} else if(wallState == wallUp) {
					wallState = wallCatch;
					wallstake.move_absolute(130-10 + (resetLB?10:0), 200);

					pros::Task async([&](){
						pros::delay(800);
						wallStateLock = false;
					});
				} else {
					wallStateLock = false;
				}
			}
		}

		if(!wallStateLockR && controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			wallStateLock = true;
			wallStateLockR = true;
			wallstake.move(0);
			wallState = wallDown;
			wallstake.move(-45);

			pros::Task async([&](){
				pros::delay(1700);
				wallstake.move(0);
				pros::delay(250);
				wallstake.tare_position();
				wallStateLock = false;
				wallStateLockR = false;
				resetLB = true;
			});
		}

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
			throwBlue = true;
			throwRed = false;
			controller.rumble(".");
		} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			throwBlue = false;
			throwRed = true;
			controller.rumble("-");
		} else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
			throwBlue = false;
			throwRed = false;
			controller.rumble("..");
		}
	}
}