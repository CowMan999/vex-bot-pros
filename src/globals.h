#include "main.h"

#pragma once;

extern pros::MotorGroup leftMotors, rightMotors;
extern pros::Motor conveyor, intakeMotor, wallstake;

extern pros::Controller controller;

extern pros::adi::DigitalOut mogo, arm, intake;
extern pros::adi::DigitalIn limSwitch;

extern pros::vision_signature_s_t sigRed, sigBlue;

extern pros::Optical optical;
extern pros::Distance distance;

extern pros::Imu inertial;

extern bool motorOverideAuton;