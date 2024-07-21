#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct STACK {
	int data;
	struct STACK *next;
}STACK;
typedef struct STACK *stack;

stack Init() {
	stack top = (STACK *)malloc(sizeof(STACK));
	if (top!=NULL) 
	top->next = NULL;
	return top;
}


int Push(stack S, int data) {
	stack top = S;
	STACK *P = (STACK *)malloc(sizeof(STACK));
	top->data = data;
	P->next=top->next;
	top->next = P;
	return OK;
}

int Pop(stack S) {
	stack top = S;
	STACK *P= (STACK *)malloc(sizeof(STACK));
	P = top->next;
	top->next = P->next;
	printf("popnumber:%d\n", top->data);
	free(P);
	return OK;
}

int Output(stack S) {
	stack top = S;
	printf("number:%d\n", top->data);//top->next->data输出是-842150451
	return OK;
}