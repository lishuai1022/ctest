#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//构造双向链表(头插法 尾插法)

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

//构造双向链表(尾插法)
DLINKLIST getDoubleLinklist(int arr[10]) {
	DLINKLIST head,tail,node;
	//头结点
	head = getNode(-1);
	tail = head;

	for (int i = 0; i < 10; ++i)
	{

		DLINKLIST node = getNode(arr[i]);
		//指针连起来
		node->pre = tail;
		tail->next = node;

		tail = tail->next;
	}
	return head;
}

void printDoubleLinklist(DLINKLIST head) {
	while(head->next != NULL) {
		printf("%d\n", head->next->data);
		head = head->next;
	}
}

//构造双向链表(头插法)
DLINKLIST getDoubleLinklist2(int arr[10]) {
	DLINKLIST head,tail,node;
	//头结点
	head = getNode(-1);
	tail = head;

	for (int i = 0; i < 10; ++i)
	{

		DLINKLIST node = getNode(arr[i]);
		//指针连起来
		node->pre = tail;
		tail->next = node;

		tail = tail->next;
	}
	return tail;
}

void printDoubleLinklist2(DLINKLIST tail) {
	while(tail != NULL && tail->data != -1) {
		printf("%d\n", tail->data);
		if(tail->pre != NULL) {
			tail = tail->pre;
		} else {
			break;
		}
	}
}


int main(int argc, char const *argv[])
{
	int arr[10] = {
		14,11,17,88,32,12,23,12,33,55
	};
	
	printf("-------头插法及遍历----------\n");
	DLINKLIST dlist = getDoubleLinklist(arr);
	printDoubleLinklist(dlist);

	printf("-------尾插法及遍历----------\n");

	DLINKLIST dlist2 = getDoubleLinklist2(arr);
	printDoubleLinklist2(dlist2);
	return 0;
}