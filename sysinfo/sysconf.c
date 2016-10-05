#include <stdio.h>
#include <unistd.h>

#define KB 1024
#define MB (1024 * KB)

int main()
{
	printf("Num of processors configured: %ld\n", sysconf(_SC_NPROCESSORS_CONF));
	printf("Num of processors online: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));

	printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
	printf("Num of pages: %ld\n", sysconf(_SC_PHYS_PAGES));
	printf("Num of available pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));
	printf("Memory size: %lld MB\n",
		(long long) sysconf(_SC_PAGESIZE) * (long long) sysconf(_SC_PHYS_PAGES) / MB);	printf("Num of max opened files: %ld\n", sysconf(_SC_OPEN_MAX));
	printf("NUM of ticks/sec: %ld\n", sysconf(_SC_CLK_TCK));
	printf("Max length of host name: %ld\n", sysconf(_SC_HOST_NAME_MAX));
	printf("Max length of login nameL %ld\n", sysconf(_SC_LOGIN_NAME_MAX));

	return 0;
}
