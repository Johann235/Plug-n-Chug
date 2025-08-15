CC = gcc
CFLAGS = -Wall -Wextra -std=c99
EXECUTABLE = main
OBJECTS = main.o matrix.o 

##Main executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

##Main object file
MAIN_O_SRC = main.c matrix.h
main.o: $(MAIN_O_SRC)
	$(CC) $(CFLAGS) -c main.c

MAT_SRC = matrix.c matrix.h
matrix.o: $(MAT_SRC)
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)