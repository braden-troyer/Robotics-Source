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
#include "macros.h"



void operatorControl() {

  // Initializer of the main robot data set
  Robot *main_bot = initializeRobot();

  // Values to keep track of loop time
  int time = 0, target_time = 0;


  while (1) {
    // Runs the debug code if the button to change it is pressed
    time = millis();
    if (time >= target_time)
    {
      // Simply calls updates and run, other functions may be added later
      updates(main_bot);
      run(main_bot);

      target_time += LOOP_TIME_MILLIS;
    }

  }
}
