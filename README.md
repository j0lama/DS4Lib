# DS4Lib 0.5
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

This version
-----------
DS4Lib 0.5 supports all buttons except Joysticks positions and touchPAD tracking.

In future versions DS4Lib will include tracking of Joysticks and touchPAD and gyroscope/accelerometer values in real time.

Changelog
---------
DS4Lib 0.5: Initial release.

- Tracking of all buttons.



