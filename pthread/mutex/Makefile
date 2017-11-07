CC ?= gcc

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -ggdb3 -O0
LDFLAGS = -pthread


#Addition FLAGS
CFLAGS +=
LFLAGS =

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.out: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(EXEC) $(OBJ) *.out
