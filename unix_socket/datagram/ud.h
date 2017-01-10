#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

#include "debug.h"

#define BUF_SIZE 10

#define UN_SOCK_PATH "/tmp/ud_udp"
