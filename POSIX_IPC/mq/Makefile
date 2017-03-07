CC ?= gcc

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -g

EXEC = mq_send.out mq_rec.out

#Addition FLAGS
CFLAGS +=
LFLAGS =
LDFLAGS = -lrt

.PHONY: all clean

all: $(EXEC)

#$(EXEC): $(SRC)
#	$(CC) $(CFLAGS) -o $@ $^

%.out: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(EXEC) $(OBJ) *.out
