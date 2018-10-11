#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数组做函数的参数的几种形式

void test(int p[]) {
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", p[i]);
		// p++;
	}
}

void test1(int p[100]) {
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", *p);
		p++;
	}
}

void test2(int *p) {
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", *p);
		p++;
	}
}

int main(int argc, char const *argv[])
{
	int arr[10] = {
		1,22,33,4,55,66,77,88,99,100
	};
	printf("-------------\n");
	test(arr);
	printf("-------------\n");
	test1(arr);
	printf("-------------\n");
	test2(arr);
	return 0;
}