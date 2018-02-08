#include "../program/common.h"

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Positon;
typedef struct 
{
    Link head,tail;
    int length;
}LinkList;

//----------------函数声明(22个）-------------------
//分配结点
Status MakeNode(Link &p,ElemType e);
//释放结点
void FreeNode(Link &p);
//初始化
Status InitList(LinkList &L);
//销毁
Status DestroyList(LinkList &L);
//清空
Status ClearList(LinkList &L);
//头插
Status InsFirst(Link h,Link s);
//头删
Status DelFirst(Link h,Link &q);
//尾插
Status Append(LinkList &L,Link s);
//尾删
Status Append(LinkList &L,Link &q);
//前插（p之前）
Status InsBefore(LinkList &L,Link &p,Link s);
//后插（p之后）
Status InsAfter(LinkList &L,Link &p,Link s);
//修改结点值
Status SetCurElem(Link &p,ElemType e);
//获取结点值
ElemType GetCurElem(Link p);
//链表是否为空
Status ListEmpty(LinkList L);
//链表长度
int ListLength(LinkList L);
//头结点位置
Positon GetHead(LinkList L);
//尾结点位置
Positon GetLast(LinkList L);
//前驱结点位置
Positon PriorPos(LinkList L,Link p);
//后继结点位置
Positon NextPos(LinkList L,Link p);
//第i个结点的位置
Status LocatePos(LinkList L,int i,Link &p);
//第1个与e满足函数关系的位置
Positon LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
//依次对链表元素调用函数（即遍历）
Status ListTraverse(LinkList L,Status(*visit)());

int main(int argc, char const *argv[])
{
    printf("aaaaa\n");
    return 0;
}
