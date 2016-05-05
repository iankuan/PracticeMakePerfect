#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

/*TODO: understand these three header files*/
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/**/

int main( int argc, char *argv[])
{
  int status;/**/
  struct addrinfo hints, *res, *p;//notice that "res" is used the double pointer
  char ipstr[ INET6_ADDRSTRLEN];

  memset( &hints, 0, sizeof( hints));/*make it be zero*/
  hints.ai_family = AF_UNSPEC;//AF_INET or AF_INET6 could be selected
  hints.ai_socktype = SOCK_STREAM;//TCP stream sockets
  hints.ai_flag = AI_PASSIVE;//automatic fill my ip

  if( (status = getaddrinfo( argv[1], NULL, &hint, &res)) != 0){
    perror("getaddrinfo");
    return 2;
  }

  printf("IP addresses for %s:\n\n", argv[1]);

  for( p = res; p != NULL; p = p->ai_next){
    void *addr;
    char *ipver;

    //Get the pointer to mine addr
    //IPv4 and IPv6 are different fields
    if( p->ai_family == AF_INET){//IPv4
      struct sockaddr_in *ipv4 = ( struct sockaddr_in *) p->ai_addr;
      addr = &( ipv4->sin_addr);
      ipver = "IPv4";
    }
    else{//IPv6
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) p->ai_addr;
      addr = &( ipv6->sin6_addr);
      ipver = "IPv6";
    }
  

  if
  
