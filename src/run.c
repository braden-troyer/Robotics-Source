#include "run.h"
#include "main.h"

void run(Robot *robot) {

  // Funcitons that actually make the motors turn based off of
  // operations found in updates()
  motorSet(robot->left_motor->channel, robot->left_motor->speed);
  motorSet(robot->right_motor->channel, robot->right_motor->speed);
  motorSet(robot->arm_motor->channel, robot->arm_motor->speed);
  motorSet(robot->claw_servo[0]->channel, robot->claw_servo[0]->speed);
  motorSet(robot->claw_servo[1]->channel, robot->claw_servo[1]->speed);
}
