// #include <stdio.h>

void test(char value[]) {
	printf("hello,%s\n",value);
}

void test2(char *p) {
	printf("okok,%s\n", p);

}
void test3(char p[],int n) {
	p += n;
	printf("test3,%s\n",p);
}

//
char * getSubStr(char *p,int n) {
	char *r = p;
	r += n;
	return r;
}

char * getSubStr2(char *p,int n) {
	char *r = p;
	r += n;
	return r;
}



// int main(int argc, char const *argv[])
// {
// 	test("kkkkk");
// 	return 0;
// }