#include <stdio.h>
#include <stdlib.h>

int add(int ab, int bb);
int add(int a,int b) {
    return a+b;
}

int main(int argc, char const *argv[])
{
    int res;
    res = add(5,6);
    printf("res=%d\n",res );
    return 0;
}