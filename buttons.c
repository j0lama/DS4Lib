
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#include <stdio.h> 
#include <stdlib.h>
#include "buttons.h"

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
#define ERROR -1


struct _button
{
	int status;
	int value;
};

button * ini_button(int value)
{
	button * b = NULL;
	if(value < 0)
		return NULL;
	b = (button *)malloc(sizeof(button));
	if(b == NULL)
		return NULL;
	b->status = NO_PRESSED;
	b->value = value;
	return b;
}

int free_button(button * b)
{
	if(b == NULL)
		return ERROR;
	free(b);
	return OK;
}

int button_set_status(button * b, int status)
{
	if(b == NULL)
		return ERROR;
	b->status = status;
	return OK;
}

int button_get_status(button * b)
{
	if(b == NULL)
		return ERROR;
	return b->status;
}

int button_get_value(button * b)
{
	if(b == NULL)
		return ERROR;
	return b->value;
}