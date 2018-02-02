#include"LinkQueue.h"  
#include<stdio.h>  
#include<stdlib.h>  
  
//初始化队列  
void init_link_queue(LinkQueue Q)  
{  
    Q.top = Q.bottom = (QNode *)malloc(sizeof(QNode));  
    Q.top->next = NULL;  
    Q.size = 0;  
}  
  
//入队列（尾插法）  
void in_link_queue(LinkQueue Q, QueueElem e)  
{  
    QNode * p = (QNode *)malloc (sizeof(QNode));  
    p->data = e;  
    p->next = NULL;  
  
    Q.bottom->next = p;  
    Q.bottom = p;  
    ++Q.size;  
}  
  
//出队列  
void out_link_queue(LinkQueue Q, QueueElem e)  
{  
    if(Q.size > 0)  
    {  
        e = Q.top->next->data;  
        QNode * p = Q.top->next;  
        Q.top->next = Q.top->next->next;  
  
        if(Q.bottom == p)  
            Q.bottom = Q.top;  
        free(p);  
        --Q.size;  
    }  
}  
  
//队列是否为空  
int is_queue_empty(LinkQueue Q)  
{  
    if(Q.size == 0)  
        return 1;  
    else  
        return 0;  
}  