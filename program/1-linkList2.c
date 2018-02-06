/*
    静态链表的实现（结构体数组）
    第0个元素表示头节点
    后移操作语句为：i=S[i].cur
 */
#include "common.h"

#ifndef MAXSIZE
#define MAXSIZE 1000
#endif

typedef int ElemType;

typedef struct 
{
    ElemType data;
    int cur;
} component,SLinkList[MAXSIZE];


//定位
int LocateElem_SL(SLinkList S,ElemType e) {
    printf("%d\n", S[-1].cur);
    int i = S[0].cur;
    while(i && S[i].data != e) {
        i = S[i].cur;//后移
    }
    return i;
}

int main(int argc, char const *argv[])
{
    SLinkList S = {
        {0,1},
        {100,2},
        {200,3},
        {300,-1},
    };
    int k = sizeof(S);
    printf("%d\n", k);
    return 0;
    int loc = LocateElem_SL(S,500);
    printf("loc=%d\n", loc);
    return 0;
}