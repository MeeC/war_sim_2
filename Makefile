#!/bin/bash

CC = g++
files = army.cpp functions.cpp game.cpp main.cpp map.cpp soldier.cpp
objects = army.o functions.o game.o main.o map.o soldier.o
MAIN = wargame


.PHONY: all
all: $(MAIN)
	@echo "Wargame compiled!"

$(MAIN): $(objects)
	$(CC) $(objects) -o $@

army.o		:  army.cpp globals.h functions.h army.h game.h soldier.h
			  $(CC) -c -g army.cpp


functions.o		: functions.cpp globals.h functions.h
			  $(CC) -c -g functions.cpp
			  
game.o		: game.cpp globals.h functions.h game.h
			  $(CC) -c -g game.cpp
			  
main.o		: main.cpp globals.h functions.h game.h army.h soldier.h map.h battle.h
			  $(CC) -c -g main.cpp

map.o		: map.cpp globals.h functions.h  map.h
			  $(CC) -c -g map.cpp
			  
soldier.o		: soldier.cpp globals.h functions.h  soldier.h
			  $(CC) -c -g soldier.cpp
			  
.PHONY: clean
clean:
	@echo "all object files will be deleted!"
	rm -f *.o *~ *.out
				
