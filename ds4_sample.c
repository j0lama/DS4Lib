
/*****************************************/
/*         Developed by j0lama           */
/*  Visit www.jolama.es for more details */
/*****************************************/

#include <linux/input.h>
#include <fcntl.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include "buttons.h"
#include "controller.h"
#include "ds4.h"


void print_hex_memory(void *mem) {
  int i;
  unsigned char *p = (unsigned char *)mem;
  for (i=0;i<8;i++) {
    printf("%02x ", p[i]);
  }
  printf("\n");
}


int main()
{
	char cadena[20], basura[1000];
	int fd;
	controller * c;
	if ((fd = open("/dev/input/js0", O_RDONLY)) < 0) {
	    perror("evdev open");
	    return 1;
	}

	c = ini_controller();

	read(fd, basura, sizeof(basura));
	while(1) {
	    read(fd, cadena, sizeof(cadena));
	    ds4_update_status(c, cadena);
	    ds4_print_status(c);
	    /*print_hex_memory(cadena);*/
	}

	return 0;
}