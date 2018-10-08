#include <stdio.h>
#include <string.h>
//结构体数组 
//选出学号最大的学生
struct STU
{
	char name[20];
	int age;
	char sex;
	char num[20];
};

void OutputSTU(struct STU stu[3]);

int main(int argc, char const *argv[])
{
	int i;
	struct STU stu[3];
	for (int i = 0; i < 3; ++i)
	{
		printf("请输入第%d个学生的信息：\n", i+1);
		scanf("%s%d %c%s",stu[i].name,&stu[i].age,&stu[i].sex,stu[i].num);
	}
	OutputSTU(stu);
	return 0;
}

void OutputSTU(struct STU stu[3]) {
	struct STU stumax = stu[0];
	for (int j = 0; j < 3; ++j)
	{
		if (strcmp(stumax.num,stu[j].num) < 0)
		{
			stumax = stu[j];
		}
	}
	printf("姓名：%s 年龄：%d 性别：%c 学号：%s\n",stumax.name,stumax.age,stumax.sex,stumax.num);
}
