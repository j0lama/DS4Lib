
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#include <linux/input.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include "ds4.h"

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENT   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"


int main()
{
	char rawdata[20], pre_data[1000], xdotool[30];
	int fd;
	int bytesReaded, x = 600, y = 400;
	DS4_CONTROLLER * ds4;
	/*IN MY CASE THE FILE IS js0*/
	if ((fd = open("/dev/input/by-id/usb-Sony_Computer_Entertainment_Wireless_Controller-joystick", O_RDONLY)) < 0) {
	    perror("evdev open");
	    return 1;
	}

	ds4 = ini_DS4();
	if(ds4 == NULL)
		return 1;

	printf("%sMOUSE CONTROL BY j0lama%s\n", GREEN, RESET);
	printf("%sYou will need xdotool to run this sample.%s\n", YELLOW, RESET);
	printf("%sUse left stick to move the mouse%s", YELLOW, RESET);
	printf("%sCROSS-> LEFT CLICK, CIRCLE->RIGHT CLICK%s\n", YELLOW, RESET);

	read(fd, rawdata, sizeof(pre_data));
	while(bytesReaded > 0) {
	    bytesReaded = read(fd, rawdata, sizeof(rawdata));
	    ds4_update_status(ds4, rawdata);
	    x += ds4_get_joyL_hor(ds4);
	    y += ds4_get_joyL_ver(ds4);
	    if(x < 0)
	    	x = 0;
	    if(y < 0)
	    	y = 0;
	    sprintf(xdotool, "xdotool mousemove %d %d", x, y);
	    system(xdotool);
	    if(button_pressed(ds4, CROSS) == PRESSED)
	    	system("xdotool click 1");
	    if(button_pressed(ds4, CIRCLE) == PRESSED)
	    	system("xdotool click 3");
	}
	printf("\nNOTE: %sDS4 was unpluged.%s\n", RED, RESET);
	free_DS4(ds4);
	close(fd);

	return 0;
}