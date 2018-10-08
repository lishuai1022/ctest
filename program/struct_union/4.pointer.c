#include <stdio.h>
#include <string.h>
//指向结构体变量的指针 指向结构体数组的指针
struct STU
{
	char name[20];
	int age;
	char gender;
};

int main(int argc, char const *argv[])
{
	struct STU s1;
	struct STU *p1 = NULL;
	p1 = &s1;
	//以下3种方法等价
	strcpy(p1->name,"xuan");
	(*p1).age = 5;
	s1.gender = 'f';

	printf("%s %d %c\n",p1->name,p1->age,p1->gender);



	struct STU stu[3] = {{"juan",32,'f'},{"shuai",33,'m'},{"xuan",4,'m'}};
	struct STU *p = stu;
	for (; p < stu+3; ++p)
	{
		printf("name:%s,age:%d,gender:%c\n", p->name,p->age,p->gender);
	}
	return 0;
}