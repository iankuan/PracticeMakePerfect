#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>


FILE* fopen( const char* fname, const char* mode)
{
	printf("fname = %s, mode = %s\n", fname, mode);

	FILE* (* fopen_fn)( const char*, const char*) = NULL;
	printf("Create the fopen_fn function pointer\n");
	fopen_fn = dlsym( RTLD_NEXT, "dlsym");
	printf("Return the fopen_fn function pointer\n");

	return ( *fopen)( fname, mode);
}
