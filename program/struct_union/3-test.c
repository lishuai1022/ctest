#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("%d\n",sizeof(int));

	int *p;
	int a = 3;
	p = &a;
	printf("%p\n", p);
	return 0;
}