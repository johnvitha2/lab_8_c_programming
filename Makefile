all: task1 task2
task1: task1.o
	$(CC) task1.o -o $@
task2: task2.o
	$(CC) task2.o -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: clean
clean:
	rm -f *.o prog1 prog2