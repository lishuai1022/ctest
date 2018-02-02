// #include "stdafx.h" 
// #include "iostream.h" 
#include <stdio.h> 
#include <stdlib.h> 
const int MAXLEN=10; 
typedef struct {  
    int data[MAXLEN];  
    int front,rear; 
}SeQueue; 
 
SeQueue InitSeQueue() {  
    SeQueue q;  
    q.front=-1;  
    q.rear=-1;  
    return(q); 
}

int Getfront_seq(SeQueue *q,int *x) {  
    if(q->front==q->rear)   
        return(0);  
    else  {  
        *x=q->data[(q->front)+1];
        return(1); 
    } 
}

int enterSeQueue(SeQueue *q,int x) {  
    if(q->rear==MAXLEN-1)  
        return(0);  
    else  
        q->rear++;  
    q->data[q->rear]=x;  
    return(1); 
}

int DelSeQueue(SeQueue *q,int *x) {  
    if(q->front==q->rear)   
        return(0); 
    else  {   
        q->front++; 
        *x=q->data[q->front];   
        return(1);  
    } 
} 
 
int Empty_seq(SeQueue *q) {  
    return(q->rear==q->front); 
}

void print(SeQueue q) {  
    int n; 
    if(q.front!=q.rear)  {   
        printf("队列的元素输出：");   
        for(n=q.front+1;n<=q.rear;n++)   
            printf("%3d",q.data[n]); 
    }  else   
    printf("队列为空！！！");  
    printf("\n"); 
}

int main(int argc, char* argv[]) {  
    int x; 
    SeQueue queue;  
    int n,y,z,i,j; 
    queue=InitSeQueue(); 
//     cout<<"蔡勇超 广东海洋大学寸金学院 11信息管理与信息系统2班"<<endl;  
//     cout<<"联系方式：13763**** 77532****@qq.com."<<endl; 
//     cout<<"程序设计一般原则自顶向下，逐步细化，先设计外部接口，再进行内部设计。
// "<<endl; 
// cout<<" "<<endl; 
// loop:  
// cout<<"                                 循环队列系统      "<<endl; 
//     cout<<" "<<endl;   
// cout<<"                 
// ***********************************************"<<endl;
// cout<<"                 *              1---------入 队                *"<<endl;  cout<<"                 *              2---------队列的元素输出       *"<<endl;  cout<<"                 *              3---------读列头元素           *"<<endl;  cout<<"                 *              4---------出 队                *"<<endl;  cout<<"                 *              5---------退 出                *"<<endl;  cout<<"                 *              0---------关 于                *"<<endl;  
// cout<<"                 
// ***********************************************"<<endl;  
// cout<<"请选择菜单号(0~5):"; 
// cin>>x; 
//   switch(x)  { 
//      case 1: 
//  printf("\n输入入队元素的数目n：");  scanf("%d",&n); 
//  printf("输入%d个待入队的元素：",n);  for(i=1;i<=n;i++)  {   scanf("%d",&y);   enterSeQueue(&queue,y); 
//  }  goto loop;    
//    break;   
// case 2: 
 
// print(queue); 
//     goto loop;    
//    break; 
  
// case 3: 
 
// print(queue); 
// Getfront_seq(&queue,&z);  printf("当前队头元素：%d\n",z);  goto loop;   
 
//    break; 
//      case 4:  print(queue); 
//  printf("输入出队元素的数目j(j要小于n):");  scanf("%d",&j); 
//  printf("出队的%d个元素为：",j);  for(i=1;i<=j;i++)  {   DelSeQueue(&queue,&z);   printf("%3d",z); 
 
// }
// printf("\n");  goto loop;    
//    break; 
//   case 5:return 0;    
//    break; 
  
// case 0:cout<<"欢迎使用线性表链式存储系统！"<<endl; 
//  goto loop;    
//    break; 
//   default:cout<<"！！！输入的选项不正确，请重新输入！！！"<<endl; 
//  } 
//  if(Empty_seq(&queue)!=0)   
// printf("队列为空！");  return 0; 
}