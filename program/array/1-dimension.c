#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//一维数组
	int a1[] = {22,33,44,21};
	//遍历
	for (int i = 0; i < 4; ++i)
	{
		//[]
		printf("---%d---\n", a1[i]);
		//指针
		printf("===%d===\n", *(a1+i));
	}

	//二维数组
	int a2[][4] = {{1,23,44,76},{0,16,63,43},{11,90,100,68}};
	//遍历
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			//[]
			printf("%d\n", a2[i][j]);
			//指针
			printf("===%d===\n", *(*(a2+i)+j));
		}
	}

	return 0;
}