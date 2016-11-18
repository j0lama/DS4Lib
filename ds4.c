
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "buttons.h"
#include "controller.h"
#include "ds4.h"
/*Colors*/
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENT   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

/*DPAD VALUES*/
#define HORIZ_L_1 1
#define HORIZ_L_2 128
#define HORIZ_R_1 255
#define HORIZ_R_2 127
#define VERT_U_1 1
#define VERT_U_2 128
#define VERT_D_1 255
#define VERT_D_2 127
/*Triggers values*/
#define TRIG_1 128
#define TRIG_2 144
#define TRIG_3 160
#define TRIG_4 176
#define TRIG_5 192
#define TRIG_6 208
#define TRIG_7 224
#define TRIG_8 240
#define TRIG_9 16
#define TRIG_10 32
#define TRIG_11 48
#define TRIG_12 64
#define TRIG_13 80
#define TRIG_14 96
#define TRIG_15 112

struct _DS4_CONTROLLER
{
	controller * c;
};

DS4_CONTROLLER * ini_DS4()
{
	DS4_CONTROLLER * ds4;
	ds4 = (DS4_CONTROLLER *)malloc(sizeof(DS4_CONTROLLER));
	if(ds4 == NULL)
		return NULL;
	ds4->c = ini_controller();
	if(ds4->c == NULL)
	{
		free(ds4);
		return NULL;
	}
	return ds4;
}

int free_DS4(DS4_CONTROLLER * ds4)
{
	if(ds4 == NULL)
		return ERROR;
	free_controller(ds4->c);
	free(ds4);
	return OK;
}


int button_pressed(DS4_CONTROLLER * ds4, int Button)
{
	button * b;
	controller * c;
	if(ds4 == NULL)
		return ERROR;
	c = ds4->c;
	if(c == NULL)
		return ERROR;
	b = controller_get_button(c, Button);
	if(b == NULL)
		return ERROR;
	return button_get_status(b);
}

int ds4_update_status(DS4_CONTROLLER * ds4, char * data)
{
	button * b;
	controller * c;
	if(ds4 == NULL)
		return ERROR;
	c = ds4->c;
	int button_value, status, type; /*type 1 = common button; type 2 = dpad and other*/
	unsigned char *rawdata = (unsigned char *)data;
	unsigned int trigger, dpad_value1, dpad_value2;
	if(c == NULL || rawdata == NULL)
	{
		return ERROR;
	}
	
	type = rawdata[6];
	if(type == 1)/*Common button case*/
	{
		status = rawdata[4];
		button_value = rawdata[7];
		b = controller_get_button(c, button_value);
		if(b == NULL)
			return ERROR;
		button_set_status(b, status);
	}
	else if(type == 2)
	{
		button_value = rawdata[7];
		if(button_value == 6) /*DPAD HORIZONTAL LINE*/
		{
			dpad_value1 = rawdata[4];
			dpad_value2 = rawdata[5];
			if(dpad_value1 == HORIZ_L_1 && dpad_value2 == HORIZ_L_2) /*LEFT*/
			{
				b = controller_get_button(c, LEFT);
				if(b == NULL)
					return ERROR;
				button_set_status(b, PRESSED);
			}
			else if(dpad_value1 == HORIZ_R_1 && dpad_value2 == HORIZ_R_2) /*RIGHT*/
			{
				b = controller_get_button(c, RIGHT);
				if(b == NULL)
					return ERROR;
				button_set_status(b, PRESSED);
			}
			else
			{
				/*LEFT NO PRESSED*/
				b = controller_get_button(c, LEFT);
				if(b == NULL)
					return ERROR;
				button_set_status(b, NO_PRESSED);

				/*RIGHT NO PRESSED*/
				b = controller_get_button(c, RIGHT);
				if(b == NULL)
					return ERROR;
				button_set_status(b, NO_PRESSED);
			}
		}
		else if(button_value == 7) /*DPAD VERTICAL LINE*/
		{
			dpad_value1 = rawdata[4];
			dpad_value2 = rawdata[5];
			if(dpad_value1 == VERT_U_1 && dpad_value2 == VERT_U_2) /*UP*/
			{
				b = controller_get_button(c, UP);
				if(b == NULL)
					return ERROR;
				button_set_status(b, PRESSED);
			}
			else if(dpad_value1 == VERT_D_1 && dpad_value2 == VERT_D_2) /*DOWN*/
			{
				b = controller_get_button(c, DOWN);
				if(b == NULL)
					return ERROR;
				button_set_status(b, PRESSED);
			}
			else
			{
				/*UP NO PRESSED*/
				b = controller_get_button(c, UP);
				if(b == NULL)
					return ERROR;
				button_set_status(b, NO_PRESSED);

				/*DOWN NO PRESSED*/
				b = controller_get_button(c, DOWN);
				if(b == NULL)
					return ERROR;
				button_set_status(b, NO_PRESSED);
			}
		}
		else if(button_value == 3) /*L2*/
		{
			trigger = rawdata[5];
			if(trigger < (unsigned int)TRIG_9)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 8);
			}
			else if(trigger < (unsigned int)TRIG_10)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 9);
			}
			else if(trigger < (unsigned int)TRIG_11)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 10);
			}
			else if(trigger < (unsigned int)TRIG_12)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 11);
			}
			else if(trigger < (unsigned int)TRIG_13)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 12);
			}
			else if(trigger < (unsigned int)TRIG_14)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 13);
			}
			else if(trigger < (unsigned int)TRIG_15)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 14);
			}
			else if(trigger < TRIG_1)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 15);
			}
			else if(trigger < TRIG_2)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 1);
			}
			else if(trigger < TRIG_3)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 2);
			}
			else if(trigger < TRIG_4)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 3);
			}
			else if(trigger < TRIG_5)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 4);
			}
			else if(trigger < TRIG_6)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 5);
			}
			else if(trigger < TRIG_7)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 6);
			}
			else if(trigger < TRIG_8)
			{
				b = controller_get_button(c, L2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 7);
			}
		}
		else if(button_value == 4) /*R2*/
		{
			trigger = rawdata[5];
			if(trigger < (unsigned int)TRIG_9)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 8);
			}
			else if(trigger < (unsigned int)TRIG_10)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 9);
			}
			else if(trigger < (unsigned int)TRIG_11)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 10);
			}
			else if(trigger < (unsigned int)TRIG_12)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 11);
			}
			else if(trigger < (unsigned int)TRIG_13)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 12);
			}
			else if(trigger < (unsigned int)TRIG_14)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 13);
			}
			else if(trigger < (unsigned int)TRIG_15)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 14);
			}
			else if(trigger < TRIG_1)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 15);
			}
			else if(trigger < TRIG_2)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 1);
			}
			else if(trigger < TRIG_3)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 2);
			}
			else if(trigger < TRIG_4)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 3);
			}
			else if(trigger < TRIG_5)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 4);
			}
			else if(trigger < TRIG_6)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 5);
			}
			else if(trigger < TRIG_7)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 6);
			}
			else if(trigger < TRIG_8)
			{
				b = controller_get_button(c, R2);
				if(b == NULL)
					return ERROR;
				button_set_status(b, 7);
			}
		}
	}
	return 0;


}

int ds4_print_status(DS4_CONTROLLER * ds4)
{
	char barL2[20], barR2[20];
	int i;
	if(ds4 == NULL)
		return ERROR;
	system("clear");
	printf("PS4 CONTROLLER LIBRARY DEVELOPED BY %sJON LARREA%s\n", YELLOW, RESET);
	printf("ACTION BUTTONS:\n");
	if(button_pressed(ds4, CROSS) == PRESSED)
	{
		printf("      CROSS %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      CROSS %sNOT PRESSED%s\n", RED, RESET);

	if(button_pressed(ds4, SQUARE) == PRESSED)
	{
		printf("      SQUARE %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      SQUARE %sNOT PRESSED%s\n", RED, RESET);

	if(button_pressed(ds4, CIRCLE) == PRESSED)
	{
		printf("      CIRCLE %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      CIRCLE %sNOT PRESSED%s\n", RED, RESET);

	if(button_pressed(ds4, TRIANGLE) == PRESSED)
	{
		printf("      TRIANGLE %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      TRIANGLE %sNOT PRESSED%s\n", RED, RESET);

	printf("\nL AND R BUTTONS:\n");
	if(button_pressed(ds4, L1) == PRESSED)
	{
		printf("      L1 %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      L1 %sNOT PRESSED%s\n", RED, RESET);
	
	if(button_pressed(ds4, R1) == PRESSED)
	{
		printf("      R1 %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      R1 %sNOT PRESSED%s\n", RED, RESET);

	for(i = 0; i < 20; i++)
	{
		barL2[i] = '\0';
	}
	for(i = 0; i < button_pressed(ds4, L2); i++)
	{
		barL2[i] = '*';
	}
	barR2[i + 1] = '\0';

	printf("      L2 %s%s%s\n", GREEN,barL2, RESET);

	for(i = 0; i < 20; i++)
	{
		barR2[i] = '\0';
	}
	for(i = 0; i < button_pressed(ds4, R2); i++)
	{
		barR2[i] = '*';
	}
	barR2[i + 1] = '\0';

	printf("      R2 %s%s%s\n", GREEN,barR2, RESET);

	if(button_pressed(ds4, L3) == PRESSED)
	{
		printf("      L3 %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      L3 %sNOT PRESSED%s\n", RED, RESET);

	if(button_pressed(ds4, R3) == PRESSED)
	{
		printf("      R3 %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      R3 %sNOT PRESSED%s\n", RED, RESET);

	printf("\nSPECIAL BUTTONS:\n");
	if(button_pressed(ds4, SHARE) == PRESSED)
	{
		printf("      SHARE %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      SHARE %sNOT PRESSED%s\n", RED, RESET);
	if(button_pressed(ds4, OPTIONS) == PRESSED)
	{
		printf("      OPTIONS %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      OPTIONS %sNOT PRESSED%s\n", RED, RESET);
	if(button_pressed(ds4, PSN) == PRESSED)
	{
		printf("      PSN %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      PSN %sNOT PRESSED%s\n", RED, RESET);


	printf("\nDPAD:\n");
	if(button_pressed(ds4, UP) == PRESSED)
	{
		printf("      UP %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      UP %sNOT PRESSED%s\n", RED, RESET);
	if(button_pressed(ds4, DOWN) == PRESSED)
	{
		printf("      DOWN %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      DOWN %sNOT PRESSED%s\n", RED, RESET);
	if(button_pressed(ds4, LEFT) == PRESSED)
	{
		printf("      LEFT %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      LEFT %sNOT PRESSED%s\n", RED, RESET);
	if(button_pressed(ds4, RIGHT) == PRESSED)
	{
		printf("      RIGHT %sPRESSED%s\n", GREEN, RESET);
	}
	else
		printf("      RIGHT %sNOT PRESSED%s\n", RED, RESET);

	return OK;
}