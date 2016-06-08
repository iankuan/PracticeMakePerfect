CC = gcc

CFLAGS= -g -Wall
LDFLAGS=\
	-lmysqlclient
INC_PATH= -I /usr/include/mysql
LIB_PATH=


RMF= show_version

%.out: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(INC_PATH)

show_version: show_client_ver.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(INC_PATH)

clean:
	$(RM) -f $(RMF) *.out
