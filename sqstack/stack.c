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

STACK Init() {
	STACK S;
	S.bottom = (int *)malloc(MAXSIZE*sizeof(int));
	if (!S.bottom) {
		printf("初始化失败");
	}
	S.top = S.bottom;
	S.stacksize = MAXSIZE;
	return S;
}

int Push(STACK *S,int data) {
	if (!S->bottom)return ERROR;
	else if (S->top - S->bottom >= S->stacksize) {
		S->bottom= (int *)malloc((MAXSIZE+ADDSIZE) * sizeof(int));
		S->stacksize = MAXSIZE + ADDSIZE;
	}
	S->top++;
	*S->top = data;
	return *S->top;
}

int Pop(STACK *S) {
	if (S->top==S->bottom)return ERROR;
	S->top--;
	int *e = S->top;
	return *e;
}