#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
typedef char ElemType;
/*使用递归思想创建二叉树*/
/*二叉树的二叉链表结点构造定义*/
/*结点结构*/
typedef struct BiTNode {
	ElemType data;	//结点数据
	struct BiTNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

int Create(BiTree *B) {//先序创建二叉树,传入struct BiTNode **
	char ch;
	ch = getchar();
	if (ch == '#')
		*B = NULL;//节点为空
	else {
		*B= (BiTNode*)malloc(sizeof(BiTNode));
		(*B)->data= ch;
		Create(&(*B)->lchild);//(*B)->lchild是一个实体struct BiTNode *，所以要传入地址
		Create(&(*B)->rchild);
	}
	return OK;
}


int first_print(BiTree B) {//先序根左右遍历
	if(B){
		printf("%c",B->data);
		first_print(B->lchild);
		first_print(B->rchild);
	}
	return ERROR;
}


int mid_print(BiTree B) {//中序左根右
	if(B){
		mid_print(B->lchild);
		printf("%c",B->data);
		mid_print(B->rchild);
	}
	return ERROR;
}


int fina_print(BiTree B) {//后序根左右
	if(B){
		fina_print(B->lchild);
		fina_print(B->rchild);
		printf("%c",B->data);
	}
	return ERROR;
}