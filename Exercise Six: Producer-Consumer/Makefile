#Liliana O'Sullivan 17/10/2020

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: 
	$(CC) -o main main.cpp Semaphore.cpp SafeBuffer.cpp $(CFLAGS) $(DEBUGFLAGS)

DOXY:
	doxygen Doxyfile

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
