CC = gcc
CFLAGS = -Wall -Wextra -std=c99
EXECUTABLE = main
OBJECTS = main.o matrix.o 
PKG_CFLAGS = $(shell pkg-config --cflags gtk4)
PKG_LIBS = $(shell pkg-config --libs gtk4)

##Main executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(PKG_LIBS)
 
##Main object file
MAIN_O_SRC = main.c matrix.h
main.o: $(MAIN_O_SRC)
	$(CC) $(CFLAGS) $(PKG_CFLAGS) -c main.c

MAT_SRC = matrix.c matrix.h
matrix.o: $(MAT_SRC)
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)