#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if( fork() == 0){
		execlp("ls","ls", "..","-a",NULL);
		exit(0);
	}
	else{
		wait();
		printf("Child finish\n");
	}
}
