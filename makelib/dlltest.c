#include <dlfcn.h>
#include <stdio.h>

int main()
{
	void *handle;
	void (*func)();
	char *error;

	/*handle the .so*/
	handle = dlopen("./libmylib.so", RTLD_LAZY);
	
	if( !handle)
	{
		fputs( dlerror(), stderr);
		exit(1);
	}

	/*get the address of func*/
	func = dlsym( handle, "hello");
	if( ( error = dlerror()) != NULL)
	{
		fputs( error, stderr);
		exit(1);
	}

	func();
	dlclose( handle);
}
