CC = gcc
CFLAGS = -Wall -Wextra -ansi

EXE = sample_ds4_buttons sample_ds4_joysticks sample_ds4_mouse

all : $(EXE)

clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o buttons.o controller.o ds4.o