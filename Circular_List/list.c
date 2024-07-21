#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OK 1
typedef struct NODE {
	int data;
	struct NODE *next;
}NODE;
typedef struct NODE *List;

List Init() {
	NODE *head = (NODE *)malloc(sizeof(List));
	if (head == NULL) {
		printf("初始化失败\n");
	}
	head->next = head;
	head->data = -1;
	return head;
}

int Insert(List L, int data, int poss) {
	NODE *head,*tail;
	head = L;
	tail = (NODE *)malloc(sizeof(NODE));
	tail->next = head;
	NODE *P = (NODE *)malloc(sizeof(NODE));
	/*if (poss == 0) {
		P->data = data;
		P->next = head;
		head = P;
	}
	else {*/
		for (int i = 0; i < poss; i++) {
			head = head->next;
		}
		P->data = data;
		P->next = head->next;
		head->next = P;
		/*if (P->next == head) {
			tail = P;
		}*/
	//}
	return OK;
}


int Delete(List L, int poss) {
	NODE *head, *tail;
	tail = (NODE *)malloc(sizeof(NODE));
	head = L;
	tail->next = head;
	NODE *P = (NODE *)malloc(sizeof(NODE));
	if (poss == 0) {
		head = head->next;
		tail->next = head;
	}
	else {
		for (int i = 0; i < poss; i++) {
			head = head->next;
		}
		P = head->next;
		head->next = P->next;
		if (P->next == head) {
			tail = head;
		}
		free(P);
	}
	return OK;
}

int OutPut(List L) {
	NODE *head = L->next;
	while (head->next!=L) {
		printf("number:%d\n", head->data);
		head = head->next;
	}
	return OK;
}