CC=g++
CFLAGS=-c -Wall

all:testDemo
testDemo:student.o
	$(CC) student.o -o testDemo
stud.o:student.cpp
	$(CC) $(CFLAGS) student.cpp head.h
	
clean:
	rm -f *.o		
