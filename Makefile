CFLAGS += -g
.PHONY : test

test : test_runner
	./test_runner

test_runner : test_runner.c stack_array.o

stack_array.o : stack_array.c

clean:
	find . -type f -executable -exec rm {} \;
	find . -type f -iname "*.o" -exec rm {} \;
