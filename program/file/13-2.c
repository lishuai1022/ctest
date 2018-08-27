#include <stdio.h>

/*
文件复制
 */

int main(int argc, char const *argv[])
{
    FILE *fp1;
    FILE *fp2;
    char ch;
    if (argc == 1)
    {
        printf("请输入参数\n");
        return 1;
    }
    fp1 = fopen(argv[1],"r");
    if (fp1 == NULL)
    {
        printf("打开文件1出错\n");
        return 1;
    }

    fp2 = fopen(argv[2],"w");
    if (fp2 == NULL)
    {
        printf("打开文件2出错\n");
        return 2;
    }

    ch = fgetc(fp1);
    while(ch != EOF)
    {
        fputc(ch,fp2);
        ch = fgetc(fp1);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}