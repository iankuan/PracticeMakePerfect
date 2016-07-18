#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>

void *dlsym( void *handle, const char* name)
{
	void* (*dlsym_fn)( void *, const char *) = NULL;
	printf("inside shared object::before dlsym() ...\n");
	dlsym_fn = dlsym( RTLD_NEXT, "dlsym");
	printf("inside shared object::after dlsym() ...\n");
	return (*dlsym_fn)( handle, name);
}
