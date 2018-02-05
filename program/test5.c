#include <stdio.h>
#include <stdlib.h>

int getMax(int,int);

int main(int argc, char const *argv[])
{
    int (*pmax)() = getMax;
    int m = (*pmax)(5,10);
    printf("max=%d\n", m);
    return 0;
}

int getMax(int x,int y) {
    if(x > y) {
        return x;
    } else {
        return y;
    }
}