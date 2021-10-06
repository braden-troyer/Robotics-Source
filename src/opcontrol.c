/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "robot.h"
#include "run.h"
#include "updates.h"
#include <stdlib.h>
#include <stdbool.h>
#include "debug.h"
/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

void operatorControl() {

  // Initializer of the main robot data set
  Robot main_bot;
  main_bot.is_initialized = false;

  // Values to keep track of loop time
  int time = 0, prev_time = 0;

  while (1) {
    time = millis();

    // This loop runs every 2 milliseconds; if it misses a loop, it will iterate until caught up
    if (time >= prev_time)
    {
      // Runs the debug code if the button to change it is pressed
      if (main_bot.debug_on)
      {
        debug(&main_bot);
      }
      else
      {
        // Inner loop simply calls updates and run, other functions may be added later
        updates(&main_bot);
        run(&main_bot);
      }

      prev_time += 2;
    }
  }
}
