
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#ifndef DS4_H
#define DS4_H

#include "buttons.h"
#include "controller.h"

/*Buttons*/
#define SQUARE 0
#define CROSS 1
#define CIRCLE 2
#define TRIANGLE 3
#define L1 4
#define R1 5
#define SHARE 8
#define OPTIONS 9
#define L3 10
#define R3 11
#define PSN 12
#define UP 21
#define DOWN 22
#define LEFT 23
#define RIGHT 24
#define L2 30
#define R2 31
/*Common button status*/
#define PRESSED 1
#define NO_PRESSED 0

#define OK 0
#define ERROR -10

typedef struct _DS4_CONTROLLER DS4_CONTROLLER;

/*Allocs memory for a DS4_CONTROLLER struct and initializes it*/
DS4_CONTROLLER * ini_DS4();

/*Frees the memory of DS4_CONTROLLER*/
int free_DS4(DS4_CONTROLLER * ds4);

/*Returns PRESSED or NO_PRESSED in case of common button o in case of button with variable states returns the current state*/
int button_pressed(DS4_CONTROLLER * ds4, int Button);


/*With this functions you can get the joysticks axes positions*/
int ds4_get_joyL_hor(DS4_CONTROLLER * ds4);
int ds4_get_joyL_ver(DS4_CONTROLLER * ds4);
int ds4_get_joyR_hor(DS4_CONTROLLER * ds4);
int ds4_get_joyR_ver(DS4_CONTROLLER * ds4);

/*Updates the current status of all buttons through the string rawdata*/
int ds4_update_status(DS4_CONTROLLER * ds4, char * data);

/*Prints the current values of the DS4 Controller Buttons*/
int ds4_print_buttons(DS4_CONTROLLER * ds4);

/*Prints the current values of the DS4 Controller Joysticks*/
int ds4_print_joysticks(DS4_CONTROLLER * ds4);


#endif