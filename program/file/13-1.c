#include <stdio.h>
/*

函数：
    fopen fclose
    fgetc fputc
    fgets fputs
    fread fwrite
    fscanf fprintf
    putchar getchar

    rewind

注：fgetc读取一个字符，并把指针往后移动一位
 */

int read1() 
{
    FILE *fp;
    char ch;
    fp = fopen("/tmp/cron_slistall.txt","r");
    if(fp == NULL) {
        printf("打开文件出错！\n");
        return 1;
    }
    ch = fgetc(fp);
    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(fp);
    }
    /*追加*/
    fclose(fp);
    return 0;
}

int write1()
{
    FILE *pf;
    char ch;
    pf = fopen("/tmp/aaa.txt","w+");
    if (pf == NULL)
    {
        printf("打开文件出错！\n");
        return 1;
    }
    printf("请输入一个字符：\n");
    ch = getchar();
    while(ch != '\n') {
        fputc(ch,pf);
        ch = getchar();
    }

    rewind(pf);
    ch = fgetc(pf);
    while(ch != EOF) {
        putchar(ch);
        ch = fgetc(pf);
    }

    fclose(pf);
    return 0;
}

int main(int argc, char const *argv[])
{
    read1();
    write1();
    return 0;
}