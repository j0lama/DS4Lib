# DS4Lib 0.9
Introduction
-------------

This is a simple Linux library writted to control the Dualshock 4 through USB.

This library read the data from a temporal file created in /dev/input/ when you plug the DS4.

Functions
-----------
All functions are in ds4.h.

Include this file to your proyect to can use DS4Lib.

  **Functions:**
  
- *DS4_CONTROLLER * ini_DS4();*

- *int free_DS4(DS4_CONTROLLER * ds4);*

- *int button_pressed(DS4_CONTROLLER * ds4, int Button);*

- *int ds4_update_status(DS4_CONTROLLER * ds4, char * data);*

- *int ds4_print_status(DS4_CONTROLLER * ds4);*

- *int ds4_get_joyL_hor(DS4_CONTROLLER * ds4);*
- *int ds4_get_joyL_ver(DS4_CONTROLLER * ds4);*
- *int ds4_get_joyR_hor(DS4_CONTROLLER * ds4);*
- *int ds4_get_joyR_ver(DS4_CONTROLLER * ds4);*

This version
-----------
DS4Lib 0.9 adds Joysticks tracking. You can get the value of Joysticks axises. 

In future versions DS4Lib will include tracking of touchPAD and gyroscope/accelerometer values in real time.

Changelog
---------
DS4Lib 0.9: Add Joystick tracking.

- Tracking of all buttons and Joysticks.


DS4Lib 0.5: Initial release.

- Tracking of all buttons.


Contributors
----------

j0lama: Buttons and Joysticks traking.

s0cKr4te5: Working in TouchPAD tracking.
