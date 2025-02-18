#include "globals.h"

pros::MotorGroup leftMotors({-5, -4, -1}, pros::MotorGears::blue, pros::MotorEncoderUnits::degrees);
pros::MotorGroup rightMotors({8, 7, 6}, pros::MotorGears::blue, pros::MotorEncoderUnits::degrees);
pros::Motor conveyor(-18);
pros::Motor wallstake(-20);
pros::Motor intakeMotor(16);

pros::Imu inertial(2);

pros::vision_signature_s_t sigRed = pros::Vision::signature_from_utility(1, 14729,15239,14984, 689, 1149, 919, 20, 0);
pros::vision_signature_s_t sigBlue = pros::Vision::signature_from_utility(2, -4013,-3477,-3745, 11013, 11469, 11241, 25, 0);

pros::Optical optical(15);

pros::Controller controller(pros::controller_id_e_t::E_CONTROLLER_MASTER);

pros::adi::DigitalOut mogo('G');
pros::adi::DigitalOut arm('F');
pros::adi::DigitalOut intake('B');

