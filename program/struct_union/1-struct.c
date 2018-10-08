#include <stdio.h>
//结构体的声明 结构体变量的定义和初始化
struct AGE
{
	int year;
	int month;
	int day;
};
struct STU
{
	char name[20];
	struct AGE birthday;
	float score;
	char detail[100];
};

int main(int argc, char const *argv[])
{
	
	struct STU juan = {
		"huijuan",
		{1984,10,9},
		71.0,
		"kkkkk"
	};
	struct TEACHER
	{
		char name[20];
		int age;
		float score;
		char detail[100];
	};
	struct TEACHER shuai = {
		"lishuai",
		34,
		72.8,
		"aaaa"
	};
	printf("name:%s\n",juan.name);
	printf("birthday:%d-%d-%d\n",juan.birthday.year,juan.birthday.month,juan.birthday.day);
	printf("name:%s\n",shuai.name);
	return 0;
}