CC ?= gcc

CFLAGS = -std=c99 -Wall
LDFAGS =

EXEC = main
OBJ	 = myfunc.o

vpath %.c src
#vpath %.h include

INC = include

CFLAGS += -I $(INC)

all: $(EXEC)

main: main.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) $(EXEC) $(OBJ)
