#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int * a = (int *)malloc(10 * sizeof(int));
    *a = 1;
    *(a+1) = 2;
    *(a+2) = 3;
    // int b = a[0] = 6;
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    // printf("%d\n", b);
    return 0;
}