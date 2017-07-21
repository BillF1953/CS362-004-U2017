CC = gcc

CFLAGS = -g -Wall -std=c90

all : tests prog

prog : main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c

clean :
	-rm *.o
	-rm prog
