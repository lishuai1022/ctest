#include <stdio.h>
//typedef的4种应用

int main(int argc, char const *argv[])
{
	//1.为基本类型定义新的类型名
	//2.为自定义类型起别名
	typedef struct STU
	{
		char name[100];
		int age;
		struct STU *pnext;	
	} stu, *pstu;
	stu s1 = {"lishuai",33,NULL};
	printf("name:%s,age:%d,pnext:%p\n", s1.name,s1.age,s1.pnext);

	typedef struct 
	{
		char name[100];
		int age;
	} st,*pst;
	st s2 = {"juan",33};
	printf("name:%s,age:%d", s2.name,s2.age);

	//3.为数组定义简洁的类型名
	//4.为指针定义简洁的名称
	return 0;
}