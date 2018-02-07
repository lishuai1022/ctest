#include "common.h"

typedef struct node
{
    float coef;//系数
    int expn;//指数
    struct node *pNext;
} NODE,*PNODE;

/*
    初始化一个空的链表
 */
PNODE initList() {
    PNODE pHead;
    pHead = (PNODE) malloc(sizeof(NODE));
    if (pHead == NULL)
    {
        printf("内存分配失败！\n");
        exit(-1);
    }
    pHead->pNext = NULL;
    return pHead;
}

/*
    判断链表是否为空
 */
int isEmptyList(PNODE list) {
    if (list == NULL || list->pNext == NULL)
    {
        return 1;
    }
    return 0;
}

/*
    获取链表长度
 */

int getListLength(PNODE list) {
    if(isEmptyList(list)) {
        return 0;
    }

    PNODE p = list;
    int length = 0;
    while(p->pNext != NULL) {
        ++length;
        p = p->pNext;
    }
    return length;
}

/*
    获取链表第pos位置
 */

PNODE getListPos(PNODE list,int pos) {
    PNODE p = list;
    int j = 0;
    if(!isEmptyList(list) && getListLength(list) >= pos) {
        while(p->pNext != NULL && j < pos) {
            p = p->pNext;
            ++j;
        }
    }
    return p;
}

/*
    “尾插法”构造带头结点单链表，返回头结点的指针（地址）
    注：1.每次尾插完一个新节点，新节点即为尾节点
        2.头结点不变化，返回头结点的地址就可以找到这个单链表了；
        3.构造过程中尾节点不断后移，直到所有节点都插入。
 */
PNODE createList(int num) {
    int expn;//存放节点值
    float coef;
    //头节点 尾节点
    PNODE pHead,pTail;
    pHead = initList();
    //尾指针
    pTail = pHead;//头节点和尾节点是一个节点

    //构造链表节点
    for (int i = 0; i < num; ++i)
    {
        PNODE n = (PNODE)malloc(sizeof(NODE));
        if (n == NULL)
        {
            printf("内存分配失败！\n");
            exit(-1);
        }
        printf("请输入系数：\n");
        scanf("%f",&coef);
        printf("请输入指数：\n");
        scanf("%d",&expn);
        n->coef = coef;//填充数据域
        n->expn = expn;//填充数据域
        n->pNext = NULL;//新节点指针域为空

        pTail->pNext = n;//连上线（把新节点连到尾节点后面）
        pTail = n;//新节点为尾节点
    }

    return pHead;
}

/*
    遍历链表，传入链表的头结点指针作为参数
    注：要用到临时节点，临时节点不断后移，直到链表末尾
 */
void traverseList(PNODE list)
{
    PNODE p;//临时节点
    if(list->pNext == NULL) {
        return;
    }
    p = list->pNext;//把链表的首结点作为临时节点
    while(p != NULL) {
        printf("%fx^%d\n",p->coef,p->expn);
        p = p->pNext;
    }
    printf("\n");
}

/*
    在pos位置之后插入一个元素data
 */
int insertList(PNODE list,int pos,float coef,int expn)
{
    PNODE p_new,p_pos;
    int i = 0;
    if (list->pNext == NULL)
    {
        return -1;
    }
    //构造新节点
    p_new = (PNODE)malloc(sizeof(NODE));
    p_new->coef = coef;
    p_new->expn = expn;
    p_new->pNext = NULL;
    //找到pos位置
    p_pos = list;
    while(p_pos->pNext && i < pos) {
        p_pos = p_pos->pNext;
        ++i;
    }
    if (!(p_pos) || i > pos)//位置不合理
    {
        return -1;
    }
    //连线
    p_new->pNext = p_pos->pNext;
    p_pos->pNext = p_new;

    return 0;
}

/*
    删除第pos个元素
 */
int deleteList(PNODE list,int pos)
{
    //找到第pos个节点
    // PNODE p = list + pos;//连续空间时才可以这么用！
    // PNODE p_pre = p - 1;
    // PNODE p_next = p + 1;
    
    PNODE p_pre = list;
    int i = 0;
    //找到第pos-1个节点
    while(p_pre->pNext && i < pos-1) {
        p_pre = p_pre->pNext;
        ++i;
    }
    if (!(p_pre->pNext) || i > pos)//位置不合理
    {
        return -1;
    }
    PNODE p = p_pre->pNext;
    p_pre->pNext = p->pNext;
    free(p);
    return 0;
}

//add



int main(int argc, char const *argv[])
{
    // PNODE listlist = initList();
    // printf("list=%p\n", listlist);
    // return 0;
    int num;
    printf("请输入链表长度：\n");
    scanf("%d",&num);
    if (num < 1)
    {
        printf("链表长度最小值为1\n");
        return -1;
    }
    //创建链表
    PNODE list = createList(num);
    traverseList(list);

    printf("请输入链表长度：\n");
    scanf("%d",&num);
    if (num < 1)
    {
        printf("链表长度最小值为1\n");
        return -1;
    }
    PNODE list2 = createList(num);
    traverseList(list2);

    // PNODE pos_node = getListPos(list,3);
    // printf("pos_node->data=%d\n",(pos_node->data));


    // // int list_length = getListLength(list);
    // // printf("list_length=%d\n",list_length );
    // return 0;
    // //在第2个节点后插入节点100
    // insertList(list,2,100);
    // traverseList(list);
    // //删除第4个元素
    // deleteList(list,4);
    // traverseList(list);

    // //判断是否为空
    // int flag = isEmptyList(list);
    // printf("flag=%d\n", flag);

    // printf("程序结束\n");
    return 0;
}



