#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct NODE
{
    ElemType data;
    struct NODE *next;
} NODE,*PNODE;

typedef struct LinkStack
{
    int size;
    PNODE bottom,top;
} LinkStack, *PLinkStack;


void initStack(PLinkStack);//初始化空栈
void pushStack(PLinkStack,ElemType);//入栈
void popStack(PLinkStack);//出栈
int isEmptyStack(PLinkStack);//栈是否为空
void traverseStack(PLinkStack);//遍历栈
void clearStack(PLinkStack);//清空栈
int getStackLength(PLinkStack);//获取栈的长度

//初始化空栈
void initStack(PLinkStack pls) {
    PNODE p = (PNODE)malloc(sizeof(NODE));
    if(p == NULL) {
        printf("内存分配失败\n");
        exit(-1);
    }
    p->next = NULL;
    pls->top = p;
    pls->bottom = p;
    pls->size = 0;
}

//入栈（头插法）
void pushStack(PLinkStack pls,ElemType e) {
    if (pls->size == 0)//利用空闲空间
    {
        pls->top->data = e;
    } else {
        PNODE p = (PNODE)malloc(sizeof(NODE));
        if(p == NULL) {
            printf("内存分配失败\n");
            exit(-1);
        }
        p->data = e;
        p->next = pls->top;
        pls->top = p;
    }
    pls->size++;
}

//出栈(弹出栈顶元素)
void popStack(PLinkStack pls) {
    int count = getStackLength(pls);
    if (count <= 0)
    {
        return;
    }
    if(pls->top) {
        PNODE p = pls->top;
        pls->top = pls->top->next;
        pls->size--;
        free(p);
    }
}

//判断栈是否为空
int isEmptyStack(PLinkStack pls) {
    if (pls->size >0) {
        return 0;
    } else {
        return 1;
    }

}

//从上往下遍历
void traverseStack(PLinkStack pls) {
    PNODE p = pls->top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//清空栈
void clearStack(PLinkStack pls) {
    while(pls->size > 0) {
        popStack(pls);
    }

}

//获取栈长度
int getStackLength(PLinkStack pls) {
    return pls->size;
}

int main(int argc, char const *argv[])
{
    PLinkStack pls = (PLinkStack)malloc(sizeof(LinkStack));
    initStack(pls);

    pushStack(pls,111);
    pushStack(pls,222);
    pushStack(pls,333);
    // pushStack(pls,101);
    traverseStack(pls);
    printf("%d\n", getStackLength(pls));

    popStack(pls);
    clearStack(pls);
    popStack(pls);
    int flag = isEmptyStack(pls);
    if(flag == 0) {
        printf("不是空栈\n");
    } else {
        printf("空栈\n");
    }
    traverseStack(pls);
    printf("%d\n", getStackLength(pls));

    popStack(pls);
    int flag1 = isEmptyStack(pls);
    if(flag1 == 0) {
        printf("不是空栈\n");
    } else {
        printf("空栈\n");
    }
    popStack(pls);
    traverseStack(pls);
    printf("%d\n", getStackLength(pls));
    return 0;
}