#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    int arr[] = {11,33,44,55};
    printf("%p\n", arr);
    printf("%p\n", arr+1);
    printf("%p\n", arr+2);
    printf("%p\n", arr+3);
    printf("%d\n", *arr);
    printf("%d\n", *(arr+1));
    printf("%d\n", *(arr+2));
    printf("%d\n", *(arr+3));
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);
    return 0;
}