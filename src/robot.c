#include "robot.h"
#include "macros.h"
#include <stdlib.h>

Motor *initializeMotor(int channel)
{
  Motor *base = calloc(1, sizeof(Motor));
  base->channel = channel;
  base->speed = 0;
  return base;
}

Button *initializeButton(int joystick, int button_set, int location)
{
  Button *base = calloc(1, sizeof(Button));
  base->joystick = joystick;
  base->button_set = button_set;
  base->location = location;
  return base;
}

Robot *initializeRobot() {
  Robot *robot = malloc(sizeof(Robot));


  robot->left_motor = initializeMotor(LEFT_MOTOR);
  robot->right_motor = initializeMotor(RIGHT_MOTOR);
  robot->arm_motor = initializeMotor(ARM_MOTOR);
//    robot->claw_servo[0] = initializeMotor(CLAW_SERVO_1);
//    robot->claw_servo[1] = initializeMotor(CLAW_SERVO_2);

  robot->scale_down = initializeButton(JOYSTICK, 8, JOY_DOWN);
  robot->scale_up = initializeButton(JOYSTICK, 8, JOY_UP);

  robot->alternate_button = initializeButton(JOYSTICK, 8, JOY_LEFT);

  robot->forward_button = initializeButton(JOYSTICK, 7, JOY_UP);
  robot->backward_button = initializeButton(JOYSTICK, 7, JOY_DOWN);
  robot->left_turn = initializeButton(JOYSTICK, 7, JOY_LEFT);
  robot->right_turn = initializeButton(JOYSTICK, 7, JOY_RIGHT);

  robot->wheel_scale = 1.0;
  robot->debug_on = false;

  return robot;
}

bool checkButton(Button *button, short mode)
{
  if (mode == 0) {
    button->last_state = button->current_state;
    button->current_state = joystickGetDigital(button->joystick, button->button_set, button->location);

    return (!button->current_state && button->current_state != button->last_state);
  } else if (mode == 1) {
    return joystickGetDigital(button->joystick, button->button_set, button->location);
  }
  return NULL;
}
