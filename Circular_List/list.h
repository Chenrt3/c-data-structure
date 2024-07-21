#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OK 1
typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;
typedef struct NODE *List;
List Init();
int Insert(List L,int data,int poss);
int Delete(List L,int poss);
int OutPut(List L);