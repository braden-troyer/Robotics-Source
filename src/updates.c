#include "updates.h"
#include "macros.h"
#include <math.h>


void updates(Robot *robot) {
  // Variable 'Names'
  int power, turn, arm_power, claw_pos;


// Button Checking Section
  // Setting a multiplier on the amount of wheel power
  if (checkButton(robot->scale_down, 0) && robot->wheel_scale > SPEED_LOW)
    robot->wheel_scale -= SPEED_SHIFT;

  if (checkButton(robot->scale_up, 0) && robot->wheel_scale < SPEED_HIGH)
    robot->wheel_scale += SPEED_SHIFT;

  if (checkButton(robot->alternate_button, 0))
    robot->wheel_scale *= -1;



  robot->arm_switch.isOn = digitalRead(3);


  // Joystick Checking Section
  power = joystickGetAnalog(JOYSTICK, 3);
  turn = joystickGetAnalog(JOYSTICK, 4);
  arm_power = joystickGetAnalog(JOYSTICK, 2);

  /*
  if (joystickGetDigital(JOYSTICK, 6, JOY_UP) && robot->claw_servo[0]->speed < 127) {
    robot->claw_servo[0]->speed++;
    robot->claw_servo[1]->speed = -robot->claw_servo[0]->speed;
  }
  if (joystickGetDigital(JOYSTICK, 6, JOY_DOWN) && robot->claw_servo[0]->speed > -127) {
    robot->claw_servo[0]->speed--;
    robot->claw_servo[1]->speed = -robot->claw_servo[0]->speed;
  }

  if (joystickGetDigital(JOYSTICK, 5, JOY_UP) && robot->claw_servo[1]->speed < 127) {
    robot->claw_servo[1]->speed++;
  }
  if (joystickGetDigital(JOYSTICK, 5, JOY_DOWN) && robot->claw_servo[1]->speed > -127) {
    robot->claw_servo[1]->speed--;
  }
  */

  if (checkButton(robot->forward_button, 1)) {

    robot->left_motor->speed = PRECISION_SPEED;
    robot->right_motor->speed = -PRECISION_SPEED;

  } else if (checkButton(robot->backward_button, 1)) {

    robot->left_motor->speed =  -PRECISION_SPEED;
    robot->right_motor->speed = PRECISION_SPEED;

  } else if (checkButton(robot->left_turn, 1)) {

    robot->left_motor->speed = -PRECISION_SPEED / 2;
    robot->right_motor->speed = -PRECISION_SPEED / 2;

  } else if (checkButton(robot->right_turn, 1)) {

    robot->left_motor->speed = PRECISION_SPEED / 2;
    robot->right_motor->speed = PRECISION_SPEED / 2;

  } else if (robot->wheel_scale < 0) {
    robot->left_motor->speed = robot->wheel_scale * (power + turn);
    robot->right_motor->speed = robot->wheel_scale * -(power - turn);
  } else {

    robot->left_motor->speed = robot->wheel_scale * (power + turn);
    robot->right_motor->speed = robot->wheel_scale * -(power - turn);

  }

  robot->arm_motor->speed = fabs(robot->wheel_scale) * arm_power;
}
