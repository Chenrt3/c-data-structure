#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct ThreadNode {
	DataType data;	//数据元素
	struct ThreadNode *lchild, *rchild;	//左、右孩子指针
	int ltag, rtag;	//左、右线索标志
}ThreadNode, *ThreadTree;

void CreateTree(ThreadTree *T);
void Inthreading(ThreadTree T);
ThreadTree Next(ThreadTree *T);
void InorderTraverse(ThreadTree *t);