#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct QUEUE{
        int data;
        struct QUEUE *next;
}QUEUE;

typedef struct{
        QUEUE *front,*rear;

}LINKQUEUE;
LINKQUEUE *Init();
int Enter_Queue(LINKQUEUE *L,int data);
int Delete_Queue(LINKQUEUE *L);
void OutPut(LINKQUEUE *L);