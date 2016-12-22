CC ?= gcc

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -g
LDFLAGS =


#Addition FLAGS
CFLAGS +=
LFLAGS =

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.out: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXEC) $(OBJ) *.out
