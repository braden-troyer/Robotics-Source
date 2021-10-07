#include "debug.h"


void debug(Robot *robot)
{
  if (checkButton(robot->debug_button))
    robot->debug_on = !robot->debug_on;
}
