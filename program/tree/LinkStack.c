#include "LinkStack.h"  
  
//初始化栈  
void init_link_stack(LinkStack S)  
{  
    S.node = (SNode *)malloc(sizeof(SNode));  
    S.node->next = NULL;  
    S.size = 0;  
}  
  
//进栈  
void push(LinkStack S, LStackElem e)  
{  
    LinkNode p = (LinkNode)malloc(sizeof(SNode));  
    p->data = e;  
    p->next = S.node->next;  
    S.node->next = p;  
    ++S.size;  
}  
  
//出栈  
void pop(LinkStack S, LStackElem e)  
{  
    if(is_stack_empty(S))  
    {  
        printf("栈为空，不能出栈。\n");  
        return;  
    }  
    e = S.node->next->data;  
    LinkNode p = S.node->next;  
    S.node->next = S.node->next->next;  
    free(p);  
    --S.size;  
}  
  
//判断栈是否为空  
int is_stack_empty(LinkStack S)  
{  
    if(S.size == 0)  
        return 1;  
    else  
        return 0;  
}  
  
//获得栈顶元素  
void get_top(LinkStack S, LStackElem e)  
{  
    e = S.node->next->data;  
}  