CC ?= gcc

CFLAGS = -std=c99 -Wall
LDFAGS =

EXEC = main
OBJ	 = myfunc.o

SRC = src
INC = include

# TEST
TEST = test.c

vpath %.c $(SRC)
#vpath %.h $(INC)

CFLAGS += -I $(INC)

all: $(EXEC)

main: main.c $(OBJ)
	@echo "TEST: S(test.c:.c=.replace)"; echo "=> "$(TEST:.c=.replace); \
	#@echo "we can use the default rule for compile. I don't write anything here, but it could work~!"
	$(CC) $(CFLAGS) $^ -o $@

# we can use it to specified the range
myfunc.o: %.o: %.c
	@echo "I use second implict rule"
	$(CC) $(CFLAGS) -c $^

%.o: %.c
	@echo "Makefile would search the rule from back to front"
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) $(EXEC) $(OBJ)
