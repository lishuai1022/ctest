#include <stdio.h>
#include <stdlib.h>

void nzp(int a[],int n) {
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {
        55,33,11,
    };
    nzp(arr,3);
    return 0;
}