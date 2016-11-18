
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct _button button;



/*Creates a new button with value as value*/
/*Return the pointer to the Button variable created*/
button * ini_button(int value);


/*Frees memory of the button*/
/*Returns OK if everything is correct or ERROR if an error has ocurred.*/
int free_button(button * b);


/*Sets if the button b is pressed or not*/
/*Returns OK if everything is correct or ERROR if an error has ocurred.*/
int button_set_status(button * b, int status);


/*Gets if the button b is pressed or not*/
/*Returns the status of or ERRORifndef */
int button_get_status(button * b);


/*Gets the button b value*/
/*Returns the value of b or ERROR*/
int button_get_value(button * b);



#endif


