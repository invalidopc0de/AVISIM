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

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: avisim

avisim:  avisim.o alg_deployment1.o devicelib.o
	$(CC) $(CFLAGS) -o $@ $^

avisim.o: 
	$(CC) $(CFLAGS) -c avisim.c
    
devicelib.o:
	$(CC) $(CFLAGS) -c devicelib.c

alg_deployment1.o:
	$(CC) $(CFLAGS) -c alg_deployment1.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) count *.o *~
