#define __USE_GNU
#include <stdio.h>

extern void * __libc_dlsym( void *, const char *);

void *dlsym( void *handle, const char *symbol)
{
	printf("change the dlsym()\n");
	void *result = __libc_dlsym( handle, symbol);
	return result;
}
