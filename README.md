# Stack
implementation of stack in c language, using dynamic allocation

## Use this Makefile if you dont use netbeans


	stack: main.o stack.o
	
	gcc -Wall -g main.o stack.o -o stack


	main.o: main.c stack.h
	
	gcc -Wall -g -c main.c


	stack.o: stack.c
	
	gcc -Wall -g -c stack.c


	run: stack
	
	./stack


	clean:
	
	rm *.o stack

memory:
	
	valgrind ./stack

debug:
	gdb -tui ./stack

Hope to be useful!
