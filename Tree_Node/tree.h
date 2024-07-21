#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
typedef int ElemType;

/*二叉树的二叉链表结点构造定义*/
/*结点结构*/
typedef struct BiTNode{
	ElemType data;	//结点数据
	struct BiTNode *lchild, *rchild;	//左右孩子指针
} BiTNode, *BiTree;
int Create(BiTree *B);
int first_print(BiTree B);
int mid_print(BiTree B);
int fina_print(BiTree B);