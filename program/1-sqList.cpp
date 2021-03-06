#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_INIT_SIZE
#define LIST_INIT_SIZE 20
#endif

#ifndef LISTINCREMENT
#define LISTINCREMENT 10
#endif

typedef struct sqList
{
    int * elem;//存储空间基址
    int length;//当前长度(实际拥有的元素个数)
    int listsize;//分配的存储空间（以元素为单位）总个数
}sqList;

int InitList_sq(sqList &L) {
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    printf("%p\n", L.elem);
    if(!L.elem) {
        exit(-1);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 0;
}

//在第i个元素前插入一个元素e
int ListInsert_sq(sqList &L,int i,int e) {
    if (i < 1 || i > L.length+1)
    {
        return -1;
    }
    if (L.listsize <= L.length)//空间满了
    {
        int * newbase = (int *)realloc(L.elem,(L.listsize+LISTINCREMENT) * sizeof(int));
        if (!newbase)
        {
            exit(-1);
        }

        L.elem = newbase;
        L.listsize = L.listsize + LISTINCREMENT;
    }

    int * q = &L.elem[i-1];
    //后移
    for (int * p = &L.elem[L.length-1]; p >= q; --p)
    {
        *(p+1) = *p;
    }
    //插入指定位置
    *q = e;
    //表长加1
    ++L.length;

    return 0;
}

void traverse_sq(sqList &L){
    for (int i = 0; i < L.length; ++i)
    {
        printf("%d\n", *(L.elem+i));
    }
}

int main(int argc, char const *argv[])
{
    // sqList * L=(sqList *)malloc(sizeof(sqList));
    sqList L;
    InitList_sq(L);
    // printf("L.elem=%p\n",L.elem);
    // printf("L.length=%d\n",L.length);
    // printf("L.listsize=%d\n",L.listsize);
    // return 0;
    ListInsert_sq(L,1,100);
    ListInsert_sq(L,1,200);
    ListInsert_sq(L,1,300);
    ListInsert_sq(L,1,400);
    ListInsert_sq(L,1,500);
    traverse_sq(L);
    return 0;
}