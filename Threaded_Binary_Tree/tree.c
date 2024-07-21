#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct ThreadNode {
	DataType data;	//数据元素
	struct ThreadNode *lchild, *rchild;	//左、右孩子指针
	int ltag, rtag;	//左、右线索标志
}ThreadNode, *ThreadTree;

void CreateTree(ThreadTree *T) {//先序创建二叉树
	DataType ch;
	ch = getchar();
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (ThreadNode *)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
}

void Inthreading(ThreadTree T) {//中序线索化
	static ThreadTree pre = NULL;//定义静态全局变量指向上一个节点
	if (T) {
		Inthreading(T->lchild);
		if (!T->lchild) {
			T->ltag = 1;
			T->lchild = pre;
		}
		if (pre && !pre->rchild) {
			pre->rtag = 1;
			pre->rchild = T;
		}
		pre = T;
		Inthreading(T->rchild);
	}
}

ThreadTree Next(ThreadTree *T) {//知道T节点找T节点后继
	if ((*T)->rtag == 1) {
		*T = (*T)->rchild;
	}
	else {
		*T = (*T)->rchild;
		while ((*T)->ltag == 0) {
			(*T) = (*T)->lchild;
		}
	}
	return *T;
}

ThreadTree Prior(ThreadTree *T) {
	if ((*T)->ltag == 1) {
	*T = (*T)->lchild;
	}
	else {
		*T = (*T)->lchild;
		while ((*T)->rtag == 0) {
			(*T) = (*T)->rchild;
		}
	}
	return *T;
}

void InorderTraverse(ThreadTree *t)//利用线索实现中序遍历 
{
	if (!t)
	{
		return;
	}

	while ((*t)->ltag == 0)//查找第一个节点 
	{               //因为二叉树的创建creat是以先序遍历序列创建，所以t所指向的第一个结点并不是中序遍历所要访问的第一个结点 
		(*t)= (*t)->lchild;
	}
	printf("%c ", (*t)->data);//访问第一个结 
	while ((*t)->rchild)// 此处以"t的右孩子不为空"为循环条件，是因为，先前设定了最后一个结点的"后继"为空，表示结束 
	{               //根据线索访问后续结点 
		(*t) = Next(t);
		printf("%c ", (*t)->data);
	}
}