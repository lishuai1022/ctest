#include <stdio.h>
#include <stdlib.h>
//构造AVL树
#ifndef LH
#define LH 1
#endif
#ifndef EH
#define EH 0
#endif
#ifndef RH
#define RH -1
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef int Status;
typedef struct BiTNode
{
	int data;
	int bf;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	
} BiTNode,* BiTree;

void R_Rotate(BiTree *P) {
	BiTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
	*P = L;
}

void L_Rotate(BiTree *P) {
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->rchild;
	R->lchild = (*P);
	*P = R;
}

void LeftBalance(BiTree *T)
{
	BiTree L,Lr;
	L = (*T)->lchild;
	switch(L->bf)
	{
		case LH:
		    (*T)->bf = L->bf = EH;
		    R_Rotate(T);
		    break; 
		case RH:
		    Lr = L->rchild;
		    switch(Lr->bf) {
		    	case LH:
		    	    (*T)->bf = RH;
		    	    L->bf = EH;
		    	    break;
		    	case EH:
		    	    (*T)->bf = L->bf = EH;
		    	    break;
		    	case RH:
		    	    (*T)->bf = EH;
		    	    L->bf = LH;
		    	    break;
		    }
		    Lr->bf = EH;
		    L_Rotate(&(*T)->lchild);
		    R_Rotate(T);
	}
}

void RightBalance(BiTree *T) {
	BiTree R,Rl;
	R = (*T)->rchild;
	switch(R->bf) {
		case RH:
		    (*T)->bf = R->bf = EH;
		    L_Rotate(T);
		    break;
		case LH:
		    Rl = R->lchild;
		    switch(Rl->bf) {
		    	case RH:
		    	    (*T)->bf = LH;
		    	    R->bf = EH;
		    	    break;
		    	case EH:
		    	    (*T)->bf = R->bf = EH;
		    	    break;
		    	case LH:
		    	    (*T)->bf = EH;
		    	    R->bf = RH;
		    	    break;
		    }
		    Rl->bf = EH;
		    R_Rotate(&(*T)->rchild);
		    L_Rotate(T);
	}
}

Status InsertAVL(BiTree *T,int e,int *taller)
{
	if (!*T) {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	} else {
		if ((*T)->data == e) {
			*taller = FALSE;
			return FALSE;
		} else if ((*T)->data > e) {
			if (!InsertAVL(&(*T)->lchild,e,taller))
			{
				return FALSE;
			} else {
				if (*taller)
				{
					switch((*T)->bf) {
						case LH:
						    LeftBalance(T);
						    *taller = FALSE;
						    break;
						case EH:
						    (*T)->bf = LH;
						    *taller = TRUE;
						    break;
						case RH:
						    (*T)->bf = EH;
						    *taller = FALSE;
						    break;

					}
				}
			}
		} else {
			if (!InsertAVL(&(*T)->rchild,e,taller))
			{
				return FALSE;
			} else {
				if (*taller)
				{
					switch((*T)->bf) {
						case LH:
						    (*T)->bf = EH;
						    *taller = FALSE;
						    break;
						case EH:
						    (*T)->bf = RH;
						    *taller = TRUE;
						    break;
						case RH:
						    RightBalance(T);
						    *taller = FALSE;
						    break;
					}
				}
			}

		}
	}
	return TRUE;
}

int main(int argc, char const *argv[])
{
	//构造10个结点的AVL树
	int i;
	int a[10] = {3,2,1,4,5,6,7,10,9,8};
	BiTree T = NULL;
	int taller;
	for (int i = 0; i < 10; ++i)
	{
		InsertAVL(&T,a[i],&taller);
	}
	printf("ok\n");
	return 0;
}