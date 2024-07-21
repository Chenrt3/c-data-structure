#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct NODE{
  int data;
  struct NODE* next;
}NODE;
typedef struct NODE *LIST;
LIST Init();
int HeadInsert(LIST L,int data,int poss);
int TailInsert(LIST L,int data,int poss);
int Delete(LIST L,int poss);
int Change(LIST L,int data,int poss);
int OutPut(LIST L);
int FreeNode(LIST L);
