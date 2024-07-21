#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct QUEUE {
	int data;
	struct QUEUE *next;
}QUEUE;

typedef struct {
	QUEUE *front, *rear;

}LINKQUEUE;

LINKQUEUE *Init() {
	LINKQUEUE *L = (LINKQUEUE*)malloc(sizeof(LINKQUEUE));
	L->front= L->rear=(QUEUE*)malloc(sizeof(QUEUE));//初始化时不能L->rear->next =L->front->next= NULL
	if (L->front == NULL)							//出队时使用头节点成空节点
		printf("chushihuashibai\n");
	L->rear->next = NULL;//尾节点的next指向null
	return L;
}

int Enter_Queue(LINKQUEUE *L, int data) {
	QUEUE *Q = (QUEUE*)malloc(sizeof(QUEUE));
	if (Q == NULL)
		return ERROR;
	Q->next = NULL;
	Q->data = data;
	L->rear->next = Q;//尾插法
	L->rear = Q;//更新尾节点
	return OK;
}


int Delete_Queue(LINKQUEUE *L) {
	//QUEUE *Q = (QUEUE*)malloc(sizeof(QUEUE));删除节点不用新开地址，因为不做数据修改
	QUEUE *Q;//构造中间变量再free
	Q = L->front->next;
	if (L->front == L->rear)
		printf("null\n");
	if (Q == L->rear)//当队列只有一个结点时应防止丢失队尾指针 *
		L->front = L->rear;
	L->front->next = Q->next;//正常的链表删除元素
	free(Q);
	return OK;
}

void OutPut(LINKQUEUE *L) {
	QUEUE *P = L->front->next;//头节点不存数据，相当于链表的遍历元素从next开始遍历
	while (P !=NULL) {
		printf("number:%d\n", P->data);
		P = P->next;
	}
}