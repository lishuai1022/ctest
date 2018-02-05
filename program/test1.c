#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3};
    char str[] = "hello pp";
    // for (int i = 0; i < 3; ++i)
    // {
    //     printf("%d\n", arr[i]);
    // }
    for (int i = 0; i < 3; ++i)
    {
        printf("%p\n",arr+i );
        printf("%d\n", *(arr+i));
    }

    for (int j = 0; j < 8; ++j)
    {
        printf("%c", str[j]);
    }
    printf("\n");
    printf("%s\n", str);
    return 0;
}