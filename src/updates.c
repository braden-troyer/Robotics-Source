#include "updates.h"

#define JOYSTICK 1
#define SPEED_HIGH 1
#define SPEED_LOW .5

void updates(Robot *robot) {
  // Variable 'Names'
  int power, turn, arm_power;

  // Initializing the robot only if it has not yet been initialized
  if (!(robot->is_initialized))
  {
    // Pointing to the memory allocated and initialized
    robot->left_motor = initializeMotor(2);
    robot->right_motor = initializeMotor(3);
    robot->arm_motor = initializeMotor(4);

    robot->scale_down = initializeButton(JOYSTICK, 8, JOY_LEFT);
    robot->scale_up = initializeButton(JOYSTICK, 8, JOY_RIGHT);
    robot->debug_button = initializeButton(JOYSTICK, 7, JOY_UP);


    robot->wheel_scale = 1.0;

    robot->is_initialized = true;
    robot->debug_on = false;
  }


// Button Checking Section
  // Setting a multiplier on the amount of wheel power
  if (checkButton(robot->scale_down) && robot->wheel_scale > SPEED_LOW)
    robot->wheel_scale -= .1;

  if (checkButton(robot->scale_up) && robot->wheel_scale < SPEED_HIGH)
    robot->wheel_scale += .1;

  // Change to debug mode
  if (checkButton(robot->debug_button))
    robot->debug_on = !robot->debug_on;


  robot->arm_switch.isOn = digitalRead(3);


  // Joystick Checking Section
  power = joystickGetAnalog(JOYSTICK, 3);
  turn = joystickGetAnalog(JOYSTICK, 4);
  arm_power = joystickGetAnalog(JOYSTICK, 1);

  robot->left_motor->speed =  robot->wheel_scale * (power + turn);
  robot->right_motor->speed = robot->wheel_scale * -(power - turn);

  if (robot->arm_switch.isOn && arm_power < 0)
    robot->arm_motor->speed = 0;
  else
    robot->arm_motor->speed = arm_power;
}
