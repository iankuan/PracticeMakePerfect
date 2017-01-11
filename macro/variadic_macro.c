#include <stdio.h>


/**
 * follow GNU: https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 *	It should compile with C99
 */
#define dprintf(...) printf(__VA_ARGS__);
#define dprintf1(str,...) printf(str __VA_ARGS__);
#define dprintf1(str,...) printf(str __VA_ARGS__);
#define vprintf( arg, ...) fprintf( arg,__VA_ARGS__);

#define func(num,...) __VA_ARGS__(num)

int db(int i) { return i * 2;}

int main()
{
	int i = 1;
	dprintf("Without Any Argument\n");
	dprintf("i = %d\n", i);
	dprintf1("only str no var args\n");

	printf("test func(num,...) = %d\n", func(10, db));

	vprintf( stderr, "i = %d\n", i);
}
