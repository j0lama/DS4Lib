CC = gcc
CFLAGS = -Wall -Wextra -ansi

EXE = ds4_buttons_demo ds4_joysticks_demo

all : $(EXE)

clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o buttons.o controller.o ds4.o