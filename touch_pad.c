/*****************************************/
/*         Developed by s0cKr4te5        */
/*                                       */
/*****************************************/
/*TOUCHPAD DIMENSIONS: 52 x 23*/

/**************************/
/*SIMPLE PRECISION FOR NOW*/
/**************************/
/*Value must be between 1 & 256*/
#include <stdio.h> 
#include <stdlib.h>
#include "ds4.h"
#include "touch_pad.h"
#include "buttons.h"


struct _tpad
{
	button * tpad_click;
	button * tpad_touch;
	int coord[NUM_AXIS]; /*Las coordenadas van a ser traducidas a x(0-256), y(0-256) y el (0,0) estará en la esquina superior izquierda*/
};

touch_pad * tpad_ini(){
	touch_pad * tpad=NULL;

	tpad = (touch_pad*) calloc(1,sizeof(touch_pad));

	if(!tpad){
		return NULL;
	}

	tpad->tpad_click = ini_button(TPAD_CLICK);
	if(!tpad->tpad_click){
		free(tpad);
		return NULL;
	}
	tpad->tpad_touch = ini_button(TPAD_TOUCH);
	if(!tpad->tpad_touch){
		free_button(tpad->tpad_click);
		free(tpad);
		return NULL;
	}

	tpad->coord[XAXIS]= XAXIS_DEF;
	tpad->coord[YAXIS]= YAXIS_DEF;

	return tpad;
}

int tpad_set_coordinates(touch_pad * tpad, int axis, int value){
	
	if(!tpad){
		return ERROR;
	}

	if((axis != XAXIS && axis != YAXIS) || value > MAX_COORD || value < MIN_COORD){
		return ERROR;
	}
	
	switch(axis){
		case XAXIS:
		tpad->coord[XAXIS]= value;
		break;
		case YAXIS:
		tpad->coord[YAXIS]= value;
		break;
		default:
		return ERROR;
		break;
	}

	return OK;
}

int tpad_get_coordinates(touch_pad * tpad, int axis){
	if(!tpad){
		return ERROR;
	}

	if(axis != XAXIS && axis != YAXIS){
		return ERROR;
	}

	switch(axis){
		case XAXIS:
		return tpad->coord[XAXIS];
		break;
		case YAXIS:
		return tpad->coord[YAXIS];
		break;
		default:
		return ERROR;
		break;
	}
	return ERROR;
}

int tpad_set_touch(touch_pad * tpad, int status){
	if(tpad == NULL|| (status!= PRESSED && status!= NO_PRESSED)){
		return ERROR;
	}
	button_set_status(tpad->tpad_touch,status);
	return OK;
}

int tpad_set_click(touch_pad * tpad, int status){
	if(tpad == NULL|| (status!= PRESSED && status!= NO_PRESSED)){
		return ERROR;
	}
	button_set_status(tpad->tpad_click,status);
	return OK;
}

button* tpad_get_touch(touch_pad * tpad){
	if(tpad == NULL){
		return NULL;
	}
	return tpad->tpad_touch;
}

button* tpad_get_click(touch_pad * tpad){
	if(tpad == NULL){
		return NULL;
	}
	return tpad->tpad_click;
}

void tpad_free(touch_pad * tpad){
	if(tpad == NULL){
		return;
	}

	free_button(tpad->tpad_touch);
	free_button(tpad->tpad_click);
	free(tpad);

	return;
}