#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
把一个序列转化为单链表存储，并遍历链表
*/

//结点 结点指针
typedef struct LNODE
{
	int data;
	struct LNODE *pnext;
} LNODE,* LINKLIST;

//构造一个结点，返回指针
LINKLIST getNode(int value) {
	LINKLIST node = (LINKLIST)malloc(sizeof(LNODE));
	node->data = value;
	node->pnext = NULL;
	return node;
}

//构造带头结点,头指针，尾指针，长度为n的单链表，返回指针
LINKLIST getLinklist(int n[10]) {
	LINKLIST head,tail,node;//头指针 尾指针 结点
	//头结点
	head = getNode(0);
	tail = head;

    //构造链表 
	for (int i = 0; i < 10; ++i)
	{
		//结点
		node = getNode(n[i]);
        //指针连线连起来
		tail->pnext = node;
		tail = node;
	}
	return head;
}

//遍历链表
void printLinklist(LINKLIST head) {
	//遍历
	while(head->pnext != NULL)
	{
		printf("%d\n", head->pnext->data);
		head++;
	}
}



int main(int argc, char const *argv[])
{
	int arr[10] = {
		11,22,33,44,55,66,77,88,99,100
	};
	LINKLIST link = getLinklist(arr);
	printLinklist(link);
	return 0;
}