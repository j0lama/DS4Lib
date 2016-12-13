
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


int main()
{
	char rawdata[20], pre_data[1000];
	int fd;
	int bytesReaded = 1;
	DS4_CONTROLLER * ds4;
	/*IN MY CASE THE FILE IS js0*/
	if ((fd = open("/dev/input/by-id/usb-Sony_Computer_Entertainment_Wireless_Controller-joystick", O_RDONLY)) < 0) {
	    perror("evdev open");
	    return 1;
	}

	ds4 = ini_DS4();
	if(ds4 == NULL)
		return 1;

	read(fd, rawdata, sizeof(pre_data));
	while(bytesReaded > 0) {
	    bytesReaded = read(fd, rawdata, sizeof(rawdata));
	    ds4_update_status(ds4, rawdata);
	    ds4_print_buttons(ds4);
	}
	free_DS4(ds4);
	close(fd);

	return 0;
}