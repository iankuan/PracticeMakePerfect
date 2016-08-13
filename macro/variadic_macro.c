#include <stdio.h>


/**
 * follow GNU: https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 *	It should compile with C99
 */
#define dprintf(...) printf(__VA_ARGS__);

int main()
{
	int i = 1;
	dprintf("i = %d\n", i);
}
