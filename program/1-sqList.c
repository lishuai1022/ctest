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
}sqList,*psqList;


int compare_sq(int,int);

//初始化
int InitList_sq(psqList L) {
    L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    printf("%p\n", L->elem);
    if(!L->elem) {
        exit(-1);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 0;
}

//在第i个元素前插入一个元素e
int ListInsert_sq(psqList L,int i,int e) {
    if (i < 1 || i > L->length+1)
    {
        return -1;
    }
    if (L->listsize <= L->length)//空间满了
    {
        int * newbase = (int *)realloc(L->elem,(L->listsize+LISTINCREMENT) * sizeof(int));
        if (!newbase)
        {
            exit(-1);
        }

        L->elem = newbase;
        L->listsize = L->listsize + LISTINCREMENT;
    }

    // int * q = &L->elem[i-1];
    int *q = L->elem+(i-1);
    //后移
    // for (int * p = &L->elem[L->length-1]; p >= q; --p)
    // {
    //     *(p+1) = *p;
    // }
    for (int * p = L->elem+(L->length-1); p >= q; --p)
    {
        *(p+1) = *p;
    }
    //插入指定位置
    *q = e;
    //表长加1
    ++L->length;

    return 0;
}

//删除第i个元素
int ListDelete_sq(psqList L,int i) {
    if (i < 1 || i > L->length+1)
    {
        return -1;
    }

    int * q = L->elem+(i-1);
    //前移
    for (int * p = q+1; p <= L->elem+(L->length-1); ++p)
    {
        *(q) = *p;
        q++;
    }
    //表长减1
    --L->length;

    return 0;
}

//遍历
void traverse_sq(psqList L){
    for (int i = 0; i < L->length; ++i)
    {
        printf("%d\n", *(L->elem+i));
    }
}

int compare_sq(int x,int y) {
    if (x == y)
    {
        return 1;
    } else {
        return 0;
    }

}

//找到第一个值为给定值的下标
int LocateElem_sq(psqList L,int e,int (*compare)(int,int)) {
    int i = 1;
    int *p = L->elem;
    while(i <= L->length && !(*compare)(*p++,e)) {
        ++i;
    }
    if (i <= L->length)
    {
        return i;
    } else {
        return 0;
    }
}

//La Lb非递减排列，把La Lb归并为非递减排列的Lc
psqList MergeList_sq(psqList La,psqList Lb) {
    int *pa,*pa_last,*pb,*pb_last,*pc,listsize;
    pa = La->elem;
    pb = Lb->elem;
    pa_last = pa + La->length - 1;
    pb_last = pb + Lb->length - 1;
    listsize = La->listsize + Lb->listsize;

    psqList Lc = (psqList) malloc(sizeof(sqList));
    if (!Lc)
    {
        exit(-1);
    }
    InitList_sq(Lc);
    Lc->elem = (int *)realloc(Lc->elem,listsize * sizeof(int));
    if(!Lc->elem) {
        exit(-1);
    }
    Lc->listsize = Lc->length = listsize;
    pc = Lc->elem;

    //归并
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa >= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }

    while(pa <= pa_last) {
        *pc++ = *pa++;
    }
    while(pb <= pb_last) {
        *pc++ = *pb++;
    }

    return Lc;
}

int main(int argc, char const *argv[])
{
    psqList L=(psqList)malloc(sizeof(sqList));
    InitList_sq(L);
    // printf("L->elem=%p\n",L->elem);
    // printf("L->length=%d\n",L->length);
    // printf("L->listsize=%d\n",L->listsize);
    // return 0;
    ListInsert_sq(L,1,100);
    ListInsert_sq(L,1,200);
    ListInsert_sq(L,1,300);
    ListInsert_sq(L,1,400);
    ListInsert_sq(L,1,500);
    traverse_sq(L);
    printf("\n");
    // ListDelete_sq(L,3);
    // ListDelete_sq(L,3);
    // traverse_sq(L);
    // // int (*cp_sq)() = compare_sq;
    // int loc = LocateElem_sq(L,500,compare_sq);
    // printf("loc=%d\n", loc);

    psqList L2 = (psqList)malloc(sizeof(sqList));
    InitList_sq(L2);
    ListInsert_sq(L2,1,101);
    ListInsert_sq(L2,1,201);
    ListInsert_sq(L2,1,301);
    ListInsert_sq(L2,1,401);
    ListInsert_sq(L2,1,501);
    traverse_sq(L2);
    printf("\n");

    psqList L3 = MergeList_sq(L,L2);
    traverse_sq(L3);
    printf("L3->listsize=%d\n",L3->listsize);
    printf("\n");
    return 0;
}