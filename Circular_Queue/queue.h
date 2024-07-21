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
QUEUE Init();
int Enter_Queue(QUEUE *Q,int data);
int Delete_Queue(QUEUE *Q);
void OutPut(QUEUE Q);