#ifndef ROBOT_H_
#define ROBOT_H_

#include <stdbool.h>
#include "main.h"

// Datatype that holds much of the needed data for Motors
typedef struct Motor {
  int speed;
  int channel;
} Motor;


// Defines buttons on the controller
typedef struct Button {
  // Two different states
  bool current_state, last_state;
  int joystick, button_set, location;
} Button;

// Digital input (switches, etc)
typedef struct Digital {
  bool isOn;
} Switch;

typedef struct Robot {
  // Motors on the Robot
  Motor *left_motor;
  Motor *right_motor;

  Motor *arm_motor;

  Motor *claw_servo[2];

  // Switches on the Robot
  Switch arm_switch;

  // Buttons on the controller
  Button *scale_down, *scale_up;
  Button *alternate_button;
  Button *forward_button, *backward_button, *left_turn, *right_turn;


  // Other values
  float wheel_scale;
  bool debug_on;
}Robot;

Motor *initializeMotor(int channel);
Button *initializeButton(int joystick, int button_set, int location);
Robot *initializeRobot();

bool checkButton(Button *button, short mode);

#endif
