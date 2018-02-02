#include"BiTree.h"  
#include"LinkStack.h"  
#include"LinkQueue.h"  
#include<stdio.h>  
#include<stdlib.h>  
  
//初始化一棵仅含根节点的二叉树,根节点的值为e  
void init_bitree(BiTree T, BiNodeElem e)  
{  
    T = (BiNode *) malloc(sizeof(BiNode));  
    T->data = e;  
    T->lchild = NULL;  
    T->rchild = NULL;  
}  
  
//产生树节点  
BiNode * creat_bitree_node(BiNodeElem e, BiNode * lchild, BiNode * rchild)  
{  
    BiNode * pTree = (BiNode *)malloc(sizeof(BiNode));  
    pTree->data = e;  
    pTree->lchild = lchild;  
    pTree->rchild = rchild;  
    return pTree;  
}  
  
//增加左子树  
void add_lchild(BiNode * binode, BiNode * lchild)  
{  
    if(binode != NULL)  
        binode->lchild = lchild;  
}  
  
//增加右子树  
void add_rchild(BiNode * binode, BiNode * rchild)  
{  
    if(binode != NULL)  
        binode->rchild = rchild;  
}  
  
//递归先序遍历  
void pro_order_recursion(BiTree T)  
{  
    if(T != NULL)  
    {  
        printf("%d    ",T->data);  
        pro_order_recursion(T->lchild);  
        pro_order_recursion(T->rchild);  
    }  
}  
  
//递归中序遍历  
void infix_order_recursion(BiTree T)  
{  
    if(T != NULL)  
    {  
        infix_order_recursion(T->lchild);  
        printf("%d    ",T->data);  
        infix_order_recursion(T->rchild);  
    }  
}  
  
//递归后序遍历  
void post_order_recursion(BiTree T)  
{  
    if(T != NULL)  
    {  
        post_order_recursion(T->lchild);  
        post_order_recursion(T->rchild);  
        printf("%d    ",T->data);  
    }  
}  
  
//非递归先序遍历  
void pro_order_no_recursion(BiTree T)  
{  
    LinkStack S;  
    init_link_stack(S);  
  
    //把根节点指针赋值给p  
    BiNode * p = T;  
    while( NULL != p || !is_stack_empty(S))  
    {  
        //打印当前节点，其左节点依次进栈  
        while(NULL != p )  
        {  
            printf("%d    ",p->data);  
            push(S,p);  
            p = p->lchild;  
        }  
        if(!is_stack_empty(S))  
        {  
            pop(S,p);  
            p = p->rchild;  
        }  
    }  
}  
  
//非递归中序遍历  
void infix_order_no_recursion(BiTree T)  
{  
    LinkStack S;  
    init_link_stack(S);  
  
    //把根节点指针赋值给p  
    BiNode * p = T;  
    while( NULL != p || !is_stack_empty(S))  
    {  
        //左节点依次进栈  
        while(NULL != p)  
        {  
            push(S,p);  
            p = p->lchild;  
        }  
        if(!is_stack_empty(S))  
        {  
            pop(S,p);  
            printf("%d    ",p->data);  
            p = p->rchild;  
        }  
    }  
}  
  
//非递归后序遍历  
void post_order_no_recursion(BiTree T)  
{  
    LinkStack S;  
    init_link_stack(S);  
  
    BiNode * p = T;  
    //存储最近一次访问的节点  
    BiNode * visited =NULL;  
    while(NULL != p || !is_stack_empty(S))  
    {  
        //直接写p 更为简单，不需要写NULL !=p  
        while(p)  
        {  
            push(S,p);  
            p = p->lchild;  
        }  
        if(!is_stack_empty(S))  
        {  
            pop(S,p);  
            //如果不存在右子树，或右子树被访问  
            /* 
                解析一下：根据上面的while循环，栈顶元素必然不存在左子树；如何存在右子树，又根据后序遍历的特点， 
                最近一次被访问的节点，必然是该节点的右子树 
            */  
            if( !p->rchild || p->rchild == visited)  
            {  
                printf("%d    ",p->data);  
                visited = p;  
                p = NULL;  
            }  
            else  
            {  
                push(S,p);  
                p = p->rchild;  
            }  
        }  
    }  
}  
  
//层次遍历  
void hierarchy_order(BiTree T)  
{  
    LinkQueue Q;  
    init_link_queue(Q);  
      
    BiNode * p;  
  
    if(T)  
    {  
        in_link_queue(Q,T);  
        while(!is_queue_empty(Q))  
        {  
            out_link_queue(Q,p);  
            printf("%d    ",p->data);  
  
            if(p->lchild)  
                in_link_queue(Q,p->lchild);  
            if(p->rchild)  
                in_link_queue(Q,p->rchild);  
        }  
    }  
}  