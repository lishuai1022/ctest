#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode * lchild, * rchild;
} BiTNode,* BiTree;

//创建二叉树
BiTree createBiTree(){
    BiTree T;
    int ch;
    scanf("%d",&ch);
    if(ch == 0) {
        T = NULL;
    } else {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T) {
            exit(0);
        }
        T->data = ch;
        printf("请输入%d的左结点\n", ch);
        T->lchild = createBiTree();
        printf("请输入%d的右结点\n", ch);
        T->rchild = createBiTree();
    }
    return T;
}

//先根遍历二叉树
void preOrderTraverse(BiTree P) {
    if (P == NULL || P->data == 0)
    {
        return;
    }
    printf("%d ", P->data);
    preOrderTraverse(P->lchild);
    preOrderTraverse(P->rchild);
}
//中根遍历二叉树
void inOrderTraverse(BiTree P) {
    if (P == NULL || P->data == 0)
    {
        return;
    }
    if (P->lchild != NULL)
    {
        inOrderTraverse(P->lchild);
    }
    printf("%d ", P->data);
    if (P->rchild != NULL)
    {
        inOrderTraverse(P->rchild);
    }
}

//后根遍历二叉树
void postOrderTraverse(BiTree P) {
    if (P == NULL || P->data == 0)
    {
        return;
    }
    if (P->lchild != NULL)
    {
        postOrderTraverse(P->lchild);
    }
    if (P->rchild != NULL)
    {
        postOrderTraverse(P->rchild);
    }
    printf("%d ", P->data);
}
//层次遍历二叉树
// void levelOrderTraverse(BiTree P) {
//     if (P == NULL || P->data == 0)
//     {
//         return;
//     }
//     printf("%d ", P->data);
//     if (P->lchild != NULL)
//     {
//         levelOrderTraverse(P->lchild);
//     }
//     // levelOrderTraverse()
// }
// //求二叉树的深度
// int getTreeHeight(BiTree P) {

// }
// //求二叉树叶子结点总数
// int getLeavesCount(BiTree P) {

// }
// //交换二叉树所有结点的左右子树
// void exchangeSubTree(BiTree P) {

// }


int main(int argc, char const *argv[])
{
    BiTree T;
    T = createBiTree();

    printf("先根遍历结果：\n");
    preOrderTraverse(T);
    printf("\n");

    printf("中根遍历结果：\n");
    inOrderTraverse(T);
    printf("\n");
    
    printf("后根遍历结果：\n");
    postOrderTraverse(T);
    printf("\n");

    // printf("T=%p\n", T);
    return 0;
}