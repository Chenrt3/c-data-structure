#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAXSIZE 20

typedef struct QUEUE {
	int queue[MAXSIZE];
	int front;
	int rear;
}QUEUE;


QUEUE Init() {
	QUEUE Q;
	Q.front = Q.rear = -1;
	return Q;
}

int Enter_Queue(QUEUE *Q, int data) {//结构体传入中的各个元素传入的是地址而不是int的数据，所以
	if (Q->rear == MAXSIZE) {			//QUEUE *Q而不是QUEUE Q直接传入
		return ERROR;
	}
	Q->rear++;
	Q->queue[Q->rear] = data;//传入QUEUE *Q这一步数组才能等于data，而不是data地址
	return OK;
}

int Delete_Queue(QUEUE *Q) {//同上
	if (Q->front == Q->rear) {
		printf("NULL\n");
	}
	Q->rear--;
	return OK;
}

void Output(QUEUE Q) {	
	while (Q.front != Q.rear) {
		printf("number:%d\n", Q.queue[Q.rear]);
		Q.rear--;
	}
}