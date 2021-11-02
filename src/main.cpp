/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

motor l1 = motor(PORT20);
motor l2 = motor(PORT19);
motor r1 = motor(PORT10);
motor r2 = motor(PORT9);


// A global instance of competition
competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
  double speed = 70;
  l1.spin(directionType::fwd, speed, percentUnits::pct);
  
}

void usercontrol(void) {

  // User control code here, inside the loop
  while (true) {

    l1.spin(directionType::fwd, Controller1.Axis2.value(), percentUnits::pct);
    l2.spin(directionType::rev, Controller1.Axis2.value(), percentUnits::pct);
    
    r1.spin(directionType::rev, Controller1.Axis2.value(), percentUnits::pct);
    r2.spin(directionType::fwd, Controller1.Axis2.value(), percentUnits::pct);

    // turning 
    if (Controller1.ButtonL1.pressing()){
      l1.spin(directionType::fwd, 50, percentUnits::pct);
      l2.spin(directionType::rev, 50, percentUnits::pct);
    }
    else if (Controller1.ButtonR1.pressing()){
      r1.spin(directionType::rev, 50, percentUnits::pct);
      r2.spin(directionType::fwd, 50, percentUnits::pct);
    }
    wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  usercontrol();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
