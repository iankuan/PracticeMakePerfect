#include <stdio.h>
#include <stdlib.h>
#include <socket.h>

typedef int skfd;

int main(){

 skfd _skfd;
 struct socketaddr_in servip;
 
 skfd = socket(AF_INET,SOCK_STREAM,0);
 
 servip.sin_family=AF_INET;
 servip.sin_addr.s_addr=inet_addr("127.0.0.1");
 servip.sin_port = htons(2222);/*?*/
 
 connect( _skfd, &servip, sizeof(servip));
  


 close(skfd);
}

