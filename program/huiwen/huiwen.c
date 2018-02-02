#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

typedef struct//栈结构体 
{ 
    char e[MAX]; 
    int top; 
} SeqStack; 
 
typedef struct NODE//队列结构体 
{ 
    char d; 
    struct NODE *next; 
} LinkQN;
 
typedef struct//封装头指针为指针 
{ 
    LinkQN *front; 
    LinkQN *rear; 
}LinkQ;


void InitStack(SeqStack *s)//初始化顺序栈 
{ 
    s->top=-1; 
} 

int push(SeqStack *s,char ch)//入栈 
{ 
    if(s->top==MAX-1) 
        return(0); 
    s->top++; 
    s->e[s->top]=ch; 
    return(1); 
}

int pop(SeqStack *s,char *x)//出栈 
{ 
    if(s->top==-1) 
        return(0); 
    else { 
        *x=s->e[s->top]; 
        s->top--; 
        return(1);
    }
}

void InitQuene(LinkQ *q)//链队列初始化 
{ 
    q->front=(LinkQN *)malloc(sizeof(LinkQN)); 
    if(!q->front) { 
        printf("分配空间失败!"); 
    } 
    q->rear=q->front; 
    q->front->next=NULL; 
}

int enter(LinkQ *q,char ch)//入队 
{ 
    LinkQN *np; 
    np=(LinkQN *)malloc(sizeof(LinkQN)); 
    if(!np) 
        return(0); 
    np->d=ch; 
    np->next=NULL; 
    q->rear->next=np; 
    q->rear=np; 
    return(1); 
}


int deleteq(LinkQ *q,char *c)//出队 
{ 
    LinkQN *p; 
    if(q->front==q->rear) 
        return(0); 
    p=q->front->next; 
    q->front->next=p->next; 
    if(q->rear==p) 
        q->rear=q->front; 
    *c=p->d; 
    free(p); 
    return(0); 
}

int huiwen(SeqStack s,LinkQ q)//回文判断
{ 
    int flag=1,m=0,t=1; 
    int i; 
    char ch1,ch2,ch; 
    InitStack(&s); 
    InitQuene(&q); 
    printf("请输入字符序列当输入字符@时输入结束:\n"); 
    while(ch!='@') { 
        ch=getchar(); 
        if(ch!='@') { 
            printf("%c",ch); 
            push(&s,ch); 
            enter(&q,ch); 
            m++; 
        } 
    } 
    printf("\n输入完成!\n"); 
    getchar(); 
    if(m%2)
    { 
        if(s.e[m/2]=='&') { 
            for(i=1;i<(m+1)/2;i++) { 
                pop(&s,&ch1); 
                deleteq(&q,&ch2); 
                if(ch1!=ch2) 
                    flag=0; 
            } 
        } else {
            flag=0; 
        }
    } else {
        flag=0; 
    }
    return(flag); 
} 

int main() { 
    SeqStack s; 
    LinkQ q; 
    int m; 
    m=huiwen(s,q); 
    printf("\n"); 
    if(m) 
        printf("该字符序列是回文序列!\n"); 
    else 
        printf("该字符序列不是回文序列!\n");
    return 0;
}
