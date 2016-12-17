CC ?= gcc
CPP ?= g++

OBJ =
EXEC = gdb_test
SRC = gdb_test.c

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -g
LFLAGS =


#Addition FLAGS
CFLAGS +=
LFLAGS =

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(EXEC) $(OBJ)
