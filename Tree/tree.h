#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAXSIZE 255
typedef struct TNODE{
        char data;//节点数据
        int parent;//双亲位置
}TNODE;
typedef struct{
        TNODE NODES[MAXSIZE];//节点数组
        int n,r;//节点数根的位置
}TREE;
int Insert(TREE *T,char *ch,int *loc);
typedef struct CTNode{
	int child;//横着的链表存储的孩子节点
	struct CTNode *next;//横着的链表存储的链表next节点
}*ChildPtr;
/*表头结点*/
typedef struct{
	char data;//数据域
	ChildPtr firstchild;//竖着的数组存储的节点
}CTBox;
/*树结构*/
typedef struct{
	CTBox nodes[MAXSIZE];	//结点数组
	int root,size;		//根的位置和结点数
}CTREE;
int CreateTree(CTREE *T,int size);
void OutPut(CTREE *T);
