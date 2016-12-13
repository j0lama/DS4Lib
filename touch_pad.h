/*****************************************/
/*         Developed by s0cKr4te5        */
/*                                       */
/*****************************************/

#ifndef TOUCH_PAD_H
#define TOUCH_PAD_H
 
 #include "buttons.h"

/*TPAD COORDINATE MACROS*/
#define NUM_AXIS 2
#define XAXIS 0
#define YAXIS 1
#define XAXIS_DEF -2
#define YAXIS_DEF -2
#define MIN_COORD 0
#define MAX_COORD 255

typedef struct _tpad touch_pad;

touch_pad * tpad_ini();

int tpad_set_coordinates(touch_pad * tpad, int axis, int value);

int tpad_get_coordinates(touch_pad * tpad, int axis);

int tpad_set_touch(touch_pad * tpad, int status);

int tpad_set_click(touch_pad * tpad, int status);

button* tpad_get_touch(touch_pad * tpad);

button* tpad_get_click(touch_pad * tpad);

void tpad_free(touch_pad * tpad);


#endif