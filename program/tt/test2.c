#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//构造双向链表

//结点 结点指针
typedef struct DNODE
{
	struct DNODE *pre;
	struct DNODE *next;
	int data;
} DNODE,*DLINKLIST;

//构造结点
DLINKLIST getNode(int value) 
{
	DLINKLIST dnode = (DLINKLIST)malloc(sizeof(DNODE));
	dnode->data = value;
	dnode->pre = NULL;
	dnode->next = NULL;
	return dnode;
}

//构造双向链表
DLINKLIST getDoubleLinklist(int arr[10]) {
	DLINKLIST head,tail,node;
	//头结点
	head = getNode(11);
	tail = head;

	for (int i = 0; i < 10; ++i)
	{

		DLINKLIST node = getNode(arr[i]);
		// printf("%p\n", tail);
		// printf("%d\n", node->data);
		//指针连起来
		node->pre = tail;
		tail->next = node;

		tail++;
	}
	return head;
}

void printDoubleLinklist(DLINKLIST head) {
	while(head->next != NULL) {
		printf("%d\n", head->next->data);
		head++;
	}
}


int main(int argc, char const *argv[])
{
	int arr[10] = {
		14,11,17,88,32,12,23,12,33,55
	};
	DLINKLIST dlist = getDoubleLinklist(arr);
	printDoubleLinklist(dlist);
	return 0;
}