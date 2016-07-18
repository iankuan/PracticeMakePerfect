##hook the library function##
http://opensourceforu.com/2011/08/lets-hook-a-library-function/

It's very strange for the .so lib linking.

I first use that `gcc -shared -ldl -fPIC prog2.c -o libprog2.so`,and `ldd libprog2.so` we could find the dl link.

But after i change the order like that `gcc -shared -fPIC prog2.c -o libprog2.so -ldl` , and it works!!!

**BUG**

I follow the web code, but i get infinite loop ...

	`LD_PRELOAD=$PWD/libproc2.so ./a.out`

After I first declare the LD_PRELOAD `LD_PRELOAD=$PWD/libproc2.so`, then we can wrok with once QQ
