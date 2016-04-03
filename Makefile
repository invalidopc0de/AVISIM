#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall
LDFLAGS = 
SRC=avisim.c devicelib.c alg_deployment1.c cJSON/cJSON.c
OBJ=$(SRC:.c=.o)
EXE=avisim

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: $(SRC) $(EXE)

$(EXE): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $@ -lm 

*.c.o:
	$(CC) $(CFLAGS) $< -o $@

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) count *.o *~
