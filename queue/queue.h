#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAXSIZE 20

typedef struct QUEUE{
        int queue[MAXSIZE];
        int front;
        int rear;
}QUEUE;
QUEUE Init();
int Enter_Queue(QUEUE *Q,int data);//涉及到修改值的就传入指针
int Delete_Queue(QUEUE *Q);
void Output(QUEUE Q);//单纯输入输出值的就直接构造