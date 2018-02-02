#include "LinkStack.c"  
#include "LinkQueue.c"  
#include "BiTree.c"  
  
int main()  
{  
    BiTree T;  
    init_bitree(T,10);  
    BiNode * lchild = creat_bitree_node(20,NULL,creat_bitree_node(40,NULL,NULL));  
    add_lchild(T, lchild);  
    BiNode * rchild1 = creat_bitree_node(50,creat_bitree_node(60,NULL,NULL),creat_bitree_node(70,NULL,NULL));  
    BiNode * rchild = creat_bitree_node(30, NULL, rchild1);  
    add_rchild(T,rchild);  
  
    printf("构造的树的结果如下：\n");  
    printf("                             10\n");  
    printf("                            /   \\\n");  
    printf("                          20     30\n");  
    printf("                            \\     \\ \n");  
    printf("                                40    50\n");  
    printf("                                      /\\\n");  
    printf("                                    60 70\n\n");  
  
  
    printf("递归先序遍历的结果：\n");  
    pro_order_recursion(T);  
    printf("\n");  
  
    printf("递归中序遍历的结果：\n");  
    infix_order_recursion(T);  
    printf("\n");  
  
    printf("递归后序遍历的结果：\n");  
    post_order_recursion(T);  
    printf("\n");  
    printf("\n===============================================\n\n");  
  
    printf("非递归先序遍历的结果：\n");  
    pro_order_no_recursion(T);  
    printf("\n");  
  
    printf("非递归中序遍历的结果：\n");  
    infix_order_no_recursion(T);  
    printf("\n");  
  
    printf("非递归后序遍历的结果：\n");  
    post_order_no_recursion(T);  
    printf("\n");  
  
    printf("非递归层次遍历的结果：\n");  
    hierarchy_order(T);  
    printf("\n");  
      
    return 0;  
}