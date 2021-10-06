#ifndef ROBOT_H_
#define ROBOT_H_

#include <stdbool.h>
#include "main.h"

// Datatype that holds much of the needed data for Motors
typedef struct Motor {
  int speed;
  int channel;
} Motor;


typedef struct Button {
  // Two different states
  bool current_state, last_state;
  int joystick, button_set, location;
} Button;


typedef struct Digital {
  bool isOn;
} Switch;

typedef struct Robot {
  // Motors on the Robot
  Motor *left_motor;
  Motor *right_motor;

  Motor *arm_motor;

  // Switches on the Robot
  Switch arm_switch;

  // Buttons on the controller
  Button *scale_down, *scale_up;
  Button *debug_button;

  // Other values
  bool is_initialized;
  float wheel_scale;
  bool debug_on;
}Robot;

Motor *initializeMotor(int channel);
Button *initializeButton(int joystick, int button_set, int location);

bool checkButton(Button *button);

#endif
