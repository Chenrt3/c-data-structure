#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct NODE{
    int data;
    struct NODE *next;
    struct NODE *porior;
}NODE;
typedef struct NODE *LIST;
LIST Init();
int Insert(LIST L,int data,int poss);
int Delete(LIST L,int poss);
int OutPut (LIST L);