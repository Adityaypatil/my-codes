CC=g++
CFLAGS=-c -Wall

all:testDemo
testDemo:main.o func.o 
	$(CC) main.o func.o -o testDemo
main.o:main.cpp
	$(CC) $(CFLAGS) main.cpp header.h
functions.o:functions.cpp
	$(CC) $(CFLAGS)	func.cpp header.h
	
clean:
	rm -rf *~ o~		
