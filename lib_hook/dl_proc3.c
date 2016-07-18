#define __USE_GNU
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern void *__libc_dlsym( void *, const char *);

void *dlsym( void *handle, const char *symbol)
{
	printf("Ha Ha ... dlsym() Hooked\n");
	void* result = __libc_dlsym( handle, symbol);
	return result;
}
