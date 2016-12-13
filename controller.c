
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "buttons.h"
#include "controller.h"
#include "touch_pad.h"
#include "ds4.h"


/*Positions of common buttons in the array of the struct*/
#define BUTTONS_NUMBER 11
#define SQUARE_POS 0
#define CROSS_POS 1
#define CIRCLE_POS 2
#define TRIANGLE_POS 3
#define L1_POS 4
#define R1_POS 5
#define SHARE_POS 6
#define OPTIONS_POS 7
#define L3_POS 8
#define R3_POS 9
#define PSN_POS 10
/*Positions of DPAD in the array of the struct*/
#define UP_POS 0
#define DOWN_POS 1
#define LEFT_POS 2
#define RIGHT_POS 3
/*Positions of triggers in the array of the struct*/
#define L2_POS 0
#define R2_POS 1

struct _controller
{
	button * buttons[BUTTONS_NUMBER];
	button * dpad[4];
	button * trigger[2];
	button * joystickL[2]; /*0 -> X, 1 -> Y*/
	button * joystickR[2]; /*0 -> X, 1 -> Y*/
	touch_pad * tpad;
};

controller * ini_controller()
{
	controller * c;
	c = (controller *)malloc(sizeof(controller));
	/*Common buttons*/
	c->buttons[SQUARE_POS] = ini_button(SQUARE);
	c->buttons[CROSS_POS] = ini_button(CROSS);
	c->buttons[CIRCLE_POS] = ini_button(CIRCLE);
	c->buttons[TRIANGLE_POS] = ini_button(TRIANGLE);
	c->buttons[L1_POS] = ini_button(L1);
	c->buttons[R1_POS] = ini_button(R1);
	c->buttons[SHARE_POS] = ini_button(SHARE);
	c->buttons[OPTIONS_POS] = ini_button(OPTIONS);
	c->buttons[L3_POS] = ini_button(L3);
	c->buttons[R3_POS] = ini_button(R3);
	c->buttons[PSN_POS] = ini_button(PSN);

	/*Dpad*/
	c->dpad[UP_POS] = ini_button(UP);
	c->dpad[DOWN_POS] = ini_button(DOWN);
	c->dpad[LEFT_POS] = ini_button(LEFT);
	c->dpad[RIGHT_POS] = ini_button(RIGHT);

	c->trigger[L2_POS] = ini_button(L2);
	c->trigger[R2_POS] = ini_button(R2);

	c->joystickL[0] = ini_button(40);
	c->joystickL[1] = ini_button(41);

	c->joystickR[0] = ini_button(50);
	c->joystickR[1] = ini_button(51);

	/*TOUCHPAD*/
	if(!(c->tpad = tpad_ini())){
		return NULL;
	}


	return c;
}

int free_controller(controller * c)
{
	int i;
	if(c == NULL)
		return ERROR;
	for(i = 0; i < BUTTONS_NUMBER; i++)
	{
		free_button(c->buttons[i]);
	}
	for(i = 0; i < 4; i++)
	{
		free_button(c->dpad[i]);
	}
	for(i = 0; i < 2; i++)
	{
		free_button(c->trigger[i]);
	}
	for(i = 0; i < 2; i++)
	{
		free_button(c->joystickL[i]);
	}
	for(i = 0; i < 2; i++)
	{
		free_button(c->joystickR[i]);
	}
	tpad_free(c->tpad);
	free(c);
	return OK;
}


button * controller_get_button(controller * c, int Button)
{
	int pos;
	if(c == NULL)
		return NULL;
	if(Button < 20)
	{
		if(Button == SQUARE)
			pos = SQUARE_POS;
		else if(Button == CROSS)
			pos = CROSS_POS;
		else if(Button == CIRCLE)
			pos = CIRCLE_POS;
		else if(Button == TRIANGLE)
			pos = TRIANGLE_POS;
		else if(Button == L1)
			pos = L1_POS;
		else if(Button == R1)
			pos = R1_POS;
		else if(Button == SHARE)
			pos = SHARE_POS;
		else if(Button == OPTIONS)
			pos = OPTIONS_POS;
		else if(Button == L3)
			pos = L3_POS;
		else if(Button == R3)
			pos = R3_POS;
		else if(Button == PSN)
			pos = PSN_POS;
		else
			return NULL;
		return c->buttons[pos];
	}
	else if(Button < 25)
	{
		if(Button == UP)
			pos = UP_POS;
		else if(Button == DOWN)
			pos = DOWN_POS;
		else if(Button == LEFT)
			pos = LEFT_POS;
		else if(Button == RIGHT)
			pos = RIGHT_POS;
		else
			return NULL;
		return c->dpad[pos];
	}
	if(Button == L2)
		pos = L2_POS;
	else if(Button == R2)
		pos = R2_POS;
	else if (Button == TPAD_TOUCH){
		return controller_get_tpadtouch(c);
	}
	else if (Button == TPAD_CLICK){
		return controller_get_tpadclick(c);
	}
	else{
		return NULL;
	}

	return c->trigger[pos];

}

/**************************************************
CONTROLLER FUNCTIONS
***************************************************/
button* controller_get_tpadclick(controller * c){
	if(c == NULL){
		return NULL;
	}
	return tpad_get_click(c->tpad);
}

button* controller_get_tpadtouch(controller * c){
	if(c == NULL){
		return NULL;
	}
	return tpad_get_touch(c->tpad);

}



int controller_set_joyL_hor(controller * c, int value)
{
	if(c == NULL)
		return ERROR;
	button_set_status(c->joystickL[0], value);
	return OK;
}

int controller_set_joyL_ver(controller * c, int value)
{
	if(c == NULL)
		return ERROR;
	button_set_status(c->joystickL[1], value);
	return OK;
}


int controller_set_joyR_hor(controller * c, int value)
{
	if(c == NULL)
		return ERROR;
	button_set_status(c->joystickR[0], value);
	return OK;
}

int controller_set_joyR_ver(controller * c, int value)
{
	if(c == NULL)
		return ERROR;
	button_set_status(c->joystickR[1], value);
	return OK;
}




int controller_get_joyL_hor(controller * c)
{
	if(c == NULL)
		return ERROR;
	return button_get_status(c->joystickL[0]);
}

int controller_get_joyL_ver(controller * c)
{
	if(c == NULL)
		return ERROR;
	return button_get_status(c->joystickL[1]);
}


int controller_get_joyR_hor(controller * c)
{
	if(c == NULL)
		return ERROR;
	return button_get_status(c->joystickR[0]);
}

int controller_get_joyR_ver(controller * c)
{
	if(c == NULL)
		return ERROR;
	return button_get_status(c->joystickR[1]);
}

int* controller_get_tpad_coord(controller * c){
	int * coord=NULL;
	if(c == NULL){
		return NULL;
	}
	coord = (int*) calloc(2,sizeof(int));
	if(coord == NULL){
		return NULL;
	} 
	coord[XAXIS]= tpad_get_coordinates(c->tpad,XAXIS);
	coord[YAXIS]= tpad_get_coordinates(c->tpad,YAXIS);

	return coord;
}

int controller_set_coordinates(controller * c, int axis, int value){
	if (c==NULL || (axis != XAXIS && axis != YAXIS) || value > MAX_COORD || value < MIN_COORD){
		return ERROR;
	}
	return tpad_set_coordinates(c->tpad,axis,value);

}
