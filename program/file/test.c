#include "comhead.h"
#ifndef SIZE
#define SIZE 200
#endif

int main(int argc, char const *argv[])
{
	FILE *p;
	char buffer[SIZE];
	p = fopen("/Users/admin/Desktop/1111.txt","r");
	fread(buffer,SIZE,1,p);
	printf("%s\n", buffer);
	fclose(p);
	return 0;
}