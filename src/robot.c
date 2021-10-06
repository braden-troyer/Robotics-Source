#include "robot.h"

Motor *initializeMotor(int channel)
{
  Motor *base = malloc(sizeof(Motor));
  base->channel = channel;
  base->speed = 0;
  return base;
}

Button *initializeButton(int joystick, int button_set, int location)
{
  Button *base = malloc(sizeof(Button));
  base->current_state = false;
  base->last_state = false;
  base->joystick = joystick;
  base->button_set = button_set;
  base->location = location;
  return base;
}

bool checkButton(Button *button)
{
  button->last_state = button->current_state;
  button->current_state = joystickGetDigital(button->joystick, button->button_set, button->location);

  return (!button->current_state && button->current_state != button->last_state);
}
