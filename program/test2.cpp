#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a = 1;
    int &b = a;
    b = 2;
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}