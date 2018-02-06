#include "common.h"

typedef int ElemType;

int getmax(int,int);
Status myprintf(int,int);


int main(int argc, char const *argv[])
{
    int i,j;
    i = 2;
    j = 3;
    int max = getmax(i,j);
    printf("max=%d\n",max);

    myprintf(5,20);
    return 0;
}

int getmax(int x,int y) {
    if (x > y)
    {
        return x;
    }

    return y;
}

Status myprintf(int a,int count) {
    for (int i = 0; i < count; ++i)
    {
        printf("%d\n", a);
    }
    return OK;
} 