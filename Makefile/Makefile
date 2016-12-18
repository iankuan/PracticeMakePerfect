CC ?= gcc

CFLAGS = -std=c99 -Wall
LDFAGS =

EXEC = main
OBJ	 = myfunc.o

SRC = src
INC = include

# TEST
TEST = test.c
LIST = c b a

vpath %.c $(SRC)
#vpath %.h $(INC)

CFLAGS += -I $(INC)


COMM = command
.PHONY: $(COMM)

include command.rule

# Specified Rule
myfunc.o: CFLAGS += -g3
main: CFLAGS += -g

all: $(EXEC) $(COMM)

$(COMM):
	@$(call newdir);
	@echo "(sort c b a) =>$(sort $(LIST))"; 
	@echo "(shell ls) =>$(shell ls)";
	@echo "(strip (LIST)) =>$(strip LIST)";
	@echo "TEST: S(test.c:.c=.replace) =>$(TEST:.c=.replace)";
	@echo "(patsubst %.c,%._patsubst,(TEST)) =>$(patsubst %.c,%._patsubst,$(TEST))";
	@echo "(filiter a,(LIST)) =>$(filter a,$(LIST)))";
	@echo "(filiter-out a,(LIST)) =>$(filter-out a,$(LIST)))";
	@echo "(wildcard src/*.c) =>$(wildcard src/*.c)";
	$(if $(filter $(MAKE_VERSION),4.0), $(warning WARNIGN version is truely 4.0 haha), $(error version not 4.0))

main: main.c $(OBJ)
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
	$(RM) -rf $(EXEC) $(OBJ) tmp
