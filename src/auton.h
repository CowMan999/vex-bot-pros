#include "globals.h"

#pragma once


void autonSkills();

void autonRingBLue();
void autonRingRed();
void autonGoalBlue();
void autonGoalRed();

void autonGoalBlue2();
void autonGoalRed2();


void moveAuto(bool forw, float distance, float speed = 100.f);
void rotateToAuto(float orientation, float speed = 45.f, int acc = 2);
void moveToAuto(float x, float y, float speed = 60.f, int acc = 2, bool rev = false);
void startPos(float x, float y, float ori);
void startPosft(float xf, float yf, float ori);
void startPosTile(float xf, float yf, float ori);

extern float xPos;
extern float yPos;