#ifndef _BITREE_H  
#define _BITREE_H  
  
//定义二叉树中存储的数据类型  
typedef int BiNodeElem;  
  
//定义二叉树的结构  
typedef struct BiNode  
{  
    BiNodeElem data;  
    struct BiNode * lchild;  
    struct BiNode * rchild;  
}BiNode, *BiTree;  
  
//初始化一棵仅含根节点的二叉树,根节点的值为e  
void init_bitree(BiTree T, BiNodeElem e);  
  
//产生树节点  
BiNode * creat_bitree_node(BiNodeElem e, BiNode * lchild, BiNode * rchild);  
  
//增加左子树  
void add_lchild(BiNode * binode, BiNode * lchild);  
  
//增加右子树  
void add_rchild(BiNode * binode, BiNode * rchild);  
  
//递归先序遍历  
void pro_order_recursion(BiTree T);  
  
//递归中序遍历  
void infix_order_recursion(BiTree T);  
  
//递归后序遍历  
void post_order_recursion(BiTree T);  
  
//非递归先序遍历  
void pro_order_no_recursion(BiTree T);  
  
//非递归中序遍历  
void infix_order_no_recursion(BiTree T);  
  
//非递归后序遍历  
void post_order_no_recursion(BiTree T);  
  
//层次遍历  
void hierarchy_order(BiTree T);  
  
#endif  
