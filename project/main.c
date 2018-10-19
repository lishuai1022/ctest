#include "./commh.h"
#include "./user/user.c"

int main(int argc, char const *argv[])
{
	// printf("kkkkk\n");
	test("pp");
	char sss[] = "lishuai";
	char *str = "lishuai";
	test2(sss);
	test3(str,2);
	char *r = getSubStr(str,3);//返回字符串指针
	printf("%s\n",r);//根据指针打印字符串
	
	char s2='k';
	char *r2 = getSubStr(s2,0);//返回字符指针
	printf("%c\n", *r2);//打印字符
	return 0;
}