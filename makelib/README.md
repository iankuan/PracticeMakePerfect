Pratice makeing LIB myself

LIB:
	.a: static lib

		gcc -c hello.c world.c
		ar rcs libmylib.a hello.o world.o

		gcc main_mylib.c libmylib.a
			or
		gcc main_mylib.c -L. -lmylib
		
	.so: shared lib

		gcc -c -fPIC hello.c world.c
		gcc -shared -Wl,-soname,libmylib.so.1 -o libmylib1.0.0 hello.o world.o
								 (L not I, lowercase)

		ln -s libmylib.so1.0.0 libmylib.so
		ln -s libmylib.so1.0.0 libmylib.so.1

		gcc main_mylib.c libmylib.so
			or
		gcc main_mylib.c -L. -lmylib

	DLL: dynamically loaded library

		#include <dlfcn.h> => dlopen() dlsym() ...

		gcc dktest,c -ldl
