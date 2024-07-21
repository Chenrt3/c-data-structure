#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct NODE {
	int data;
	struct NODE* next;
}NODE;
typedef struct NODE *LIST;


LIST Init() {
	struct NODE *L = (NODE *)malloc(sizeof(LIST));
	if (L == NULL) {
		printf("申请失败\n");
	}
	L->next = NULL;
	return L;
}

int HeadInsert(LIST L, int data, int poss) {
	NODE *head = L;
	for (int i = 0; i < poss; i++) {
		head = head->next;
	}
	NODE *P = (NODE *)malloc(sizeof(NODE));
	P->data = data;
	P->next = head->next;
	head->next = P;
	return OK;
}


int TailInsert(LIST L, int data, int poss) {
	NODE *head = L;
	for (int i = 0; i < poss; i++) {
		head = head->next;
	}
	NODE *P = (NODE *)malloc(sizeof(NODE));
	P->data = data;
	head->next = P;
	head = P;
	return OK;
}

int Delete(LIST L, int poss) {
	NODE *head = L;
	for (int i = 0; i < poss; i++) {
		head = head->next;
	}
	NODE *P = (NODE *)malloc(sizeof(NODE));
	P = head->next;
	head->next = head->next->next;
	free(P);
	return OK;
}


int Change(LIST L, int data, int poss) {
	NODE *head = L;
	for (int i = 0; i < poss; i++) {
		head = head->next;
	}
	head->data = data;
	printf("Number:%d\n", head->data);
	return OK;
}

int OutPut(LIST L) {
	NODE *head = L->next;
	while (head) {
		printf("number:%d\n", head->data);
		head = head->next;
	}
	return OK;
}

int FreeNode(LIST L) {
	NODE *head = L;
	NODE *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	return OK;
}