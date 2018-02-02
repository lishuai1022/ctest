#ifndef _LINKQUEUE_H  
#define _LINKQUEUE_H  
#include "BiTree.h"  
  
typedef BiTree QueueElem;  
  
typedef struct QNode  
{  
    QueueElem data;  
    struct QNode * next;  
}QNode;  
  
typedef struct   
{  
    QNode * top;          //队列头指针  
    QNode * bottom;   //队列尾指针  
    int size;                  //队列大小  
}LinkQueue;  
  
  
//初始化队列  
void init_link_queue(LinkQueue Q);  
  
//入队列  
void in_link_queue(LinkQueue Q, QueueElem e);  
  
//出队列  
void out_link_queue(LinkQueue Q, QueueElem e);  
  
//队列是否为空  
int is_queue_empty(LinkQueue Q);  
  
#endif  