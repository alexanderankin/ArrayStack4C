CFLAGS += -g

file : file.c another.o

another.o : another.c

clean:
	find . -type f -executable -exec rm {} \;
	find . -type f -iname "*.o" -exec rm {} \;
