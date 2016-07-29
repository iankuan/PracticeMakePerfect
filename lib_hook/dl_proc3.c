#define __USE_GNU
#include <stdio.h>
/*There is no needed, example is error*/
//#include <stdlib.h> 
//#include <dlfcn.h>

extern void *__libc_dlsym( void *, const char *);

void *dlsym( void *handle, const char *symbol)
{
	printf("Ha Ha ... dlsym() Hooked\n");
	void* result = __libc_dlsym( handle, symbol);
	return result;
}
