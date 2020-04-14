CC = gcc
CFLAGS  = -g -Wall
ECHO = echo

default: lab1

lab1:  lab1.o message.o 
	$(CC) $(CFLAGS) -o lab1 lab1.o message.o

lab1.o:  lab1.c
	$(CC) $(CFLAGS) -c lab1.c

message.o:  message.c message.h 
	$(CC) $(CFLAGS) -c message.c

clean: 	
	@$(ECHO) Removing back ups
	$(RM) count *.o *~
