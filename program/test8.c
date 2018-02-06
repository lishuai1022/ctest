#include "common.h"
#include <string.h>


int main(int argc, char const *argv[])
{
    char str[100],str2[100];
    gets(str);
    printf("ok!\n");
    puts(str);
    gets(str2);
    printf("okok!\n");
    puts(str2);
    strcat(str,str2);
    puts(str);
    printf("str=%s\n", str);
    return 0;
}