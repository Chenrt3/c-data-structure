#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1 
#define MAXSIZE 20

typedef struct QUEUE{
        int QUEUE[MAXSIZE];
        int rear;
        int front;

}QUEUE;

QUEUE Init(){
    QUEUE Q;
    Q.front=Q.rear=0;
    return Q;
}


int Enter_Queue(QUEUE *Q,int data){
    if(Q->front==(Q->rear+1)%MAXSIZE){//判断队列是否已满
        return ERROR;
    }
    Q->QUEUE[Q->rear]=data;
    Q->rear=(Q->rear+1)%MAXSIZE;//队尾向前进一步
    return OK;
}


int Delete_Queue(QUEUE *Q){
    if(Q->front+1==Q->rear){//判断队列是否空
        printf("NULL\n");
    }
    Q->front=(Q->front+1)%MAXSIZE;//队头向前进一步
    return OK;
}

void OutPut(QUEUE Q){
    while(Q.front+1!=Q.rear){
        printf("number:%d\n",Q.QUEUE[Q.front]);//输出仅适用于队头尾从零开始且未满
        Q.front++;
    }
}