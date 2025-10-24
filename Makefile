CC=gcc # C compiler
CFLAGS = -Wall -Wextra -std=c11 -O2 # Compiler flags
all: prog # Build the program
prog: main.o isEven.o isOdd.o # Link files into prog
	$(CC) main.o isEven.o isOdd.o -o prog
task1.o: task1.c # Compile task1.c
	$(CC) $(CFLAGS) -c task1.c -o task1.o 
task2.o: task2.c  # Compile task2.c
	$(CC) $(CFLAGS) -c task2.c -o task2.o
.PHONY: clean # Always run 'clean' as a command even if there is a file named 'clean'
clean: # Delete compiled files
	rm -f *.o prog

