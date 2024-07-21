#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAXSIZE 100
#define ADDSIZE 10

typedef struct STACK {
	int stacksize;
	int *top;
	int *bottom;
}STACK;
STACK Init();
int Push(STACK *S,int data);
int Pop(STACK *S);
