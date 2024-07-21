#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAXSIZE 255
//#define PlanA 1//条件编译，只能使用在同一文件中
#define PlanB 1

#ifdef PlanA
/*树的双亲表示法结构定义*/
typedef struct TNODE{
        char data;//节点数据
        int parent;//双亲位置
}TNODE;
typedef struct{
        TNODE NODES[MAXSIZE];//节点数组
        int n,r;//节点数根的位置
}TREE;
        int Insert(TREE *T,char *ch,int *loc){
            T->n=0;
            for(int i=0;i<10;i++){
                T->NODES[i].data=ch[i];//给叶子节点赋值
                T->NODES[i].parent=loc[i];//各个节点的下标位置
                T->n++;
            }
           T->r=T->NODES[0].parent=ch[0];//根节点
            return OK;
        }

#elif PlanB
/*树的孩子表示法结构定义*/
/*孩子结点*/
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
	int root,size;	//根的位置和结点数
}CTREE;

int CreateTree(CTREE *T, int size) {
	T->size = size;
	T->root = 0;
	for (int i = 0; i < size; i++) {
		getchar();
		printf("%dST父节点:", i + 1);
		scanf_s("%c",&T->nodes[i].data);
		printf("输入要创建的孩子结点个数：");
		int childnum;
		scanf_s("%d", &childnum);
		ChildPtr Tail = T->nodes[i].firstchild = NULL;
		for (int j = 0; j < childnum; j++) {
			ChildPtr P = (ChildPtr)malloc(sizeof(struct CTNode));
			P->next = NULL;
			printf("输入%dST孩子结点的下标:",j);
			scanf_s("%d", &P->child);
				if (T->nodes[i].firstchild == NULL) {
					Tail = T->nodes[i].firstchild = P;
				}
				else {
					Tail->next = P;
					Tail = Tail->next;
				}
		}

	}
	return OK;
}
void OutPut(CTREE *T) {
	for (int i = 0; i < T->size; i++) {
		printf("输出父节点：%c",T->nodes[i].data);
		ChildPtr temp = T->nodes[i].firstchild;
		while (temp) {
			printf("-%c",&T->nodes[temp->child].data);
			temp = temp->next;
		}
	}
}
#endif