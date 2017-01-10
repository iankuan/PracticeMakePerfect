CC ?= gcc

SRC = ud_udp_server.c ud_udp_client.c
EXEC = $(patsubst %.c, %.out, $(SRC))

INC =
LIB = 
CFLAGS = -std=gnu99 -Wall -g
LDFLAGS =


#Addition FLAGS
CFLAGS +=
LFLAGS =

.PHONY: all clean

all: $(EXEC)

#$(EXEC): $(SRC)
#	$(CC) $(CFLAGS) -o $@ $^

%.out: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXEC) $(OBJ) *.out
