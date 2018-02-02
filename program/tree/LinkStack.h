#ifndef _LINKSTACK_H  
#define _LINKSTACK_H  
  
#include <stdlib.h>  
#include <stdio.h>  
#include "BiTree.h"  
  
//定义栈中数据的类型  
typedef BiTree LStackElem;  
  
//定义栈元素的结构  
typedef struct SNode  
{  
    LStackElem data;  
    struct SNode * next;  
} SNode, *LinkNode;  
  
//定义栈的结构  
typedef struct   
{  
    LinkNode node;  //栈顶指针（相当于链表中的头指针）  
    int size;               //栈的大小  
} LinkStack;  
  
//初始化栈  
void init_link_stack(LinkStack S);  
  
//进栈  
void push(LinkStack S, LStackElem e);  
  
//出栈  
void pop(LinkStack S, LStackElem e);  
  
//判断栈是否为空  
int is_stack_empty(LinkStack S);  
  
//获得栈顶元素  
void get_top(LinkStack S, LStackElem e);  
  
#endif