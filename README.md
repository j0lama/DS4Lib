# DS4Lib 1.0
Introduction
-------------

This is a simple Linux library written to control the Dualshock 4 through USB.

This library reads the data from a temporal file created in /dev/input/ when you plug in the DS4.

Functions
-----------
All functions are in ds4.h.

Include this file to your proyect to be able to use DS4Lib.

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

- *int* ds4_get_tpad_coord(DS4_CONTROLLER * ds4);*

This version
-----------
DS4Lib 1.0 adds touchpad tracking. You can get the status of the new pressable buttons (TPAD_CLICK, TPAD_TOUCH) declared in buttons with the usual button_pressed() function. You can also retrieve the coordinates of your finger on the touchpad with 
the new **'ds4_get_tpad_coord(DS4_CONTROLLER * ds4)'** function.

          x-axis         
  0_ _ _ _ _ _ _ _ _ _ _ _255
  
  y|_ _ _ _ _ _ _ _ _ _ _|
  
  -|_ _ _ _ _ _ _ _ _ _ _|
  
  a|_ _ _ _ _ _ _ _ _ _ _|
  
  x|_ _ _ _ _ _ _ _ _ _ _|
  
  i|_ _ _ _ _ _ _ _ _ _ _|
  
  s|_ _ _ _ _ _ _ _ _ _ _|
  
255_ _ _ _ _ _ _ _ _ _ _ _


In future versions DS4Lib will include tracking of touchPAD and gyroscope/accelerometer values in real time.

Changelog
---------
DS4Lib 1.0: Add Touchpoad tracking


DS4Lib 0.9: Add Joystick tracking.

- Tracking of all buttons and Joysticks.


DS4Lib 0.5: Initial release.

- Tracking of all buttons.


Contributors
----------

j0lama: Buttons and Joysticks tracking. 

s0cKrate5: TouchPAD tracking.
