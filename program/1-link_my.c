#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
} NODE, * PNODE;

/*
    “尾插法”构造带头结点单链表，返回头结点的指针（地址）
    注：1.每次尾插完一个新节点，新节点即为尾节点
        2.头结点不变化，返回头结点的地址就可以找到这个单链表了；
        3.构造过程中尾节点不断后移，直到所有节点都插入。
 */
PNODE createList(int num) {
    int val;//存放节点值
    //头节点
    PNODE pHead;
    pHead = (PNODE)malloc(sizeof(NODE));
    if (pHead == NULL)
    {
        printf("内存分配失败！\n");
        exit(-1);
    }
    pHead->pNext = NULL;

    //尾指针
    PNODE pTail = pHead;//头节点和尾节点是一个节点

    //构造链表节点
    for (int i = 0; i < num; ++i)
    {
        PNODE n = (PNODE)malloc(sizeof(NODE));
        if (n == NULL)
        {
            printf("内存分配失败！\n");
            exit(-1);
        }
        printf("请输入元素值：\n");
        scanf("%d",&val);
        n->data = val;//填充数据域
        n->pNext = NULL;//新节点指针域为空

        pTail->pNext = n;//连上线（把新节点连到尾节点后面）
        pTail = n;//新节点为尾节点
    }

    return pHead;
}


int main(int argc, char const *argv[])
{
    int num;
    printf("请输入链表长度：\n");
    scanf("%d",&num);
    PNODE list = createList(num);
    printf("list=%p\n",list);
    return 0;
}