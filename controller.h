
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "buttons.h"


typedef struct _controller controller;


/*Creates a controller*/
/*Return the pointer to the Controller variable created*/
controller * ini_controller();


/*Frees memory of the controller*/
/*Returns OK if everything is correct or ERROR if an error has ocurred.*/
int free_controller(controller * c);

/*Gets the button pointer whose value is Button*/
button * controller_get_button(controller * c, int Button);


#endif