
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H



typedef struct _controller controller;


/*Creates a controller*/
/*Return the pointer to the Controller variable created*/
controller * ini_controller();


/*Frees memory of the controller*/
/*Returns OK if everything is correct or ERROR if an error has ocurred.*/
int free_controller(controller * c);

/*Gets the button pointer whose value is Button*/
button * controller_get_button(controller * c, int Button);


/*Set joystick data*/
int controller_set_joyL_hor(controller * c, int value);
int controller_set_joyL_ver(controller * c, int value);
int controller_set_joyR_hor(controller * c, int value);
int controller_set_joyR_ver(controller * c, int value);



/*Get joystick data*/
int controller_get_joyL_hor(controller * c);
int controller_get_joyL_ver(controller * c);
int controller_get_joyR_hor(controller * c);
int controller_get_joyR_ver(controller * c);

/*Tpad functions*/
button* controller_get_tpadclick(controller * c);
button* controller_get_tpadtouch(controller * c);
/*2_integer coordinate string, NULL if error*/
int* controller_get_tpad_coord(controller * c);
/*Set function*/
int controller_set_coordinates(controller * c, int axis, int value);


#endif