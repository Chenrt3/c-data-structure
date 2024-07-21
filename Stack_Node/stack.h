#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct STACK{
    int data;
    struct STACK *next;
}STACK;
typedef struct STACK *stack;
stack Init();
int Push(stack S,int data);
int Pop(stack S);
int Output(stack S);