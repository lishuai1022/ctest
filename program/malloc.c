#include "common.h"

int main(int argc, char const *argv[])
{
	int *p;
	p = (int *)malloc(sizeof(int) * 10);
	printf("%p\n", p);
	free(p);
	return 0;
}