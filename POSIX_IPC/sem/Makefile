CC ?= gcc

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -g

EXEC = named_semaphone_test.out semaphone_test.out  test.out  test_trywait.out

#Addition FLAGS
CFLAGS +=
LFLAGS =
LDFLAGS = -pthread

.PHONY: all clean

all: $(EXEC)

#$(EXEC): $(SRC)
#	$(CC) $(CFLAGS) -o $@ $^

%.out: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(EXEC) $(OBJ) *.out
